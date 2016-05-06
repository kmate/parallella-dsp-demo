#include "processor.h"
#include <e-feldspar.h>
#include <e-hal.h>
#include <e-loader.h>
#include <stdbool.h>
#include <stdint.h>
off_t la0 = 8192;
off_t la1 = 8196;
off_t sa2 = 16777216;
off_t la3 = 8192;
off_t la4 = 8200;
off_t la5 = 8204;
off_t la6 = 8196;
off_t la7 = 8200;
off_t la8 = 8192;
off_t la9 = 16400;
off_t la10 = 16404;
off_t la11 = 8196;
off_t la12 = 8200;
off_t la13 = 8192;
off_t la14 = 16400;
off_t la15 = 16404;
off_t la16 = 8196;
off_t la17 = 8200;
off_t la18 = 8192;
off_t la19 = 12312;
off_t la20 = 12316;
off_t la21 = 8196;
off_t la22 = 8200;
off_t la23 = 8192;
off_t la24 = 12312;
off_t la25 = 12316;
off_t la26 = 8196;
off_t la27 = 8200;
off_t la28 = 8192;
off_t la29 = 16400;
off_t la30 = 16404;
off_t la31 = 8196;
off_t la32 = 8200;
off_t la33 = 16400;
off_t la34 = 16404;
off_t sa35 = 16781316;
int main()
{
    e_epiphany_t group0;
    e_mem_t shm1;
    uint32_t _a2[1];
    uint32_t *a2 = _a2;
    uint32_t _a3[1];
    uint32_t *a3 = _a3;
    uint32_t _a4[1];
    uint32_t *a4 = _a4;
    uint32_t _a5[1];
    uint32_t *a5 = _a5;
    uint32_t _a6[1];
    uint32_t *a6 = _a6;
    uint32_t _a7[1];
    uint32_t *a7 = _a7;
    uint32_t _a8[1];
    uint32_t *a8 = _a8;
    uint32_t _a9[1];
    uint32_t *a9 = _a9;
    uint32_t _a10[1];
    uint32_t *a10 = _a10;
    uint32_t _a11[1];
    uint32_t *a11 = _a11;
    uint32_t _a12[1];
    uint32_t *a12 = _a12;
    uint32_t _a13[1];
    uint32_t *a13 = _a13;
    uint32_t _a14[1];
    uint32_t *a14 = _a14;
    uint32_t _a15[1];
    uint32_t *a15 = _a15;
    uint32_t _a16[1];
    uint32_t *a16 = _a16;
    uint32_t _a17[1];
    uint32_t *a17 = _a17;
    uint32_t _a18[1];
    uint32_t *a18 = _a18;
    uint32_t _a19[1];
    uint32_t *a19 = _a19;
    uint32_t _a20[1];
    uint32_t *a20 = _a20;
    uint32_t _a21[1];
    uint32_t *a21 = _a21;
    uint32_t _a22[1];
    uint32_t *a22 = _a22;
    uint32_t _a23[1];
    uint32_t *a23 = _a23;
    uint32_t _a24[1];
    uint32_t *a24 = _a24;
    uint32_t _a25[1];
    uint32_t *a25 = _a25;
    uint32_t _a26[1];
    uint32_t *a26 = _a26;
    uint32_t _a27[1];
    uint32_t *a27 = _a27;
    e_mem_t shm28;
    uint32_t _a29[1];
    uint32_t *a29 = _a29;
    uint32_t _a30[1];
    uint32_t *a30 = _a30;
    bool r31;
    
    e_init(0);
    e_reset_system();
    e_open(&group0, 0, 0, 4, 4);
    e_reset_group(&group0);
    setup_queues();
    e_alloc(&shm1, sa2, 4100);
    a2[0] = 0;
    host_write_local(&group0, 0, 0, la0, a2, 0, 0, 0);
    a3[0] = 0;
    host_write_local(&group0, 0, 0, la1, a3, 0, 0, 0);
    a4[0] = 0;
    host_write_local(&group0, 0, 1, la3, a4, 0, 0, 0);
    a5[0] = 0;
    host_write_local(&group0, 0, 0, la4, a5, 0, 0, 0);
    a6[0] = 0;
    host_write_local(&group0, 0, 0, la5, a6, 0, 0, 0);
    a7[0] = 0;
    host_write_local(&group0, 0, 1, la6, a7, 0, 0, 0);
    e_load("core0.srec", &group0, 0, 0, 1);
    a8[0] = 0;
    host_write_local(&group0, 0, 2, la8, a8, 0, 0, 0);
    a9[0] = 0;
    host_write_local(&group0, 0, 1, la9, a9, 0, 0, 0);
    a10[0] = 0;
    host_write_local(&group0, 0, 1, la10, a10, 0, 0, 0);
    a11[0] = 0;
    host_write_local(&group0, 0, 2, la11, a11, 0, 0, 0);
    e_load("core1.srec", &group0, 0, 1, 1);
    a12[0] = 0;
    host_write_local(&group0, 0, 3, la13, a12, 0, 0, 0);
    a13[0] = 0;
    host_write_local(&group0, 0, 2, la14, a13, 0, 0, 0);
    a14[0] = 0;
    host_write_local(&group0, 0, 2, la15, a14, 0, 0, 0);
    a15[0] = 0;
    host_write_local(&group0, 0, 3, la16, a15, 0, 0, 0);
    e_load("core2.srec", &group0, 0, 2, 1);
    a16[0] = 0;
    host_write_local(&group0, 1, 0, la18, a16, 0, 0, 0);
    a17[0] = 0;
    host_write_local(&group0, 0, 3, la19, a17, 0, 0, 0);
    a18[0] = 0;
    host_write_local(&group0, 0, 3, la20, a18, 0, 0, 0);
    a19[0] = 0;
    host_write_local(&group0, 1, 0, la21, a19, 0, 0, 0);
    e_load("core3.srec", &group0, 0, 3, 1);
    a20[0] = 0;
    host_write_local(&group0, 1, 1, la23, a20, 0, 0, 0);
    a21[0] = 0;
    host_write_local(&group0, 1, 0, la24, a21, 0, 0, 0);
    a22[0] = 0;
    host_write_local(&group0, 1, 0, la25, a22, 0, 0, 0);
    a23[0] = 0;
    host_write_local(&group0, 1, 1, la26, a23, 0, 0, 0);
    e_load("core4.srec", &group0, 1, 0, 1);
    a24[0] = 0;
    host_write_local(&group0, 1, 2, la28, a24, 0, 0, 0);
    a25[0] = 0;
    host_write_local(&group0, 1, 1, la29, a25, 0, 0, 0);
    a26[0] = 0;
    host_write_local(&group0, 1, 1, la30, a26, 0, 0, 0);
    a27[0] = 0;
    host_write_local(&group0, 1, 2, la31, a27, 0, 0, 0);
    e_load("core5.srec", &group0, 1, 1, 1);
    e_alloc(&shm28, sa35, 4100);
    a29[0] = 0;
    host_write_local(&group0, 1, 2, la33, a29, 0, 0, 0);
    a30[0] = 0;
    host_write_local(&group0, 1, 2, la34, a30, 0, 0, 0);
    e_load("core6.srec", &group0, 1, 2, 1);
    r31 = true;
    while (1) {
        bool v32;
        float _a33[1024];
        float *a33 = _a33;
        bool v34;
        uint32_t r35;
        float _a36[1024];
        float *a36 = _a36;
        uint32_t v37;
        uint32_t r38;
        
        v32 = r31;
        if (!v32)
            break;
        v34 = receive_samples(a33);
        r35 = 1024;
        for (v37 = 0; v37 < 1024; v37++) {
            a36[v37] = a33[v37];
        }
        r38 = 0;
        while (1) {
            uint32_t v39;
            uint32_t v40;
            uint32_t _a45[1];
            uint32_t *a45 = _a45;
            uint32_t v46;
            uint32_t _a47[1];
            uint32_t *a47 = _a47;
            uint32_t v48;
            uint32_t _a49[1];
            uint32_t *a49 = _a49;
            
            v39 = r38;
            if (!(v39 < 1024))
                break;
            v40 = r38;
            while (1) {
                uint32_t _a41[1];
                uint32_t *a41 = _a41;
                uint32_t v42;
                uint32_t _a43[1];
                uint32_t *a43 = _a43;
                uint32_t v44;
                
                host_read_local(&group0, 0, 0, la0, a41, 0, 0, 0);
                v42 = a41[0];
                host_read_local(&group0, 0, 0, la1, a43, 0, 0, 0);
                v44 = a43[0];
                if (!((v44 + 1) % 1025 == v42))
                    break;
            }
            host_read_local(&group0, 0, 0, la0, a45, 0, 0, 0);
            v46 = a45[0];
            host_read_local(&group0, 0, 0, la1, a47, 0, 0, 0);
            v48 = a47[0];
            if (v48 + (-v40 + 1024 <= -((v48 + 1025 - v46) % 1025) +
                       1024 ? -v40 + 1024 : -((v48 + 1025 - v46) % 1025) +
                       1024) <= 1025) {
                host_write_shared(&shm1, a36, v48, v40, v40 + (-v40 + 1024 <=
                                                               -((v48 + 1025 -
                                                                  v46) % 1025) +
                                                               1024 ? -v40 +
                                                               1024 : -((v48 +
                                                                         1025 -
                                                                         v46) %
                                                                        1025) +
                                                               1024) - 1);
            } else {
                host_write_shared(&shm1, a36, v48, v40, v40 + (-v48 + 1025) -
                                  1);
                host_write_shared(&shm1, a36, 0, v40 + (-v48 + 1025), v40 +
                                  (-v48 + 1025) + ((-v40 + 1024 <= -((v48 +
                                                                      1025 -
                                                                      v46) %
                                                                     1025) +
                                                    1024 ? -v40 +
                                                    1024 : -((v48 + 1025 -
                                                              v46) % 1025) +
                                                    1024) - (-v48 + 1025)) - 1);
            }
            a49[0] = (v48 + (-v40 + 1024 <= -((v48 + 1025 - v46) % 1025) +
                             1024 ? -v40 + 1024 : -((v48 + 1025 - v46) % 1025) +
                             1024)) % 1025;
            host_write_local(&group0, 0, 0, la1, a49, 0, 0, 0);
            r38 = v40 + (-v40 + 1024 <= -((v48 + 1025 - v46) % 1025) +
                         1024 ? -v40 + 1024 : -((v48 + 1025 - v46) % 1025) +
                         1024);
        }
        if (v34) {
            float _a50[1024];
            float *a50 = _a50;
            uint32_t r51;
            uint32_t _a63[1];
            uint32_t *a63 = _a63;
            uint32_t v64;
            uint32_t _a65[1];
            uint32_t *a65 = _a65;
            uint32_t v66;
            uint32_t r69;
            uint32_t v71;
            bool v72;
            
            r51 = 0;
            while (1) {
                uint32_t v52;
                uint32_t v53;
                uint32_t _a58[1];
                uint32_t *a58 = _a58;
                uint32_t v59;
                uint32_t _a60[1];
                uint32_t *a60 = _a60;
                uint32_t v61;
                uint32_t _a62[1];
                uint32_t *a62 = _a62;
                
                v52 = r51;
                if (!(v52 < 1024))
                    break;
                v53 = r51;
                while (1) {
                    uint32_t _a54[1];
                    uint32_t *a54 = _a54;
                    uint32_t v55;
                    uint32_t _a56[1];
                    uint32_t *a56 = _a56;
                    uint32_t v57;
                    
                    host_read_local(&group0, 1, 2, la33, a54, 0, 0, 0);
                    v55 = a54[0];
                    host_read_local(&group0, 1, 2, la34, a56, 0, 0, 0);
                    v57 = a56[0];
                    if (!(v55 == v57))
                        break;
                }
                host_read_local(&group0, 1, 2, la33, a58, 0, 0, 0);
                v59 = a58[0];
                host_read_local(&group0, 1, 2, la34, a60, 0, 0, 0);
                v61 = a60[0];
                if (v59 + (-v53 + 1024 <= (v61 + 1025 - v59) % 1025 ? -v53 +
                           1024 : (v61 + 1025 - v59) % 1025) <= 1025) {
                    host_read_shared(&shm28, a50, v59, v53, v53 + (-v53 +
                                                                   1024 <=
                                                                   (v61 + 1025 -
                                                                    v59) %
                                                                   1025 ? -v53 +
                                                                   1024 : (v61 +
                                                                           1025 -
                                                                           v59) %
                                                                   1025) - 1);
                } else {
                    host_read_shared(&shm28, a50, v59, v53, v53 + (-v59 +
                                                                   1025) - 1);
                    host_read_shared(&shm28, a50, 0, v53 + (-v59 + 1025), v53 +
                                     (-v59 + 1025) + (-v53 + 1024 <= (v61 +
                                                                      1025 -
                                                                      v59) %
                                                      1025 ? -v53 +
                                                      1024 : (v61 + 1025 -
                                                              v59) % 1025) -
                                     (-v59 + 1025) - 1);
                }
                a62[0] = (v59 + (-v53 + 1024 <= (v61 + 1025 - v59) %
                                 1025 ? -v53 + 1024 : (v61 + 1025 - v59) %
                                 1025)) % 1025;
                host_write_local(&group0, 1, 2, la33, a62, 0, 0, 0);
                r51 = v53 + (-v53 + 1024 <= (v61 + 1025 - v59) % 1025 ? -v53 +
                             1024 : (v61 + 1025 - v59) % 1025);
            }
            host_read_local(&group0, 1, 2, la33, a63, 0, 0, 0);
            v64 = a63[0];
            host_read_local(&group0, 1, 2, la34, a65, 0, 0, 0);
            v66 = a65[0];
            if (v64 == v66 && v66 == 1024) {
                uint32_t _a67[1];
                uint32_t *a67 = _a67;
                uint32_t _a68[1];
                uint32_t *a68 = _a68;
                
                a67[0] = 0;
                host_write_local(&group0, 1, 2, la33, a67, 0, 0, 0);
                a68[0] = 0;
                host_write_local(&group0, 1, 2, la34, a68, 0, 0, 0);
            }
            r69 = 1024;
            
            float _a70[r69];
            float *a70 = _a70;
            
            for (v71 = 0; v71 < r69; v71++) {
                a70[v71] = a50[v71];
            }
            v72 = emit_samples(a70);
            if (!v72) {
                r31 = false;
            }
        } else {
            r31 = false;
        }
    }
    teardown_queues();
    e_free(&shm1);
    e_free(&shm28);
    e_reset_group(&group0);
    e_close(&group0);
    e_finalize();
    return 0;
}
