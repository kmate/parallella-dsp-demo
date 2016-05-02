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

#define DEBUG(...) // printf(__VA_ARGS__)

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

bool receive_samples(float *input) {
  static float inFrame[BUFFER_SIZE];
  static int cursor = IN_LATENCY;
  static int sample = BUFFER_SIZE;

  if (BUFFER_SIZE <= sample) {
    if (BUFFER_SIZE != fread(inFrame, sizeof(float), BUFFER_SIZE, dsp_in)) {
      printf("[Processor] Terminated (fread).\n");
      return false;
    }
    DEBUG("[Processor] Samples received.\n");

    cursor = IN_LATENCY;
    sample = 0;
  }

  for (; sample < BUFFER_SIZE; ++sample) {
    in_queue[cursor++] = inFrame[sample];
    if (FFT_SIZE <= cursor) {
      cursor = IN_LATENCY;
      memcpy(input, in_queue, FFT_SIZE * sizeof(float));
      memmove(in_queue, in_queue + STEP_SIZE, IN_LATENCY * sizeof(float));
      break;
    }
  }
  return true;
}

bool emit_samples(float *output) {
  static int last_done = 0;
  static float outFrame[BUFFER_SIZE];

  for (int k = 0; k < FFT_SIZE; ++k) {
    accumulator[k] += output[k];
  }
  memcpy(out_queue, accumulator, STEP_SIZE * sizeof(float));
  memcpy(outFrame + last_done, out_queue, STEP_SIZE * sizeof(float));
  memmove(accumulator, accumulator + STEP_SIZE, FFT_SIZE * sizeof(float));
  last_done += STEP_SIZE;

  if (BUFFER_SIZE < last_done) {
    last_done = 0;

    if (BUFFER_SIZE != fwrite(outFrame, sizeof(float), BUFFER_SIZE, dsp_out)) {
      printf("[Processor] Terminated (fwrite).\n");
      return false;
    }
    fflush(dsp_out);
    DEBUG("[Processor] Samples sent.\n");
  }
  return true;
}

#endif // PROCESSOR_H_

