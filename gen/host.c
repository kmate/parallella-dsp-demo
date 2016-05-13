#include "processor.h"
#include <e-feldspar.h>
#include <e-hal.h>
#include <e-loader.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
off_t la0 = 8192;
off_t la1 = 8196;
off_t sa2 = 16777216;
off_t la3 = 8192;
off_t la4 = 8200;
off_t la5 = 8204;
off_t la6 = 8196;
off_t la7 = 8200;
off_t la8 = 8192;
off_t la9 = 10256;
off_t la10 = 10260;
off_t la11 = 8196;
off_t la12 = 8200;
off_t la13 = 8192;
off_t la14 = 10256;
off_t la15 = 10260;
off_t la16 = 8196;
off_t la17 = 8200;
off_t la18 = 8192;
off_t la19 = 10256;
off_t la20 = 10260;
off_t la21 = 8196;
off_t la22 = 8200;
off_t la23 = 8192;
off_t la24 = 10256;
off_t la25 = 10260;
off_t la26 = 8196;
off_t la27 = 8200;
off_t la28 = 8192;
off_t la29 = 10256;
off_t la30 = 10260;
off_t la31 = 8196;
off_t la32 = 8200;
off_t la33 = 8192;
off_t la34 = 10256;
off_t la35 = 10260;
off_t la36 = 8196;
off_t la37 = 8200;
off_t la38 = 8192;
off_t la39 = 10256;
off_t la40 = 10260;
off_t la41 = 8196;
off_t la42 = 8200;
off_t la43 = 8192;
off_t la44 = 10256;
off_t la45 = 10260;
off_t la46 = 8196;
off_t la47 = 8200;
off_t la48 = 8192;
off_t la49 = 10256;
off_t la50 = 10260;
off_t la51 = 8196;
off_t la52 = 8200;
off_t la53 = 8192;
off_t la54 = 10256;
off_t la55 = 10260;
off_t la56 = 8196;
off_t la57 = 8200;
off_t la58 = 8192;
off_t la59 = 10256;
off_t la60 = 10260;
off_t la61 = 8196;
off_t la62 = 8200;
off_t la63 = 9228;
off_t la64 = 9232;
off_t sa65 = 16778244;
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
    uint32_t _a28[1];
    uint32_t *a28 = _a28;
    uint32_t _a29[1];
    uint32_t *a29 = _a29;
    uint32_t _a30[1];
    uint32_t *a30 = _a30;
    uint32_t _a31[1];
    uint32_t *a31 = _a31;
    uint32_t _a32[1];
    uint32_t *a32 = _a32;
    uint32_t _a33[1];
    uint32_t *a33 = _a33;
    uint32_t _a34[1];
    uint32_t *a34 = _a34;
    uint32_t _a35[1];
    uint32_t *a35 = _a35;
    uint32_t _a36[1];
    uint32_t *a36 = _a36;
    uint32_t _a37[1];
    uint32_t *a37 = _a37;
    uint32_t _a38[1];
    uint32_t *a38 = _a38;
    uint32_t _a39[1];
    uint32_t *a39 = _a39;
    uint32_t _a40[1];
    uint32_t *a40 = _a40;
    uint32_t _a41[1];
    uint32_t *a41 = _a41;
    uint32_t _a42[1];
    uint32_t *a42 = _a42;
    uint32_t _a43[1];
    uint32_t *a43 = _a43;
    uint32_t _a44[1];
    uint32_t *a44 = _a44;
    uint32_t _a45[1];
    uint32_t *a45 = _a45;
    uint32_t _a46[1];
    uint32_t *a46 = _a46;
    uint32_t _a47[1];
    uint32_t *a47 = _a47;
    uint32_t _a48[1];
    uint32_t *a48 = _a48;
    uint32_t _a49[1];
    uint32_t *a49 = _a49;
    uint32_t _a50[1];
    uint32_t *a50 = _a50;
    uint32_t _a51[1];
    uint32_t *a51 = _a51;
    e_mem_t shm52;
    uint32_t _a53[1];
    uint32_t *a53 = _a53;
    uint32_t _a54[1];
    uint32_t *a54 = _a54;
    bool r55;
    
    e_init(0);
    e_reset_system();
    e_open(&group0, 0, 0, 4, 4);
    e_reset_group(&group0);
    setup_queues();
    e_alloc(&shm1, sa2, 1028);
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
    host_write_local(&group0, 1, 3, la18, a16, 0, 0, 0);
    a17[0] = 0;
    host_write_local(&group0, 0, 3, la19, a17, 0, 0, 0);
    a18[0] = 0;
    host_write_local(&group0, 0, 3, la20, a18, 0, 0, 0);
    a19[0] = 0;
    host_write_local(&group0, 1, 3, la21, a19, 0, 0, 0);
    e_load("core3.srec", &group0, 0, 3, 1);
    a20[0] = 0;
    host_write_local(&group0, 1, 2, la23, a20, 0, 0, 0);
    a21[0] = 0;
    host_write_local(&group0, 1, 3, la24, a21, 0, 0, 0);
    a22[0] = 0;
    host_write_local(&group0, 1, 3, la25, a22, 0, 0, 0);
    a23[0] = 0;
    host_write_local(&group0, 1, 2, la26, a23, 0, 0, 0);
    e_load("core7.srec", &group0, 1, 3, 1);
    a24[0] = 0;
    host_write_local(&group0, 2, 1, la28, a24, 0, 0, 0);
    a25[0] = 0;
    host_write_local(&group0, 1, 2, la29, a25, 0, 0, 0);
    a26[0] = 0;
    host_write_local(&group0, 1, 2, la30, a26, 0, 0, 0);
    a27[0] = 0;
    host_write_local(&group0, 2, 1, la31, a27, 0, 0, 0);
    e_load("core6.srec", &group0, 1, 2, 1);
    a28[0] = 0;
    host_write_local(&group0, 2, 2, la33, a28, 0, 0, 0);
    a29[0] = 0;
    host_write_local(&group0, 2, 1, la34, a29, 0, 0, 0);
    a30[0] = 0;
    host_write_local(&group0, 2, 1, la35, a30, 0, 0, 0);
    a31[0] = 0;
    host_write_local(&group0, 2, 2, la36, a31, 0, 0, 0);
    e_load("core9.srec", &group0, 2, 1, 1);
    a32[0] = 0;
    host_write_local(&group0, 2, 3, la38, a32, 0, 0, 0);
    a33[0] = 0;
    host_write_local(&group0, 2, 2, la39, a33, 0, 0, 0);
    a34[0] = 0;
    host_write_local(&group0, 2, 2, la40, a34, 0, 0, 0);
    a35[0] = 0;
    host_write_local(&group0, 2, 3, la41, a35, 0, 0, 0);
    e_load("core10.srec", &group0, 2, 2, 1);
    a36[0] = 0;
    host_write_local(&group0, 3, 3, la43, a36, 0, 0, 0);
    a37[0] = 0;
    host_write_local(&group0, 2, 3, la44, a37, 0, 0, 0);
    a38[0] = 0;
    host_write_local(&group0, 2, 3, la45, a38, 0, 0, 0);
    a39[0] = 0;
    host_write_local(&group0, 3, 3, la46, a39, 0, 0, 0);
    e_load("core11.srec", &group0, 2, 3, 1);
    a40[0] = 0;
    host_write_local(&group0, 3, 2, la48, a40, 0, 0, 0);
    a41[0] = 0;
    host_write_local(&group0, 3, 3, la49, a41, 0, 0, 0);
    a42[0] = 0;
    host_write_local(&group0, 3, 3, la50, a42, 0, 0, 0);
    a43[0] = 0;
    host_write_local(&group0, 3, 2, la51, a43, 0, 0, 0);
    e_load("core15.srec", &group0, 3, 3, 1);
    a44[0] = 0;
    host_write_local(&group0, 3, 1, la53, a44, 0, 0, 0);
    a45[0] = 0;
    host_write_local(&group0, 3, 2, la54, a45, 0, 0, 0);
    a46[0] = 0;
    host_write_local(&group0, 3, 2, la55, a46, 0, 0, 0);
    a47[0] = 0;
    host_write_local(&group0, 3, 1, la56, a47, 0, 0, 0);
    e_load("core14.srec", &group0, 3, 2, 1);
    a48[0] = 0;
    host_write_local(&group0, 3, 0, la58, a48, 0, 0, 0);
    a49[0] = 0;
    host_write_local(&group0, 3, 1, la59, a49, 0, 0, 0);
    a50[0] = 0;
    host_write_local(&group0, 3, 1, la60, a50, 0, 0, 0);
    a51[0] = 0;
    host_write_local(&group0, 3, 0, la61, a51, 0, 0, 0);
    e_load("core13.srec", &group0, 3, 1, 1);
    e_alloc(&shm52, sa65, 1028);
    a53[0] = 0;
    host_write_local(&group0, 3, 0, la63, a53, 0, 0, 0);
    a54[0] = 0;
    host_write_local(&group0, 3, 0, la64, a54, 0, 0, 0);
    e_load("core12.srec", &group0, 3, 0, 1);
    r55 = true;
    while (1) {
        bool v56;
        float _a57[256];
        float *a57 = _a57;
        bool v58;
        uint32_t r59;
        float _a60[256];
        float *a60 = _a60;
        uint32_t v61;
        uint32_t r62;
        
        v56 = r55;
        if (!v56)
            break;
        v58 = receive_samples(a57);
        r59 = 256;
        for (v61 = 0; v61 < 256; v61++) {
            a60[v61] = a57[v61];
        }
        r62 = 0;
        while (1) {
            uint32_t v63;
            uint32_t v64;
            uint32_t _a70[1];
            uint32_t *a70 = _a70;
            uint32_t v71;
            uint32_t _a72[1];
            uint32_t *a72 = _a72;
            uint32_t v73;
            uint32_t let74;
            uint32_t r75;
            uint32_t r76;
            uint32_t let77;
            uint32_t r78;
            uint32_t let81;
            uint32_t r82;
            uint32_t _a83[1];
            uint32_t *a83 = _a83;
            
            v63 = r62;
            if (!(v63 < 256))
                break;
            v64 = r62;
            while (1) {
                uint32_t _a65[1];
                uint32_t *a65 = _a65;
                uint32_t v66;
                uint32_t _a67[1];
                uint32_t *a67 = _a67;
                uint32_t v68;
                uint32_t let69;
                
                host_read_local(&group0, 0, 0, la0, a65, 0, 0, 0);
                v66 = a65[0];
                host_read_local(&group0, 0, 0, la1, a67, 0, 0, 0);
                v68 = a67[0];
                let69 = v68 + 1;
                if (!((let69 < 257 ? let69 : v68 + 4294967040) == v66))
                    break;
                usleep(100);
            }
            host_read_local(&group0, 0, 0, la0, a70, 0, 0, 0);
            v71 = a70[0];
            host_read_local(&group0, 0, 0, la1, a72, 0, 0, 0);
            v73 = a72[0];
            let74 = v73 + 257 - v71;
            r75 = let74 < 257 ? let74 : let74 - 257;
            r76 = -r75 + 256;
            let77 = -v64 + 256;
            r78 = let77 <= r76 ? let77 : r76;
            if (v73 + r78 <= 257) {
                host_write_shared(&shm1, a60, v73, v64, v64 + r78 - 1);
            } else {
                uint32_t r79;
                uint32_t r80;
                
                r79 = -v73 + 257;
                host_write_shared(&shm1, a60, v73, v64, v64 + r79 - 1);
                r80 = v64 + r79;
                host_write_shared(&shm1, a60, 0, r80, r80 + (r78 - r79) - 1);
            }
            let81 = v73 + r78;
            r82 = let81 < 257 ? let81 : let81 - 257;
            a83[0] = r82;
            host_write_local(&group0, 0, 0, la1, a83, 0, 0, 0);
            r62 = v64 + r78;
        }
        if (v58) {
            float _a84[256];
            float *a84 = _a84;
            uint32_t r85;
            uint32_t _a106[1];
            uint32_t *a106 = _a106;
            uint32_t v107;
            uint32_t _a108[1];
            uint32_t *a108 = _a108;
            uint32_t v109;
            uint32_t r112;
            uint32_t v114;
            bool v115;
            
            r85 = 0;
            while (1) {
                uint32_t v86;
                uint32_t v87;
                uint32_t _a92[1];
                uint32_t *a92 = _a92;
                uint32_t v93;
                uint32_t _a94[1];
                uint32_t *a94 = _a94;
                uint32_t v95;
                uint32_t r96;
                uint32_t let97;
                uint32_t r98;
                uint32_t let99;
                uint32_t r100;
                uint32_t let103;
                uint32_t r104;
                uint32_t _a105[1];
                uint32_t *a105 = _a105;
                
                v86 = r85;
                if (!(v86 < 256))
                    break;
                v87 = r85;
                while (1) {
                    uint32_t _a88[1];
                    uint32_t *a88 = _a88;
                    uint32_t v89;
                    uint32_t _a90[1];
                    uint32_t *a90 = _a90;
                    uint32_t v91;
                    
                    host_read_local(&group0, 3, 0, la63, a88, 0, 0, 0);
                    v89 = a88[0];
                    host_read_local(&group0, 3, 0, la64, a90, 0, 0, 0);
                    v91 = a90[0];
                    if (!(v89 == v91))
                        break;
                    usleep(100);
                }
                host_read_local(&group0, 3, 0, la63, a92, 0, 0, 0);
                v93 = a92[0];
                host_read_local(&group0, 3, 0, la64, a94, 0, 0, 0);
                v95 = a94[0];
                r96 = 257;
                let97 = r96 + v95 - v93;
                r98 = let97 < r96 ? let97 : let97 - r96;
                let99 = -v87 + 256;
                r100 = let99 <= r98 ? let99 : r98;
                if (v93 + r100 <= r96) {
                    host_read_shared(&shm52, a84, v93, v87, v87 + r100 - 1);
                } else {
                    uint32_t r101;
                    uint32_t r102;
                    
                    r101 = r96 - v93;
                    host_read_shared(&shm52, a84, v93, v87, v87 + r101 - 1);
                    r102 = v87 + r101;
                    host_read_shared(&shm52, a84, 0, r102, r102 + r100 - r101 -
                                     1);
                }
                let103 = v93 + r100;
                r104 = let103 < r96 ? let103 : let103 - r96;
                a105[0] = r104;
                host_write_local(&group0, 3, 0, la63, a105, 0, 0, 0);
                r85 = v87 + r100;
            }
            host_read_local(&group0, 3, 0, la63, a106, 0, 0, 0);
            v107 = a106[0];
            host_read_local(&group0, 3, 0, la64, a108, 0, 0, 0);
            v109 = a108[0];
            if (v107 == v109 && v109 == 256) {
                uint32_t _a110[1];
                uint32_t *a110 = _a110;
                uint32_t _a111[1];
                uint32_t *a111 = _a111;
                
                a110[0] = 0;
                host_write_local(&group0, 3, 0, la63, a110, 0, 0, 0);
                a111[0] = 0;
                host_write_local(&group0, 3, 0, la64, a111, 0, 0, 0);
            }
            r112 = 256;
            
            float _a113[r112];
            float *a113 = _a113;
            
            for (v114 = 0; v114 < r112; v114++) {
                a113[v114] = a84[v114];
            }
            v115 = emit_samples(a113);
            if (!v115) {
                r55 = false;
            }
        } else {
            r55 = false;
        }
    }
    teardown_queues();
    e_free(&shm1);
    e_free(&shm52);
    e_reset_group(&group0);
    e_close(&group0);
    e_finalize();
    return 0;
}
