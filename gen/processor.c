#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
void *thread_t2(void *unused);
void *thread_t19(void *unused);
void *thread_t60(void *unused);
void *thread_t78(void *unused);
void *thread_t94(void *unused);
void *thread_t112(void *unused);
void *thread_t153(void *unused);
void *thread_t169(void *unused);
pthread_t t112;
pthread_t t153;
pthread_t t169;
pthread_t t19;
pthread_t t2;
pthread_t t60;
pthread_t t78;
pthread_t t94;
chan_t chan0;
chan_t chan1;
#define FELD_PI 3.141592653589793
void *thread_t2(void *unused)
{
    uint32_t r3;
    float _a4[1024];
    float *a4 = _a4;
    uint32_t v5;
    
    r3 = 1024;
    for (v5 = 0; v5 < 1024; v5++) {
        a4[v5] = -(0.5 * cos(2.0 * FELD_PI * (float) v5 / 1024.0)) + 0.5;
    }
    while (1) {
        uint32_t v6;
        bool v8;
        uint32_t r9;
        bool v10;
        uint32_t r11;
        uint32_t v13;
        uint32_t v14;
        uint32_t v15;
        bool v16;
        bool v17;
        
        chan_read(chan0, sizeof(v6), &v6);
        
        float _a7[v6];
        float *a7 = _a7;
        
        chan_read(chan0, sizeof(*a7) * (v6 - 0), &a7[0]);
        v8 = chan_last_read_ok(chan0);
        r9 = v6;
        v10 = chan_last_read_ok(chan0);
        if (!v10) {
            chan_close(chan1);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
        r11 = r9 <= r3 ? r9 : r3;
        
        float _Complex _a12[r9 <= r3 ? r9 : r3];
        float _Complex *a12 = _a12;
        
        for (v13 = 0; v13 < (r9 <= r3 ? r9 : r3); v13++) {
            a12[v13] = a7[v13] * a4[v13];
        }
        v14 = r11;
        v15 = v14;
        v16 = chan_write(chan1, sizeof(v15), &v15);
        v17 = chan_write(chan1, sizeof(*a12) * (v14 - 0), &a12[0]);
        if (!v17) {
            chan_close(chan0);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
    }
    chan_close(chan0);
    chan_close(chan1);
    return NULL;
}
chan_t chan18;
void *thread_t19(void *unused)
{
    uint32_t r20;
    float _Complex _a21[512];
    float _Complex *a21 = _a21;
    uint32_t v22;
    uint32_t r23;
    float _Complex _a24[1024];
    float _Complex *a24 = _a24;
    uint32_t r25;
    float _Complex _a26[1024];
    float _Complex *a26 = _a26;
    
    r20 = 512;
    for (v22 = 0; v22 < 512; v22++) {
        a21[v22] = exp(I * (FELD_PI * (float) v22 * -1.953125e-3));
    }
    r23 = 1024;
    r25 = 1024;
    while (1) {
        uint32_t v27;
        bool v29;
        uint32_t r30;
        bool v31;
        uint32_t v32;
        uint32_t v33;
        uint32_t v34;
        uint32_t v35;
        uint32_t v36;
        uint32_t v37;
        uint32_t v38;
        uint32_t v39;
        uint32_t v40;
        uint32_t v41;
        uint32_t v42;
        uint32_t v43;
        uint32_t v44;
        uint32_t v45;
        uint32_t v46;
        uint32_t v47;
        uint32_t v48;
        uint32_t v49;
        uint32_t v50;
        uint32_t v51;
        uint32_t r52;
        uint32_t v54;
        uint32_t v55;
        uint32_t v56;
        bool v57;
        bool v58;
        
        chan_read(chan1, sizeof(v27), &v27);
        
        float _Complex _a28[v27];
        float _Complex *a28 = _a28;
        
        chan_read(chan1, sizeof(*a28) * (v27 - 0), &a28[0]);
        v29 = chan_last_read_ok(chan1);
        r30 = v27;
        v31 = chan_last_read_ok(chan1);
        if (!v31) {
            chan_close(chan18);
            pthread_cancel(t19);
            pthread_join(t19, NULL);
        }
        for (v32 = 0; v32 < r30; v32++) {
            a24[v32] = a28[v32];
        }
        for (v33 = 0; v33 < 1024; v33++) {
            a26[v33] = !((v33 & 512) == 0) ? a21[v33 << 0 & 511] * (a24[v33 ^
                                                                        512] -
                                                                    a24[v33]) : a24[v33] +
                a24[v33 ^ 512];
        }
        for (v34 = 0; v34 < 1024; v34++) {
            a24[v34] = !((v34 & 256) == 0) ? a21[v34 << 1 & 511] * (a26[v34 ^
                                                                        256] -
                                                                    a26[v34]) : a26[v34] +
                a26[v34 ^ 256];
        }
        for (v35 = 0; v35 < 1024; v35++) {
            a26[v35] = !((v35 & 128) == 0) ? a21[v35 << 2 & 511] * (a24[v35 ^
                                                                        128] -
                                                                    a24[v35]) : a24[v35] +
                a24[v35 ^ 128];
        }
        for (v36 = 0; v36 < 1024; v36++) {
            a24[v36] = !((v36 & 64) == 0) ? a21[v36 << 3 & 511] * (a26[v36 ^
                                                                       64] -
                                                                   a26[v36]) : a26[v36] +
                a26[v36 ^ 64];
        }
        for (v37 = 0; v37 < 1024; v37++) {
            a26[v37] = !((v37 & 32) == 0) ? a21[v37 << 4 & 511] * (a24[v37 ^
                                                                       32] -
                                                                   a24[v37]) : a24[v37] +
                a24[v37 ^ 32];
        }
        for (v38 = 0; v38 < 1024; v38++) {
            a24[v38] = !((v38 & 16) == 0) ? a21[v38 << 5 & 511] * (a26[v38 ^
                                                                       16] -
                                                                   a26[v38]) : a26[v38] +
                a26[v38 ^ 16];
        }
        for (v39 = 0; v39 < 1024; v39++) {
            a26[v39] = !((v39 & 8) == 0) ? a21[v39 << 6 & 511] * (a24[v39 ^ 8] -
                                                                  a24[v39]) : a24[v39] +
                a24[v39 ^ 8];
        }
        for (v40 = 0; v40 < 1024; v40++) {
            a24[v40] = !((v40 & 4) == 0) ? a21[v40 << 7 & 511] * (a26[v40 ^ 4] -
                                                                  a26[v40]) : a26[v40] +
                a26[v40 ^ 4];
        }
        for (v41 = 0; v41 < 1024; v41++) {
            a26[v41] = !((v41 & 2) == 0) ? a21[v41 << 8 & 511] * (a24[v41 ^ 2] -
                                                                  a24[v41]) : a24[v41] +
                a24[v41 ^ 2];
        }
        for (v42 = 0; v42 < 1024; v42++) {
            a24[v42] = !((v42 & 1) == 0) ? a21[v42 << 9 & 511] * (a26[v42 ^ 1] -
                                                                  a26[v42]) : a26[v42] +
                a26[v42 ^ 1];
        }
        for (v43 = 0; v43 < r23; v43++) {
            a26[v43] = a24[(v43 >> 1 >> 1 << 1 | (v43 & 1)) << 1 | (v43 >> 1 &
                                                                    1)];
        }
        for (v44 = 0; v44 < r25; v44++) {
            a24[v44] = a26[(v44 >> 1 >> 2 << 1 | (v44 & 1)) << 2 | (v44 >> 1 &
                                                                    3)];
        }
        for (v45 = 0; v45 < r23; v45++) {
            a26[v45] = a24[(v45 >> 1 >> 3 << 1 | (v45 & 1)) << 3 | (v45 >> 1 &
                                                                    7)];
        }
        for (v46 = 0; v46 < r25; v46++) {
            a24[v46] = a26[(v46 >> 1 >> 4 << 1 | (v46 & 1)) << 4 | (v46 >> 1 &
                                                                    15)];
        }
        for (v47 = 0; v47 < r23; v47++) {
            a26[v47] = a24[(v47 >> 1 >> 5 << 1 | (v47 & 1)) << 5 | (v47 >> 1 &
                                                                    31)];
        }
        for (v48 = 0; v48 < r25; v48++) {
            a24[v48] = a26[(v48 >> 1 >> 6 << 1 | (v48 & 1)) << 6 | (v48 >> 1 &
                                                                    63)];
        }
        for (v49 = 0; v49 < r23; v49++) {
            a26[v49] = a24[(v49 >> 1 >> 7 << 1 | (v49 & 1)) << 7 | (v49 >> 1 &
                                                                    127)];
        }
        for (v50 = 0; v50 < r25; v50++) {
            a24[v50] = a26[(v50 >> 1 >> 8 << 1 | (v50 & 1)) << 8 | (v50 >> 1 &
                                                                    255)];
        }
        for (v51 = 0; v51 < r23; v51++) {
            a26[v51] = a24[(v51 >> 1 >> 9 << 1 | (v51 & 1)) << 9 | (v51 >> 1 &
                                                                    511)];
        }
        r52 = r23;
        
        float _Complex _a53[r23];
        float _Complex *a53 = _a53;
        
        for (v54 = 0; v54 < r23; v54++) {
            a53[v54] = a24[(v54 >> 1 >> 9 << 1 | (v54 & 1)) << 9 | (v54 >> 1 &
                                                                    511)];
        }
        v55 = r52;
        v56 = v55;
        v57 = chan_write(chan18, sizeof(v56), &v56);
        v58 = chan_write(chan18, sizeof(*a53) * (v55 - 0), &a53[0]);
        if (!v58) {
            chan_close(chan1);
            pthread_cancel(t19);
            pthread_join(t19, NULL);
        }
    }
    chan_close(chan1);
    chan_close(chan18);
    return NULL;
}
chan_t chan59;
void *thread_t60(void *unused)
{
    uint32_t r61;
    float _a62[513];
    float *a62 = _a62;
    uint32_t v63;
    
    r61 = 513;
    for (v63 = 0; v63 < 513; v63++) {
        a62[v63] = 0.0;
    }
    while (1) {
        uint32_t v64;
        bool v66;
        uint32_t r67;
        bool v68;
        uint32_t r69;
        float _Complex _a70[513];
        float _Complex *a70 = _a70;
        uint32_t v71;
        uint32_t v72;
        uint32_t v73;
        bool v74;
        bool v75;
        uint32_t v76;
        
        chan_read(chan18, sizeof(v64), &v64);
        
        float _Complex _a65[v64];
        float _Complex *a65 = _a65;
        
        chan_read(chan18, sizeof(*a65) * (v64 - 0), &a65[0]);
        v66 = chan_last_read_ok(chan18);
        r67 = v64;
        v68 = chan_last_read_ok(chan18);
        if (!v68) {
            chan_close(chan59);
            pthread_cancel(t60);
            pthread_join(t60, NULL);
        }
        r69 = 513;
        for (v71 = 0; v71 < 513; v71++) {
            a70[v71] = 2.0 * cabs(a65[v71]) + I * (((float) v71 + 4.0 *
                                                    (carg(a65[v71]) - a62[v71] -
                                                     (float) v71 * 1.5707964) /
                                                    (2.0 * FELD_PI)) *
                                                   43.066406);
        }
        v72 = r69;
        v73 = v72;
        v74 = chan_write(chan59, sizeof(v73), &v73);
        v75 = chan_write(chan59, sizeof(*a70) * (v72 - 0), &a70[0]);
        if (!v75) {
            chan_close(chan18);
            pthread_cancel(t60);
            pthread_join(t60, NULL);
        }
        for (v76 = 0; v76 < 513; v76++) {
            a62[v76] = carg(a65[v76]);
        }
    }
    chan_close(chan18);
    chan_close(chan59);
    return NULL;
}
chan_t chan77;
void *thread_t78(void *unused)
{
    while (1) {
        uint32_t v79;
        bool v81;
        uint32_t r82;
        bool v83;
        float _Complex _a84[513];
        float _Complex *a84 = _a84;
        uint32_t v85;
        uint32_t r86;
        float _Complex _a87[513];
        float _Complex *a87 = _a87;
        uint32_t v88;
        uint32_t v89;
        uint32_t v90;
        bool v91;
        bool v92;
        
        chan_read(chan59, sizeof(v79), &v79);
        
        float _Complex _a80[v79];
        float _Complex *a80 = _a80;
        
        chan_read(chan59, sizeof(*a80) * (v79 - 0), &a80[0]);
        v81 = chan_last_read_ok(chan59);
        r82 = v79;
        v83 = chan_last_read_ok(chan59);
        if (!v83) {
            chan_close(chan77);
            pthread_cancel(t78);
            pthread_join(t78, NULL);
        }
        for (v85 = 0; v85 < 513; v85++) {
            a84[(uint32_t) lround((float) v85 * 2.0)] =
                (uint32_t) lround((float) v85 * 2.0) < 513 ? creal(a80[v85]) +
                I * (2.0 * cimag(a80[v85])) : 0.0;
        }
        r86 = 513;
        for (v88 = 0; v88 < 513; v88++) {
            a87[v88] = a84[v88];
        }
        v89 = r86;
        v90 = v89;
        v91 = chan_write(chan77, sizeof(v90), &v90);
        v92 = chan_write(chan77, sizeof(*a87) * (v89 - 0), &a87[0]);
        if (!v92) {
            chan_close(chan59);
            pthread_cancel(t78);
            pthread_join(t78, NULL);
        }
    }
    chan_close(chan59);
    chan_close(chan77);
    return NULL;
}
chan_t chan93;
void *thread_t94(void *unused)
{
    uint32_t r95;
    float _a96[513];
    float *a96 = _a96;
    uint32_t v97;
    
    r95 = 513;
    for (v97 = 0; v97 < 513; v97++) {
        a96[v97] = 0.0;
    }
    while (1) {
        uint32_t v98;
        bool v100;
        uint32_t r101;
        bool v102;
        uint32_t v103;
        uint32_t r104;
        float _Complex _a105[1024];
        float _Complex *a105 = _a105;
        uint32_t v106;
        uint32_t v107;
        uint32_t v108;
        bool v109;
        bool v110;
        
        chan_read(chan77, sizeof(v98), &v98);
        
        float _Complex _a99[v98];
        float _Complex *a99 = _a99;
        
        chan_read(chan77, sizeof(*a99) * (v98 - 0), &a99[0]);
        v100 = chan_last_read_ok(chan77);
        r101 = v98;
        v102 = chan_last_read_ok(chan77);
        if (!v102) {
            chan_close(chan93);
            pthread_cancel(t94);
            pthread_join(t94, NULL);
        }
        for (v103 = 0; v103 < 513; v103++) {
            a96[v103] = a96[v103] + (2.0 * FELD_PI * ((cimag(a99[v103]) -
                                                       (float) v103 *
                                                       43.066406) / 43.066406) /
                                     4.0 + (float) v103 * 1.5707964);
        }
        r104 = 1024;
        for (v106 = 0; v106 < 1024; v106++) {
            a105[v106] = v106 <= 513 ? creal(a99[v106]) * exp(I * (a96[v106] +
                                                                   (2.0 *
                                                                    FELD_PI *
                                                                    ((cimag(a99[v106]) -
                                                                      (float) v106 *
                                                                      43.066406) /
                                                                     43.066406) /
                                                                    4.0 +
                                                                    (float) v106 *
                                                                    1.5707964))) : 0.0;
        }
        v107 = r104;
        v108 = v107;
        v109 = chan_write(chan93, sizeof(v108), &v108);
        v110 = chan_write(chan93, sizeof(*a105) * (v107 - 0), &a105[0]);
        if (!v110) {
            chan_close(chan77);
            pthread_cancel(t94);
            pthread_join(t94, NULL);
        }
    }
    chan_close(chan77);
    chan_close(chan93);
    return NULL;
}
chan_t chan111;
void *thread_t112(void *unused)
{
    uint32_t r113;
    float _Complex _a114[512];
    float _Complex *a114 = _a114;
    uint32_t v115;
    uint32_t r116;
    float _Complex _a117[1024];
    float _Complex *a117 = _a117;
    uint32_t r118;
    float _Complex _a119[1024];
    float _Complex *a119 = _a119;
    
    r113 = 512;
    for (v115 = 0; v115 < 512; v115++) {
        a114[v115] = exp(I * (FELD_PI * (float) v115 * 1.953125e-3));
    }
    r116 = 1024;
    r118 = 1024;
    while (1) {
        uint32_t v120;
        bool v122;
        uint32_t r123;
        bool v124;
        uint32_t v125;
        uint32_t v126;
        uint32_t v127;
        uint32_t v128;
        uint32_t v129;
        uint32_t v130;
        uint32_t v131;
        uint32_t v132;
        uint32_t v133;
        uint32_t v134;
        uint32_t v135;
        uint32_t v136;
        uint32_t v137;
        uint32_t v138;
        uint32_t v139;
        uint32_t v140;
        uint32_t v141;
        uint32_t v142;
        uint32_t v143;
        uint32_t v144;
        uint32_t r145;
        uint32_t v147;
        uint32_t v148;
        uint32_t v149;
        bool v150;
        bool v151;
        
        chan_read(chan93, sizeof(v120), &v120);
        
        float _Complex _a121[v120];
        float _Complex *a121 = _a121;
        
        chan_read(chan93, sizeof(*a121) * (v120 - 0), &a121[0]);
        v122 = chan_last_read_ok(chan93);
        r123 = v120;
        v124 = chan_last_read_ok(chan93);
        if (!v124) {
            chan_close(chan111);
            pthread_cancel(t112);
            pthread_join(t112, NULL);
        }
        for (v125 = 0; v125 < r123; v125++) {
            a117[v125] = a121[v125];
        }
        for (v126 = 0; v126 < 1024; v126++) {
            a119[v126] = !((v126 & 512) == 0) ? a114[v126 << 0 & 511] *
                (a117[v126 ^ 512] - a117[v126]) : a117[v126] + a117[v126 ^ 512];
        }
        for (v127 = 0; v127 < 1024; v127++) {
            a117[v127] = !((v127 & 256) == 0) ? a114[v127 << 1 & 511] *
                (a119[v127 ^ 256] - a119[v127]) : a119[v127] + a119[v127 ^ 256];
        }
        for (v128 = 0; v128 < 1024; v128++) {
            a119[v128] = !((v128 & 128) == 0) ? a114[v128 << 2 & 511] *
                (a117[v128 ^ 128] - a117[v128]) : a117[v128] + a117[v128 ^ 128];
        }
        for (v129 = 0; v129 < 1024; v129++) {
            a117[v129] = !((v129 & 64) == 0) ? a114[v129 << 3 & 511] *
                (a119[v129 ^ 64] - a119[v129]) : a119[v129] + a119[v129 ^ 64];
        }
        for (v130 = 0; v130 < 1024; v130++) {
            a119[v130] = !((v130 & 32) == 0) ? a114[v130 << 4 & 511] *
                (a117[v130 ^ 32] - a117[v130]) : a117[v130] + a117[v130 ^ 32];
        }
        for (v131 = 0; v131 < 1024; v131++) {
            a117[v131] = !((v131 & 16) == 0) ? a114[v131 << 5 & 511] *
                (a119[v131 ^ 16] - a119[v131]) : a119[v131] + a119[v131 ^ 16];
        }
        for (v132 = 0; v132 < 1024; v132++) {
            a119[v132] = !((v132 & 8) == 0) ? a114[v132 << 6 & 511] *
                (a117[v132 ^ 8] - a117[v132]) : a117[v132] + a117[v132 ^ 8];
        }
        for (v133 = 0; v133 < 1024; v133++) {
            a117[v133] = !((v133 & 4) == 0) ? a114[v133 << 7 & 511] *
                (a119[v133 ^ 4] - a119[v133]) : a119[v133] + a119[v133 ^ 4];
        }
        for (v134 = 0; v134 < 1024; v134++) {
            a119[v134] = !((v134 & 2) == 0) ? a114[v134 << 8 & 511] *
                (a117[v134 ^ 2] - a117[v134]) : a117[v134] + a117[v134 ^ 2];
        }
        for (v135 = 0; v135 < 1024; v135++) {
            a117[v135] = !((v135 & 1) == 0) ? a114[v135 << 9 & 511] *
                (a119[v135 ^ 1] - a119[v135]) : a119[v135] + a119[v135 ^ 1];
        }
        for (v136 = 0; v136 < r116; v136++) {
            a119[v136] = a117[(v136 >> 1 >> 1 << 1 | (v136 & 1)) << 1 | (v136 >>
                                                                         1 &
                                                                         1)];
        }
        for (v137 = 0; v137 < r118; v137++) {
            a117[v137] = a119[(v137 >> 1 >> 2 << 1 | (v137 & 1)) << 2 | (v137 >>
                                                                         1 &
                                                                         3)];
        }
        for (v138 = 0; v138 < r116; v138++) {
            a119[v138] = a117[(v138 >> 1 >> 3 << 1 | (v138 & 1)) << 3 | (v138 >>
                                                                         1 &
                                                                         7)];
        }
        for (v139 = 0; v139 < r118; v139++) {
            a117[v139] = a119[(v139 >> 1 >> 4 << 1 | (v139 & 1)) << 4 | (v139 >>
                                                                         1 &
                                                                         15)];
        }
        for (v140 = 0; v140 < r116; v140++) {
            a119[v140] = a117[(v140 >> 1 >> 5 << 1 | (v140 & 1)) << 5 | (v140 >>
                                                                         1 &
                                                                         31)];
        }
        for (v141 = 0; v141 < r118; v141++) {
            a117[v141] = a119[(v141 >> 1 >> 6 << 1 | (v141 & 1)) << 6 | (v141 >>
                                                                         1 &
                                                                         63)];
        }
        for (v142 = 0; v142 < r116; v142++) {
            a119[v142] = a117[(v142 >> 1 >> 7 << 1 | (v142 & 1)) << 7 | (v142 >>
                                                                         1 &
                                                                         127)];
        }
        for (v143 = 0; v143 < r118; v143++) {
            a117[v143] = a119[(v143 >> 1 >> 8 << 1 | (v143 & 1)) << 8 | (v143 >>
                                                                         1 &
                                                                         255)];
        }
        for (v144 = 0; v144 < r116; v144++) {
            a119[v144] = a117[(v144 >> 1 >> 9 << 1 | (v144 & 1)) << 9 | (v144 >>
                                                                         1 &
                                                                         511)];
        }
        r145 = r116;
        
        float _Complex _a146[r116];
        float _Complex *a146 = _a146;
        
        for (v147 = 0; v147 < r116; v147++) {
            a146[v147] = a117[(v147 >> 1 >> 9 << 1 | (v147 & 1)) << 9 | (v147 >>
                                                                         1 &
                                                                         511)];
        }
        v148 = r145;
        v149 = v148;
        v150 = chan_write(chan111, sizeof(v149), &v149);
        v151 = chan_write(chan111, sizeof(*a146) * (v148 - 0), &a146[0]);
        if (!v151) {
            chan_close(chan93);
            pthread_cancel(t112);
            pthread_join(t112, NULL);
        }
    }
    chan_close(chan93);
    chan_close(chan111);
    return NULL;
}
chan_t chan152;
void *thread_t153(void *unused)
{
    uint32_t r154;
    float _a155[1024];
    float *a155 = _a155;
    uint32_t v156;
    
    r154 = 1024;
    for (v156 = 0; v156 < 1024; v156++) {
        a155[v156] = -(0.5 * cos(2.0 * FELD_PI * (float) v156 / 1024.0)) + 0.5;
    }
    while (1) {
        uint32_t v157;
        bool v159;
        uint32_t r160;
        bool v161;
        uint32_t r162;
        uint32_t v164;
        uint32_t v165;
        uint32_t v166;
        bool v167;
        bool v168;
        
        chan_read(chan111, sizeof(v157), &v157);
        
        float _Complex _a158[v157];
        float _Complex *a158 = _a158;
        
        chan_read(chan111, sizeof(*a158) * (v157 - 0), &a158[0]);
        v159 = chan_last_read_ok(chan111);
        r160 = v157;
        v161 = chan_last_read_ok(chan111);
        if (!v161) {
            chan_close(chan152);
            pthread_cancel(t153);
            pthread_join(t153, NULL);
        }
        r162 = r160 <= r154 ? r160 : r154;
        
        float _a163[r160 <= r154 ? r160 : r154];
        float *a163 = _a163;
        
        for (v164 = 0; v164 < (r160 <= r154 ? r160 : r154); v164++) {
            a163[v164] = creal(a158[v164]) / 4096.0 * a155[v164];
        }
        v165 = r162;
        v166 = v165;
        v167 = chan_write(chan152, sizeof(v166), &v166);
        v168 = chan_write(chan152, sizeof(*a163) * (v165 - 0), &a163[0]);
        if (!v168) {
            chan_close(chan111);
            pthread_cancel(t153);
            pthread_join(t153, NULL);
        }
    }
    chan_close(chan111);
    chan_close(chan152);
    return NULL;
}
void *thread_t169(void *unused)
{
    while (1) {
        uint32_t v170;
        bool v172;
        uint32_t r173;
        bool v174;
        uint32_t v176;
        bool v177;
        
        chan_read(chan152, sizeof(v170), &v170);
        
        float _a171[v170];
        float *a171 = _a171;
        
        chan_read(chan152, sizeof(*a171) * (v170 - 0), &a171[0]);
        v172 = chan_last_read_ok(chan152);
        r173 = v170;
        v174 = chan_last_read_ok(chan152);
        if (!v174) {
            pthread_cancel(t169);
            pthread_join(t169, NULL);
        }
        
        float _a175[r173];
        float *a175 = _a175;
        
        for (v176 = 0; v176 < r173; v176++) {
            a175[v176] = a171[v176];
        }
        v177 = emit_samples(a175);
        if (!v177) {
            chan_close(chan152);
            pthread_cancel(t169);
            pthread_join(t169, NULL);
        }
    }
    return NULL;
}
int main()
{
    setup_queues();
    chan0 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 * sizeof(float)));
    chan1 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                   sizeof(float _Complex)));
    pthread_create(&t2, NULL, thread_t2, NULL);
    chan18 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                    sizeof(float _Complex)));
    pthread_create(&t19, NULL, thread_t19, NULL);
    chan59 = chan_new(10 * sizeof(uint32_t) + 10 * (513 *
                                                    sizeof(float _Complex)));
    pthread_create(&t60, NULL, thread_t60, NULL);
    chan77 = chan_new(10 * sizeof(uint32_t) + 10 * (513 *
                                                    sizeof(float _Complex)));
    pthread_create(&t78, NULL, thread_t78, NULL);
    chan93 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                    sizeof(float _Complex)));
    pthread_create(&t94, NULL, thread_t94, NULL);
    chan111 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t112, NULL, thread_t112, NULL);
    chan152 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 * sizeof(float)));
    pthread_create(&t153, NULL, thread_t153, NULL);
    pthread_create(&t169, NULL, thread_t169, NULL);
    while (1) {
        float _a178[1024];
        float *a178 = _a178;
        bool v179;
        uint32_t r180;
        float _a181[1024];
        float *a181 = _a181;
        uint32_t v182;
        uint32_t v183;
        uint32_t v184;
        bool v185;
        bool v186;
        
        v179 = receive_samples(a178);
        if (!v179) {
            break;
        }
        r180 = 1024;
        for (v182 = 0; v182 < 1024; v182++) {
            a181[v182] = a178[v182];
        }
        v183 = r180;
        v184 = v183;
        v185 = chan_write(chan0, sizeof(v184), &v184);
        v186 = chan_write(chan0, sizeof(*a181) * (v183 - 0), &a181[0]);
        if (!v186) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t169, NULL);
    teardown_queues();
    return 0;
}

