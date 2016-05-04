#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
void *thread_t2(void *unused);
void *thread_t21(void *unused);
void *thread_t94(void *unused);
void *thread_t116(void *unused);
void *thread_t134(void *unused);
void *thread_t156(void *unused);
void *thread_t229(void *unused);
void *thread_t247(void *unused);
pthread_t t116;
pthread_t t134;
pthread_t t156;
pthread_t t2;
pthread_t t21;
pthread_t t229;
pthread_t t247;
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
        uint32_t v10;
        bool v12;
        uint32_t r13;
        uint32_t v15;
        uint32_t v16;
        uint32_t v17;
        bool v18;
        bool v19;
        
        chan_read(chan0, sizeof(v6), &v6);
        
        float _a7[v6];
        float *a7 = _a7;
        
        chan_read(chan0, sizeof(*a7) * (v6 - 0), &a7[0]);
        v8 = chan_last_read_ok(chan0);
        r9 = v6;
        v10 = r9;
        
        float _a11[v10];
        float *a11 = _a11;
        
        memcpy(a11, a7, v10 * sizeof(float));
        v12 = chan_last_read_ok(chan0);
        if (!v12) {
            chan_close(chan1);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
        r13 = v10 <= r3 ? v10 : r3;
        
        float _Complex _a14[v10 <= r3 ? v10 : r3];
        float _Complex *a14 = _a14;
        
        for (v15 = 0; v15 < (v10 <= r3 ? v10 : r3); v15++) {
            a14[v15] = a11[v15] * a4[v15];
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
chan_t chan20;
void *thread_t21(void *unused)
{
    uint32_t r22;
    float _Complex _a23[512];
    float _Complex *a23 = _a23;
    uint32_t v24;
    
    r22 = 512;
    for (v24 = 0; v24 < 512; v24++) {
        a23[v24] = exp(I * (FELD_PI * (float) v24 * -1.953125e-3));
    }
    while (1) {
        uint32_t v25;
        bool v27;
        uint32_t r28;
        uint32_t v29;
        bool v31;
        uint32_t r32;
        float _Complex _a33[1024];
        float _Complex *a33 = _a33;
        uint32_t v34;
        uint32_t r35;
        float _Complex _a36[1024];
        float _Complex *a36 = _a36;
        uint32_t v37;
        uint32_t r38;
        float _Complex _a39[1024];
        float _Complex *a39 = _a39;
        uint32_t v40;
        uint32_t r41;
        float _Complex _a42[1024];
        float _Complex *a42 = _a42;
        uint32_t v43;
        uint32_t r44;
        float _Complex _a45[1024];
        float _Complex *a45 = _a45;
        uint32_t v46;
        uint32_t r47;
        float _Complex _a48[1024];
        float _Complex *a48 = _a48;
        uint32_t v49;
        uint32_t r50;
        float _Complex _a51[1024];
        float _Complex *a51 = _a51;
        uint32_t v52;
        uint32_t r53;
        float _Complex _a54[1024];
        float _Complex *a54 = _a54;
        uint32_t v55;
        uint32_t r56;
        float _Complex _a57[1024];
        float _Complex *a57 = _a57;
        uint32_t v58;
        uint32_t r59;
        float _Complex _a60[1024];
        float _Complex *a60 = _a60;
        uint32_t v61;
        uint32_t r62;
        uint32_t v64;
        uint32_t r65;
        uint32_t v67;
        uint32_t r68;
        uint32_t v70;
        uint32_t r71;
        uint32_t v73;
        uint32_t r74;
        uint32_t v76;
        uint32_t r77;
        uint32_t v79;
        uint32_t r80;
        uint32_t v82;
        uint32_t r83;
        uint32_t v85;
        uint32_t r86;
        uint32_t v88;
        uint32_t v89;
        uint32_t v90;
        bool v91;
        bool v92;
        
        chan_read(chan1, sizeof(v25), &v25);
        
        float _Complex _a26[v25];
        float _Complex *a26 = _a26;
        
        chan_read(chan1, sizeof(*a26) * (v25 - 0), &a26[0]);
        v27 = chan_last_read_ok(chan1);
        r28 = v25;
        v29 = r28;
        
        float _Complex _a30[v29];
        float _Complex *a30 = _a30;
        
        memcpy(a30, a26, v29 * sizeof(float _Complex));
        v31 = chan_last_read_ok(chan1);
        if (!v31) {
            chan_close(chan20);
            pthread_cancel(t21);
            pthread_join(t21, NULL);
        }
        r32 = 1024;
        for (v34 = 0; v34 < 1024; v34++) {
            a33[v34] = !((v34 & 512) == 0) ? a23[v34 << 0 & 511] * (a30[v34 ^
                                                                        512] -
                                                                    a30[v34]) : a30[v34] +
                a30[v34 ^ 512];
        }
        r35 = 1024;
        for (v37 = 0; v37 < 1024; v37++) {
            a36[v37] = !((v37 & 256) == 0) ? a23[v37 << 1 & 511] * (a33[v37 ^
                                                                        256] -
                                                                    a33[v37]) : a33[v37] +
                a33[v37 ^ 256];
        }
        r38 = 1024;
        for (v40 = 0; v40 < 1024; v40++) {
            a39[v40] = !((v40 & 128) == 0) ? a23[v40 << 2 & 511] * (a36[v40 ^
                                                                        128] -
                                                                    a36[v40]) : a36[v40] +
                a36[v40 ^ 128];
        }
        r41 = 1024;
        for (v43 = 0; v43 < 1024; v43++) {
            a42[v43] = !((v43 & 64) == 0) ? a23[v43 << 3 & 511] * (a39[v43 ^
                                                                       64] -
                                                                   a39[v43]) : a39[v43] +
                a39[v43 ^ 64];
        }
        r44 = 1024;
        for (v46 = 0; v46 < 1024; v46++) {
            a45[v46] = !((v46 & 32) == 0) ? a23[v46 << 4 & 511] * (a42[v46 ^
                                                                       32] -
                                                                   a42[v46]) : a42[v46] +
                a42[v46 ^ 32];
        }
        r47 = 1024;
        for (v49 = 0; v49 < 1024; v49++) {
            a48[v49] = !((v49 & 16) == 0) ? a23[v49 << 5 & 511] * (a45[v49 ^
                                                                       16] -
                                                                   a45[v49]) : a45[v49] +
                a45[v49 ^ 16];
        }
        r50 = 1024;
        for (v52 = 0; v52 < 1024; v52++) {
            a51[v52] = !((v52 & 8) == 0) ? a23[v52 << 6 & 511] * (a48[v52 ^ 8] -
                                                                  a48[v52]) : a48[v52] +
                a48[v52 ^ 8];
        }
        r53 = 1024;
        for (v55 = 0; v55 < 1024; v55++) {
            a54[v55] = !((v55 & 4) == 0) ? a23[v55 << 7 & 511] * (a51[v55 ^ 4] -
                                                                  a51[v55]) : a51[v55] +
                a51[v55 ^ 4];
        }
        r56 = 1024;
        for (v58 = 0; v58 < 1024; v58++) {
            a57[v58] = !((v58 & 2) == 0) ? a23[v58 << 8 & 511] * (a54[v58 ^ 2] -
                                                                  a54[v58]) : a54[v58] +
                a54[v58 ^ 2];
        }
        r59 = 1024;
        for (v61 = 0; v61 < 1024; v61++) {
            a60[v61] = !((v61 & 1) == 0) ? a23[v61 << 9 & 511] * (a57[v61 ^ 1] -
                                                                  a57[v61]) : a57[v61] +
                a57[v61 ^ 1];
        }
        r62 = r59;
        
        float _Complex _a63[r59];
        float _Complex *a63 = _a63;
        
        for (v64 = 0; v64 < r59; v64++) {
            a63[v64] = a60[(v64 >> 1 >> 1 << 1 | (v64 & 1)) << 1 | (v64 >> 1 &
                                                                    1)];
        }
        r65 = r62;
        
        float _Complex _a66[r62];
        float _Complex *a66 = _a66;
        
        for (v67 = 0; v67 < r62; v67++) {
            a66[v67] = a63[(v67 >> 1 >> 2 << 1 | (v67 & 1)) << 2 | (v67 >> 1 &
                                                                    3)];
        }
        r68 = r65;
        
        float _Complex _a69[r65];
        float _Complex *a69 = _a69;
        
        for (v70 = 0; v70 < r65; v70++) {
            a69[v70] = a66[(v70 >> 1 >> 3 << 1 | (v70 & 1)) << 3 | (v70 >> 1 &
                                                                    7)];
        }
        r71 = r68;
        
        float _Complex _a72[r68];
        float _Complex *a72 = _a72;
        
        for (v73 = 0; v73 < r68; v73++) {
            a72[v73] = a69[(v73 >> 1 >> 4 << 1 | (v73 & 1)) << 4 | (v73 >> 1 &
                                                                    15)];
        }
        r74 = r71;
        
        float _Complex _a75[r71];
        float _Complex *a75 = _a75;
        
        for (v76 = 0; v76 < r71; v76++) {
            a75[v76] = a72[(v76 >> 1 >> 5 << 1 | (v76 & 1)) << 5 | (v76 >> 1 &
                                                                    31)];
        }
        r77 = r74;
        
        float _Complex _a78[r74];
        float _Complex *a78 = _a78;
        
        for (v79 = 0; v79 < r74; v79++) {
            a78[v79] = a75[(v79 >> 1 >> 6 << 1 | (v79 & 1)) << 6 | (v79 >> 1 &
                                                                    63)];
        }
        r80 = r77;
        
        float _Complex _a81[r77];
        float _Complex *a81 = _a81;
        
        for (v82 = 0; v82 < r77; v82++) {
            a81[v82] = a78[(v82 >> 1 >> 7 << 1 | (v82 & 1)) << 7 | (v82 >> 1 &
                                                                    127)];
        }
        r83 = r80;
        
        float _Complex _a84[r80];
        float _Complex *a84 = _a84;
        
        for (v85 = 0; v85 < r80; v85++) {
            a84[v85] = a81[(v85 >> 1 >> 8 << 1 | (v85 & 1)) << 8 | (v85 >> 1 &
                                                                    255)];
        }
        r86 = r83;
        
        float _Complex _a87[r83];
        float _Complex *a87 = _a87;
        
        for (v88 = 0; v88 < r83; v88++) {
            a87[v88] = a84[(v88 >> 1 >> 9 << 1 | (v88 & 1)) << 9 | (v88 >> 1 &
                                                                    511)];
        }
        v89 = r86;
        v90 = v89;
        v91 = chan_write(chan20, sizeof(v90), &v90);
        v92 = chan_write(chan20, sizeof(*a87) * (v89 - 0), &a87[0]);
        if (!v92) {
            chan_close(chan1);
            pthread_cancel(t21);
            pthread_join(t21, NULL);
        }
    }
    chan_close(chan1);
    chan_close(chan20);
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
        uint32_t v102;
        bool v104;
        uint32_t v105;
        uint32_t v107;
        uint32_t r108;
        float _Complex _a109[513];
        float _Complex *a109 = _a109;
        uint32_t v110;
        uint32_t v111;
        uint32_t v112;
        bool v113;
        bool v114;
        
        chan_read(chan20, sizeof(v98), &v98);
        
        float _Complex _a99[v98];
        float _Complex *a99 = _a99;
        
        chan_read(chan20, sizeof(*a99) * (v98 - 0), &a99[0]);
        v100 = chan_last_read_ok(chan20);
        r101 = v98;
        v102 = r101;
        
        float _Complex _a103[v102];
        float _Complex *a103 = _a103;
        
        memcpy(a103, a99, v102 * sizeof(float _Complex));
        v104 = chan_last_read_ok(chan20);
        if (!v104) {
            chan_close(chan93);
            pthread_cancel(t94);
            pthread_join(t94, NULL);
        }
        v105 = r95;
        
        float _a106[v105];
        float *a106 = _a106;
        
        memcpy(a106, a96, v105 * sizeof(float));
        for (v107 = 0; v107 < 513; v107++) {
            a96[v107] = carg(a103[v107]);
        }
        r108 = 513;
        for (v110 = 0; v110 < 513; v110++) {
            a109[v110] = 2.0 * cabs(a103[v110]) + I * (((float) v110 + 4.0 *
                                                        (carg(a103[v110]) -
                                                         a106[v110] -
                                                         (float) v110 *
                                                         1.5707964) / (2.0 *
                                                                       FELD_PI)) *
                                                       43.066406);
        }
        v111 = r108;
        v112 = v111;
        v113 = chan_write(chan93, sizeof(v112), &v112);
        v114 = chan_write(chan93, sizeof(*a109) * (v111 - 0), &a109[0]);
        if (!v114) {
            chan_close(chan20);
            pthread_cancel(t94);
            pthread_join(t94, NULL);
        }
    }
    chan_close(chan20);
    chan_close(chan93);
    return NULL;
}
chan_t chan115;
void *thread_t116(void *unused)
{
    while (1) {
        uint32_t v117;
        bool v119;
        uint32_t r120;
        uint32_t v121;
        bool v123;
        float _Complex _a124[513];
        float _Complex *a124 = _a124;
        uint32_t v125;
        uint32_t r126;
        float _Complex _a127[513];
        float _Complex *a127 = _a127;
        uint32_t v128;
        uint32_t v129;
        uint32_t v130;
        bool v131;
        bool v132;
        
        chan_read(chan93, sizeof(v117), &v117);
        
        float _Complex _a118[v117];
        float _Complex *a118 = _a118;
        
        chan_read(chan93, sizeof(*a118) * (v117 - 0), &a118[0]);
        v119 = chan_last_read_ok(chan93);
        r120 = v117;
        v121 = r120;
        
        float _Complex _a122[v121];
        float _Complex *a122 = _a122;
        
        memcpy(a122, a118, v121 * sizeof(float _Complex));
        v123 = chan_last_read_ok(chan93);
        if (!v123) {
            chan_close(chan115);
            pthread_cancel(t116);
            pthread_join(t116, NULL);
        }
        for (v125 = 0; v125 < 513; v125++) {
            a124[(uint32_t) lround((float) v125 * 2.0)] =
                (uint32_t) lround((float) v125 * 2.0) <
                513 ? creal(a122[v125]) + I * (2.0 * cimag(a122[v125])) : 0.0;
        }
        r126 = 513;
        for (v128 = 0; v128 < 513; v128++) {
            a127[v128] = a124[v128];
        }
        v129 = r126;
        v130 = v129;
        v131 = chan_write(chan115, sizeof(v130), &v130);
        v132 = chan_write(chan115, sizeof(*a127) * (v129 - 0), &a127[0]);
        if (!v132) {
            chan_close(chan93);
            pthread_cancel(t116);
            pthread_join(t116, NULL);
        }
    }
    chan_close(chan93);
    chan_close(chan115);
    return NULL;
}
chan_t chan133;
void *thread_t134(void *unused)
{
    uint32_t r135;
    float _a136[513];
    float *a136 = _a136;
    uint32_t v137;
    
    r135 = 513;
    for (v137 = 0; v137 < 513; v137++) {
        a136[v137] = 0.0;
    }
    while (1) {
        uint32_t v138;
        bool v140;
        uint32_t r141;
        uint32_t v142;
        bool v144;
        uint32_t v145;
        uint32_t v147;
        uint32_t r148;
        float _Complex _a149[1024];
        float _Complex *a149 = _a149;
        uint32_t v150;
        uint32_t v151;
        uint32_t v152;
        bool v153;
        bool v154;
        
        chan_read(chan115, sizeof(v138), &v138);
        
        float _Complex _a139[v138];
        float _Complex *a139 = _a139;
        
        chan_read(chan115, sizeof(*a139) * (v138 - 0), &a139[0]);
        v140 = chan_last_read_ok(chan115);
        r141 = v138;
        v142 = r141;
        
        float _Complex _a143[v142];
        float _Complex *a143 = _a143;
        
        memcpy(a143, a139, v142 * sizeof(float _Complex));
        v144 = chan_last_read_ok(chan115);
        if (!v144) {
            chan_close(chan133);
            pthread_cancel(t134);
            pthread_join(t134, NULL);
        }
        v145 = r135;
        
        float _a146[v145];
        float *a146 = _a146;
        
        memcpy(a146, a136, v145 * sizeof(float));
        for (v147 = 0; v147 < 513; v147++) {
            a136[v147] = a146[v147] + (2.0 * FELD_PI * ((cimag(a143[v147]) -
                                                         (float) v147 *
                                                         43.066406) /
                                                        43.066406) / 4.0 +
                                       (float) v147 * 1.5707964);
        }
        r148 = 1024;
        for (v150 = 0; v150 < 1024; v150++) {
            a149[v150] = v150 <= 513 ? creal(a143[v150]) * exp(I * (a146[v150] +
                                                                    (2.0 *
                                                                     FELD_PI *
                                                                     ((cimag(a143[v150]) -
                                                                       (float) v150 *
                                                                       43.066406) /
                                                                      43.066406) /
                                                                     4.0 +
                                                                     (float) v150 *
                                                                     1.5707964))) : 0.0;
        }
        v151 = r148;
        v152 = v151;
        v153 = chan_write(chan133, sizeof(v152), &v152);
        v154 = chan_write(chan133, sizeof(*a149) * (v151 - 0), &a149[0]);
        if (!v154) {
            chan_close(chan115);
            pthread_cancel(t134);
            pthread_join(t134, NULL);
        }
    }
    chan_close(chan115);
    chan_close(chan133);
    return NULL;
}
chan_t chan155;
void *thread_t156(void *unused)
{
    uint32_t r157;
    float _Complex _a158[512];
    float _Complex *a158 = _a158;
    uint32_t v159;
    
    r157 = 512;
    for (v159 = 0; v159 < 512; v159++) {
        a158[v159] = exp(I * (FELD_PI * (float) v159 * 1.953125e-3));
    }
    while (1) {
        uint32_t v160;
        bool v162;
        uint32_t r163;
        uint32_t v164;
        bool v166;
        uint32_t r167;
        float _Complex _a168[1024];
        float _Complex *a168 = _a168;
        uint32_t v169;
        uint32_t r170;
        float _Complex _a171[1024];
        float _Complex *a171 = _a171;
        uint32_t v172;
        uint32_t r173;
        float _Complex _a174[1024];
        float _Complex *a174 = _a174;
        uint32_t v175;
        uint32_t r176;
        float _Complex _a177[1024];
        float _Complex *a177 = _a177;
        uint32_t v178;
        uint32_t r179;
        float _Complex _a180[1024];
        float _Complex *a180 = _a180;
        uint32_t v181;
        uint32_t r182;
        float _Complex _a183[1024];
        float _Complex *a183 = _a183;
        uint32_t v184;
        uint32_t r185;
        float _Complex _a186[1024];
        float _Complex *a186 = _a186;
        uint32_t v187;
        uint32_t r188;
        float _Complex _a189[1024];
        float _Complex *a189 = _a189;
        uint32_t v190;
        uint32_t r191;
        float _Complex _a192[1024];
        float _Complex *a192 = _a192;
        uint32_t v193;
        uint32_t r194;
        float _Complex _a195[1024];
        float _Complex *a195 = _a195;
        uint32_t v196;
        uint32_t r197;
        uint32_t v199;
        uint32_t r200;
        uint32_t v202;
        uint32_t r203;
        uint32_t v205;
        uint32_t r206;
        uint32_t v208;
        uint32_t r209;
        uint32_t v211;
        uint32_t r212;
        uint32_t v214;
        uint32_t r215;
        uint32_t v217;
        uint32_t r218;
        uint32_t v220;
        uint32_t r221;
        uint32_t v223;
        uint32_t v224;
        uint32_t v225;
        bool v226;
        bool v227;
        
        chan_read(chan133, sizeof(v160), &v160);
        
        float _Complex _a161[v160];
        float _Complex *a161 = _a161;
        
        chan_read(chan133, sizeof(*a161) * (v160 - 0), &a161[0]);
        v162 = chan_last_read_ok(chan133);
        r163 = v160;
        v164 = r163;
        
        float _Complex _a165[v164];
        float _Complex *a165 = _a165;
        
        memcpy(a165, a161, v164 * sizeof(float _Complex));
        v166 = chan_last_read_ok(chan133);
        if (!v166) {
            chan_close(chan155);
            pthread_cancel(t156);
            pthread_join(t156, NULL);
        }
        r167 = 1024;
        for (v169 = 0; v169 < 1024; v169++) {
            a168[v169] = !((v169 & 512) == 0) ? a158[v169 << 0 & 511] *
                (a165[v169 ^ 512] - a165[v169]) : a165[v169] + a165[v169 ^ 512];
        }
        r170 = 1024;
        for (v172 = 0; v172 < 1024; v172++) {
            a171[v172] = !((v172 & 256) == 0) ? a158[v172 << 1 & 511] *
                (a168[v172 ^ 256] - a168[v172]) : a168[v172] + a168[v172 ^ 256];
        }
        r173 = 1024;
        for (v175 = 0; v175 < 1024; v175++) {
            a174[v175] = !((v175 & 128) == 0) ? a158[v175 << 2 & 511] *
                (a171[v175 ^ 128] - a171[v175]) : a171[v175] + a171[v175 ^ 128];
        }
        r176 = 1024;
        for (v178 = 0; v178 < 1024; v178++) {
            a177[v178] = !((v178 & 64) == 0) ? a158[v178 << 3 & 511] *
                (a174[v178 ^ 64] - a174[v178]) : a174[v178] + a174[v178 ^ 64];
        }
        r179 = 1024;
        for (v181 = 0; v181 < 1024; v181++) {
            a180[v181] = !((v181 & 32) == 0) ? a158[v181 << 4 & 511] *
                (a177[v181 ^ 32] - a177[v181]) : a177[v181] + a177[v181 ^ 32];
        }
        r182 = 1024;
        for (v184 = 0; v184 < 1024; v184++) {
            a183[v184] = !((v184 & 16) == 0) ? a158[v184 << 5 & 511] *
                (a180[v184 ^ 16] - a180[v184]) : a180[v184] + a180[v184 ^ 16];
        }
        r185 = 1024;
        for (v187 = 0; v187 < 1024; v187++) {
            a186[v187] = !((v187 & 8) == 0) ? a158[v187 << 6 & 511] *
                (a183[v187 ^ 8] - a183[v187]) : a183[v187] + a183[v187 ^ 8];
        }
        r188 = 1024;
        for (v190 = 0; v190 < 1024; v190++) {
            a189[v190] = !((v190 & 4) == 0) ? a158[v190 << 7 & 511] *
                (a186[v190 ^ 4] - a186[v190]) : a186[v190] + a186[v190 ^ 4];
        }
        r191 = 1024;
        for (v193 = 0; v193 < 1024; v193++) {
            a192[v193] = !((v193 & 2) == 0) ? a158[v193 << 8 & 511] *
                (a189[v193 ^ 2] - a189[v193]) : a189[v193] + a189[v193 ^ 2];
        }
        r194 = 1024;
        for (v196 = 0; v196 < 1024; v196++) {
            a195[v196] = !((v196 & 1) == 0) ? a158[v196 << 9 & 511] *
                (a192[v196 ^ 1] - a192[v196]) : a192[v196] + a192[v196 ^ 1];
        }
        r197 = r194;
        
        float _Complex _a198[r194];
        float _Complex *a198 = _a198;
        
        for (v199 = 0; v199 < r194; v199++) {
            a198[v199] = a195[(v199 >> 1 >> 1 << 1 | (v199 & 1)) << 1 | (v199 >>
                                                                         1 &
                                                                         1)];
        }
        r200 = r197;
        
        float _Complex _a201[r197];
        float _Complex *a201 = _a201;
        
        for (v202 = 0; v202 < r197; v202++) {
            a201[v202] = a198[(v202 >> 1 >> 2 << 1 | (v202 & 1)) << 2 | (v202 >>
                                                                         1 &
                                                                         3)];
        }
        r203 = r200;
        
        float _Complex _a204[r200];
        float _Complex *a204 = _a204;
        
        for (v205 = 0; v205 < r200; v205++) {
            a204[v205] = a201[(v205 >> 1 >> 3 << 1 | (v205 & 1)) << 3 | (v205 >>
                                                                         1 &
                                                                         7)];
        }
        r206 = r203;
        
        float _Complex _a207[r203];
        float _Complex *a207 = _a207;
        
        for (v208 = 0; v208 < r203; v208++) {
            a207[v208] = a204[(v208 >> 1 >> 4 << 1 | (v208 & 1)) << 4 | (v208 >>
                                                                         1 &
                                                                         15)];
        }
        r209 = r206;
        
        float _Complex _a210[r206];
        float _Complex *a210 = _a210;
        
        for (v211 = 0; v211 < r206; v211++) {
            a210[v211] = a207[(v211 >> 1 >> 5 << 1 | (v211 & 1)) << 5 | (v211 >>
                                                                         1 &
                                                                         31)];
        }
        r212 = r209;
        
        float _Complex _a213[r209];
        float _Complex *a213 = _a213;
        
        for (v214 = 0; v214 < r209; v214++) {
            a213[v214] = a210[(v214 >> 1 >> 6 << 1 | (v214 & 1)) << 6 | (v214 >>
                                                                         1 &
                                                                         63)];
        }
        r215 = r212;
        
        float _Complex _a216[r212];
        float _Complex *a216 = _a216;
        
        for (v217 = 0; v217 < r212; v217++) {
            a216[v217] = a213[(v217 >> 1 >> 7 << 1 | (v217 & 1)) << 7 | (v217 >>
                                                                         1 &
                                                                         127)];
        }
        r218 = r215;
        
        float _Complex _a219[r215];
        float _Complex *a219 = _a219;
        
        for (v220 = 0; v220 < r215; v220++) {
            a219[v220] = a216[(v220 >> 1 >> 8 << 1 | (v220 & 1)) << 8 | (v220 >>
                                                                         1 &
                                                                         255)];
        }
        r221 = r218;
        
        float _Complex _a222[r218];
        float _Complex *a222 = _a222;
        
        for (v223 = 0; v223 < r218; v223++) {
            a222[v223] = a219[(v223 >> 1 >> 9 << 1 | (v223 & 1)) << 9 | (v223 >>
                                                                         1 &
                                                                         511)];
        }
        v224 = r221;
        v225 = v224;
        v226 = chan_write(chan155, sizeof(v225), &v225);
        v227 = chan_write(chan155, sizeof(*a222) * (v224 - 0), &a222[0]);
        if (!v227) {
            chan_close(chan133);
            pthread_cancel(t156);
            pthread_join(t156, NULL);
        }
    }
    chan_close(chan133);
    chan_close(chan155);
    return NULL;
}
chan_t chan228;
void *thread_t229(void *unused)
{
    uint32_t r230;
    float _a231[1024];
    float *a231 = _a231;
    uint32_t v232;
    
    r230 = 1024;
    for (v232 = 0; v232 < 1024; v232++) {
        a231[v232] = -(0.5 * cos(2.0 * FELD_PI * (float) v232 / 1024.0)) + 0.5;
    }
    while (1) {
        uint32_t v233;
        bool v235;
        uint32_t r236;
        uint32_t v237;
        bool v239;
        uint32_t r240;
        uint32_t v242;
        uint32_t v243;
        uint32_t v244;
        bool v245;
        bool v246;
        
        chan_read(chan155, sizeof(v233), &v233);
        
        float _Complex _a234[v233];
        float _Complex *a234 = _a234;
        
        chan_read(chan155, sizeof(*a234) * (v233 - 0), &a234[0]);
        v235 = chan_last_read_ok(chan155);
        r236 = v233;
        v237 = r236;
        
        float _Complex _a238[v237];
        float _Complex *a238 = _a238;
        
        memcpy(a238, a234, v237 * sizeof(float _Complex));
        v239 = chan_last_read_ok(chan155);
        if (!v239) {
            chan_close(chan228);
            pthread_cancel(t229);
            pthread_join(t229, NULL);
        }
        r240 = v237 <= r230 ? v237 : r230;
        
        float _a241[v237 <= r230 ? v237 : r230];
        float *a241 = _a241;
        
        for (v242 = 0; v242 < (v237 <= r230 ? v237 : r230); v242++) {
            a241[v242] = creal(a238[v242]) / 4096.0 * a231[v242];
        }
        v243 = r240;
        v244 = v243;
        v245 = chan_write(chan228, sizeof(v244), &v244);
        v246 = chan_write(chan228, sizeof(*a241) * (v243 - 0), &a241[0]);
        if (!v246) {
            chan_close(chan155);
            pthread_cancel(t229);
            pthread_join(t229, NULL);
        }
    }
    chan_close(chan155);
    chan_close(chan228);
    return NULL;
}
void *thread_t247(void *unused)
{
    while (1) {
        uint32_t v248;
        bool v250;
        uint32_t r251;
        uint32_t v252;
        bool v254;
        uint32_t v256;
        bool v257;
        
        chan_read(chan228, sizeof(v248), &v248);
        
        float _a249[v248];
        float *a249 = _a249;
        
        chan_read(chan228, sizeof(*a249) * (v248 - 0), &a249[0]);
        v250 = chan_last_read_ok(chan228);
        r251 = v248;
        v252 = r251;
        
        float _a253[v252];
        float *a253 = _a253;
        
        memcpy(a253, a249, v252 * sizeof(float));
        v254 = chan_last_read_ok(chan228);
        if (!v254) {
            pthread_cancel(t247);
            pthread_join(t247, NULL);
        }
        
        float _a255[v252];
        float *a255 = _a255;
        
        for (v256 = 0; v256 < v252; v256++) {
            a255[v256] = a253[v256];
        }
        v257 = emit_samples(a255);
        if (!v257) {
            chan_close(chan228);
            pthread_cancel(t247);
            pthread_join(t247, NULL);
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
    chan20 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                    sizeof(float _Complex)));
    pthread_create(&t21, NULL, thread_t21, NULL);
    chan93 = chan_new(10 * sizeof(uint32_t) + 10 * (513 *
                                                    sizeof(float _Complex)));
    pthread_create(&t94, NULL, thread_t94, NULL);
    chan115 = chan_new(10 * sizeof(uint32_t) + 10 * (513 *
                                                     sizeof(float _Complex)));
    pthread_create(&t116, NULL, thread_t116, NULL);
    chan133 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t134, NULL, thread_t134, NULL);
    chan155 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t156, NULL, thread_t156, NULL);
    chan228 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 * sizeof(float)));
    pthread_create(&t229, NULL, thread_t229, NULL);
    pthread_create(&t247, NULL, thread_t247, NULL);
    while (1) {
        float _a258[1024];
        float *a258 = _a258;
        bool v259;
        uint32_t r260;
        float _a261[1024];
        float *a261 = _a261;
        uint32_t v262;
        uint32_t v263;
        uint32_t v264;
        bool v265;
        bool v266;
        
        v259 = receive_samples(a258);
        if (!v259) {
            break;
        }
        r260 = 1024;
        for (v262 = 0; v262 < 1024; v262++) {
            a261[v262] = a258[v262];
        }
        v263 = r260;
        v264 = v263;
        v265 = chan_write(chan0, sizeof(v264), &v264);
        v266 = chan_write(chan0, sizeof(*a261) * (v263 - 0), &a261[0]);
        if (!v266) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t247, NULL);
    teardown_queues();
    return 0;
}

