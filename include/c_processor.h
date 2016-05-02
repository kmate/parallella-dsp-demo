#ifndef C_PROCESSOR_H_
#define C_PROCESSOR_H_

/****************************************************************************
*
* NAME: smbPitchShift.cpp
* VERSION: 1.2
* HOME URL: http://blogs.zynaptiq.com/bernsee
* KNOWN BUGS: none
*
* SYNOPSIS: Routine for doing pitch shifting while maintaining
* duration using the Short Time Fourier Transform.
*
* DESCRIPTION: The routine takes a pitchShift factor value which is between 0.5
* (one octave down) and 2. (one octave up). A value of exactly 1 does not change
* the pitch. numSampsToProcess tells the routine how many samples in indata[0...
* numSampsToProcess-1] should be pitch shifted and moved to outdata[0 ...
* numSampsToProcess-1]. The two buffers can be identical (ie. it can process the
* data in-place). fftFrameSize defines the FFT frame size used for the
* processing. Typical values are 1024, 2048 and 4096. It may be any value <=
* MAX_FRAME_LENGTH but it MUST be a power of 2. osamp is the STFT
* oversampling factor which also determines the overlap between adjacent STFT
* frames. It should at least be 4 for moderate scaling ratios. A value of 32 is
* recommended for best quality. sampleRate takes the sample rate for the signal 
* in unit Hz, ie. 44100 for 44.1 kHz audio. The data passed to the routine in 
* indata[] should be in the range [-1.0, 1.0), which is also the output range 
* for the data, make sure you scale the data accordingly (for 16bit signed integers
* you would have to divide (and multiply) by 32768). 
*
* COPYRIGHT 1999-2015 Stephan M. Bernsee <s.bernsee [AT] zynaptiq [DOT] com>
*
* 						The Wide Open License (WOL)
*
* Permission to use, copy, modify, distribute and sell this software and its
* documentation for any purpose is hereby granted without fee, provided that
* the above copyright notice and this license appear in all source copies. 
* THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY OF
* ANY KIND. See http://www.dspguru.com/wol.htm for more information.
*
*****************************************************************************/ 

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define M_PI 3.14159265358979323846

void smbFft(float *fftBuffer, long fftFrameSize, long sign)
/* 
	FFT routine, (C)1996 S.M.Bernsee. Sign = -1 is FFT, 1 is iFFT (inverse)
	Fills fftBuffer[0...2*fftFrameSize-1] with the Fourier transform of the
	time domain data in fftBuffer[0...2*fftFrameSize-1]. The FFT array takes
	and returns the cosine and sine parts in an interleaved manner, ie.
	fftBuffer[0] = cosPart[0], fftBuffer[1] = sinPart[0], asf. fftFrameSize
	must be a power of 2. It expects a complex input signal (see footnote 2),
	ie. when working with 'common' audio signals our input signal has to be
	passed as {in[0],0.,in[1],0.,in[2],0.,...} asf. In that case, the transform
	of the frequencies of interest is in fftBuffer[0...fftFrameSize].
*/
{
	float wr, wi, arg, *p1, *p2, temp;
	float tr, ti, ur, ui, *p1r, *p1i, *p2r, *p2i;
	long i, bitm, j, le, le2, k;

	for (i = 2; i < 2*fftFrameSize-2; i += 2) {
		for (bitm = 2, j = 0; bitm < 2*fftFrameSize; bitm <<= 1) {
			if (i & bitm) j++;
			j <<= 1;
		}
		if (i < j) {
			p1 = fftBuffer+i; p2 = fftBuffer+j;
			temp = *p1; *(p1++) = *p2;
			*(p2++) = temp; temp = *p1;
			*p1 = *p2; *p2 = temp;
		}
	}
	for (k = 0, le = 2; k < (long)(log(fftFrameSize)/log(2.)+.5); k++) {
		le <<= 1;
		le2 = le>>1;
		ur = 1.0;
		ui = 0.0;
		arg = M_PI / (le2>>1);
		wr = cos(arg);
		wi = sign*sin(arg);
		for (j = 0; j < le2; j += 2) {
			p1r = fftBuffer+j; p1i = p1r+1;
			p2r = p1r+le2; p2i = p2r+1;
			for (i = j; i < 2*fftFrameSize; i += le) {
				tr = *p2r * ur - *p2i * ui;
				ti = *p2r * ui + *p2i * ur;
				*p2r = *p1r - tr; *p2i = *p1i - ti;
				*p1r += tr; *p1i += ti;
				p1r += le; p1i += le;
				p2r += le; p2i += le;
			}
			tr = ur*wr - ui*wi;
			ui = ur*wi + ui*wr;
			ur = tr;
		}
	}
}

