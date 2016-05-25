#include "processor.h"
#include <e-feldspar.h>
#include <e-hal.h>
#include <e-loader.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
void *thread_t101(void *unused);
e_epiphany_t group0;
e_mem_t shm98;
off_t la0 = 8192;
off_t la1 = 8208;
off_t la2 = 8224;
off_t la3 = 8240;
off_t sa4 = 16777216;
off_t la5 = 8256;
off_t la6 = 8272;
off_t la7 = 8192;
off_t la8 = 8288;
off_t la9 = 8304;
off_t la10 = 8208;
off_t la11 = 8224;
off_t la12 = 12336;
off_t la13 = 12352;
off_t la14 = 8192;
off_t la15 = 12368;
off_t la16 = 12384;
off_t la17 = 8208;
off_t la18 = 8224;
off_t la19 = 12336;
off_t la20 = 12352;
off_t la21 = 8192;
off_t la22 = 12368;
off_t la23 = 12384;
off_t la24 = 8208;
off_t la25 = 8224;
off_t la26 = 12336;
off_t la27 = 12352;
off_t la28 = 8192;
off_t la29 = 12368;
off_t la30 = 12384;
off_t la31 = 8208;
off_t la32 = 8224;
off_t la33 = 12336;
off_t la34 = 12352;
off_t la35 = 8192;
off_t la36 = 12368;
off_t la37 = 12384;
off_t la38 = 8208;
off_t la39 = 8224;
off_t la40 = 12336;
off_t la41 = 12352;
off_t la42 = 8192;
off_t la43 = 12368;
off_t la44 = 12384;
off_t la45 = 8208;
off_t la46 = 8224;
off_t la47 = 12336;
off_t la48 = 12352;
off_t la49 = 8192;
off_t la50 = 12368;
off_t la51 = 12384;
off_t la52 = 8208;
off_t la53 = 8224;
off_t la54 = 10288;
off_t la55 = 10304;
off_t la56 = 8192;
off_t la57 = 10320;
off_t la58 = 10336;
off_t la59 = 8208;
off_t la60 = 8224;
off_t la61 = 10288;
off_t la62 = 10304;
off_t la63 = 8192;
off_t la64 = 10320;
off_t la65 = 10336;
off_t la66 = 8208;
off_t la67 = 8224;
off_t la68 = 12336;
off_t la69 = 12352;
off_t la70 = 8192;
off_t la71 = 12368;
off_t la72 = 12384;
off_t la73 = 8208;
off_t la74 = 8224;
off_t la75 = 12336;
off_t la76 = 12352;
off_t la77 = 8192;
off_t la78 = 12368;
off_t la79 = 12384;
off_t la80 = 8208;
off_t la81 = 8224;
off_t la82 = 12336;
off_t la83 = 12352;
off_t la84 = 8192;
off_t la85 = 12368;
off_t la86 = 12384;
off_t la87 = 8208;
off_t la88 = 8224;
off_t la89 = 12336;
off_t la90 = 12352;
off_t la91 = 8192;
off_t la92 = 12368;
off_t la93 = 12384;
off_t la94 = 8208;
off_t la95 = 8224;
off_t la96 = 12336;
off_t la97 = 12352;
off_t la98 = 8192;
off_t la99 = 12368;
off_t la100 = 12384;
off_t la101 = 8208;
off_t la102 = 8224;
off_t la103 = 12336;
off_t la104 = 12352;
off_t la105 = 8192;
off_t la106 = 12368;
off_t la107 = 12384;
off_t la108 = 8208;
off_t la109 = 8224;
off_t la110 = 10288;
off_t la111 = 10304;
off_t la112 = 10320;
off_t la113 = 10336;
off_t sa114 = 16779280;
void *thread_t101(void *unused)
{
    bool r102;
    
    r102 = true;
    while (1) {
        bool v103;
        uint32_t r104;
        float _a105[512];
        float *a105 = _a105;
        bool _a106[1];
        bool *a106 = _a106;
        bool v107;
        bool _a108[1];
        bool *a108 = _a108;
        
        v103 = r102;
        if (!v103)
            break;
        r104 = 512;
        host_read_local(&group0, 3, 0, la110, a106, 0, 0, 0);
        v107 = a106[0];
        a108[0] = v107;
        host_write_local(&group0, 3, 0, la111, a108, 0, 0, 0);
        if (v107) {
            uint32_t r109;
            uint32_t _a131[1];
            uint32_t *a131 = _a131;
            uint32_t v132;
            uint32_t _a133[1];
            uint32_t *a133 = _a133;
            uint32_t v134;
            
            r109 = 0;
            while (1) {
                bool _a110[1];
                bool *a110 = _a110;
                bool v111;
                uint32_t v112;
                uint32_t v113;
                uint32_t _a114[1];
                uint32_t *a114 = _a114;
                uint32_t v115;
                uint32_t _a116[1];
                uint32_t *a116 = _a116;
                uint32_t v117;
                uint32_t r118;
                uint32_t let119;
                uint32_t let120;
                uint32_t r121;
                uint32_t let122;
                uint32_t r123;
                uint32_t r124;
                
                host_read_local(&group0, 3, 0, la110, a110, 0, 0, 0);
                v111 = a110[0];
                v112 = r109;
                if (!(v111 && v112 < r104))
                    break;
                v113 = r109;
                host_read_local(&group0, 3, 0, la112, a114, 0, 0, 0);
                v115 = a114[0];
                host_read_local(&group0, 3, 0, la113, a116, 0, 0, 0);
                v117 = a116[0];
                r118 = 513;
                let119 = r118 + v117 - v115;
                let120 = r118;
                r121 = let119 < let120 ? let119 : let119 - let120;
                let122 = r104 - 1 - v113 + 1;
                r123 = let122 <= r121 ? let122 : r121;
                if (r123 > 0) {
                    uint32_t let127;
                    uint32_t let128;
                    uint32_t r129;
                    uint32_t _a130[1];
                    uint32_t *a130 = _a130;
                    
                    if (v115 + r123 <= r118) {
                        host_read_shared(&shm98, a105, v115, v113, v113 + r123 -
                                         1);
                    } else {
                        uint32_t r125;
                        uint32_t r126;
                        
                        r125 = r118 - v115;
                        host_read_shared(&shm98, a105, v115, v113, v113 + r125 -
                                         1);
                        r126 = v113 + r125;
                        host_read_shared(&shm98, a105, 0, r126, r126 + r123 -
                                         r125 - 1);
                    }
                    let127 = v115 + r123;
                    let128 = r118;
                    r129 = let127 < let128 ? let127 : let127 - let128;
                    a130[0] = r129;
                    host_write_local(&group0, 3, 0, la112, a130, 0, 0, 0);
                    r124 = r123;
                } else {
                    r124 = 0;
                }
                if (0 == r124) {
                    usleep(100);
                } else {
                    r109 = v113 + r124;
                }
            }
            host_read_local(&group0, 3, 0, la112, a131, 0, 0, 0);
            v132 = a131[0];
            host_read_local(&group0, 3, 0, la113, a133, 0, 0, 0);
            v134 = a133[0];
            if (v132 == v134 && v134 == 512) {
                uint32_t _a135[1];
                uint32_t *a135 = _a135;
                uint32_t _a136[1];
                uint32_t *a136 = _a136;
                
                a135[0] = 0;
                host_write_local(&group0, 3, 0, la112, a135, 0, 0, 0);
                a136[0] = 0;
                host_write_local(&group0, 3, 0, la113, a136, 0, 0, 0);
            }
        }
        if (v107) {
            bool v137;
            
            v137 = emit_samples(a105);
            r102 = v137;
            if (!v137) {
                bool _a138[1];
                bool *a138 = _a138;
                
                a138[0] = false;
                host_write_local(&group0, 3, 0, la110, a138, 0, 0, 0);
            }
        } else {
            r102 = false;
        }
    }
    return NULL;
}
int main()
{
    bool _a1[1];
    bool *a1 = _a1;
    bool _a2[1];
    bool *a2 = _a2;
    e_mem_t shm3;
    uint32_t _a4[1];
    uint32_t *a4 = _a4;
    uint32_t _a5[1];
    uint32_t *a5 = _a5;
    bool _a6[1];
    bool *a6 = _a6;
    bool _a7[1];
    bool *a7 = _a7;
    uint32_t _a8[1];
    uint32_t *a8 = _a8;
    uint32_t _a9[1];
    uint32_t *a9 = _a9;
    uint32_t _a10[1];
    uint32_t *a10 = _a10;
    uint32_t _a11[1];
    uint32_t *a11 = _a11;
    bool _a12[1];
    bool *a12 = _a12;
    bool _a13[1];
    bool *a13 = _a13;
    uint32_t _a14[1];
    uint32_t *a14 = _a14;
    uint32_t _a15[1];
    uint32_t *a15 = _a15;
    uint32_t _a16[1];
    uint32_t *a16 = _a16;
    uint32_t _a17[1];
    uint32_t *a17 = _a17;
    bool _a18[1];
    bool *a18 = _a18;
    bool _a19[1];
    bool *a19 = _a19;
    uint32_t _a20[1];
    uint32_t *a20 = _a20;
    uint32_t _a21[1];
    uint32_t *a21 = _a21;
    uint32_t _a22[1];
    uint32_t *a22 = _a22;
    uint32_t _a23[1];
    uint32_t *a23 = _a23;
    bool _a24[1];
    bool *a24 = _a24;
    bool _a25[1];
    bool *a25 = _a25;
    uint32_t _a26[1];
    uint32_t *a26 = _a26;
    uint32_t _a27[1];
    uint32_t *a27 = _a27;
    uint32_t _a28[1];
    uint32_t *a28 = _a28;
    uint32_t _a29[1];
    uint32_t *a29 = _a29;
    bool _a30[1];
    bool *a30 = _a30;
    bool _a31[1];
    bool *a31 = _a31;
    uint32_t _a32[1];
    uint32_t *a32 = _a32;
    uint32_t _a33[1];
    uint32_t *a33 = _a33;
    uint32_t _a34[1];
    uint32_t *a34 = _a34;
    uint32_t _a35[1];
    uint32_t *a35 = _a35;
    bool _a36[1];
    bool *a36 = _a36;
    bool _a37[1];
    bool *a37 = _a37;
    uint32_t _a38[1];
    uint32_t *a38 = _a38;
    uint32_t _a39[1];
    uint32_t *a39 = _a39;
    uint32_t _a40[1];
    uint32_t *a40 = _a40;
    uint32_t _a41[1];
    uint32_t *a41 = _a41;
    bool _a42[1];
    bool *a42 = _a42;
    bool _a43[1];
    bool *a43 = _a43;
    uint32_t _a44[1];
    uint32_t *a44 = _a44;
    uint32_t _a45[1];
    uint32_t *a45 = _a45;
    uint32_t _a46[1];
    uint32_t *a46 = _a46;
    uint32_t _a47[1];
    uint32_t *a47 = _a47;
    bool _a48[1];
    bool *a48 = _a48;
    bool _a49[1];
    bool *a49 = _a49;
    uint32_t _a50[1];
    uint32_t *a50 = _a50;
    uint32_t _a51[1];
    uint32_t *a51 = _a51;
    uint32_t _a52[1];
    uint32_t *a52 = _a52;
    uint32_t _a53[1];
    uint32_t *a53 = _a53;
    bool _a54[1];
    bool *a54 = _a54;
    bool _a55[1];
    bool *a55 = _a55;
    uint32_t _a56[1];
    uint32_t *a56 = _a56;
    uint32_t _a57[1];
    uint32_t *a57 = _a57;
    uint32_t _a58[1];
    uint32_t *a58 = _a58;
    uint32_t _a59[1];
    uint32_t *a59 = _a59;
    bool _a60[1];
    bool *a60 = _a60;
    bool _a61[1];
    bool *a61 = _a61;
    uint32_t _a62[1];
    uint32_t *a62 = _a62;
    uint32_t _a63[1];
    uint32_t *a63 = _a63;
    uint32_t _a64[1];
    uint32_t *a64 = _a64;
    uint32_t _a65[1];
    uint32_t *a65 = _a65;
    bool _a66[1];
    bool *a66 = _a66;
    bool _a67[1];
    bool *a67 = _a67;
    uint32_t _a68[1];
    uint32_t *a68 = _a68;
    uint32_t _a69[1];
    uint32_t *a69 = _a69;
    uint32_t _a70[1];
    uint32_t *a70 = _a70;
    uint32_t _a71[1];
    uint32_t *a71 = _a71;
    bool _a72[1];
    bool *a72 = _a72;
    bool _a73[1];
    bool *a73 = _a73;
    uint32_t _a74[1];
    uint32_t *a74 = _a74;
    uint32_t _a75[1];
    uint32_t *a75 = _a75;
    uint32_t _a76[1];
    uint32_t *a76 = _a76;
    uint32_t _a77[1];
    uint32_t *a77 = _a77;
    bool _a78[1];
    bool *a78 = _a78;
    bool _a79[1];
    bool *a79 = _a79;
    uint32_t _a80[1];
    uint32_t *a80 = _a80;
    uint32_t _a81[1];
    uint32_t *a81 = _a81;
    uint32_t _a82[1];
    uint32_t *a82 = _a82;
    uint32_t _a83[1];
    uint32_t *a83 = _a83;
    bool _a84[1];
    bool *a84 = _a84;
    bool _a85[1];
    bool *a85 = _a85;
    uint32_t _a86[1];
    uint32_t *a86 = _a86;
    uint32_t _a87[1];
    uint32_t *a87 = _a87;
    uint32_t _a88[1];
    uint32_t *a88 = _a88;
    uint32_t _a89[1];
    uint32_t *a89 = _a89;
    bool _a90[1];
    bool *a90 = _a90;
    bool _a91[1];
    bool *a91 = _a91;
    uint32_t _a92[1];
    uint32_t *a92 = _a92;
    uint32_t _a93[1];
    uint32_t *a93 = _a93;
    uint32_t _a94[1];
    uint32_t *a94 = _a94;
    uint32_t _a95[1];
    uint32_t *a95 = _a95;
    bool _a96[1];
    bool *a96 = _a96;
    bool _a97[1];
    bool *a97 = _a97;
    uint32_t _a99[1];
    uint32_t *a99 = _a99;
    uint32_t _a100[1];
    uint32_t *a100 = _a100;
    pthread_t t101;
    bool r139;
    bool _a172[1];
    bool *a172 = _a172;
    
    e_init(0);
    e_reset_system();
    e_open(&group0, 0, 0, 4, 4);
    e_reset_group(&group0);
    setup_queues();
    a1[0] = true;
    host_write_local(&group0, 0, 0, la0, a1, 0, 0, 0);
    a2[0] = true;
    host_write_local(&group0, 0, 0, la1, a2, 0, 0, 0);
    e_alloc(&shm3, sa4, 2052);
    a4[0] = 0;
    host_write_local(&group0, 0, 0, la2, a4, 0, 0, 0);
    a5[0] = 0;
    host_write_local(&group0, 0, 0, la3, a5, 0, 0, 0);
    a6[0] = true;
    host_write_local(&group0, 0, 0, la5, a6, 0, 0, 0);
    a7[0] = true;
    host_write_local(&group0, 0, 0, la6, a7, 0, 0, 0);
    a8[0] = 0;
    host_write_local(&group0, 0, 1, la7, a8, 0, 0, 0);
    a9[0] = 0;
    host_write_local(&group0, 0, 0, la8, a9, 0, 0, 0);
    a10[0] = 0;
    host_write_local(&group0, 0, 0, la9, a10, 0, 0, 0);
    a11[0] = 0;
    host_write_local(&group0, 0, 1, la10, a11, 0, 0, 0);
    e_load("core0.srec", &group0, 0, 0, 1);
    a12[0] = true;
    host_write_local(&group0, 0, 1, la12, a12, 0, 0, 0);
    a13[0] = true;
    host_write_local(&group0, 0, 1, la13, a13, 0, 0, 0);
    a14[0] = 0;
    host_write_local(&group0, 0, 2, la14, a14, 0, 0, 0);
    a15[0] = 0;
    host_write_local(&group0, 0, 1, la15, a15, 0, 0, 0);
    a16[0] = 0;
    host_write_local(&group0, 0, 1, la16, a16, 0, 0, 0);
    a17[0] = 0;
    host_write_local(&group0, 0, 2, la17, a17, 0, 0, 0);
    e_load("core1.srec", &group0, 0, 1, 1);
    a18[0] = true;
    host_write_local(&group0, 0, 2, la19, a18, 0, 0, 0);
    a19[0] = true;
    host_write_local(&group0, 0, 2, la20, a19, 0, 0, 0);
    a20[0] = 0;
    host_write_local(&group0, 0, 3, la21, a20, 0, 0, 0);
    a21[0] = 0;
    host_write_local(&group0, 0, 2, la22, a21, 0, 0, 0);
    a22[0] = 0;
    host_write_local(&group0, 0, 2, la23, a22, 0, 0, 0);
    a23[0] = 0;
    host_write_local(&group0, 0, 3, la24, a23, 0, 0, 0);
    e_load("core2.srec", &group0, 0, 2, 1);
    a24[0] = true;
    host_write_local(&group0, 0, 3, la26, a24, 0, 0, 0);
    a25[0] = true;
    host_write_local(&group0, 0, 3, la27, a25, 0, 0, 0);
    a26[0] = 0;
    host_write_local(&group0, 1, 3, la28, a26, 0, 0, 0);
    a27[0] = 0;
    host_write_local(&group0, 0, 3, la29, a27, 0, 0, 0);
    a28[0] = 0;
    host_write_local(&group0, 0, 3, la30, a28, 0, 0, 0);
    a29[0] = 0;
    host_write_local(&group0, 1, 3, la31, a29, 0, 0, 0);
    e_load("core3.srec", &group0, 0, 3, 1);
    a30[0] = true;
    host_write_local(&group0, 1, 3, la33, a30, 0, 0, 0);
    a31[0] = true;
    host_write_local(&group0, 1, 3, la34, a31, 0, 0, 0);
    a32[0] = 0;
    host_write_local(&group0, 1, 2, la35, a32, 0, 0, 0);
    a33[0] = 0;
    host_write_local(&group0, 1, 3, la36, a33, 0, 0, 0);
    a34[0] = 0;
    host_write_local(&group0, 1, 3, la37, a34, 0, 0, 0);
    a35[0] = 0;
    host_write_local(&group0, 1, 2, la38, a35, 0, 0, 0);
    e_load("core7.srec", &group0, 1, 3, 1);
    a36[0] = true;
    host_write_local(&group0, 1, 2, la40, a36, 0, 0, 0);
    a37[0] = true;
    host_write_local(&group0, 1, 2, la41, a37, 0, 0, 0);
    a38[0] = 0;
    host_write_local(&group0, 1, 1, la42, a38, 0, 0, 0);
    a39[0] = 0;
    host_write_local(&group0, 1, 2, la43, a39, 0, 0, 0);
    a40[0] = 0;
    host_write_local(&group0, 1, 2, la44, a40, 0, 0, 0);
    a41[0] = 0;
    host_write_local(&group0, 1, 1, la45, a41, 0, 0, 0);
    e_load("core6.srec", &group0, 1, 2, 1);
    a42[0] = true;
    host_write_local(&group0, 1, 1, la47, a42, 0, 0, 0);
    a43[0] = true;
    host_write_local(&group0, 1, 1, la48, a43, 0, 0, 0);
    a44[0] = 0;
    host_write_local(&group0, 1, 0, la49, a44, 0, 0, 0);
    a45[0] = 0;
    host_write_local(&group0, 1, 1, la50, a45, 0, 0, 0);
    a46[0] = 0;
    host_write_local(&group0, 1, 1, la51, a46, 0, 0, 0);
    a47[0] = 0;
    host_write_local(&group0, 1, 0, la52, a47, 0, 0, 0);
    e_load("core5.srec", &group0, 1, 1, 1);
    a48[0] = true;
    host_write_local(&group0, 1, 0, la54, a48, 0, 0, 0);
    a49[0] = true;
    host_write_local(&group0, 1, 0, la55, a49, 0, 0, 0);
    a50[0] = 0;
    host_write_local(&group0, 2, 0, la56, a50, 0, 0, 0);
    a51[0] = 0;
    host_write_local(&group0, 1, 0, la57, a51, 0, 0, 0);
    a52[0] = 0;
    host_write_local(&group0, 1, 0, la58, a52, 0, 0, 0);
    a53[0] = 0;
    host_write_local(&group0, 2, 0, la59, a53, 0, 0, 0);
    e_load("core4.srec", &group0, 1, 0, 1);
    a54[0] = true;
    host_write_local(&group0, 2, 0, la61, a54, 0, 0, 0);
    a55[0] = true;
    host_write_local(&group0, 2, 0, la62, a55, 0, 0, 0);
    a56[0] = 0;
    host_write_local(&group0, 2, 1, la63, a56, 0, 0, 0);
    a57[0] = 0;
    host_write_local(&group0, 2, 0, la64, a57, 0, 0, 0);
    a58[0] = 0;
    host_write_local(&group0, 2, 0, la65, a58, 0, 0, 0);
    a59[0] = 0;
    host_write_local(&group0, 2, 1, la66, a59, 0, 0, 0);
    e_load("core8.srec", &group0, 2, 0, 1);
    a60[0] = true;
    host_write_local(&group0, 2, 1, la68, a60, 0, 0, 0);
    a61[0] = true;
    host_write_local(&group0, 2, 1, la69, a61, 0, 0, 0);
    a62[0] = 0;
    host_write_local(&group0, 2, 2, la70, a62, 0, 0, 0);
    a63[0] = 0;
    host_write_local(&group0, 2, 1, la71, a63, 0, 0, 0);
    a64[0] = 0;
    host_write_local(&group0, 2, 1, la72, a64, 0, 0, 0);
    a65[0] = 0;
    host_write_local(&group0, 2, 2, la73, a65, 0, 0, 0);
    e_load("core9.srec", &group0, 2, 1, 1);
    a66[0] = true;
    host_write_local(&group0, 2, 2, la75, a66, 0, 0, 0);
    a67[0] = true;
    host_write_local(&group0, 2, 2, la76, a67, 0, 0, 0);
    a68[0] = 0;
    host_write_local(&group0, 2, 3, la77, a68, 0, 0, 0);
    a69[0] = 0;
    host_write_local(&group0, 2, 2, la78, a69, 0, 0, 0);
    a70[0] = 0;
    host_write_local(&group0, 2, 2, la79, a70, 0, 0, 0);
    a71[0] = 0;
    host_write_local(&group0, 2, 3, la80, a71, 0, 0, 0);
    e_load("core10.srec", &group0, 2, 2, 1);
    a72[0] = true;
    host_write_local(&group0, 2, 3, la82, a72, 0, 0, 0);
    a73[0] = true;
    host_write_local(&group0, 2, 3, la83, a73, 0, 0, 0);
    a74[0] = 0;
    host_write_local(&group0, 3, 3, la84, a74, 0, 0, 0);
    a75[0] = 0;
    host_write_local(&group0, 2, 3, la85, a75, 0, 0, 0);
    a76[0] = 0;
    host_write_local(&group0, 2, 3, la86, a76, 0, 0, 0);
    a77[0] = 0;
    host_write_local(&group0, 3, 3, la87, a77, 0, 0, 0);
    e_load("core11.srec", &group0, 2, 3, 1);
    a78[0] = true;
    host_write_local(&group0, 3, 3, la89, a78, 0, 0, 0);
    a79[0] = true;
    host_write_local(&group0, 3, 3, la90, a79, 0, 0, 0);
    a80[0] = 0;
    host_write_local(&group0, 3, 2, la91, a80, 0, 0, 0);
    a81[0] = 0;
    host_write_local(&group0, 3, 3, la92, a81, 0, 0, 0);
    a82[0] = 0;
    host_write_local(&group0, 3, 3, la93, a82, 0, 0, 0);
    a83[0] = 0;
    host_write_local(&group0, 3, 2, la94, a83, 0, 0, 0);
    e_load("core15.srec", &group0, 3, 3, 1);
    a84[0] = true;
    host_write_local(&group0, 3, 2, la96, a84, 0, 0, 0);
    a85[0] = true;
    host_write_local(&group0, 3, 2, la97, a85, 0, 0, 0);
    a86[0] = 0;
    host_write_local(&group0, 3, 1, la98, a86, 0, 0, 0);
    a87[0] = 0;
    host_write_local(&group0, 3, 2, la99, a87, 0, 0, 0);
    a88[0] = 0;
    host_write_local(&group0, 3, 2, la100, a88, 0, 0, 0);
    a89[0] = 0;
    host_write_local(&group0, 3, 1, la101, a89, 0, 0, 0);
    e_load("core14.srec", &group0, 3, 2, 1);
    a90[0] = true;
    host_write_local(&group0, 3, 1, la103, a90, 0, 0, 0);
    a91[0] = true;
    host_write_local(&group0, 3, 1, la104, a91, 0, 0, 0);
    a92[0] = 0;
    host_write_local(&group0, 3, 0, la105, a92, 0, 0, 0);
    a93[0] = 0;
    host_write_local(&group0, 3, 1, la106, a93, 0, 0, 0);
    a94[0] = 0;
    host_write_local(&group0, 3, 1, la107, a94, 0, 0, 0);
    a95[0] = 0;
    host_write_local(&group0, 3, 0, la108, a95, 0, 0, 0);
    e_load("core13.srec", &group0, 3, 1, 1);
    a96[0] = true;
    host_write_local(&group0, 3, 0, la110, a96, 0, 0, 0);
    a97[0] = true;
    host_write_local(&group0, 3, 0, la111, a97, 0, 0, 0);
    e_alloc(&shm98, sa114, 2052);
    a99[0] = 0;
    host_write_local(&group0, 3, 0, la112, a99, 0, 0, 0);
    a100[0] = 0;
    host_write_local(&group0, 3, 0, la113, a100, 0, 0, 0);
    e_load("core12.srec", &group0, 3, 0, 1);
    pthread_create(&t101, NULL, thread_t101, NULL);
    r139 = true;
    while (1) {
        bool v140;
        float _a141[512];
        float *a141 = _a141;
        bool v142;
        
        v140 = r139;
        if (!v140)
            break;
        v142 = receive_samples(a141);
        if (v142) {
            uint32_t r143;
            float _a144[512];
            float *a144 = _a144;
            uint32_t v145;
            bool _a146[1];
            bool *a146 = _a146;
            bool v147;
            bool r148;
            
            r143 = 512;
            for (v145 = 0; v145 < 512; v145++) {
                a144[v145] = a141[v145];
            }
            host_read_local(&group0, 0, 0, la0, a146, 0, 0, 0);
            v147 = a146[0];
            if (v147) {
                uint32_t r149;
                
                r149 = 0;
                while (1) {
                    bool _a150[1];
                    bool *a150 = _a150;
                    bool v151;
                    uint32_t v152;
                    uint32_t v153;
                    uint32_t _a154[1];
                    uint32_t *a154 = _a154;
                    uint32_t v155;
                    uint32_t _a156[1];
                    uint32_t *a156 = _a156;
                    uint32_t v157;
                    uint32_t r158;
                    uint32_t let159;
                    uint32_t let160;
                    uint32_t r161;
                    uint32_t r162;
                    uint32_t let163;
                    uint32_t r164;
                    uint32_t r165;
                    
                    host_read_local(&group0, 0, 0, la0, a150, 0, 0, 0);
                    v151 = a150[0];
                    v152 = r149;
                    if (!(v151 && v152 < r143))
                        break;
                    v153 = r149;
                    host_read_local(&group0, 0, 0, la2, a154, 0, 0, 0);
                    v155 = a154[0];
                    host_read_local(&group0, 0, 0, la3, a156, 0, 0, 0);
                    v157 = a156[0];
                    r158 = 513;
                    let159 = r158 + v157 - v155;
                    let160 = r158;
                    r161 = let159 < let160 ? let159 : let159 - let160;
                    r162 = r158 - r161 - 1;
                    let163 = r143 - 1 - v153 + 1;
                    r164 = let163 <= r162 ? let163 : r162;
                    if (r164 > 0) {
                        uint32_t let168;
                        uint32_t let169;
                        uint32_t r170;
                        uint32_t _a171[1];
                        uint32_t *a171 = _a171;
                        
                        if (v157 + r164 <= r158) {
                            host_write_shared(&shm3, a144, v157, v153, v153 +
                                              r164 - 1);
                        } else {
                            uint32_t r166;
                            uint32_t r167;
                            
                            r166 = r158 - v157;
                            host_write_shared(&shm3, a144, v157, v153, v153 +
                                              r166 - 1);
                            r167 = v153 + r166;
                            host_write_shared(&shm3, a144, 0, r167, r167 +
                                              (r164 - r166) - 1);
                        }
                        let168 = v157 + r164;
                        let169 = r158;
                        r170 = let168 < let169 ? let168 : let168 - let169;
                        a171[0] = r170;
                        host_write_local(&group0, 0, 0, la3, a171, 0, 0, 0);
                        r165 = r164;
                    } else {
                        r165 = 0;
                    }
                    if (0 == r165) {
                        usleep(100);
                    } else {
                        r149 = v153 + r165;
                    }
                }
                r148 = true;
            } else {
                r148 = false;
            }
            r139 = r148;
        } else {
            r139 = false;
        }
    }
    a172[0] = false;
    host_write_local(&group0, 0, 0, la0, a172, 0, 0, 0);
    pthread_join(t101, NULL);
    teardown_queues();
    e_free(&shm98);
    e_free(&shm3);
    e_reset_group(&group0);
    e_close(&group0);
    e_finalize();
    return 0;
}
