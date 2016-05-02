#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

#define DSP_FIFO_IN  "dsp_in.fifo"
#define DSP_FIFO_OUT "dsp_out.fifo"
FILE *dsp_in;
FILE *dsp_out;

#define DEBUG(x) // printf(x)

#define BUFFER_SIZE 1024
#define FFT_SIZE    1024
#define OVERLAP     4
#define SAMPLE_RATE 44100

float gInFIFO[FFT_SIZE];
float gOutFIFO[FFT_SIZE];
float gOutputAccum[2 * FFT_SIZE];

void setup_queues() {
  memset(gInFIFO, 0, FFT_SIZE * sizeof(float));
  memset(gOutFIFO, 0, FFT_SIZE * sizeof(float));
  memset(gOutputAccum, 0, 2 * FFT_SIZE * sizeof(float));

  mkfifo(DSP_FIFO_IN, S_IRUSR | S_IWUSR);
  if (NULL == (dsp_in = fopen(DSP_FIFO_IN, "r"))) {
    perror("[Processor] fopen("DSP_FIFO_IN")");
    exit(2);
  }

  mkfifo(DSP_FIFO_OUT, S_IRUSR | S_IWUSR);
  if (NULL == (dsp_out = fopen(DSP_FIFO_OUT, "w"))) {
    perror("[Processor] fopen("DSP_FIFO_OUT")");
    exit(2);
  }
  printf("[Processor] Started.\n");
}

void teardown_queues() {
  fclose(dsp_in);
  fclose(dsp_out);
}

bool receive_samples(void *input, size_t length) {
  if (length != fread(input, sizeof(float), length, dsp_in)) {
    printf("[Processor] Terminated (fread).\n");
    return false;
  }
  DEBUG("[Processor] Samples received.\n");
  return true;
}

bool emit_samples(void *output, size_t length) {
  if (length != fwrite(output, sizeof(float), length, dsp_out)) {
    printf("[Processor] Terminated (fwrite).\n");
    return false;
  }
  fflush(dsp_out);
  DEBUG("[Processor] Samples sent.\n");
  return true;
}

////////////////////////////////////////////////////////////////////////////////

void smbPitchShift(float pitchShift, float *indata, float *outdata) {
	/* set up some handy variables */
	int stepSize = FFT_SIZE/OVERLAP;
	int inFifoLatency = FFT_SIZE-stepSize;
	int gRover = inFifoLatency;

	/* main processing loop */
	for (int i = 0; i < BUFFER_SIZE; i++){

		/* As long as we have not yet collected enough data just read in */
		gInFIFO[gRover] = indata[i];
		outdata[i] = gOutFIFO[gRover-inFifoLatency];
		gRover++;

		/* now we have enough data for processing */
		if (gRover >= FFT_SIZE) {
		
			gRover = inFifoLatency;

pitchShiftBody(pitchShift, FFT_SIZE, OVERLAP, SAMPLE_RATE, gInFIFO, gOutputAccum);

			memcpy(gOutFIFO, gOutputAccum, stepSize*sizeof(float));

			/* shift accumulator */
			memmove(gOutputAccum, gOutputAccum+stepSize, FFT_SIZE*sizeof(float));

			/* move input FIFO */
			memmove(gInFIFO, gInFIFO+stepSize, inFifoLatency*sizeof(float));
		}
	}
}


#endif // PROCESSOR_H_

