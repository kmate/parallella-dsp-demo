#include "processor.h"
#include <e-feldspar.h>
#include <e-hal.h>
#include <e-loader.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
void *thread_t67(void *unused);
e_epiphany_t group0;
e_mem_t shm64;
off_t la0 = 8192;
off_t la1 = 8196;
off_t sa2 = 16777216;
off_t la3 = 8192;
off_t la4 = 8200;
off_t la5 = 8204;
off_t la6 = 8196;
off_t la7 = 8200;
off_t la8 = 8192;
off_t la9 = 12304;
off_t la10 = 12308;
off_t la11 = 8196;
off_t la12 = 8200;
off_t la13 = 8192;
off_t la14 = 12304;
off_t la15 = 12308;
off_t la16 = 8196;
off_t la17 = 8200;
off_t la18 = 8192;
off_t la19 = 12304;
off_t la20 = 12308;
off_t la21 = 8196;
off_t la22 = 8200;
off_t la23 = 8192;
off_t la24 = 12304;
off_t la25 = 12308;
off_t la26 = 8196;
off_t la27 = 8200;
off_t la28 = 8192;
off_t la29 = 12304;
off_t la30 = 12308;
off_t la31 = 8196;
off_t la32 = 8200;
off_t la33 = 8192;
off_t la34 = 12304;
off_t la35 = 12308;
off_t la36 = 8196;
off_t la37 = 8200;
off_t la38 = 8192;
off_t la39 = 10264;
off_t la40 = 10268;
off_t la41 = 8196;
off_t la42 = 8200;
off_t la43 = 8192;
off_t la44 = 10264;
off_t la45 = 10268;
off_t la46 = 8196;
off_t la47 = 8200;
off_t la48 = 8192;
off_t la49 = 12304;
off_t la50 = 12308;
off_t la51 = 8196;
off_t la52 = 8200;
off_t la53 = 8192;
off_t la54 = 12304;
off_t la55 = 12308;
off_t la56 = 8196;
off_t la57 = 8200;
off_t la58 = 8192;
off_t la59 = 12304;
off_t la60 = 12308;
off_t la61 = 8196;
off_t la62 = 8200;
off_t la63 = 8192;
off_t la64 = 12304;
off_t la65 = 12308;
off_t la66 = 8196;
off_t la67 = 8200;
off_t la68 = 8192;
off_t la69 = 12304;
off_t la70 = 12308;
off_t la71 = 8196;
off_t la72 = 8200;
off_t la73 = 8192;
off_t la74 = 12304;
off_t la75 = 12308;
off_t la76 = 8196;
off_t la77 = 8200;
off_t la78 = 10252;
off_t la79 = 10256;
off_t sa80 = 16779268;
void *thread_t67(void *unused)
{
    bool r68;
    
    r68 = true;
    while (1) {
        bool v69;
        float _a70[512];
        float *a70 = _a70;
        uint32_t r71;
        uint32_t _a91[1];
        uint32_t *a91 = _a91;
        uint32_t v92;
        uint32_t _a93[1];
        uint32_t *a93 = _a93;
        uint32_t v94;
        uint32_t r97;
        uint32_t v99;
        bool v100;
        
        v69 = r68;
        if (!v69)
            break;
        r71 = 0;
        while (1) {
            uint32_t v72;
            uint32_t v73;
            uint32_t _a74[1];
            uint32_t *a74 = _a74;
            uint32_t v75;
            uint32_t _a76[1];
            uint32_t *a76 = _a76;
            uint32_t v77;
            uint32_t r78;
            uint32_t let79;
            uint32_t let80;
            uint32_t r81;
            uint32_t let82;
            uint32_t r83;
            uint32_t r84;
            
            v72 = r71;
            if (!(v72 < 512))
                break;
            v73 = r71;
            host_read_local(&group0, 3, 0, la78, a74, 0, 0, 0);
            v75 = a74[0];
            host_read_local(&group0, 3, 0, la79, a76, 0, 0, 0);
            v77 = a76[0];
            r78 = 513;
            let79 = r78 + v77 - v75;
            let80 = r78;
            r81 = let79 < let80 ? let79 : let79 - let80;
            let82 = -v73 + 512;
            r83 = let82 <= r81 ? let82 : r81;
            if (r83 > 0) {
                uint32_t let87;
                uint32_t let88;
                uint32_t r89;
                uint32_t _a90[1];
                uint32_t *a90 = _a90;
                
                if (v75 + r83 <= r78) {
                    host_read_shared(&shm64, a70, v75, v73, v73 + r83 - 1);
                } else {
                    uint32_t r85;
                    uint32_t r86;
                    
                    r85 = r78 - v75;
                    host_read_shared(&shm64, a70, v75, v73, v73 + r85 - 1);
                    r86 = v73 + r85;
                    host_read_shared(&shm64, a70, 0, r86, r86 + r83 - r85 - 1);
                }
                let87 = v75 + r83;
                let88 = r78;
                r89 = let87 < let88 ? let87 : let87 - let88;
                a90[0] = r89;
                host_write_local(&group0, 3, 0, la78, a90, 0, 0, 0);
                r84 = r83;
            } else {
                r84 = 0;
            }
            if (0 == r84) {
                usleep(100);
            } else {
                r71 = v73 + r84;
            }
        }
        host_read_local(&group0, 3, 0, la78, a91, 0, 0, 0);
        v92 = a91[0];
        host_read_local(&group0, 3, 0, la79, a93, 0, 0, 0);
        v94 = a93[0];
        if (v92 == v94 && v94 == 512) {
            uint32_t _a95[1];
            uint32_t *a95 = _a95;
            uint32_t _a96[1];
            uint32_t *a96 = _a96;
            
            a95[0] = 0;
            host_write_local(&group0, 3, 0, la78, a95, 0, 0, 0);
            a96[0] = 0;
            host_write_local(&group0, 3, 0, la79, a96, 0, 0, 0);
        }
        r97 = 512;
        
        float _a98[r97];
        float *a98 = _a98;
        
        for (v99 = 0; v99 < r97; v99++) {
            a98[v99] = a70[v99];
        }
        v100 = emit_samples(a98);
        r68 = v100;
    }
    return NULL;
}
int main()
{
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
    uint32_t _a52[1];
    uint32_t *a52 = _a52;
    uint32_t _a53[1];
    uint32_t *a53 = _a53;
    uint32_t _a54[1];
    uint32_t *a54 = _a54;
    uint32_t _a55[1];
    uint32_t *a55 = _a55;
    uint32_t _a56[1];
    uint32_t *a56 = _a56;
    uint32_t _a57[1];
    uint32_t *a57 = _a57;
    uint32_t _a58[1];
    uint32_t *a58 = _a58;
    uint32_t _a59[1];
    uint32_t *a59 = _a59;
    uint32_t _a60[1];
    uint32_t *a60 = _a60;
    uint32_t _a61[1];
    uint32_t *a61 = _a61;
    uint32_t _a62[1];
    uint32_t *a62 = _a62;
    uint32_t _a63[1];
    uint32_t *a63 = _a63;
    uint32_t _a65[1];
    uint32_t *a65 = _a65;
    uint32_t _a66[1];
    uint32_t *a66 = _a66;
    pthread_t t67;
    bool r101;
    
    e_init(0);
    e_reset_system();
    e_open(&group0, 0, 0, 4, 4);
    e_reset_group(&group0);
    setup_queues();
    e_alloc(&shm1, sa2, 2052);
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
    host_write_local(&group0, 1, 1, la28, a24, 0, 0, 0);
    a25[0] = 0;
    host_write_local(&group0, 1, 2, la29, a25, 0, 0, 0);
    a26[0] = 0;
    host_write_local(&group0, 1, 2, la30, a26, 0, 0, 0);
    a27[0] = 0;
    host_write_local(&group0, 1, 1, la31, a27, 0, 0, 0);
    e_load("core6.srec", &group0, 1, 2, 1);
    a28[0] = 0;
    host_write_local(&group0, 1, 0, la33, a28, 0, 0, 0);
    a29[0] = 0;
    host_write_local(&group0, 1, 1, la34, a29, 0, 0, 0);
    a30[0] = 0;
    host_write_local(&group0, 1, 1, la35, a30, 0, 0, 0);
    a31[0] = 0;
    host_write_local(&group0, 1, 0, la36, a31, 0, 0, 0);
    e_load("core5.srec", &group0, 1, 1, 1);
    a32[0] = 0;
    host_write_local(&group0, 2, 0, la38, a32, 0, 0, 0);
    a33[0] = 0;
    host_write_local(&group0, 1, 0, la39, a33, 0, 0, 0);
    a34[0] = 0;
    host_write_local(&group0, 1, 0, la40, a34, 0, 0, 0);
    a35[0] = 0;
    host_write_local(&group0, 2, 0, la41, a35, 0, 0, 0);
    e_load("core4.srec", &group0, 1, 0, 1);
    a36[0] = 0;
    host_write_local(&group0, 2, 1, la43, a36, 0, 0, 0);
    a37[0] = 0;
    host_write_local(&group0, 2, 0, la44, a37, 0, 0, 0);
    a38[0] = 0;
    host_write_local(&group0, 2, 0, la45, a38, 0, 0, 0);
    a39[0] = 0;
    host_write_local(&group0, 2, 1, la46, a39, 0, 0, 0);
    e_load("core8.srec", &group0, 2, 0, 1);
    a40[0] = 0;
    host_write_local(&group0, 2, 2, la48, a40, 0, 0, 0);
    a41[0] = 0;
    host_write_local(&group0, 2, 1, la49, a41, 0, 0, 0);
    a42[0] = 0;
    host_write_local(&group0, 2, 1, la50, a42, 0, 0, 0);
    a43[0] = 0;
    host_write_local(&group0, 2, 2, la51, a43, 0, 0, 0);
    e_load("core9.srec", &group0, 2, 1, 1);
    a44[0] = 0;
    host_write_local(&group0, 2, 3, la53, a44, 0, 0, 0);
    a45[0] = 0;
    host_write_local(&group0, 2, 2, la54, a45, 0, 0, 0);
    a46[0] = 0;
    host_write_local(&group0, 2, 2, la55, a46, 0, 0, 0);
    a47[0] = 0;
    host_write_local(&group0, 2, 3, la56, a47, 0, 0, 0);
    e_load("core10.srec", &group0, 2, 2, 1);
    a48[0] = 0;
    host_write_local(&group0, 3, 3, la58, a48, 0, 0, 0);
    a49[0] = 0;
    host_write_local(&group0, 2, 3, la59, a49, 0, 0, 0);
    a50[0] = 0;
    host_write_local(&group0, 2, 3, la60, a50, 0, 0, 0);
    a51[0] = 0;
    host_write_local(&group0, 3, 3, la61, a51, 0, 0, 0);
    e_load("core11.srec", &group0, 2, 3, 1);
    a52[0] = 0;
    host_write_local(&group0, 3, 2, la63, a52, 0, 0, 0);
    a53[0] = 0;
    host_write_local(&group0, 3, 3, la64, a53, 0, 0, 0);
    a54[0] = 0;
    host_write_local(&group0, 3, 3, la65, a54, 0, 0, 0);
    a55[0] = 0;
    host_write_local(&group0, 3, 2, la66, a55, 0, 0, 0);
    e_load("core15.srec", &group0, 3, 3, 1);
    a56[0] = 0;
    host_write_local(&group0, 3, 1, la68, a56, 0, 0, 0);
    a57[0] = 0;
    host_write_local(&group0, 3, 2, la69, a57, 0, 0, 0);
    a58[0] = 0;
    host_write_local(&group0, 3, 2, la70, a58, 0, 0, 0);
    a59[0] = 0;
    host_write_local(&group0, 3, 1, la71, a59, 0, 0, 0);
    e_load("core14.srec", &group0, 3, 2, 1);
    a60[0] = 0;
    host_write_local(&group0, 3, 0, la73, a60, 0, 0, 0);
    a61[0] = 0;
    host_write_local(&group0, 3, 1, la74, a61, 0, 0, 0);
    a62[0] = 0;
    host_write_local(&group0, 3, 1, la75, a62, 0, 0, 0);
    a63[0] = 0;
    host_write_local(&group0, 3, 0, la76, a63, 0, 0, 0);
    e_load("core13.srec", &group0, 3, 1, 1);
    e_alloc(&shm64, sa80, 2052);
    a65[0] = 0;
    host_write_local(&group0, 3, 0, la78, a65, 0, 0, 0);
    a66[0] = 0;
    host_write_local(&group0, 3, 0, la79, a66, 0, 0, 0);
    e_load("core12.srec", &group0, 3, 0, 1);
    pthread_create(&t67, NULL, thread_t67, NULL);
    r101 = true;
    while (1) {
        bool v102;
        float _a103[512];
        float *a103 = _a103;
        bool v104;
        uint32_t r105;
        float _a106[512];
        float *a106 = _a106;
        uint32_t v107;
        uint32_t r108;
        
        v102 = r101;
        if (!v102)
            break;
        v104 = receive_samples(a103);
        r105 = 512;
        for (v107 = 0; v107 < 512; v107++) {
            a106[v107] = a103[v107];
        }
        r108 = 0;
        while (1) {
            uint32_t v109;
            uint32_t v110;
            uint32_t _a111[1];
            uint32_t *a111 = _a111;
            uint32_t v112;
            uint32_t _a113[1];
            uint32_t *a113 = _a113;
            uint32_t v114;
            uint32_t r115;
            uint32_t let116;
            uint32_t let117;
            uint32_t r118;
            uint32_t r119;
            uint32_t let120;
            uint32_t r121;
            uint32_t r122;
            
            v109 = r108;
            if (!(v109 < 512))
                break;
            v110 = r108;
            host_read_local(&group0, 0, 0, la0, a111, 0, 0, 0);
            v112 = a111[0];
            host_read_local(&group0, 0, 0, la1, a113, 0, 0, 0);
            v114 = a113[0];
            r115 = 513;
            let116 = r115 + v114 - v112;
            let117 = r115;
            r118 = let116 < let117 ? let116 : let116 - let117;
            r119 = r115 - r118 - 1;
            let120 = -v110 + 512;
            r121 = let120 <= r119 ? let120 : r119;
            if (r121 > 0) {
                uint32_t let125;
                uint32_t let126;
                uint32_t r127;
                uint32_t _a128[1];
                uint32_t *a128 = _a128;
                
                if (v114 + r121 <= r115) {
                    host_write_shared(&shm1, a106, v114, v110, v110 + r121 - 1);
                } else {
                    uint32_t r123;
                    uint32_t r124;
                    
                    r123 = r115 - v114;
                    host_write_shared(&shm1, a106, v114, v110, v110 + r123 - 1);
                    r124 = v110 + r123;
                    host_write_shared(&shm1, a106, 0, r124, r124 + (r121 -
                                                                    r123) - 1);
                }
                let125 = v114 + r121;
                let126 = r115;
                r127 = let125 < let126 ? let125 : let125 - let126;
                a128[0] = r127;
                host_write_local(&group0, 0, 0, la1, a128, 0, 0, 0);
                r122 = r121;
            } else {
                r122 = 0;
            }
            if (0 == r122) {
                usleep(100);
            } else {
                r108 = v110 + r122;
            }
        }
        r101 = v104;
    }
    pthread_join(t67, NULL);
    teardown_queues();
    e_free(&shm1);
    e_free(&shm64);
    e_reset_group(&group0);
    e_close(&group0);
    e_finalize();
    return 0;
}
