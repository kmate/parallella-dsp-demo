#include "dsp.h"
#include "mongoose.h"
#include <stdio.h>
#include <string.h>


static sig_atomic_t s_signal_received = 0;
static const char *s_http_port = "8000";
static struct mg_serve_http_opts s_http_server_opts;

static void signal_handler(int sig_num) {
  signal(sig_num, signal_handler);  // Reinstantiate signal handler
  s_signal_received = sig_num;
}

#define BUFFER_SIZE 1024
float input[BUFFER_SIZE];
float output[BUFFER_SIZE];

static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
  switch (ev) {
    case MG_EV_HTTP_REQUEST:
      mg_serve_http(nc, (struct http_message *)ev_data, s_http_server_opts);
      break;
    case MG_EV_WEBSOCKET_HANDSHAKE_DONE: {
      printf("Connected!\n");
      break;
    }
    case MG_EV_WEBSOCKET_FRAME: {
      struct websocket_message *wm = (struct websocket_message *)ev_data;
      memcpy(input, wm->data, wm->size);
      process_samples(input, output, BUFFER_SIZE);
      mg_send_websocket_frame(nc, WEBSOCKET_OP_BINARY, output, BUFFER_SIZE * sizeof(float));
      break;
    }
  }
}

int main(void) {
  struct mg_mgr mgr;
  struct mg_connection *nc;

  signal(SIGTERM, signal_handler);
  signal(SIGINT, signal_handler);

  mg_mgr_init(&mgr, NULL);

  nc = mg_bind(&mgr, s_http_port, ev_handler);
  s_http_server_opts.document_root = "htdocs";
  mg_set_protocol_http_websocket(nc);

  printf("Started on port %s\n", s_http_port);
  while (0 == s_signal_received) {
    mg_mgr_poll(&mgr, 200);
  }
  mg_mgr_free(&mgr);

  return 0;
}

