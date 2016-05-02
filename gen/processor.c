#include "c_processor.h"
#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
void *thread_t2(void *unused);
void *thread_t19(void *unused);
pthread_t t19;
pthread_t t2;
chan_t chan0;
chan_t chan1;
void *thread_t2(void *unused)
{
    while (1) {
        uint32_t v3;
        bool v5;
        uint32_t r6;
        uint32_t v7;
        bool v9;
        uint32_t v11;
        uint32_t r12;
        uint32_t v14;
        uint32_t v15;
        uint32_t v16;
        bool v17;
        bool v18;
        
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
        
        float _a10[v7];
        float *a10 = _a10;
        
        for (v11 = 0; v11 < v7; v11++) {
            a10[v11] = a8[v11];
        }
        smbPitchShift(2.0, a10, a10);
        r12 = v7;
        
        float _a13[v7];
        float *a13 = _a13;
        
        for (v14 = 0; v14 < v7; v14++) {
            a13[v14] = a10[v14];
        }
        v15 = r12;
        v16 = v15;
        v17 = chan_write(chan1, sizeof(v16), &v16);
        v18 = chan_write(chan1, sizeof(*a13) * (v15 - 0), &a13[0]);
        if (!v18) {
            chan_close(chan0);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
    }
    chan_close(chan0);
    chan_close(chan1);
    return NULL;
}
void *thread_t19(void *unused)
{
    while (1) {
        uint32_t v20;
        bool v22;
        uint32_t r23;
        uint32_t v24;
        bool v26;
        uint32_t v28;
        bool v29;
        
        chan_read(chan1, sizeof(v20), &v20);
        
        float _a21[v20];
        float *a21 = _a21;
        
        chan_read(chan1, sizeof(*a21) * (v20 - 0), &a21[0]);
        v22 = chan_last_read_ok(chan1);
        r23 = v20;
        v24 = r23;
        
        float _a25[v24];
        float *a25 = _a25;
        
        memcpy(a25, a21, v24 * sizeof(float));
        v26 = chan_last_read_ok(chan1);
        if (!v26) {
            pthread_cancel(t19);
            pthread_join(t19, NULL);
        }
        
        float _a27[v24];
        float *a27 = _a27;
        
        for (v28 = 0; v28 < v24; v28++) {
            a27[v28] = a25[v28];
        }
        v29 = emit_samples(a27);
        if (!v29) {
            chan_close(chan1);
            pthread_cancel(t19);
            pthread_join(t19, NULL);
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
    pthread_create(&t19, NULL, thread_t19, NULL);
    while (1) {
        float _a30[1024];
        float *a30 = _a30;
        bool v31;
        uint32_t r32;
        float _a33[1024];
        float *a33 = _a33;
        uint32_t v34;
        uint32_t v35;
        uint32_t v36;
        bool v37;
        bool v38;
        
        v31 = receive_samples(a30);
        if (!v31) {
            break;
        }
        r32 = 1024;
        for (v34 = 0; v34 < 1024; v34++) {
            a33[v34] = a30[v34];
        }
        v35 = r32;
        v36 = v35;
        v37 = chan_write(chan0, sizeof(v36), &v36);
        v38 = chan_write(chan0, sizeof(*a33) * (v35 - 0), &a33[0]);
        if (!v38) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t19, NULL);
    teardown_queues();
    return 0;
}

