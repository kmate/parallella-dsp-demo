#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
void *thread_t2(void *unused);
void *thread_t21(void *unused);
void *thread_t64(void *unused);
void *thread_t86(void *unused);
void *thread_t104(void *unused);
void *thread_t126(void *unused);
void *thread_t169(void *unused);
void *thread_t187(void *unused);
pthread_t t104;
pthread_t t126;
pthread_t t169;
pthread_t t187;
pthread_t t2;
pthread_t t21;
pthread_t t64;
pthread_t t86;
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
    uint32_t r25;
    float _Complex _a26[1024];
    float _Complex *a26 = _a26;
    uint32_t r27;
    float _Complex _a28[1024];
    float _Complex *a28 = _a28;
    
    r22 = 512;
    for (v24 = 0; v24 < 512; v24++) {
        a23[v24] = exp(I * (FELD_PI * (float) v24 * -1.953125e-3));
    }
    r25 = 1024;
    r27 = 1024;
    while (1) {
        uint32_t v29;
        bool v31;
        uint32_t r32;
        uint32_t v33;
        bool v35;
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
        uint32_t v52;
        uint32_t v53;
        uint32_t v54;
        uint32_t v55;
        uint32_t r56;
        uint32_t v58;
        uint32_t v59;
        uint32_t v60;
        bool v61;
        bool v62;
        
        chan_read(chan1, sizeof(v29), &v29);
        
        float _Complex _a30[v29];
        float _Complex *a30 = _a30;
        
        chan_read(chan1, sizeof(*a30) * (v29 - 0), &a30[0]);
        v31 = chan_last_read_ok(chan1);
        r32 = v29;
        v33 = r32;
        
        float _Complex _a34[v33];
        float _Complex *a34 = _a34;
        
        memcpy(a34, a30, v33 * sizeof(float _Complex));
        v35 = chan_last_read_ok(chan1);
        if (!v35) {
            chan_close(chan20);
            pthread_cancel(t21);
            pthread_join(t21, NULL);
        }
        for (v36 = 0; v36 < v33; v36++) {
            a26[v36] = a34[v36];
        }
        for (v37 = 0; v37 < 1024; v37++) {
            a28[v37] = !((v37 & 512) == 0) ? a23[v37 << 0 & 511] * (a26[v37 ^
                                                                        512] -
                                                                    a26[v37]) : a26[v37] +
                a26[v37 ^ 512];
        }
        for (v38 = 0; v38 < 1024; v38++) {
            a26[v38] = !((v38 & 256) == 0) ? a23[v38 << 1 & 511] * (a28[v38 ^
                                                                        256] -
                                                                    a28[v38]) : a28[v38] +
                a28[v38 ^ 256];
        }
        for (v39 = 0; v39 < 1024; v39++) {
            a28[v39] = !((v39 & 128) == 0) ? a23[v39 << 2 & 511] * (a26[v39 ^
                                                                        128] -
                                                                    a26[v39]) : a26[v39] +
                a26[v39 ^ 128];
        }
        for (v40 = 0; v40 < 1024; v40++) {
            a26[v40] = !((v40 & 64) == 0) ? a23[v40 << 3 & 511] * (a28[v40 ^
                                                                       64] -
                                                                   a28[v40]) : a28[v40] +
                a28[v40 ^ 64];
        }
        for (v41 = 0; v41 < 1024; v41++) {
            a28[v41] = !((v41 & 32) == 0) ? a23[v41 << 4 & 511] * (a26[v41 ^
                                                                       32] -
                                                                   a26[v41]) : a26[v41] +
                a26[v41 ^ 32];
        }
        for (v42 = 0; v42 < 1024; v42++) {
            a26[v42] = !((v42 & 16) == 0) ? a23[v42 << 5 & 511] * (a28[v42 ^
                                                                       16] -
                                                                   a28[v42]) : a28[v42] +
                a28[v42 ^ 16];
        }
        for (v43 = 0; v43 < 1024; v43++) {
            a28[v43] = !((v43 & 8) == 0) ? a23[v43 << 6 & 511] * (a26[v43 ^ 8] -
                                                                  a26[v43]) : a26[v43] +
                a26[v43 ^ 8];
        }
        for (v44 = 0; v44 < 1024; v44++) {
            a26[v44] = !((v44 & 4) == 0) ? a23[v44 << 7 & 511] * (a28[v44 ^ 4] -
                                                                  a28[v44]) : a28[v44] +
                a28[v44 ^ 4];
        }
        for (v45 = 0; v45 < 1024; v45++) {
            a28[v45] = !((v45 & 2) == 0) ? a23[v45 << 8 & 511] * (a26[v45 ^ 2] -
                                                                  a26[v45]) : a26[v45] +
                a26[v45 ^ 2];
        }
        for (v46 = 0; v46 < 1024; v46++) {
            a26[v46] = !((v46 & 1) == 0) ? a23[v46 << 9 & 511] * (a28[v46 ^ 1] -
                                                                  a28[v46]) : a28[v46] +
                a28[v46 ^ 1];
        }
        for (v47 = 0; v47 < r25; v47++) {
            a28[v47] = a26[(v47 >> 1 >> 1 << 1 | (v47 & 1)) << 1 | (v47 >> 1 &
                                                                    1)];
        }
        for (v48 = 0; v48 < r27; v48++) {
            a26[v48] = a28[(v48 >> 1 >> 2 << 1 | (v48 & 1)) << 2 | (v48 >> 1 &
                                                                    3)];
        }
        for (v49 = 0; v49 < r25; v49++) {
            a28[v49] = a26[(v49 >> 1 >> 3 << 1 | (v49 & 1)) << 3 | (v49 >> 1 &
                                                                    7)];
        }
        for (v50 = 0; v50 < r27; v50++) {
            a26[v50] = a28[(v50 >> 1 >> 4 << 1 | (v50 & 1)) << 4 | (v50 >> 1 &
                                                                    15)];
        }
        for (v51 = 0; v51 < r25; v51++) {
            a28[v51] = a26[(v51 >> 1 >> 5 << 1 | (v51 & 1)) << 5 | (v51 >> 1 &
                                                                    31)];
        }
        for (v52 = 0; v52 < r27; v52++) {
            a26[v52] = a28[(v52 >> 1 >> 6 << 1 | (v52 & 1)) << 6 | (v52 >> 1 &
                                                                    63)];
        }
        for (v53 = 0; v53 < r25; v53++) {
            a28[v53] = a26[(v53 >> 1 >> 7 << 1 | (v53 & 1)) << 7 | (v53 >> 1 &
                                                                    127)];
        }
        for (v54 = 0; v54 < r27; v54++) {
            a26[v54] = a28[(v54 >> 1 >> 8 << 1 | (v54 & 1)) << 8 | (v54 >> 1 &
                                                                    255)];
        }
        for (v55 = 0; v55 < r25; v55++) {
            a28[v55] = a26[(v55 >> 1 >> 9 << 1 | (v55 & 1)) << 9 | (v55 >> 1 &
                                                                    511)];
        }
        r56 = r25;
        
        float _Complex _a57[r25];
        float _Complex *a57 = _a57;
        
        for (v58 = 0; v58 < r25; v58++) {
            a57[v58] = a26[(v58 >> 1 >> 9 << 1 | (v58 & 1)) << 9 | (v58 >> 1 &
                                                                    511)];
        }
        v59 = r56;
        v60 = v59;
        v61 = chan_write(chan20, sizeof(v60), &v60);
        v62 = chan_write(chan20, sizeof(*a57) * (v59 - 0), &a57[0]);
        if (!v62) {
            chan_close(chan1);
            pthread_cancel(t21);
            pthread_join(t21, NULL);
        }
    }
    chan_close(chan1);
    chan_close(chan20);
    return NULL;
}
chan_t chan63;
void *thread_t64(void *unused)
{
    uint32_t r65;
    float _a66[513];
    float *a66 = _a66;
    uint32_t v67;
    
    r65 = 513;
    for (v67 = 0; v67 < 513; v67++) {
        a66[v67] = 0.0;
    }
    while (1) {
        uint32_t v68;
        bool v70;
        uint32_t r71;
        uint32_t v72;
        bool v74;
        uint32_t v75;
        uint32_t v77;
        uint32_t r78;
        float _Complex _a79[513];
        float _Complex *a79 = _a79;
        uint32_t v80;
        uint32_t v81;
        uint32_t v82;
        bool v83;
        bool v84;
        
        chan_read(chan20, sizeof(v68), &v68);
        
        float _Complex _a69[v68];
        float _Complex *a69 = _a69;
        
        chan_read(chan20, sizeof(*a69) * (v68 - 0), &a69[0]);
        v70 = chan_last_read_ok(chan20);
        r71 = v68;
        v72 = r71;
        
        float _Complex _a73[v72];
        float _Complex *a73 = _a73;
        
        memcpy(a73, a69, v72 * sizeof(float _Complex));
        v74 = chan_last_read_ok(chan20);
        if (!v74) {
            chan_close(chan63);
            pthread_cancel(t64);
            pthread_join(t64, NULL);
        }
        v75 = r65;
        
        float _a76[v75];
        float *a76 = _a76;
        
        memcpy(a76, a66, v75 * sizeof(float));
        for (v77 = 0; v77 < 513; v77++) {
            a66[v77] = carg(a73[v77]);
        }
        r78 = 513;
        for (v80 = 0; v80 < 513; v80++) {
            a79[v80] = 2.0 * cabs(a73[v80]) + I * (((float) v80 + 4.0 *
                                                    (carg(a73[v80]) - a76[v80] -
                                                     (float) v80 * 1.5707964) /
                                                    (2.0 * FELD_PI)) *
                                                   43.066406);
        }
        v81 = r78;
        v82 = v81;
        v83 = chan_write(chan63, sizeof(v82), &v82);
        v84 = chan_write(chan63, sizeof(*a79) * (v81 - 0), &a79[0]);
        if (!v84) {
            chan_close(chan20);
            pthread_cancel(t64);
            pthread_join(t64, NULL);
        }
    }
    chan_close(chan20);
    chan_close(chan63);
    return NULL;
}
chan_t chan85;
void *thread_t86(void *unused)
{
    while (1) {
        uint32_t v87;
        bool v89;
        uint32_t r90;
        uint32_t v91;
        bool v93;
        float _Complex _a94[513];
        float _Complex *a94 = _a94;
        uint32_t v95;
        uint32_t r96;
        float _Complex _a97[513];
        float _Complex *a97 = _a97;
        uint32_t v98;
        uint32_t v99;
        uint32_t v100;
        bool v101;
        bool v102;
        
        chan_read(chan63, sizeof(v87), &v87);
        
        float _Complex _a88[v87];
        float _Complex *a88 = _a88;
        
        chan_read(chan63, sizeof(*a88) * (v87 - 0), &a88[0]);
        v89 = chan_last_read_ok(chan63);
        r90 = v87;
        v91 = r90;
        
        float _Complex _a92[v91];
        float _Complex *a92 = _a92;
        
        memcpy(a92, a88, v91 * sizeof(float _Complex));
        v93 = chan_last_read_ok(chan63);
        if (!v93) {
            chan_close(chan85);
            pthread_cancel(t86);
            pthread_join(t86, NULL);
        }
        for (v95 = 0; v95 < 513; v95++) {
            a94[(uint32_t) lround((float) v95 * 2.0)] =
                (uint32_t) lround((float) v95 * 2.0) < 513 ? creal(a92[v95]) +
                I * (2.0 * cimag(a92[v95])) : 0.0;
        }
        r96 = 513;
        for (v98 = 0; v98 < 513; v98++) {
            a97[v98] = a94[v98];
        }
        v99 = r96;
        v100 = v99;
        v101 = chan_write(chan85, sizeof(v100), &v100);
        v102 = chan_write(chan85, sizeof(*a97) * (v99 - 0), &a97[0]);
        if (!v102) {
            chan_close(chan63);
            pthread_cancel(t86);
            pthread_join(t86, NULL);
        }
    }
    chan_close(chan63);
    chan_close(chan85);
    return NULL;
}
chan_t chan103;
void *thread_t104(void *unused)
{
    uint32_t r105;
    float _a106[513];
    float *a106 = _a106;
    uint32_t v107;
    
    r105 = 513;
    for (v107 = 0; v107 < 513; v107++) {
        a106[v107] = 0.0;
    }
    while (1) {
        uint32_t v108;
        bool v110;
        uint32_t r111;
        uint32_t v112;
        bool v114;
        uint32_t v115;
        uint32_t v117;
        uint32_t r118;
        float _Complex _a119[1024];
        float _Complex *a119 = _a119;
        uint32_t v120;
        uint32_t v121;
        uint32_t v122;
        bool v123;
        bool v124;
        
        chan_read(chan85, sizeof(v108), &v108);
        
        float _Complex _a109[v108];
        float _Complex *a109 = _a109;
        
        chan_read(chan85, sizeof(*a109) * (v108 - 0), &a109[0]);
        v110 = chan_last_read_ok(chan85);
        r111 = v108;
        v112 = r111;
        
        float _Complex _a113[v112];
        float _Complex *a113 = _a113;
        
        memcpy(a113, a109, v112 * sizeof(float _Complex));
        v114 = chan_last_read_ok(chan85);
        if (!v114) {
            chan_close(chan103);
            pthread_cancel(t104);
            pthread_join(t104, NULL);
        }
        v115 = r105;
        
        float _a116[v115];
        float *a116 = _a116;
        
        memcpy(a116, a106, v115 * sizeof(float));
        for (v117 = 0; v117 < 513; v117++) {
            a106[v117] = a116[v117] + (2.0 * FELD_PI * ((cimag(a113[v117]) -
                                                         (float) v117 *
                                                         43.066406) /
                                                        43.066406) / 4.0 +
                                       (float) v117 * 1.5707964);
        }
        r118 = 1024;
        for (v120 = 0; v120 < 1024; v120++) {
            a119[v120] = v120 <= 513 ? creal(a113[v120]) * exp(I * (a116[v120] +
                                                                    (2.0 *
                                                                     FELD_PI *
                                                                     ((cimag(a113[v120]) -
                                                                       (float) v120 *
                                                                       43.066406) /
                                                                      43.066406) /
                                                                     4.0 +
                                                                     (float) v120 *
                                                                     1.5707964))) : 0.0;
        }
        v121 = r118;
        v122 = v121;
        v123 = chan_write(chan103, sizeof(v122), &v122);
        v124 = chan_write(chan103, sizeof(*a119) * (v121 - 0), &a119[0]);
        if (!v124) {
            chan_close(chan85);
            pthread_cancel(t104);
            pthread_join(t104, NULL);
        }
    }
    chan_close(chan85);
    chan_close(chan103);
    return NULL;
}
chan_t chan125;
void *thread_t126(void *unused)
{
    uint32_t r127;
    float _Complex _a128[512];
    float _Complex *a128 = _a128;
    uint32_t v129;
    uint32_t r130;
    float _Complex _a131[1024];
    float _Complex *a131 = _a131;
    uint32_t r132;
    float _Complex _a133[1024];
    float _Complex *a133 = _a133;
    
    r127 = 512;
    for (v129 = 0; v129 < 512; v129++) {
        a128[v129] = exp(I * (FELD_PI * (float) v129 * 1.953125e-3));
    }
    r130 = 1024;
    r132 = 1024;
    while (1) {
        uint32_t v134;
        bool v136;
        uint32_t r137;
        uint32_t v138;
        bool v140;
        uint32_t v141;
        uint32_t v142;
        uint32_t v143;
        uint32_t v144;
        uint32_t v145;
        uint32_t v146;
        uint32_t v147;
        uint32_t v148;
        uint32_t v149;
        uint32_t v150;
        uint32_t v151;
        uint32_t v152;
        uint32_t v153;
        uint32_t v154;
        uint32_t v155;
        uint32_t v156;
        uint32_t v157;
        uint32_t v158;
        uint32_t v159;
        uint32_t v160;
        uint32_t r161;
        uint32_t v163;
        uint32_t v164;
        uint32_t v165;
        bool v166;
        bool v167;
        
        chan_read(chan103, sizeof(v134), &v134);
        
        float _Complex _a135[v134];
        float _Complex *a135 = _a135;
        
        chan_read(chan103, sizeof(*a135) * (v134 - 0), &a135[0]);
        v136 = chan_last_read_ok(chan103);
        r137 = v134;
        v138 = r137;
        
        float _Complex _a139[v138];
        float _Complex *a139 = _a139;
        
        memcpy(a139, a135, v138 * sizeof(float _Complex));
        v140 = chan_last_read_ok(chan103);
        if (!v140) {
            chan_close(chan125);
            pthread_cancel(t126);
            pthread_join(t126, NULL);
        }
        for (v141 = 0; v141 < v138; v141++) {
            a131[v141] = a139[v141];
        }
        for (v142 = 0; v142 < 1024; v142++) {
            a133[v142] = !((v142 & 512) == 0) ? a128[v142 << 0 & 511] *
                (a131[v142 ^ 512] - a131[v142]) : a131[v142] + a131[v142 ^ 512];
        }
        for (v143 = 0; v143 < 1024; v143++) {
            a131[v143] = !((v143 & 256) == 0) ? a128[v143 << 1 & 511] *
                (a133[v143 ^ 256] - a133[v143]) : a133[v143] + a133[v143 ^ 256];
        }
        for (v144 = 0; v144 < 1024; v144++) {
            a133[v144] = !((v144 & 128) == 0) ? a128[v144 << 2 & 511] *
                (a131[v144 ^ 128] - a131[v144]) : a131[v144] + a131[v144 ^ 128];
        }
        for (v145 = 0; v145 < 1024; v145++) {
            a131[v145] = !((v145 & 64) == 0) ? a128[v145 << 3 & 511] *
                (a133[v145 ^ 64] - a133[v145]) : a133[v145] + a133[v145 ^ 64];
        }
        for (v146 = 0; v146 < 1024; v146++) {
            a133[v146] = !((v146 & 32) == 0) ? a128[v146 << 4 & 511] *
                (a131[v146 ^ 32] - a131[v146]) : a131[v146] + a131[v146 ^ 32];
        }
        for (v147 = 0; v147 < 1024; v147++) {
            a131[v147] = !((v147 & 16) == 0) ? a128[v147 << 5 & 511] *
                (a133[v147 ^ 16] - a133[v147]) : a133[v147] + a133[v147 ^ 16];
        }
        for (v148 = 0; v148 < 1024; v148++) {
            a133[v148] = !((v148 & 8) == 0) ? a128[v148 << 6 & 511] *
                (a131[v148 ^ 8] - a131[v148]) : a131[v148] + a131[v148 ^ 8];
        }
        for (v149 = 0; v149 < 1024; v149++) {
            a131[v149] = !((v149 & 4) == 0) ? a128[v149 << 7 & 511] *
                (a133[v149 ^ 4] - a133[v149]) : a133[v149] + a133[v149 ^ 4];
        }
        for (v150 = 0; v150 < 1024; v150++) {
            a133[v150] = !((v150 & 2) == 0) ? a128[v150 << 8 & 511] *
                (a131[v150 ^ 2] - a131[v150]) : a131[v150] + a131[v150 ^ 2];
        }
        for (v151 = 0; v151 < 1024; v151++) {
            a131[v151] = !((v151 & 1) == 0) ? a128[v151 << 9 & 511] *
                (a133[v151 ^ 1] - a133[v151]) : a133[v151] + a133[v151 ^ 1];
        }
        for (v152 = 0; v152 < r130; v152++) {
            a133[v152] = a131[(v152 >> 1 >> 1 << 1 | (v152 & 1)) << 1 | (v152 >>
                                                                         1 &
                                                                         1)];
        }
        for (v153 = 0; v153 < r132; v153++) {
            a131[v153] = a133[(v153 >> 1 >> 2 << 1 | (v153 & 1)) << 2 | (v153 >>
                                                                         1 &
                                                                         3)];
        }
        for (v154 = 0; v154 < r130; v154++) {
            a133[v154] = a131[(v154 >> 1 >> 3 << 1 | (v154 & 1)) << 3 | (v154 >>
                                                                         1 &
                                                                         7)];
        }
        for (v155 = 0; v155 < r132; v155++) {
            a131[v155] = a133[(v155 >> 1 >> 4 << 1 | (v155 & 1)) << 4 | (v155 >>
                                                                         1 &
                                                                         15)];
        }
        for (v156 = 0; v156 < r130; v156++) {
            a133[v156] = a131[(v156 >> 1 >> 5 << 1 | (v156 & 1)) << 5 | (v156 >>
                                                                         1 &
                                                                         31)];
        }
        for (v157 = 0; v157 < r132; v157++) {
            a131[v157] = a133[(v157 >> 1 >> 6 << 1 | (v157 & 1)) << 6 | (v157 >>
                                                                         1 &
                                                                         63)];
        }
        for (v158 = 0; v158 < r130; v158++) {
            a133[v158] = a131[(v158 >> 1 >> 7 << 1 | (v158 & 1)) << 7 | (v158 >>
                                                                         1 &
                                                                         127)];
        }
        for (v159 = 0; v159 < r132; v159++) {
            a131[v159] = a133[(v159 >> 1 >> 8 << 1 | (v159 & 1)) << 8 | (v159 >>
                                                                         1 &
                                                                         255)];
        }
        for (v160 = 0; v160 < r130; v160++) {
            a133[v160] = a131[(v160 >> 1 >> 9 << 1 | (v160 & 1)) << 9 | (v160 >>
                                                                         1 &
                                                                         511)];
        }
        r161 = r130;
        
        float _Complex _a162[r130];
        float _Complex *a162 = _a162;
        
        for (v163 = 0; v163 < r130; v163++) {
            a162[v163] = a131[(v163 >> 1 >> 9 << 1 | (v163 & 1)) << 9 | (v163 >>
                                                                         1 &
                                                                         511)];
        }
        v164 = r161;
        v165 = v164;
        v166 = chan_write(chan125, sizeof(v165), &v165);
        v167 = chan_write(chan125, sizeof(*a162) * (v164 - 0), &a162[0]);
        if (!v167) {
            chan_close(chan103);
            pthread_cancel(t126);
            pthread_join(t126, NULL);
        }
    }
    chan_close(chan103);
    chan_close(chan125);
    return NULL;
}
chan_t chan168;
void *thread_t169(void *unused)
{
    uint32_t r170;
    float _a171[1024];
    float *a171 = _a171;
    uint32_t v172;
    
    r170 = 1024;
    for (v172 = 0; v172 < 1024; v172++) {
        a171[v172] = -(0.5 * cos(2.0 * FELD_PI * (float) v172 / 1024.0)) + 0.5;
    }
    while (1) {
        uint32_t v173;
        bool v175;
        uint32_t r176;
        uint32_t v177;
        bool v179;
        uint32_t r180;
        uint32_t v182;
        uint32_t v183;
        uint32_t v184;
        bool v185;
        bool v186;
        
        chan_read(chan125, sizeof(v173), &v173);
        
        float _Complex _a174[v173];
        float _Complex *a174 = _a174;
        
        chan_read(chan125, sizeof(*a174) * (v173 - 0), &a174[0]);
        v175 = chan_last_read_ok(chan125);
        r176 = v173;
        v177 = r176;
        
        float _Complex _a178[v177];
        float _Complex *a178 = _a178;
        
        memcpy(a178, a174, v177 * sizeof(float _Complex));
        v179 = chan_last_read_ok(chan125);
        if (!v179) {
            chan_close(chan168);
            pthread_cancel(t169);
            pthread_join(t169, NULL);
        }
        r180 = v177 <= r170 ? v177 : r170;
        
        float _a181[v177 <= r170 ? v177 : r170];
        float *a181 = _a181;
        
        for (v182 = 0; v182 < (v177 <= r170 ? v177 : r170); v182++) {
            a181[v182] = creal(a178[v182]) / 4096.0 * a171[v182];
        }
        v183 = r180;
        v184 = v183;
        v185 = chan_write(chan168, sizeof(v184), &v184);
        v186 = chan_write(chan168, sizeof(*a181) * (v183 - 0), &a181[0]);
        if (!v186) {
            chan_close(chan125);
            pthread_cancel(t169);
            pthread_join(t169, NULL);
        }
    }
    chan_close(chan125);
    chan_close(chan168);
    return NULL;
}
void *thread_t187(void *unused)
{
    while (1) {
        uint32_t v188;
        bool v190;
        uint32_t r191;
        uint32_t v192;
        bool v194;
        uint32_t v196;
        bool v197;
        
        chan_read(chan168, sizeof(v188), &v188);
        
        float _a189[v188];
        float *a189 = _a189;
        
        chan_read(chan168, sizeof(*a189) * (v188 - 0), &a189[0]);
        v190 = chan_last_read_ok(chan168);
        r191 = v188;
        v192 = r191;
        
        float _a193[v192];
        float *a193 = _a193;
        
        memcpy(a193, a189, v192 * sizeof(float));
        v194 = chan_last_read_ok(chan168);
        if (!v194) {
            pthread_cancel(t187);
            pthread_join(t187, NULL);
        }
        
        float _a195[v192];
        float *a195 = _a195;
        
        for (v196 = 0; v196 < v192; v196++) {
            a195[v196] = a193[v196];
        }
        v197 = emit_samples(a195);
        if (!v197) {
            chan_close(chan168);
            pthread_cancel(t187);
            pthread_join(t187, NULL);
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
    chan63 = chan_new(10 * sizeof(uint32_t) + 10 * (513 *
                                                    sizeof(float _Complex)));
    pthread_create(&t64, NULL, thread_t64, NULL);
    chan85 = chan_new(10 * sizeof(uint32_t) + 10 * (513 *
                                                    sizeof(float _Complex)));
    pthread_create(&t86, NULL, thread_t86, NULL);
    chan103 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t104, NULL, thread_t104, NULL);
    chan125 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t126, NULL, thread_t126, NULL);
    chan168 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 * sizeof(float)));
    pthread_create(&t169, NULL, thread_t169, NULL);
    pthread_create(&t187, NULL, thread_t187, NULL);
    while (1) {
        float _a198[1024];
        float *a198 = _a198;
        bool v199;
        uint32_t r200;
        float _a201[1024];
        float *a201 = _a201;
        uint32_t v202;
        uint32_t v203;
        uint32_t v204;
        bool v205;
        bool v206;
        
        v199 = receive_samples(a198);
        if (!v199) {
            break;
        }
        r200 = 1024;
        for (v202 = 0; v202 < 1024; v202++) {
            a201[v202] = a198[v202];
        }
        v203 = r200;
        v204 = v203;
        v205 = chan_write(chan0, sizeof(v204), &v204);
        v206 = chan_write(chan0, sizeof(*a201) * (v203 - 0), &a201[0]);
        if (!v206) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t187, NULL);
    teardown_queues();
    return 0;
}

