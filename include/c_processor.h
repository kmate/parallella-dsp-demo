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

void smbFft(float *fftBuffer, long fftFrameSize, long sign) {
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

#define BUFFER_SIZE  1024
#define FFT_SIZE     1024
#define OVERLAP      4
#define SAMPLE_RATE  44100

#define FFT_SIZE2    ((FFT_SIZE) / 2)
#define FREQ_PER_BIN ((SAMPLE_RATE) / (double)(FFT_SIZE))
#define STEP_SIZE    ((FFT_SIZE) / (OVERLAP))
#define IN_LATENCY   ((FFT_SIZE) - (STEP_SIZE))
#define EXPCT_DIFF   (2.0 * (M_PI) * (double)(STEP_SIZE) / (double)(FFT_SIZE))

void pitchShiftBody(float pitchShift, float *input, float *output) {
	/* do windowing and re,im interleave */
	float gFFTworksp[2*FFT_SIZE];
	for (int k = 0; k < FFT_SIZE;k++) {
	    /* Hann window */
		double window = -.5*cos(2.*M_PI*(double)k/(double)FFT_SIZE)+.5;
		gFFTworksp[2*k] = input[k] * window;
		gFFTworksp[2*k+1] = 0.;
	}

	/* ***************** ANALYSIS ******************* */
	/* do transform */
	smbFft(gFFTworksp, FFT_SIZE, -1);

    /* this is the analysis step */
    float gAnaFreq[FFT_SIZE];
    float gAnaMagn[FFT_SIZE];
    float gLastPhase[FFT_SIZE/2+1];
	for (int k = 0; k <= FFT_SIZE2; k++) {

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
		tmp -= (double)k*EXPCT_DIFF;

		/* map delta phase into +/- Pi interval */
		int qpd = tmp/M_PI;
		if (qpd >= 0) qpd += qpd&1;
		else qpd -= qpd&1;
		tmp -= M_PI*(double)qpd;

		/* get deviation from bin frequency from the +/- Pi interval */
		tmp = OVERLAP*tmp/(2.*M_PI);

		/* compute the k-th partials' true frequency */
		tmp = (double)k*FREQ_PER_BIN + tmp*FREQ_PER_BIN;

		/* store magnitude and true frequency in analysis arrays */
		gAnaMagn[k] = magn;
		gAnaFreq[k] = tmp;

	}

	/* ***************** PROCESSING ******************* */
	/* this does the actual pitch shifting */
    float gSynFreq[FFT_SIZE];
    float gSynMagn[FFT_SIZE];
	memset(gSynMagn, 0, FFT_SIZE*sizeof(float));
	memset(gSynFreq, 0, FFT_SIZE*sizeof(float));
	for (int k = 0; k <= FFT_SIZE2; k++) { 
		int index = k*pitchShift;
		if (index <= FFT_SIZE2) { 
			gSynMagn[index] += gAnaMagn[k]; 
			gSynFreq[index] = gAnaFreq[k] * pitchShift; 
		} 
	}
	
	/* ***************** SYNTHESIS ******************* */
	/* this is the synthesis step */
    float gSumPhase[FFT_SIZE/2+1];
	for (int k = 0; k <= FFT_SIZE2; k++) {

		/* get magnitude and true frequency from synthesis arrays */
		double magn = gSynMagn[k];
		double tmp = gSynFreq[k];

		/* subtract bin mid frequency */
		tmp -= (double)k*FREQ_PER_BIN;

		/* get bin deviation from freq deviation */
		tmp /= FREQ_PER_BIN;

		/* take OVERLAP into account */
		tmp = 2.*M_PI*tmp/OVERLAP;

		/* add the overlap phase advance back in */
		tmp += (double)k*EXPCT_DIFF;

		/* accumulate delta phase to get bin phase */
		gSumPhase[k] += tmp;
		double phase = gSumPhase[k];

		/* get real and imag part and re-interleave */
		gFFTworksp[2*k] = magn*cos(phase);
		gFFTworksp[2*k+1] = magn*sin(phase);
	} 

	/* zero negative frequencies */
	for (int k = FFT_SIZE+2; k < 2*FFT_SIZE; k++) gFFTworksp[k] = 0.;

	/* do inverse transform */
	smbFft(gFFTworksp, FFT_SIZE, 1);

	/* do windowing and add to output accumulator */
	for(int k=0; k < FFT_SIZE; k++) {
	    /* the window is exactly the same as above */
		double window = -.5*cos(2.*M_PI*(double)k/(double)FFT_SIZE)+.5;
		output[k] = window*gFFTworksp[2*k]/(FFT_SIZE*OVERLAP);
	}
}

#endif // C_PROCESSOR_H_
