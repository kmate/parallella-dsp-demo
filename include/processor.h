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
#define STEP_SIZE   ((FFT_SIZE) / (OVERLAP))
#define IN_LATENCY  ((FFT_SIZE) - (STEP_SIZE))

float in_queue[FFT_SIZE];
float out_queue[FFT_SIZE];
float accumulator[2 * FFT_SIZE];

void setup_queues() {
  memset(in_queue, 0, FFT_SIZE * sizeof(float));
  memset(out_queue, 0, FFT_SIZE * sizeof(float));
  memset(accumulator, 0, 2 * FFT_SIZE * sizeof(float));

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
	int gRover = IN_LATENCY;

    /* main processing loop */
	for (int i = 0; i < BUFFER_SIZE; i++) {

		/* As long as we have not yet collected enough data just read in */
		in_queue[gRover] = indata[i];
		outdata[i] = out_queue[gRover - IN_LATENCY];
		gRover++;

		/* now we have enough data for processing */
		if (gRover >= FFT_SIZE) {
		
			gRover = IN_LATENCY;

pitchShiftBody(pitchShift, FFT_SIZE, OVERLAP, SAMPLE_RATE, in_queue, accumulator);

            /* copy accum to out fifo */
			memcpy(out_queue, accumulator, STEP_SIZE * sizeof(float));

			/* shift accumulator */
			memmove(accumulator, accumulator + STEP_SIZE, FFT_SIZE * sizeof(float));

			/* move input FIFO */
			memmove(in_queue, in_queue + STEP_SIZE, IN_LATENCY * sizeof(float));
		}
	}
}


#endif // PROCESSOR_H_

