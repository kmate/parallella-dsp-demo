#include "processor.h"
#include <e-hal.h>
#include <e-loader.h>
#include <feldspar-parallella.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
void *thread_t5(void *unused);
host_chan_t chan4;
off_t la0 = 8192;
off_t la1 = 8208;
off_t sa2 = 16777216;
off_t la3 = 8192;
off_t la4 = 8208;
off_t la5 = 8224;
off_t la6 = 8192;
off_t la7 = 8208;
off_t la8 = 8224;
off_t la9 = 8192;
off_t la10 = 8208;
off_t la11 = 8224;
off_t la12 = 8192;
off_t la13 = 8208;
off_t la14 = 8224;
off_t la15 = 8192;
off_t la16 = 8208;
off_t la17 = 8224;
off_t la18 = 8192;
off_t la19 = 8208;
off_t la20 = 8224;
off_t la21 = 8192;
off_t la22 = 8208;
off_t la23 = 8224;
off_t la24 = 8192;
off_t la25 = 8208;
off_t la26 = 8224;
off_t la27 = 8192;
off_t la28 = 8208;
off_t la29 = 8224;
off_t la30 = 8192;
off_t la31 = 8208;
off_t la32 = 8224;
off_t la33 = 8192;
off_t la34 = 8208;
off_t la35 = 8224;
off_t la36 = 8192;
off_t la37 = 8208;
off_t la38 = 8224;
off_t la39 = 8192;
off_t la40 = 8208;
off_t la41 = 8224;
off_t la42 = 8192;
off_t la43 = 8208;
off_t la44 = 8224;
off_t la45 = 8192;
off_t la46 = 8208;
off_t la47 = 8224;
off_t la48 = 10272;
off_t la49 = 10288;
off_t sa50 = 16779264;
void *thread_t5(void *unused)
{
    bool r6;
    
    r6 = true;
    while (1) {
        bool v7;
        uint32_t r8;
        float _a9[512];
        float *a9 = _a9;
        bool v10;
        
        v7 = r6;
        if (!v7)
            break;
        r8 = 512;
        v10 = host_read_c2h(chan4, a9, 0, r8);
        if (v10) {
            bool v11;
            
            v11 = emit_samples(a9);
            r6 = v11;
            if (!v11) {
                host_close_chan(chan4);
            }
        } else {
            r6 = false;
        }
    }
    return NULL;
}
int main()
{
    e_epiphany_t group0;
    e_mem_t shm1;
    host_chan_t chan2;
    e_mem_t shm3;
    pthread_t t5;
    bool r12;
    
    e_init(0);
    e_reset_system();
    e_open(&group0, 0, 0, 4, 4);
    e_reset_group(&group0);
    setup_queues();
    e_alloc(&shm1, sa2, 2048);
    init_host_chan(&chan2, &group0, 0, 0, &shm1, la0, la1);
    init_core_chan(&group0, 0, 1, la3, la4);
    e_load("core0.srec", &group0, 0, 0, 1);
    init_core_chan(&group0, 0, 2, la6, la7);
    e_load("core1.srec", &group0, 0, 1, 1);
    init_core_chan(&group0, 0, 3, la9, la10);
    e_load("core2.srec", &group0, 0, 2, 1);
    init_core_chan(&group0, 1, 3, la12, la13);
    e_load("core3.srec", &group0, 0, 3, 1);
    init_core_chan(&group0, 1, 2, la15, la16);
    e_load("core7.srec", &group0, 1, 3, 1);
    init_core_chan(&group0, 1, 1, la18, la19);
    e_load("core6.srec", &group0, 1, 2, 1);
    init_core_chan(&group0, 1, 0, la21, la22);
    e_load("core5.srec", &group0, 1, 1, 1);
    init_core_chan(&group0, 2, 0, la24, la25);
    e_load("core4.srec", &group0, 1, 0, 1);
    init_core_chan(&group0, 2, 1, la27, la28);
    e_load("core8.srec", &group0, 2, 0, 1);
    init_core_chan(&group0, 2, 2, la30, la31);
    e_load("core9.srec", &group0, 2, 1, 1);
    init_core_chan(&group0, 2, 3, la33, la34);
    e_load("core10.srec", &group0, 2, 2, 1);
    init_core_chan(&group0, 3, 3, la36, la37);
    e_load("core11.srec", &group0, 2, 3, 1);
    init_core_chan(&group0, 3, 2, la39, la40);
    e_load("core15.srec", &group0, 3, 3, 1);
    init_core_chan(&group0, 3, 1, la42, la43);
    e_load("core14.srec", &group0, 3, 2, 1);
    init_core_chan(&group0, 3, 0, la45, la46);
    e_load("core13.srec", &group0, 3, 1, 1);
    e_alloc(&shm3, sa50, 2048);
    init_host_chan(&chan4, &group0, 3, 0, &shm3, la48, la49);
    e_load("core12.srec", &group0, 3, 0, 1);
    pthread_create(&t5, NULL, thread_t5, NULL);
    r12 = true;
    while (1) {
        bool v13;
        float _a14[512];
        float *a14 = _a14;
        bool v15;
        
        v13 = r12;
        if (!v13)
            break;
        v15 = receive_samples(a14);
        if (v15) {
            uint32_t r16;
            float _a17[512];
            float *a17 = _a17;
            uint32_t v18;
            bool v19;
            
            r16 = 512;
            for (v18 = 0; v18 < 512; v18++) {
                a17[v18] = a14[v18];
            }
            v19 = host_write_h2c(chan2, a17, 0, r16);
            r12 = v19;
        } else {
            r12 = false;
        }
    }
    host_close_chan(chan2);
    pthread_join(t5, NULL);
    teardown_queues();
    e_free(&shm1);
    e_free(&shm3);
    e_reset_group(&group0);
    e_close(&group0);
    e_finalize();
    return 0;
}
