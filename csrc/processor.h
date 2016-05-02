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

void setup_queues() {
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


#endif // PROCESSOR_H_

