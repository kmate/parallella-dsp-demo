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

#include <complex.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define M_PI 3.14159265358979323846

#define BUFFER_SIZE  1024
#define FFT_SIZE     1024
#define OVERLAP      4
#define SAMPLE_RATE  44100

#define FFT_SIZE2    ((FFT_SIZE) / 2)
#define FREQ_PER_BIN ((SAMPLE_RATE) / (double)(FFT_SIZE))
#define STEP_SIZE    ((FFT_SIZE) / (OVERLAP))
#define IN_LATENCY   ((FFT_SIZE) - (STEP_SIZE))
#define EXPCT_DIFF   (2.0 * (M_PI) * (double)(STEP_SIZE) / (double)(FFT_SIZE))

void smbPitchShift(float pitchShift, _Complex float *input, _Complex float *output) {

	/* ***************** PROCESSING ******************* */
	/* this does the actual pitch shifting */
  float gSynFreq[FFT_SIZE];
  float gSynMagn[FFT_SIZE];
	memset(gSynMagn, 0, FFT_SIZE*sizeof(float));
	memset(gSynFreq, 0, FFT_SIZE*sizeof(float));
	for (int k = 0; k <= FFT_SIZE2; k++) { 
		int index = k*pitchShift;
		if (index <= FFT_SIZE2) { 
			gSynMagn[index] += creal(input[k]);
			gSynFreq[index] = cimag(input[k]) * pitchShift;
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
		output[k] = magn*cos(phase) + I * magn*sin(phase);
	}
}

#endif // C_PROCESSOR_H_
