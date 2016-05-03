#include "c_processor.h"
#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
void *thread_t2(void *unused);
void *thread_t134(void *unused);
pthread_t t134;
pthread_t t2;
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
        uint32_t r10;
        uint32_t v12;
        uint32_t r13;
        uint32_t v15;
        uint32_t r16;
        uint32_t v18;
        uint32_t r19;
        uint32_t v21;
        uint32_t r22;
        uint32_t v24;
        uint32_t r25;
        uint32_t v27;
        uint32_t r28;
        uint32_t v30;
        uint32_t r31;
        uint32_t v33;
        uint32_t r34;
        uint32_t v36;
        uint32_t r37;
        uint32_t v39;
        uint32_t r40;
        uint32_t v42;
        uint32_t r43;
        uint32_t v45;
        uint32_t r46;
        uint32_t v48;
        uint32_t r49;
        uint32_t v51;
        uint32_t r52;
        uint32_t v54;
        uint32_t r55;
        uint32_t v57;
        uint32_t r58;
        uint32_t v60;
        uint32_t r61;
        uint32_t v63;
        uint32_t r64;
        uint32_t v66;
        uint32_t v68;
        uint32_t r70;
        uint32_t v72;
        uint32_t r73;
        uint32_t v75;
        uint32_t r76;
        uint32_t v78;
        uint32_t r79;
        uint32_t v81;
        uint32_t r82;
        uint32_t v84;
        uint32_t r85;
        uint32_t v87;
        uint32_t r88;
        uint32_t v90;
        uint32_t r91;
        uint32_t v93;
        uint32_t r94;
        uint32_t v96;
        uint32_t r97;
        uint32_t v99;
        uint32_t r100;
        uint32_t v102;
        uint32_t r103;
        uint32_t v105;
        uint32_t r106;
        uint32_t v108;
        uint32_t r109;
        uint32_t v111;
        uint32_t r112;
        uint32_t v114;
        uint32_t r115;
        uint32_t v117;
        uint32_t r118;
        uint32_t v120;
        uint32_t r121;
        uint32_t v123;
        uint32_t r124;
        uint32_t v126;
        uint32_t r127;
        uint32_t v129;
        uint32_t v130;
        uint32_t v131;
        bool v132;
        bool v133;
        
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
        r10 = v7;
        
        float _Complex _a11[v7];
        float _Complex *a11 = _a11;
        
        for (v12 = 0; v12 < v7; v12++) {
            a11[v12] = !((v12 & 512) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v12 & 511) /
                                                      512.0)) * (a8[v12 ^ 512] *
                                                                 (-(0.5 *
                                                                    cos(2.0 *
                                                                    FELD_PI *
                                                                    (float) (v12 ^
                                                                             512) /
                                                                    (float) v7)) +
                                                                  0.5) -
                                                                 a8[v12] *
                                                                 (-(0.5 *
                                                                    cos(2.0 *
                                                                    FELD_PI *
                                                                    (float) v12 /
                                                                    (float) v7)) +
                                                                  0.5)) : a8[v12] *
                (-(0.5 * cos(2.0 * FELD_PI * (float) v12 / (float) v7)) + 0.5) +
                a8[v12 ^ 512] * (-(0.5 * cos(2.0 * FELD_PI * (float) (v12 ^
                                                                      512) /
                                   (float) v7)) + 0.5);
        }
        r13 = r10;
        
        float _Complex _a14[r10];
        float _Complex *a14 = _a14;
        
        for (v15 = 0; v15 < r10; v15++) {
            a14[v15] = !((v15 & 256) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v15 & 255) /
                                                      256.0)) * (a11[v15 ^
                                                                     256] -
                                                                 a11[v15]) : a11[v15] +
                a11[v15 ^ 256];
        }
        r16 = r13;
        
        float _Complex _a17[r13];
        float _Complex *a17 = _a17;
        
        for (v18 = 0; v18 < r13; v18++) {
            a17[v18] = !((v18 & 128) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v18 & 127) /
                                                      128.0)) * (a14[v18 ^
                                                                     128] -
                                                                 a14[v18]) : a14[v18] +
                a14[v18 ^ 128];
        }
        r19 = r16;
        
        float _Complex _a20[r16];
        float _Complex *a20 = _a20;
        
        for (v21 = 0; v21 < r16; v21++) {
            a20[v21] = !((v21 & 64) == 0) ? exp(I * (-3.1415927 * (float) (v21 &
                                                                           63) /
                                                     64.0)) * (a17[v21 ^ 64] -
                                                               a17[v21]) : a17[v21] +
                a17[v21 ^ 64];
        }
        r22 = r19;
        
        float _Complex _a23[r19];
        float _Complex *a23 = _a23;
        
        for (v24 = 0; v24 < r19; v24++) {
            a23[v24] = !((v24 & 32) == 0) ? exp(I * (-3.1415927 * (float) (v24 &
                                                                           31) /
                                                     32.0)) * (a20[v24 ^ 32] -
                                                               a20[v24]) : a20[v24] +
                a20[v24 ^ 32];
        }
        r25 = r22;
        
        float _Complex _a26[r22];
        float _Complex *a26 = _a26;
        
        for (v27 = 0; v27 < r22; v27++) {
            a26[v27] = !((v27 & 16) == 0) ? exp(I * (-3.1415927 * (float) (v27 &
                                                                           15) /
                                                     16.0)) * (a23[v27 ^ 16] -
                                                               a23[v27]) : a23[v27] +
                a23[v27 ^ 16];
        }
        r28 = r25;
        
        float _Complex _a29[r25];
        float _Complex *a29 = _a29;
        
        for (v30 = 0; v30 < r25; v30++) {
            a29[v30] = !((v30 & 8) == 0) ? exp(I * (-3.1415927 * (float) (v30 &
                                                                          7) /
                                                    8.0)) * (a26[v30 ^ 8] -
                                                             a26[v30]) : a26[v30] +
                a26[v30 ^ 8];
        }
        r31 = r28;
        
        float _Complex _a32[r28];
        float _Complex *a32 = _a32;
        
        for (v33 = 0; v33 < r28; v33++) {
            a32[v33] = !((v33 & 4) == 0) ? exp(I * (-3.1415927 * (float) (v33 &
                                                                          3) /
                                                    4.0)) * (a29[v33 ^ 4] -
                                                             a29[v33]) : a29[v33] +
                a29[v33 ^ 4];
        }
        r34 = r31;
        
        float _Complex _a35[r31];
        float _Complex *a35 = _a35;
        
        for (v36 = 0; v36 < r31; v36++) {
            a35[v36] = !((v36 & 2) == 0) ? exp(I * (-3.1415927 * (float) (v36 &
                                                                          1) /
                                                    2.0)) * (a32[v36 ^ 2] -
                                                             a32[v36]) : a32[v36] +
                a32[v36 ^ 2];
        }
        r37 = r34;
        
        float _Complex _a38[r34];
        float _Complex *a38 = _a38;
        
        for (v39 = 0; v39 < r34; v39++) {
            a38[v39] = !((v39 & 1) == 0) ? exp(I * (-3.1415927 * (float) (v39 &
                                                                          0) /
                                                    1.0)) * (a35[v39 ^ 1] -
                                                             a35[v39]) : a35[v39] +
                a35[v39 ^ 1];
        }
        r40 = r37;
        
        float _Complex _a41[r37];
        float _Complex *a41 = _a41;
        
        for (v42 = 0; v42 < r37; v42++) {
            a41[v42] = a38[(v42 >> 1 >> 1 << 1 | (v42 & 1)) << 1 | (v42 >> 1 &
                                                                    1)];
        }
        r43 = r40;
        
        float _Complex _a44[r40];
        float _Complex *a44 = _a44;
        
        for (v45 = 0; v45 < r40; v45++) {
            a44[v45] = a41[(v45 >> 1 >> 2 << 1 | (v45 & 1)) << 2 | (v45 >> 1 &
                                                                    3)];
        }
        r46 = r43;
        
        float _Complex _a47[r43];
        float _Complex *a47 = _a47;
        
        for (v48 = 0; v48 < r43; v48++) {
            a47[v48] = a44[(v48 >> 1 >> 3 << 1 | (v48 & 1)) << 3 | (v48 >> 1 &
                                                                    7)];
        }
        r49 = r46;
        
        float _Complex _a50[r46];
        float _Complex *a50 = _a50;
        
        for (v51 = 0; v51 < r46; v51++) {
            a50[v51] = a47[(v51 >> 1 >> 4 << 1 | (v51 & 1)) << 4 | (v51 >> 1 &
                                                                    15)];
        }
        r52 = r49;
        
        float _Complex _a53[r49];
        float _Complex *a53 = _a53;
        
        for (v54 = 0; v54 < r49; v54++) {
            a53[v54] = a50[(v54 >> 1 >> 5 << 1 | (v54 & 1)) << 5 | (v54 >> 1 &
                                                                    31)];
        }
        r55 = r52;
        
        float _Complex _a56[r52];
        float _Complex *a56 = _a56;
        
        for (v57 = 0; v57 < r52; v57++) {
            a56[v57] = a53[(v57 >> 1 >> 6 << 1 | (v57 & 1)) << 6 | (v57 >> 1 &
                                                                    63)];
        }
        r58 = r55;
        
        float _Complex _a59[r55];
        float _Complex *a59 = _a59;
        
        for (v60 = 0; v60 < r55; v60++) {
            a59[v60] = a56[(v60 >> 1 >> 7 << 1 | (v60 & 1)) << 7 | (v60 >> 1 &
                                                                    127)];
        }
        r61 = r58;
        
        float _Complex _a62[r58];
        float _Complex *a62 = _a62;
        
        for (v63 = 0; v63 < r58; v63++) {
            a62[v63] = a59[(v63 >> 1 >> 8 << 1 | (v63 & 1)) << 8 | (v63 >> 1 &
                                                                    255)];
        }
        r64 = r61;
        
        float _Complex _a65[r61];
        float _Complex *a65 = _a65;
        
        for (v66 = 0; v66 < r61; v66++) {
            a65[v66] = a62[(v66 >> 1 >> 9 << 1 | (v66 & 1)) << 9 | (v66 >> 1 &
                                                                    511)];
        }
        
        float _Complex _a67[r64];
        float _Complex *a67 = _a67;
        
        for (v68 = 0; v68 < r64; v68++) {
            a67[v68] = a65[v68];
        }
        
        float _Complex _a69[r64];
        float _Complex *a69 = _a69;
        
        smbPitchShift(2.0, a67, a69);
        r70 = r64;
        
        float _Complex _a71[r64];
        float _Complex *a71 = _a71;
        
        for (v72 = 0; v72 < r64; v72++) {
            a71[v72] = !((v72 & 512) == 0) ? exp(I * (FELD_PI * (float) (v72 &
                                                                         511) /
                                                      512.0)) * (a69[v72 ^
                                                                     512] -
                                                                 a69[v72]) : a69[v72] +
                a69[v72 ^ 512];
        }
        r73 = r70;
        
        float _Complex _a74[r70];
        float _Complex *a74 = _a74;
        
        for (v75 = 0; v75 < r70; v75++) {
            a74[v75] = !((v75 & 256) == 0) ? exp(I * (FELD_PI * (float) (v75 &
                                                                         255) /
                                                      256.0)) * (a71[v75 ^
                                                                     256] -
                                                                 a71[v75]) : a71[v75] +
                a71[v75 ^ 256];
        }
        r76 = r73;
        
        float _Complex _a77[r73];
        float _Complex *a77 = _a77;
        
        for (v78 = 0; v78 < r73; v78++) {
            a77[v78] = !((v78 & 128) == 0) ? exp(I * (FELD_PI * (float) (v78 &
                                                                         127) /
                                                      128.0)) * (a74[v78 ^
                                                                     128] -
                                                                 a74[v78]) : a74[v78] +
                a74[v78 ^ 128];
        }
        r79 = r76;
        
        float _Complex _a80[r76];
        float _Complex *a80 = _a80;
        
        for (v81 = 0; v81 < r76; v81++) {
            a80[v81] = !((v81 & 64) == 0) ? exp(I * (FELD_PI * (float) (v81 &
                                                                        63) /
                                                     64.0)) * (a77[v81 ^ 64] -
                                                               a77[v81]) : a77[v81] +
                a77[v81 ^ 64];
        }
        r82 = r79;
        
        float _Complex _a83[r79];
        float _Complex *a83 = _a83;
        
        for (v84 = 0; v84 < r79; v84++) {
            a83[v84] = !((v84 & 32) == 0) ? exp(I * (FELD_PI * (float) (v84 &
                                                                        31) /
                                                     32.0)) * (a80[v84 ^ 32] -
                                                               a80[v84]) : a80[v84] +
                a80[v84 ^ 32];
        }
        r85 = r82;
        
        float _Complex _a86[r82];
        float _Complex *a86 = _a86;
        
        for (v87 = 0; v87 < r82; v87++) {
            a86[v87] = !((v87 & 16) == 0) ? exp(I * (FELD_PI * (float) (v87 &
                                                                        15) /
                                                     16.0)) * (a83[v87 ^ 16] -
                                                               a83[v87]) : a83[v87] +
                a83[v87 ^ 16];
        }
        r88 = r85;
        
        float _Complex _a89[r85];
        float _Complex *a89 = _a89;
        
        for (v90 = 0; v90 < r85; v90++) {
            a89[v90] = !((v90 & 8) == 0) ? exp(I * (FELD_PI * (float) (v90 &
                                                                       7) /
                                                    8.0)) * (a86[v90 ^ 8] -
                                                             a86[v90]) : a86[v90] +
                a86[v90 ^ 8];
        }
        r91 = r88;
        
        float _Complex _a92[r88];
        float _Complex *a92 = _a92;
        
        for (v93 = 0; v93 < r88; v93++) {
            a92[v93] = !((v93 & 4) == 0) ? exp(I * (FELD_PI * (float) (v93 &
                                                                       3) /
                                                    4.0)) * (a89[v93 ^ 4] -
                                                             a89[v93]) : a89[v93] +
                a89[v93 ^ 4];
        }
        r94 = r91;
        
        float _Complex _a95[r91];
        float _Complex *a95 = _a95;
        
        for (v96 = 0; v96 < r91; v96++) {
            a95[v96] = !((v96 & 2) == 0) ? exp(I * (FELD_PI * (float) (v96 &
                                                                       1) /
                                                    2.0)) * (a92[v96 ^ 2] -
                                                             a92[v96]) : a92[v96] +
                a92[v96 ^ 2];
        }
        r97 = r94;
        
        float _Complex _a98[r94];
        float _Complex *a98 = _a98;
        
        for (v99 = 0; v99 < r94; v99++) {
            a98[v99] = !((v99 & 1) == 0) ? exp(I * (FELD_PI * (float) (v99 &
                                                                       0) /
                                                    1.0)) * (a95[v99 ^ 1] -
                                                             a95[v99]) : a95[v99] +
                a95[v99 ^ 1];
        }
        r100 = r97;
        
        float _Complex _a101[r97];
        float _Complex *a101 = _a101;
        
        for (v102 = 0; v102 < r97; v102++) {
            a101[v102] = a98[(v102 >> 1 >> 1 << 1 | (v102 & 1)) << 1 | (v102 >>
                                                                        1 & 1)];
        }
        r103 = r100;
        
        float _Complex _a104[r100];
        float _Complex *a104 = _a104;
        
        for (v105 = 0; v105 < r100; v105++) {
            a104[v105] = a101[(v105 >> 1 >> 2 << 1 | (v105 & 1)) << 2 | (v105 >>
                                                                         1 &
                                                                         3)];
        }
        r106 = r103;
        
        float _Complex _a107[r103];
        float _Complex *a107 = _a107;
        
        for (v108 = 0; v108 < r103; v108++) {
            a107[v108] = a104[(v108 >> 1 >> 3 << 1 | (v108 & 1)) << 3 | (v108 >>
                                                                         1 &
                                                                         7)];
        }
        r109 = r106;
        
        float _Complex _a110[r106];
        float _Complex *a110 = _a110;
        
        for (v111 = 0; v111 < r106; v111++) {
            a110[v111] = a107[(v111 >> 1 >> 4 << 1 | (v111 & 1)) << 4 | (v111 >>
                                                                         1 &
                                                                         15)];
        }
        r112 = r109;
        
        float _Complex _a113[r109];
        float _Complex *a113 = _a113;
        
        for (v114 = 0; v114 < r109; v114++) {
            a113[v114] = a110[(v114 >> 1 >> 5 << 1 | (v114 & 1)) << 5 | (v114 >>
                                                                         1 &
                                                                         31)];
        }
        r115 = r112;
        
        float _Complex _a116[r112];
        float _Complex *a116 = _a116;
        
        for (v117 = 0; v117 < r112; v117++) {
            a116[v117] = a113[(v117 >> 1 >> 6 << 1 | (v117 & 1)) << 6 | (v117 >>
                                                                         1 &
                                                                         63)];
        }
        r118 = r115;
        
        float _Complex _a119[r115];
        float _Complex *a119 = _a119;
        
        for (v120 = 0; v120 < r115; v120++) {
            a119[v120] = a116[(v120 >> 1 >> 7 << 1 | (v120 & 1)) << 7 | (v120 >>
                                                                         1 &
                                                                         127)];
        }
        r121 = r118;
        
        float _Complex _a122[r118];
        float _Complex *a122 = _a122;
        
        for (v123 = 0; v123 < r118; v123++) {
            a122[v123] = a119[(v123 >> 1 >> 8 << 1 | (v123 & 1)) << 8 | (v123 >>
                                                                         1 &
                                                                         255)];
        }
        r124 = r121;
        
        float _Complex _a125[r121];
        float _Complex *a125 = _a125;
        
        for (v126 = 0; v126 < r121; v126++) {
            a125[v126] = a122[(v126 >> 1 >> 9 << 1 | (v126 & 1)) << 9 | (v126 >>
                                                                         1 &
                                                                         511)];
        }
        r127 = r124;
        
        float _a128[r124];
        float *a128 = _a128;
        
        for (v129 = 0; v129 < r124; v129++) {
            a128[v129] = creal(a125[v129]) / 4096.0 * (-(0.5 * cos(2.0 *
                                                         FELD_PI *
                                                         (float) v129 /
                                                         (float) r124)) + 0.5);
        }
        v130 = r127;
        v131 = v130;
        v132 = chan_write(chan1, sizeof(v131), &v131);
        v133 = chan_write(chan1, sizeof(*a128) * (v130 - 0), &a128[0]);
        if (!v133) {
            chan_close(chan0);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
    }
    chan_close(chan0);
    chan_close(chan1);
    return NULL;
}
void *thread_t134(void *unused)
{
    while (1) {
        uint32_t v135;
        bool v137;
        uint32_t r138;
        uint32_t v139;
        bool v141;
        uint32_t v143;
        bool v144;
        
        chan_read(chan1, sizeof(v135), &v135);
        
        float _a136[v135];
        float *a136 = _a136;
        
        chan_read(chan1, sizeof(*a136) * (v135 - 0), &a136[0]);
        v137 = chan_last_read_ok(chan1);
        r138 = v135;
        v139 = r138;
        
        float _a140[v139];
        float *a140 = _a140;
        
        memcpy(a140, a136, v139 * sizeof(float));
        v141 = chan_last_read_ok(chan1);
        if (!v141) {
            pthread_cancel(t134);
            pthread_join(t134, NULL);
        }
        
        float _a142[v139];
        float *a142 = _a142;
        
        for (v143 = 0; v143 < v139; v143++) {
            a142[v143] = a140[v143];
        }
        v144 = emit_samples(a142);
        if (!v144) {
            chan_close(chan1);
            pthread_cancel(t134);
            pthread_join(t134, NULL);
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
    pthread_create(&t134, NULL, thread_t134, NULL);
    while (1) {
        float _a145[1024];
        float *a145 = _a145;
        bool v146;
        uint32_t r147;
        float _a148[1024];
        float *a148 = _a148;
        uint32_t v149;
        uint32_t v150;
        uint32_t v151;
        bool v152;
        bool v153;
        
        v146 = receive_samples(a145);
        if (!v146) {
            break;
        }
        r147 = 1024;
        for (v149 = 0; v149 < 1024; v149++) {
            a148[v149] = a145[v149];
        }
        v150 = r147;
        v151 = v150;
        v152 = chan_write(chan0, sizeof(v151), &v151);
        v153 = chan_write(chan0, sizeof(*a148) * (v150 - 0), &a148[0]);
        if (!v153) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t134, NULL);
    teardown_queues();
    return 0;
}

