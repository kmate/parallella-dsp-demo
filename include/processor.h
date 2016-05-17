#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <semaphore.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
#define STEP_SIZE   ((FFT_SIZE) / (OVERLAP))
#define IN_LATENCY  ((FFT_SIZE) - (STEP_SIZE))

float in_queue[FFT_SIZE];
float accumulator[FFT_SIZE + STEP_SIZE];

bool hasMore = true;

sem_t can_read;
sem_t can_write;

void setup_queues() {
  memset(in_queue, 0, FFT_SIZE * sizeof(float));
  memset(accumulator, 0, (FFT_SIZE + STEP_SIZE) * sizeof(float));

  if(sem_init(&can_read, 0, 1) || sem_init(&can_write, 0, 0))
  {
    perror("[Processor] sem_init\n");
    exit(2);
  }

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
  static int window_start = BUFFER_SIZE;
  static float inFrame[BUFFER_SIZE];

  DEBUG("[Processor] Waiting reader lock.\n");
  sem_wait(&can_read);

  DEBUG("[Processor] Receive samples.\n");
  if (BUFFER_SIZE == window_start) {
    window_start = 0;

    DEBUG("[Processor] Reader blocks now.\n");
    if (BUFFER_SIZE != fread(inFrame, sizeof(float), BUFFER_SIZE, dsp_in)) {
      printf("[Processor] Terminated (fread).\n");

      sem_post(&can_write);
      DEBUG("[Processor] Released writer lock.\n");

      hasMore = false;
      return false;
    }
    DEBUG("[Processor] Samples received from pipe.\n");
  }

  memcpy(in_queue + IN_LATENCY, inFrame + window_start, STEP_SIZE * sizeof(float));
  memcpy(input, in_queue, FFT_SIZE * sizeof(float));
  memmove(in_queue, in_queue + STEP_SIZE, IN_LATENCY * sizeof(float));
  window_start += STEP_SIZE;

  sem_post(&can_write);
  DEBUG("[Processor] Released writer lock.\n");
  return hasMore;
}

bool emit_samples(float *output) {
  static int window_start = 0;
  static float outFrame[BUFFER_SIZE];

  DEBUG("[Processor] Waiting writer lock.\n");
  sem_wait(&can_write);

  DEBUG("[Processor] Emit samples.\n");
  for(int k=0; k < FFT_SIZE; k++) {
    accumulator[k] += output[k];
  }
  memcpy(outFrame + window_start, accumulator, STEP_SIZE * sizeof(float));
  memmove(accumulator, accumulator + STEP_SIZE, FFT_SIZE * sizeof(float));
  window_start += STEP_SIZE;

  if (BUFFER_SIZE <= window_start) {
    window_start = 0;

    DEBUG("[Processor] Writer blocks now.\n");
    if (BUFFER_SIZE != fwrite(outFrame, sizeof(float), BUFFER_SIZE, dsp_out)) {
      printf("[Processor] Terminated (fwrite).\n");

      sem_post(&can_read);
      DEBUG("[Processor] Released reader lock.\n");

      hasMore = false;
      return false;
    }
    fflush(dsp_out);
    DEBUG("[Processor] Samples emitted to pipe.\n");
  }

  sem_post(&can_read);
  DEBUG("[Processor] Released reader lock.\n");
  return hasMore;
}

#endif // PROCESSOR_H_

