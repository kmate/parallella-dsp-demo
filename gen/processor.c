#include "c_processor.h"
#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
void *thread_t2(void *unused);
void *thread_t20(void *unused);
pthread_t t2;
pthread_t t20;
chan_t chan0;
chan_t chan1;
#define FELD_PI 3.141592653589793
void *thread_t2(void *unused)
{
    while (1) {
        uint32_t v3;
        bool v5;
        uint32_t r6;
        uint32_t v7;
        bool v9;
        uint32_t v11;
        uint32_t r13;
        uint32_t v15;
        uint32_t v16;
        uint32_t v17;
        bool v18;
        bool v19;
        
        chan_read(chan0, sizeof(v3), &v3);
        
        float _a4[v3];
        float *a4 = _a4;
        
        chan_read(chan0, sizeof(*a4) * (v3 - 0), &a4[0]);
        v5 = chan_last_read_ok(chan0);
        r6 = v3;
        v7 = r6;
        
        float _a8[v7];
        float *a8 = _a8;
        
        memcpy(a8, a4, v7 * sizeof(float));
        v9 = chan_last_read_ok(chan0);
        if (!v9) {
            chan_close(chan1);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
        
        float _Complex _a10[v7 <= 1024 ? v7 : 1024];
        float _Complex *a10 = _a10;
        
        for (v11 = 0; v11 < (v7 <= 1024 ? v7 : 1024); v11++) {
            a10[v11] = a8[v11] * (-(0.5 * cos(2.0 * FELD_PI * (float) v11 /
                                    1024.0)) + 0.5);
        }
        
        float _a12[v7 <= 1024 ? v7 : 1024];
        float *a12 = _a12;
        
        smbPitchShift(2.0, a10, a12);
        r13 = v7 <= 1024 ? v7 : 1024;
        
        float _a14[v7 <= 1024 ? v7 : 1024];
        float *a14 = _a14;
        
        for (v15 = 0; v15 < (v7 <= 1024 ? v7 : 1024); v15++) {
            a14[v15] = a12[v15];
        }
        v16 = r13;
        v17 = v16;
        v18 = chan_write(chan1, sizeof(v17), &v17);
        v19 = chan_write(chan1, sizeof(*a14) * (v16 - 0), &a14[0]);
        if (!v19) {
            chan_close(chan0);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
    }
    chan_close(chan0);
    chan_close(chan1);
    return NULL;
}
void *thread_t20(void *unused)
{
    while (1) {
        uint32_t v21;
        bool v23;
        uint32_t r24;
        uint32_t v25;
        bool v27;
        uint32_t v29;
        bool v30;
        
        chan_read(chan1, sizeof(v21), &v21);
        
        float _a22[v21];
        float *a22 = _a22;
        
        chan_read(chan1, sizeof(*a22) * (v21 - 0), &a22[0]);
        v23 = chan_last_read_ok(chan1);
        r24 = v21;
        v25 = r24;
        
        float _a26[v25];
        float *a26 = _a26;
        
        memcpy(a26, a22, v25 * sizeof(float));
        v27 = chan_last_read_ok(chan1);
        if (!v27) {
            pthread_cancel(t20);
            pthread_join(t20, NULL);
        }
        
        float _a28[v25];
        float *a28 = _a28;
        
        for (v29 = 0; v29 < v25; v29++) {
            a28[v29] = a26[v29];
        }
        v30 = emit_samples(a28);
        if (!v30) {
            chan_close(chan1);
            pthread_cancel(t20);
            pthread_join(t20, NULL);
        }
    }
    return NULL;
}
int main()
{
    setup_queues();
    chan0 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 * sizeof(float)));
    chan1 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 * sizeof(float)));
    pthread_create(&t2, NULL, thread_t2, NULL);
    pthread_create(&t20, NULL, thread_t20, NULL);
    while (1) {
        float _a31[1024];
        float *a31 = _a31;
        bool v32;
        uint32_t r33;
        float _a34[1024];
        float *a34 = _a34;
        uint32_t v35;
        uint32_t v36;
        uint32_t v37;
        bool v38;
        bool v39;
        
        v32 = receive_samples(a31);
        if (!v32) {
            break;
        }
        r33 = 1024;
        for (v35 = 0; v35 < 1024; v35++) {
            a34[v35] = a31[v35];
        }
        v36 = r33;
        v37 = v36;
        v38 = chan_write(chan0, sizeof(v37), &v37);
        v39 = chan_write(chan0, sizeof(*a34) * (v36 - 0), &a34[0]);
        if (!v39) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t20, NULL);
    teardown_queues();
    return 0;
}

