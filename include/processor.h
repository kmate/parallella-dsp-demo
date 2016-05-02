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
float accumulator[FFT_SIZE + STEP_SIZE];

void setup_queues() {
  memset(in_queue, 0, FFT_SIZE * sizeof(float));
  memset(out_queue, 0, FFT_SIZE * sizeof(float));
  memset(accumulator, 0, (FFT_SIZE + STEP_SIZE) * sizeof(float));

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

void finish_loop(float *output, float *outdata) {
  static int last_done = 0;
  static float outFrame[BUFFER_SIZE];

  for(int k=0; k < FFT_SIZE; k++) {
    accumulator[k] += output[k];
  }
  memcpy(out_queue, accumulator, STEP_SIZE * sizeof(float));
  memcpy(outFrame + last_done, out_queue, STEP_SIZE * sizeof(float));
  memmove(accumulator, accumulator + STEP_SIZE, FFT_SIZE * sizeof(float));
  last_done += STEP_SIZE;

  if (BUFFER_SIZE == last_done) {
    last_done = 0;
    memcpy(outdata, outFrame, BUFFER_SIZE * sizeof(float));
  }
}

void smbPitchShift(float pitchShift, float *indata, float *outdata) {
  int gRover = IN_LATENCY;

	for (int i = 0; i < BUFFER_SIZE; i++) {
		in_queue[gRover] = indata[i];
		gRover++;

		if (gRover >= FFT_SIZE) {
      gRover = IN_LATENCY;

      float buffer[FFT_SIZE];
      memcpy(buffer, in_queue, FFT_SIZE * sizeof(float));
      memmove(in_queue, in_queue + STEP_SIZE, IN_LATENCY * sizeof(float));

      pitchShiftBody(pitchShift, buffer, buffer);

      finish_loop(buffer, outdata);
    }
  }
}

#endif // PROCESSOR_H_

