#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
void *thread_t2(void *unused);
void *thread_t21(void *unused);
void *thread_t121(void *unused);
void *thread_t143(void *unused);
void *thread_t161(void *unused);
void *thread_t183(void *unused);
void *thread_t283(void *unused);
void *thread_t301(void *unused);
pthread_t t121;
pthread_t t143;
pthread_t t161;
pthread_t t183;
pthread_t t2;
pthread_t t21;
pthread_t t283;
pthread_t t301;
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
    float _Complex _a23[1024];
    float _Complex *a23 = _a23;
    uint32_t v24;
    uint32_t r25;
    float _Complex _a26[1024];
    float _Complex *a26 = _a26;
    uint32_t v27;
    uint32_t r28;
    float _Complex _a29[1024];
    float _Complex *a29 = _a29;
    uint32_t v30;
    uint32_t r31;
    float _Complex _a32[1024];
    float _Complex *a32 = _a32;
    uint32_t v33;
    uint32_t r34;
    float _Complex _a35[1024];
    float _Complex *a35 = _a35;
    uint32_t v36;
    uint32_t r37;
    float _Complex _a38[1024];
    float _Complex *a38 = _a38;
    uint32_t v39;
    uint32_t r40;
    float _Complex _a41[1024];
    float _Complex *a41 = _a41;
    uint32_t v42;
    uint32_t r43;
    float _Complex _a44[1024];
    float _Complex *a44 = _a44;
    uint32_t v45;
    uint32_t r46;
    float _Complex _a47[1024];
    float _Complex *a47 = _a47;
    uint32_t v48;
    uint32_t r49;
    float _Complex _a50[1024];
    float _Complex *a50 = _a50;
    uint32_t v51;
    
    r22 = 1024;
    for (v24 = 0; v24 < 1024; v24++) {
        a23[v24] = exp(I * (-3.1415927 * (float) (v24 & 511) / 512.0));
    }
    r25 = 1024;
    for (v27 = 0; v27 < 1024; v27++) {
        a26[v27] = exp(I * (-3.1415927 * (float) (v27 & 255) / 256.0));
    }
    r28 = 1024;
    for (v30 = 0; v30 < 1024; v30++) {
        a29[v30] = exp(I * (-3.1415927 * (float) (v30 & 127) / 128.0));
    }
    r31 = 1024;
    for (v33 = 0; v33 < 1024; v33++) {
        a32[v33] = exp(I * (-3.1415927 * (float) (v33 & 63) / 64.0));
    }
    r34 = 1024;
    for (v36 = 0; v36 < 1024; v36++) {
        a35[v36] = exp(I * (-3.1415927 * (float) (v36 & 31) / 32.0));
    }
    r37 = 1024;
    for (v39 = 0; v39 < 1024; v39++) {
        a38[v39] = exp(I * (-3.1415927 * (float) (v39 & 15) / 16.0));
    }
    r40 = 1024;
    for (v42 = 0; v42 < 1024; v42++) {
        a41[v42] = exp(I * (-3.1415927 * (float) (v42 & 7) / 8.0));
    }
    r43 = 1024;
    for (v45 = 0; v45 < 1024; v45++) {
        a44[v45] = exp(I * (-3.1415927 * (float) (v45 & 3) / 4.0));
    }
    r46 = 1024;
    for (v48 = 0; v48 < 1024; v48++) {
        a47[v48] = exp(I * (-3.1415927 * (float) (v48 & 1) / 2.0));
    }
    r49 = 1024;
    for (v51 = 0; v51 < 1024; v51++) {
        a50[v51] = exp(I * (-3.1415927 * (float) (v51 & 0) / 1.0));
    }
    while (1) {
        uint32_t v52;
        bool v54;
        uint32_t r55;
        uint32_t v56;
        bool v58;
        uint32_t r59;
        float _Complex _a60[1024];
        float _Complex *a60 = _a60;
        uint32_t v61;
        uint32_t r62;
        float _Complex _a63[1024];
        float _Complex *a63 = _a63;
        uint32_t v64;
        uint32_t r65;
        float _Complex _a66[1024];
        float _Complex *a66 = _a66;
        uint32_t v67;
        uint32_t r68;
        float _Complex _a69[1024];
        float _Complex *a69 = _a69;
        uint32_t v70;
        uint32_t r71;
        float _Complex _a72[1024];
        float _Complex *a72 = _a72;
        uint32_t v73;
        uint32_t r74;
        float _Complex _a75[1024];
        float _Complex *a75 = _a75;
        uint32_t v76;
        uint32_t r77;
        float _Complex _a78[1024];
        float _Complex *a78 = _a78;
        uint32_t v79;
        uint32_t r80;
        float _Complex _a81[1024];
        float _Complex *a81 = _a81;
        uint32_t v82;
        uint32_t r83;
        float _Complex _a84[1024];
        float _Complex *a84 = _a84;
        uint32_t v85;
        uint32_t r86;
        float _Complex _a87[1024];
        float _Complex *a87 = _a87;
        uint32_t v88;
        uint32_t r89;
        uint32_t v91;
        uint32_t r92;
        uint32_t v94;
        uint32_t r95;
        uint32_t v97;
        uint32_t r98;
        uint32_t v100;
        uint32_t r101;
        uint32_t v103;
        uint32_t r104;
        uint32_t v106;
        uint32_t r107;
        uint32_t v109;
        uint32_t r110;
        uint32_t v112;
        uint32_t r113;
        uint32_t v115;
        uint32_t v116;
        uint32_t v117;
        bool v118;
        bool v119;
        
        chan_read(chan1, sizeof(v52), &v52);
        
        float _Complex _a53[v52];
        float _Complex *a53 = _a53;
        
        chan_read(chan1, sizeof(*a53) * (v52 - 0), &a53[0]);
        v54 = chan_last_read_ok(chan1);
        r55 = v52;
        v56 = r55;
        
        float _Complex _a57[v56];
        float _Complex *a57 = _a57;
        
        memcpy(a57, a53, v56 * sizeof(float _Complex));
        v58 = chan_last_read_ok(chan1);
        if (!v58) {
            chan_close(chan20);
            pthread_cancel(t21);
            pthread_join(t21, NULL);
        }
        r59 = 1024;
        for (v61 = 0; v61 < 1024; v61++) {
            a60[v61] = !((v61 & 512) == 0) ? a23[v61] * (a57[v61 ^ 512] -
                                                         a57[v61]) : a57[v61] +
                a57[v61 ^ 512];
        }
        r62 = 1024;
        for (v64 = 0; v64 < 1024; v64++) {
            a63[v64] = !((v64 & 256) == 0) ? a26[v64] * (a60[v64 ^ 256] -
                                                         a60[v64]) : a60[v64] +
                a60[v64 ^ 256];
        }
        r65 = 1024;
        for (v67 = 0; v67 < 1024; v67++) {
            a66[v67] = !((v67 & 128) == 0) ? a29[v67] * (a63[v67 ^ 128] -
                                                         a63[v67]) : a63[v67] +
                a63[v67 ^ 128];
        }
        r68 = 1024;
        for (v70 = 0; v70 < 1024; v70++) {
            a69[v70] = !((v70 & 64) == 0) ? a32[v70] * (a66[v70 ^ 64] -
                                                        a66[v70]) : a66[v70] +
                a66[v70 ^ 64];
        }
        r71 = 1024;
        for (v73 = 0; v73 < 1024; v73++) {
            a72[v73] = !((v73 & 32) == 0) ? a35[v73] * (a69[v73 ^ 32] -
                                                        a69[v73]) : a69[v73] +
                a69[v73 ^ 32];
        }
        r74 = 1024;
        for (v76 = 0; v76 < 1024; v76++) {
            a75[v76] = !((v76 & 16) == 0) ? a38[v76] * (a72[v76 ^ 16] -
                                                        a72[v76]) : a72[v76] +
                a72[v76 ^ 16];
        }
        r77 = 1024;
        for (v79 = 0; v79 < 1024; v79++) {
            a78[v79] = !((v79 & 8) == 0) ? a41[v79] * (a75[v79 ^ 8] -
                                                       a75[v79]) : a75[v79] +
                a75[v79 ^ 8];
        }
        r80 = 1024;
        for (v82 = 0; v82 < 1024; v82++) {
            a81[v82] = !((v82 & 4) == 0) ? a44[v82] * (a78[v82 ^ 4] -
                                                       a78[v82]) : a78[v82] +
                a78[v82 ^ 4];
        }
        r83 = 1024;
        for (v85 = 0; v85 < 1024; v85++) {
            a84[v85] = !((v85 & 2) == 0) ? a47[v85] * (a81[v85 ^ 2] -
                                                       a81[v85]) : a81[v85] +
                a81[v85 ^ 2];
        }
        r86 = 1024;
        for (v88 = 0; v88 < 1024; v88++) {
            a87[v88] = !((v88 & 1) == 0) ? a50[v88] * (a84[v88 ^ 1] -
                                                       a84[v88]) : a84[v88] +
                a84[v88 ^ 1];
        }
        r89 = r86;
        
        float _Complex _a90[r86];
        float _Complex *a90 = _a90;
        
        for (v91 = 0; v91 < r86; v91++) {
            a90[v91] = a87[(v91 >> 1 >> 1 << 1 | (v91 & 1)) << 1 | (v91 >> 1 &
                                                                    1)];
        }
        r92 = r89;
        
        float _Complex _a93[r89];
        float _Complex *a93 = _a93;
        
        for (v94 = 0; v94 < r89; v94++) {
            a93[v94] = a90[(v94 >> 1 >> 2 << 1 | (v94 & 1)) << 2 | (v94 >> 1 &
                                                                    3)];
        }
        r95 = r92;
        
        float _Complex _a96[r92];
        float _Complex *a96 = _a96;
        
        for (v97 = 0; v97 < r92; v97++) {
            a96[v97] = a93[(v97 >> 1 >> 3 << 1 | (v97 & 1)) << 3 | (v97 >> 1 &
                                                                    7)];
        }
        r98 = r95;
        
        float _Complex _a99[r95];
        float _Complex *a99 = _a99;
        
        for (v100 = 0; v100 < r95; v100++) {
            a99[v100] = a96[(v100 >> 1 >> 4 << 1 | (v100 & 1)) << 4 | (v100 >>
                                                                       1 & 15)];
        }
        r101 = r98;
        
        float _Complex _a102[r98];
        float _Complex *a102 = _a102;
        
        for (v103 = 0; v103 < r98; v103++) {
            a102[v103] = a99[(v103 >> 1 >> 5 << 1 | (v103 & 1)) << 5 | (v103 >>
                                                                        1 &
                                                                        31)];
        }
        r104 = r101;
        
        float _Complex _a105[r101];
        float _Complex *a105 = _a105;
        
        for (v106 = 0; v106 < r101; v106++) {
            a105[v106] = a102[(v106 >> 1 >> 6 << 1 | (v106 & 1)) << 6 | (v106 >>
                                                                         1 &
                                                                         63)];
        }
        r107 = r104;
        
        float _Complex _a108[r104];
        float _Complex *a108 = _a108;
        
        for (v109 = 0; v109 < r104; v109++) {
            a108[v109] = a105[(v109 >> 1 >> 7 << 1 | (v109 & 1)) << 7 | (v109 >>
                                                                         1 &
                                                                         127)];
        }
        r110 = r107;
        
        float _Complex _a111[r107];
        float _Complex *a111 = _a111;
        
        for (v112 = 0; v112 < r107; v112++) {
            a111[v112] = a108[(v112 >> 1 >> 8 << 1 | (v112 & 1)) << 8 | (v112 >>
                                                                         1 &
                                                                         255)];
        }
        r113 = r110;
        
        float _Complex _a114[r110];
        float _Complex *a114 = _a114;
        
        for (v115 = 0; v115 < r110; v115++) {
            a114[v115] = a111[(v115 >> 1 >> 9 << 1 | (v115 & 1)) << 9 | (v115 >>
                                                                         1 &
                                                                         511)];
        }
        v116 = r113;
        v117 = v116;
        v118 = chan_write(chan20, sizeof(v117), &v117);
        v119 = chan_write(chan20, sizeof(*a114) * (v116 - 0), &a114[0]);
        if (!v119) {
            chan_close(chan1);
            pthread_cancel(t21);
            pthread_join(t21, NULL);
        }
    }
    chan_close(chan1);
    chan_close(chan20);
    return NULL;
}
chan_t chan120;
void *thread_t121(void *unused)
{
    uint32_t r122;
    float _a123[513];
    float *a123 = _a123;
    uint32_t v124;
    
    r122 = 513;
    for (v124 = 0; v124 < 513; v124++) {
        a123[v124] = 0.0;
    }
    while (1) {
        uint32_t v125;
        bool v127;
        uint32_t r128;
        uint32_t v129;
        bool v131;
        uint32_t v132;
        uint32_t v134;
        uint32_t r135;
        float _Complex _a136[513];
        float _Complex *a136 = _a136;
        uint32_t v137;
        uint32_t v138;
        uint32_t v139;
        bool v140;
        bool v141;
        
        chan_read(chan20, sizeof(v125), &v125);
        
        float _Complex _a126[v125];
        float _Complex *a126 = _a126;
        
        chan_read(chan20, sizeof(*a126) * (v125 - 0), &a126[0]);
        v127 = chan_last_read_ok(chan20);
        r128 = v125;
        v129 = r128;
        
        float _Complex _a130[v129];
        float _Complex *a130 = _a130;
        
        memcpy(a130, a126, v129 * sizeof(float _Complex));
        v131 = chan_last_read_ok(chan20);
        if (!v131) {
            chan_close(chan120);
            pthread_cancel(t121);
            pthread_join(t121, NULL);
        }
        v132 = r122;
        
        float _a133[v132];
        float *a133 = _a133;
        
        memcpy(a133, a123, v132 * sizeof(float));
        for (v134 = 0; v134 < 513; v134++) {
            a123[v134] = carg(a130[v134]);
        }
        r135 = 513;
        for (v137 = 0; v137 < 513; v137++) {
            a136[v137] = 2.0 * cabs(a130[v137]) + I * (((float) v137 + 4.0 *
                                                        (carg(a130[v137]) -
                                                         a133[v137] -
                                                         (float) v137 *
                                                         1.5707964) / (2.0 *
                                                                       FELD_PI)) *
                                                       43.066406);
        }
        v138 = r135;
        v139 = v138;
        v140 = chan_write(chan120, sizeof(v139), &v139);
        v141 = chan_write(chan120, sizeof(*a136) * (v138 - 0), &a136[0]);
        if (!v141) {
            chan_close(chan20);
            pthread_cancel(t121);
            pthread_join(t121, NULL);
        }
    }
    chan_close(chan20);
    chan_close(chan120);
    return NULL;
}
chan_t chan142;
void *thread_t143(void *unused)
{
    while (1) {
        uint32_t v144;
        bool v146;
        uint32_t r147;
        uint32_t v148;
        bool v150;
        float _Complex _a151[513];
        float _Complex *a151 = _a151;
        uint32_t v152;
        uint32_t r153;
        float _Complex _a154[513];
        float _Complex *a154 = _a154;
        uint32_t v155;
        uint32_t v156;
        uint32_t v157;
        bool v158;
        bool v159;
        
        chan_read(chan120, sizeof(v144), &v144);
        
        float _Complex _a145[v144];
        float _Complex *a145 = _a145;
        
        chan_read(chan120, sizeof(*a145) * (v144 - 0), &a145[0]);
        v146 = chan_last_read_ok(chan120);
        r147 = v144;
        v148 = r147;
        
        float _Complex _a149[v148];
        float _Complex *a149 = _a149;
        
        memcpy(a149, a145, v148 * sizeof(float _Complex));
        v150 = chan_last_read_ok(chan120);
        if (!v150) {
            chan_close(chan142);
            pthread_cancel(t143);
            pthread_join(t143, NULL);
        }
        for (v152 = 0; v152 < 513; v152++) {
            a151[(uint32_t) lround((float) v152 * 2.0)] =
                (uint32_t) lround((float) v152 * 2.0) <
                513 ? creal(a149[v152]) + I * (2.0 * cimag(a149[v152])) : 0.0;
        }
        r153 = 513;
        for (v155 = 0; v155 < 513; v155++) {
            a154[v155] = a151[v155];
        }
        v156 = r153;
        v157 = v156;
        v158 = chan_write(chan142, sizeof(v157), &v157);
        v159 = chan_write(chan142, sizeof(*a154) * (v156 - 0), &a154[0]);
        if (!v159) {
            chan_close(chan120);
            pthread_cancel(t143);
            pthread_join(t143, NULL);
        }
    }
    chan_close(chan120);
    chan_close(chan142);
    return NULL;
}
chan_t chan160;
void *thread_t161(void *unused)
{
    uint32_t r162;
    float _a163[513];
    float *a163 = _a163;
    uint32_t v164;
    
    r162 = 513;
    for (v164 = 0; v164 < 513; v164++) {
        a163[v164] = 0.0;
    }
    while (1) {
        uint32_t v165;
        bool v167;
        uint32_t r168;
        uint32_t v169;
        bool v171;
        uint32_t v172;
        uint32_t v174;
        uint32_t r175;
        float _Complex _a176[1024];
        float _Complex *a176 = _a176;
        uint32_t v177;
        uint32_t v178;
        uint32_t v179;
        bool v180;
        bool v181;
        
        chan_read(chan142, sizeof(v165), &v165);
        
        float _Complex _a166[v165];
        float _Complex *a166 = _a166;
        
        chan_read(chan142, sizeof(*a166) * (v165 - 0), &a166[0]);
        v167 = chan_last_read_ok(chan142);
        r168 = v165;
        v169 = r168;
        
        float _Complex _a170[v169];
        float _Complex *a170 = _a170;
        
        memcpy(a170, a166, v169 * sizeof(float _Complex));
        v171 = chan_last_read_ok(chan142);
        if (!v171) {
            chan_close(chan160);
            pthread_cancel(t161);
            pthread_join(t161, NULL);
        }
        v172 = r162;
        
        float _a173[v172];
        float *a173 = _a173;
        
        memcpy(a173, a163, v172 * sizeof(float));
        for (v174 = 0; v174 < 513; v174++) {
            a163[v174] = a173[v174] + (2.0 * FELD_PI * ((cimag(a170[v174]) -
                                                         (float) v174 *
                                                         43.066406) /
                                                        43.066406) / 4.0 +
                                       (float) v174 * 1.5707964);
        }
        r175 = 1024;
        for (v177 = 0; v177 < 1024; v177++) {
            a176[v177] = v177 <= 513 ? creal(a170[v177]) * exp(I * (a173[v177] +
                                                                    (2.0 *
                                                                     FELD_PI *
                                                                     ((cimag(a170[v177]) -
                                                                       (float) v177 *
                                                                       43.066406) /
                                                                      43.066406) /
                                                                     4.0 +
                                                                     (float) v177 *
                                                                     1.5707964))) : 0.0;
        }
        v178 = r175;
        v179 = v178;
        v180 = chan_write(chan160, sizeof(v179), &v179);
        v181 = chan_write(chan160, sizeof(*a176) * (v178 - 0), &a176[0]);
        if (!v181) {
            chan_close(chan142);
            pthread_cancel(t161);
            pthread_join(t161, NULL);
        }
    }
    chan_close(chan142);
    chan_close(chan160);
    return NULL;
}
chan_t chan182;
void *thread_t183(void *unused)
{
    uint32_t r184;
    float _Complex _a185[1024];
    float _Complex *a185 = _a185;
    uint32_t v186;
    uint32_t r187;
    float _Complex _a188[1024];
    float _Complex *a188 = _a188;
    uint32_t v189;
    uint32_t r190;
    float _Complex _a191[1024];
    float _Complex *a191 = _a191;
    uint32_t v192;
    uint32_t r193;
    float _Complex _a194[1024];
    float _Complex *a194 = _a194;
    uint32_t v195;
    uint32_t r196;
    float _Complex _a197[1024];
    float _Complex *a197 = _a197;
    uint32_t v198;
    uint32_t r199;
    float _Complex _a200[1024];
    float _Complex *a200 = _a200;
    uint32_t v201;
    uint32_t r202;
    float _Complex _a203[1024];
    float _Complex *a203 = _a203;
    uint32_t v204;
    uint32_t r205;
    float _Complex _a206[1024];
    float _Complex *a206 = _a206;
    uint32_t v207;
    uint32_t r208;
    float _Complex _a209[1024];
    float _Complex *a209 = _a209;
    uint32_t v210;
    uint32_t r211;
    float _Complex _a212[1024];
    float _Complex *a212 = _a212;
    uint32_t v213;
    
    r184 = 1024;
    for (v186 = 0; v186 < 1024; v186++) {
        a185[v186] = exp(I * (FELD_PI * (float) (v186 & 511) / 512.0));
    }
    r187 = 1024;
    for (v189 = 0; v189 < 1024; v189++) {
        a188[v189] = exp(I * (FELD_PI * (float) (v189 & 255) / 256.0));
    }
    r190 = 1024;
    for (v192 = 0; v192 < 1024; v192++) {
        a191[v192] = exp(I * (FELD_PI * (float) (v192 & 127) / 128.0));
    }
    r193 = 1024;
    for (v195 = 0; v195 < 1024; v195++) {
        a194[v195] = exp(I * (FELD_PI * (float) (v195 & 63) / 64.0));
    }
    r196 = 1024;
    for (v198 = 0; v198 < 1024; v198++) {
        a197[v198] = exp(I * (FELD_PI * (float) (v198 & 31) / 32.0));
    }
    r199 = 1024;
    for (v201 = 0; v201 < 1024; v201++) {
        a200[v201] = exp(I * (FELD_PI * (float) (v201 & 15) / 16.0));
    }
    r202 = 1024;
    for (v204 = 0; v204 < 1024; v204++) {
        a203[v204] = exp(I * (FELD_PI * (float) (v204 & 7) / 8.0));
    }
    r205 = 1024;
    for (v207 = 0; v207 < 1024; v207++) {
        a206[v207] = exp(I * (FELD_PI * (float) (v207 & 3) / 4.0));
    }
    r208 = 1024;
    for (v210 = 0; v210 < 1024; v210++) {
        a209[v210] = exp(I * (FELD_PI * (float) (v210 & 1) / 2.0));
    }
    r211 = 1024;
    for (v213 = 0; v213 < 1024; v213++) {
        a212[v213] = exp(I * (FELD_PI * (float) (v213 & 0) / 1.0));
    }
    while (1) {
        uint32_t v214;
        bool v216;
        uint32_t r217;
        uint32_t v218;
        bool v220;
        uint32_t r221;
        float _Complex _a222[1024];
        float _Complex *a222 = _a222;
        uint32_t v223;
        uint32_t r224;
        float _Complex _a225[1024];
        float _Complex *a225 = _a225;
        uint32_t v226;
        uint32_t r227;
        float _Complex _a228[1024];
        float _Complex *a228 = _a228;
        uint32_t v229;
        uint32_t r230;
        float _Complex _a231[1024];
        float _Complex *a231 = _a231;
        uint32_t v232;
        uint32_t r233;
        float _Complex _a234[1024];
        float _Complex *a234 = _a234;
        uint32_t v235;
        uint32_t r236;
        float _Complex _a237[1024];
        float _Complex *a237 = _a237;
        uint32_t v238;
        uint32_t r239;
        float _Complex _a240[1024];
        float _Complex *a240 = _a240;
        uint32_t v241;
        uint32_t r242;
        float _Complex _a243[1024];
        float _Complex *a243 = _a243;
        uint32_t v244;
        uint32_t r245;
        float _Complex _a246[1024];
        float _Complex *a246 = _a246;
        uint32_t v247;
        uint32_t r248;
        float _Complex _a249[1024];
        float _Complex *a249 = _a249;
        uint32_t v250;
        uint32_t r251;
        uint32_t v253;
        uint32_t r254;
        uint32_t v256;
        uint32_t r257;
        uint32_t v259;
        uint32_t r260;
        uint32_t v262;
        uint32_t r263;
        uint32_t v265;
        uint32_t r266;
        uint32_t v268;
        uint32_t r269;
        uint32_t v271;
        uint32_t r272;
        uint32_t v274;
        uint32_t r275;
        uint32_t v277;
        uint32_t v278;
        uint32_t v279;
        bool v280;
        bool v281;
        
        chan_read(chan160, sizeof(v214), &v214);
        
        float _Complex _a215[v214];
        float _Complex *a215 = _a215;
        
        chan_read(chan160, sizeof(*a215) * (v214 - 0), &a215[0]);
        v216 = chan_last_read_ok(chan160);
        r217 = v214;
        v218 = r217;
        
        float _Complex _a219[v218];
        float _Complex *a219 = _a219;
        
        memcpy(a219, a215, v218 * sizeof(float _Complex));
        v220 = chan_last_read_ok(chan160);
        if (!v220) {
            chan_close(chan182);
            pthread_cancel(t183);
            pthread_join(t183, NULL);
        }
        r221 = 1024;
        for (v223 = 0; v223 < 1024; v223++) {
            a222[v223] = !((v223 & 512) == 0) ? a185[v223] * (a219[v223 ^ 512] -
                                                              a219[v223]) : a219[v223] +
                a219[v223 ^ 512];
        }
        r224 = 1024;
        for (v226 = 0; v226 < 1024; v226++) {
            a225[v226] = !((v226 & 256) == 0) ? a188[v226] * (a222[v226 ^ 256] -
                                                              a222[v226]) : a222[v226] +
                a222[v226 ^ 256];
        }
        r227 = 1024;
        for (v229 = 0; v229 < 1024; v229++) {
            a228[v229] = !((v229 & 128) == 0) ? a191[v229] * (a225[v229 ^ 128] -
                                                              a225[v229]) : a225[v229] +
                a225[v229 ^ 128];
        }
        r230 = 1024;
        for (v232 = 0; v232 < 1024; v232++) {
            a231[v232] = !((v232 & 64) == 0) ? a194[v232] * (a228[v232 ^ 64] -
                                                             a228[v232]) : a228[v232] +
                a228[v232 ^ 64];
        }
        r233 = 1024;
        for (v235 = 0; v235 < 1024; v235++) {
            a234[v235] = !((v235 & 32) == 0) ? a197[v235] * (a231[v235 ^ 32] -
                                                             a231[v235]) : a231[v235] +
                a231[v235 ^ 32];
        }
        r236 = 1024;
        for (v238 = 0; v238 < 1024; v238++) {
            a237[v238] = !((v238 & 16) == 0) ? a200[v238] * (a234[v238 ^ 16] -
                                                             a234[v238]) : a234[v238] +
                a234[v238 ^ 16];
        }
        r239 = 1024;
        for (v241 = 0; v241 < 1024; v241++) {
            a240[v241] = !((v241 & 8) == 0) ? a203[v241] * (a237[v241 ^ 8] -
                                                            a237[v241]) : a237[v241] +
                a237[v241 ^ 8];
        }
        r242 = 1024;
        for (v244 = 0; v244 < 1024; v244++) {
            a243[v244] = !((v244 & 4) == 0) ? a206[v244] * (a240[v244 ^ 4] -
                                                            a240[v244]) : a240[v244] +
                a240[v244 ^ 4];
        }
        r245 = 1024;
        for (v247 = 0; v247 < 1024; v247++) {
            a246[v247] = !((v247 & 2) == 0) ? a209[v247] * (a243[v247 ^ 2] -
                                                            a243[v247]) : a243[v247] +
                a243[v247 ^ 2];
        }
        r248 = 1024;
        for (v250 = 0; v250 < 1024; v250++) {
            a249[v250] = !((v250 & 1) == 0) ? a212[v250] * (a246[v250 ^ 1] -
                                                            a246[v250]) : a246[v250] +
                a246[v250 ^ 1];
        }
        r251 = r248;
        
        float _Complex _a252[r248];
        float _Complex *a252 = _a252;
        
        for (v253 = 0; v253 < r248; v253++) {
            a252[v253] = a249[(v253 >> 1 >> 1 << 1 | (v253 & 1)) << 1 | (v253 >>
                                                                         1 &
                                                                         1)];
        }
        r254 = r251;
        
        float _Complex _a255[r251];
        float _Complex *a255 = _a255;
        
        for (v256 = 0; v256 < r251; v256++) {
            a255[v256] = a252[(v256 >> 1 >> 2 << 1 | (v256 & 1)) << 2 | (v256 >>
                                                                         1 &
                                                                         3)];
        }
        r257 = r254;
        
        float _Complex _a258[r254];
        float _Complex *a258 = _a258;
        
        for (v259 = 0; v259 < r254; v259++) {
            a258[v259] = a255[(v259 >> 1 >> 3 << 1 | (v259 & 1)) << 3 | (v259 >>
                                                                         1 &
                                                                         7)];
        }
        r260 = r257;
        
        float _Complex _a261[r257];
        float _Complex *a261 = _a261;
        
        for (v262 = 0; v262 < r257; v262++) {
            a261[v262] = a258[(v262 >> 1 >> 4 << 1 | (v262 & 1)) << 4 | (v262 >>
                                                                         1 &
                                                                         15)];
        }
        r263 = r260;
        
        float _Complex _a264[r260];
        float _Complex *a264 = _a264;
        
        for (v265 = 0; v265 < r260; v265++) {
            a264[v265] = a261[(v265 >> 1 >> 5 << 1 | (v265 & 1)) << 5 | (v265 >>
                                                                         1 &
                                                                         31)];
        }
        r266 = r263;
        
        float _Complex _a267[r263];
        float _Complex *a267 = _a267;
        
        for (v268 = 0; v268 < r263; v268++) {
            a267[v268] = a264[(v268 >> 1 >> 6 << 1 | (v268 & 1)) << 6 | (v268 >>
                                                                         1 &
                                                                         63)];
        }
        r269 = r266;
        
        float _Complex _a270[r266];
        float _Complex *a270 = _a270;
        
        for (v271 = 0; v271 < r266; v271++) {
            a270[v271] = a267[(v271 >> 1 >> 7 << 1 | (v271 & 1)) << 7 | (v271 >>
                                                                         1 &
                                                                         127)];
        }
        r272 = r269;
        
        float _Complex _a273[r269];
        float _Complex *a273 = _a273;
        
        for (v274 = 0; v274 < r269; v274++) {
            a273[v274] = a270[(v274 >> 1 >> 8 << 1 | (v274 & 1)) << 8 | (v274 >>
                                                                         1 &
                                                                         255)];
        }
        r275 = r272;
        
        float _Complex _a276[r272];
        float _Complex *a276 = _a276;
        
        for (v277 = 0; v277 < r272; v277++) {
            a276[v277] = a273[(v277 >> 1 >> 9 << 1 | (v277 & 1)) << 9 | (v277 >>
                                                                         1 &
                                                                         511)];
        }
        v278 = r275;
        v279 = v278;
        v280 = chan_write(chan182, sizeof(v279), &v279);
        v281 = chan_write(chan182, sizeof(*a276) * (v278 - 0), &a276[0]);
        if (!v281) {
            chan_close(chan160);
            pthread_cancel(t183);
            pthread_join(t183, NULL);
        }
    }
    chan_close(chan160);
    chan_close(chan182);
    return NULL;
}
chan_t chan282;
void *thread_t283(void *unused)
{
    uint32_t r284;
    float _a285[1024];
    float *a285 = _a285;
    uint32_t v286;
    
    r284 = 1024;
    for (v286 = 0; v286 < 1024; v286++) {
        a285[v286] = -(0.5 * cos(2.0 * FELD_PI * (float) v286 / 1024.0)) + 0.5;
    }
    while (1) {
        uint32_t v287;
        bool v289;
        uint32_t r290;
        uint32_t v291;
        bool v293;
        uint32_t r294;
        uint32_t v296;
        uint32_t v297;
        uint32_t v298;
        bool v299;
        bool v300;
        
        chan_read(chan182, sizeof(v287), &v287);
        
        float _Complex _a288[v287];
        float _Complex *a288 = _a288;
        
        chan_read(chan182, sizeof(*a288) * (v287 - 0), &a288[0]);
        v289 = chan_last_read_ok(chan182);
        r290 = v287;
        v291 = r290;
        
        float _Complex _a292[v291];
        float _Complex *a292 = _a292;
        
        memcpy(a292, a288, v291 * sizeof(float _Complex));
        v293 = chan_last_read_ok(chan182);
        if (!v293) {
            chan_close(chan282);
            pthread_cancel(t283);
            pthread_join(t283, NULL);
        }
        r294 = v291 <= r284 ? v291 : r284;
        
        float _a295[v291 <= r284 ? v291 : r284];
        float *a295 = _a295;
        
        for (v296 = 0; v296 < (v291 <= r284 ? v291 : r284); v296++) {
            a295[v296] = creal(a292[v296]) / 4096.0 * a285[v296];
        }
        v297 = r294;
        v298 = v297;
        v299 = chan_write(chan282, sizeof(v298), &v298);
        v300 = chan_write(chan282, sizeof(*a295) * (v297 - 0), &a295[0]);
        if (!v300) {
            chan_close(chan182);
            pthread_cancel(t283);
            pthread_join(t283, NULL);
        }
    }
    chan_close(chan182);
    chan_close(chan282);
    return NULL;
}
void *thread_t301(void *unused)
{
    while (1) {
        uint32_t v302;
        bool v304;
        uint32_t r305;
        uint32_t v306;
        bool v308;
        uint32_t v310;
        bool v311;
        
        chan_read(chan282, sizeof(v302), &v302);
        
        float _a303[v302];
        float *a303 = _a303;
        
        chan_read(chan282, sizeof(*a303) * (v302 - 0), &a303[0]);
        v304 = chan_last_read_ok(chan282);
        r305 = v302;
        v306 = r305;
        
        float _a307[v306];
        float *a307 = _a307;
        
        memcpy(a307, a303, v306 * sizeof(float));
        v308 = chan_last_read_ok(chan282);
        if (!v308) {
            pthread_cancel(t301);
            pthread_join(t301, NULL);
        }
        
        float _a309[v306];
        float *a309 = _a309;
        
        for (v310 = 0; v310 < v306; v310++) {
            a309[v310] = a307[v310];
        }
        v311 = emit_samples(a309);
        if (!v311) {
            chan_close(chan282);
            pthread_cancel(t301);
            pthread_join(t301, NULL);
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
    chan120 = chan_new(10 * sizeof(uint32_t) + 10 * (513 *
                                                     sizeof(float _Complex)));
    pthread_create(&t121, NULL, thread_t121, NULL);
    chan142 = chan_new(10 * sizeof(uint32_t) + 10 * (513 *
                                                     sizeof(float _Complex)));
    pthread_create(&t143, NULL, thread_t143, NULL);
    chan160 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t161, NULL, thread_t161, NULL);
    chan182 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t183, NULL, thread_t183, NULL);
    chan282 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 * sizeof(float)));
    pthread_create(&t283, NULL, thread_t283, NULL);
    pthread_create(&t301, NULL, thread_t301, NULL);
    while (1) {
        float _a312[1024];
        float *a312 = _a312;
        bool v313;
        uint32_t r314;
        float _a315[1024];
        float *a315 = _a315;
        uint32_t v316;
        uint32_t v317;
        uint32_t v318;
        bool v319;
        bool v320;
        
        v313 = receive_samples(a312);
        if (!v313) {
            break;
        }
        r314 = 1024;
        for (v316 = 0; v316 < 1024; v316++) {
            a315[v316] = a312[v316];
        }
        v317 = r314;
        v318 = v317;
        v319 = chan_write(chan0, sizeof(v318), &v318);
        v320 = chan_write(chan0, sizeof(*a315) * (v317 - 0), &a315[0]);
        if (!v320) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t301, NULL);
    teardown_queues();
    return 0;
}