// -----------------------------------------------------------------------------------------------------------------

void pitchShiftBody(float pitchShift, long fftFrameSize, long osamp, float sampleRate, float *input, float *output) {
	/* set up some handy variables */
	long fftFrameSize2 = fftFrameSize/2;
	long stepSize = fftFrameSize/osamp;
	double freqPerBin = sampleRate/(double)fftFrameSize;
	double expct = 2.*M_PI*(double)stepSize/(double)fftFrameSize;

	/* do windowing and re,im interleave */
	float gFFTworksp[2*fftFrameSize];
	for (int k = 0; k < fftFrameSize;k++) {
	    /* Hann window */
		double window = -.5*cos(2.*M_PI*(double)k/(double)fftFrameSize)+.5;
		gFFTworksp[2*k] = input[k] * window;
		gFFTworksp[2*k+1] = 0.;
	}

	/* ***************** ANALYSIS ******************* */
	/* do transform */
	smbFft(gFFTworksp, fftFrameSize, -1);

    /* this is the analysis step */
    float gAnaFreq[fftFrameSize];
    float gAnaMagn[fftFrameSize];
    float gLastPhase[fftFrameSize/2+1];
	for (int k = 0; k <= fftFrameSize2; k++) {

		/* de-interlace FFT buffer */
		double real = gFFTworksp[2*k];
		double imag = gFFTworksp[2*k+1];

		/* compute magnitude and phase */
		double magn = 2.*sqrt(real*real + imag*imag);
		double phase = atan2(imag,real);

		/* compute phase difference */
		double tmp = phase - gLastPhase[k];
		gLastPhase[k] = phase;

		/* subtract expected phase difference */
		tmp -= (double)k*expct;

		/* map delta phase into +/- Pi interval */
		int qpd = tmp/M_PI;
		if (qpd >= 0) qpd += qpd&1;
		else qpd -= qpd&1;
		tmp -= M_PI*(double)qpd;

		/* get deviation from bin frequency from the +/- Pi interval */
		tmp = osamp*tmp/(2.*M_PI);

		/* compute the k-th partials' true frequency */
		tmp = (double)k*freqPerBin + tmp*freqPerBin;

		/* store magnitude and true frequency in analysis arrays */
		gAnaMagn[k] = magn;
		gAnaFreq[k] = tmp;

	}

	/* ***************** PROCESSING ******************* */
	/* this does the actual pitch shifting */
    float gSynFreq[fftFrameSize];
    float gSynMagn[fftFrameSize];
	memset(gSynMagn, 0, fftFrameSize*sizeof(float));
	memset(gSynFreq, 0, fftFrameSize*sizeof(float));
	for (int k = 0; k <= fftFrameSize2; k++) { 
		int index = k*pitchShift;
		if (index <= fftFrameSize2) { 
			gSynMagn[index] += gAnaMagn[k]; 
			gSynFreq[index] = gAnaFreq[k] * pitchShift; 
		} 
	}
	
	/* ***************** SYNTHESIS ******************* */
	/* this is the synthesis step */
    float gSumPhase[fftFrameSize/2+1];
	for (int k = 0; k <= fftFrameSize2; k++) {

		/* get magnitude and true frequency from synthesis arrays */
		double magn = gSynMagn[k];
		double tmp = gSynFreq[k];

		/* subtract bin mid frequency */
		tmp -= (double)k*freqPerBin;

		/* get bin deviation from freq deviation */
		tmp /= freqPerBin;

		/* take osamp into account */
		tmp = 2.*M_PI*tmp/osamp;

		/* add the overlap phase advance back in */
		tmp += (double)k*expct;

		/* accumulate delta phase to get bin phase */
		gSumPhase[k] += tmp;
		double phase = gSumPhase[k];

		/* get real and imag part and re-interleave */
		gFFTworksp[2*k] = magn*cos(phase);
		gFFTworksp[2*k+1] = magn*sin(phase);
	} 

	/* zero negative frequencies */
	for (int k = fftFrameSize+2; k < 2*fftFrameSize; k++) gFFTworksp[k] = 0.;

	/* do inverse transform */
	smbFft(gFFTworksp, fftFrameSize, 1);

	/* do windowing and add to output accumulator */
	for(int k=0; k < fftFrameSize; k++) {
	    /* the window is exactly the same as above */
		double window = -.5*cos(2.*M_PI*(double)k/(double)fftFrameSize)+.5;
		output[k] += window*gFFTworksp[2*k]/(fftFrameSize*osamp);
	}
}

#endif // C_PROCESSOR_H_
