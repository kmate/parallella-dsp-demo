#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
void *thread_t2(void *unused);
void *thread_t149(void *unused);
pthread_t t149;
pthread_t t2;
chan_t chan0;
chan_t chan1;
#define FELD_PI 3.141592653589793
void *thread_t2(void *unused)
{
    float _a3[513];
    float *a3 = _a3;
    float _a4[513];
    float *a4 = _a4;
    
    while (1) {
        uint32_t v5;
        bool v7;
        uint32_t r8;
        uint32_t v9;
        bool v11;
        uint32_t r12;
        uint32_t v14;
        uint32_t r15;
        uint32_t v17;
        uint32_t r18;
        uint32_t v20;
        uint32_t r21;
        uint32_t v23;
        uint32_t r24;
        uint32_t v26;
        uint32_t r27;
        uint32_t v29;
        uint32_t r30;
        uint32_t v32;
        uint32_t r33;
        uint32_t v35;
        uint32_t r36;
        uint32_t v38;
        uint32_t r39;
        uint32_t v41;
        uint32_t r42;
        uint32_t v44;
        uint32_t r45;
        uint32_t v47;
        uint32_t r48;
        uint32_t v50;
        uint32_t r51;
        uint32_t v53;
        uint32_t r54;
        uint32_t v56;
        uint32_t r57;
        uint32_t v59;
        uint32_t r60;
        uint32_t v62;
        uint32_t r63;
        uint32_t v65;
        uint32_t r66;
        uint32_t v68;
        float _Complex _a69[513];
        float _Complex *a69 = _a69;
        uint32_t v70;
        float _Complex _a78[513];
        float _Complex *a78 = _a78;
        uint32_t v79;
        float _Complex _a82[513];
        float _Complex *a82 = _a82;
        uint32_t v83;
        uint32_t r85;
        float _Complex _a86[1024];
        float _Complex *a86 = _a86;
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
        uint32_t r130;
        uint32_t v132;
        uint32_t r133;
        uint32_t v135;
        uint32_t r136;
        uint32_t v138;
        uint32_t r139;
        uint32_t v141;
        uint32_t r142;
        uint32_t v144;
        uint32_t v145;
        uint32_t v146;
        bool v147;
        bool v148;
        
        chan_read(chan0, sizeof(v5), &v5);
        
        float _a6[v5];
        float *a6 = _a6;
        
        chan_read(chan0, sizeof(*a6) * (v5 - 0), &a6[0]);
        v7 = chan_last_read_ok(chan0);
        r8 = v5;
        v9 = r8;
        
        float _a10[v9];
        float *a10 = _a10;
        
        memcpy(a10, a6, v9 * sizeof(float));
        v11 = chan_last_read_ok(chan0);
        if (!v11) {
            chan_close(chan1);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
        r12 = v9 <= 1024 ? v9 : 1024;
        
        float _Complex _a13[v9 <= 1024 ? v9 : 1024];
        float _Complex *a13 = _a13;
        
        for (v14 = 0; v14 < (v9 <= 1024 ? v9 : 1024); v14++) {
            a13[v14] = !((v14 & 512) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v14 & 511) /
                                                      512.0)) * (a10[v14 ^
                                                                     512] *
                                                                 (-(0.5 *
                                                                    cos(2.0 *
                                                                    FELD_PI *
                                                                    (float) (v14 ^
                                                                             512) /
                                                                    1024.0)) +
                                                                  0.5) -
                                                                 a10[v14] *
                                                                 (-(0.5 *
                                                                    cos(2.0 *
                                                                    FELD_PI *
                                                                    (float) v14 /
                                                                    1024.0)) +
                                                                  0.5)) : a10[v14] *
                (-(0.5 * cos(2.0 * FELD_PI * (float) v14 / 1024.0)) + 0.5) +
                a10[v14 ^ 512] * (-(0.5 * cos(2.0 * FELD_PI * (float) (v14 ^
                                                                       512) /
                                    1024.0)) + 0.5);
        }
        r15 = r12;
        
        float _Complex _a16[r12];
        float _Complex *a16 = _a16;
        
        for (v17 = 0; v17 < r12; v17++) {
            a16[v17] = !((v17 & 256) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v17 & 255) /
                                                      256.0)) * (a13[v17 ^
                                                                     256] -
                                                                 a13[v17]) : a13[v17] +
                a13[v17 ^ 256];
        }
        r18 = r15;
        
        float _Complex _a19[r15];
        float _Complex *a19 = _a19;
        
        for (v20 = 0; v20 < r15; v20++) {
            a19[v20] = !((v20 & 128) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v20 & 127) /
                                                      128.0)) * (a16[v20 ^
                                                                     128] -
                                                                 a16[v20]) : a16[v20] +
                a16[v20 ^ 128];
        }
        r21 = r18;
        
        float _Complex _a22[r18];
        float _Complex *a22 = _a22;
        
        for (v23 = 0; v23 < r18; v23++) {
            a22[v23] = !((v23 & 64) == 0) ? exp(I * (-3.1415927 * (float) (v23 &
                                                                           63) /
                                                     64.0)) * (a19[v23 ^ 64] -
                                                               a19[v23]) : a19[v23] +
                a19[v23 ^ 64];
        }
        r24 = r21;
        
        float _Complex _a25[r21];
        float _Complex *a25 = _a25;
        
        for (v26 = 0; v26 < r21; v26++) {
            a25[v26] = !((v26 & 32) == 0) ? exp(I * (-3.1415927 * (float) (v26 &
                                                                           31) /
                                                     32.0)) * (a22[v26 ^ 32] -
                                                               a22[v26]) : a22[v26] +
                a22[v26 ^ 32];
        }
        r27 = r24;
        
        float _Complex _a28[r24];
        float _Complex *a28 = _a28;
        
        for (v29 = 0; v29 < r24; v29++) {
            a28[v29] = !((v29 & 16) == 0) ? exp(I * (-3.1415927 * (float) (v29 &
                                                                           15) /
                                                     16.0)) * (a25[v29 ^ 16] -
                                                               a25[v29]) : a25[v29] +
                a25[v29 ^ 16];
        }
        r30 = r27;
        
        float _Complex _a31[r27];
        float _Complex *a31 = _a31;
        
        for (v32 = 0; v32 < r27; v32++) {
            a31[v32] = !((v32 & 8) == 0) ? exp(I * (-3.1415927 * (float) (v32 &
                                                                          7) /
                                                    8.0)) * (a28[v32 ^ 8] -
                                                             a28[v32]) : a28[v32] +
                a28[v32 ^ 8];
        }
        r33 = r30;
        
        float _Complex _a34[r30];
        float _Complex *a34 = _a34;
        
        for (v35 = 0; v35 < r30; v35++) {
            a34[v35] = !((v35 & 4) == 0) ? exp(I * (-3.1415927 * (float) (v35 &
                                                                          3) /
                                                    4.0)) * (a31[v35 ^ 4] -
                                                             a31[v35]) : a31[v35] +
                a31[v35 ^ 4];
        }
        r36 = r33;
        
        float _Complex _a37[r33];
        float _Complex *a37 = _a37;
        
        for (v38 = 0; v38 < r33; v38++) {
            a37[v38] = !((v38 & 2) == 0) ? exp(I * (-3.1415927 * (float) (v38 &
                                                                          1) /
                                                    2.0)) * (a34[v38 ^ 2] -
                                                             a34[v38]) : a34[v38] +
                a34[v38 ^ 2];
        }
        r39 = r36;
        
        float _Complex _a40[r36];
        float _Complex *a40 = _a40;
        
        for (v41 = 0; v41 < r36; v41++) {
            a40[v41] = !((v41 & 1) == 0) ? exp(I * (-3.1415927 * (float) (v41 &
                                                                          0) /
                                                    1.0)) * (a37[v41 ^ 1] -
                                                             a37[v41]) : a37[v41] +
                a37[v41 ^ 1];
        }
        r42 = r39;
        
        float _Complex _a43[r39];
        float _Complex *a43 = _a43;
        
        for (v44 = 0; v44 < r39; v44++) {
            a43[v44] = a40[(v44 >> 1 >> 1 << 1 | (v44 & 1)) << 1 | (v44 >> 1 &
                                                                    1)];
        }
        r45 = r42;
        
        float _Complex _a46[r42];
        float _Complex *a46 = _a46;
        
        for (v47 = 0; v47 < r42; v47++) {
            a46[v47] = a43[(v47 >> 1 >> 2 << 1 | (v47 & 1)) << 2 | (v47 >> 1 &
                                                                    3)];
        }
        r48 = r45;
        
        float _Complex _a49[r45];
        float _Complex *a49 = _a49;
        
        for (v50 = 0; v50 < r45; v50++) {
            a49[v50] = a46[(v50 >> 1 >> 3 << 1 | (v50 & 1)) << 3 | (v50 >> 1 &
                                                                    7)];
        }
        r51 = r48;
        
        float _Complex _a52[r48];
        float _Complex *a52 = _a52;
        
        for (v53 = 0; v53 < r48; v53++) {
            a52[v53] = a49[(v53 >> 1 >> 4 << 1 | (v53 & 1)) << 4 | (v53 >> 1 &
                                                                    15)];
        }
        r54 = r51;
        
        float _Complex _a55[r51];
        float _Complex *a55 = _a55;
        
        for (v56 = 0; v56 < r51; v56++) {
            a55[v56] = a52[(v56 >> 1 >> 5 << 1 | (v56 & 1)) << 5 | (v56 >> 1 &
                                                                    31)];
        }
        r57 = r54;
        
        float _Complex _a58[r54];
        float _Complex *a58 = _a58;
        
        for (v59 = 0; v59 < r54; v59++) {
            a58[v59] = a55[(v59 >> 1 >> 6 << 1 | (v59 & 1)) << 6 | (v59 >> 1 &
                                                                    63)];
        }
        r60 = r57;
        
        float _Complex _a61[r57];
        float _Complex *a61 = _a61;
        
        for (v62 = 0; v62 < r57; v62++) {
            a61[v62] = a58[(v62 >> 1 >> 7 << 1 | (v62 & 1)) << 7 | (v62 >> 1 &
                                                                    127)];
        }
        r63 = r60;
        
        float _Complex _a64[r60];
        float _Complex *a64 = _a64;
        
        for (v65 = 0; v65 < r60; v65++) {
            a64[v65] = a61[(v65 >> 1 >> 8 << 1 | (v65 & 1)) << 8 | (v65 >> 1 &
                                                                    255)];
        }
        r66 = r63;
        
        float _Complex _a67[r63];
        float _Complex *a67 = _a67;
        
        for (v68 = 0; v68 < r63; v68++) {
            a67[v68] = a64[(v68 >> 1 >> 9 << 1 | (v68 & 1)) << 9 | (v68 >> 1 &
                                                                    511)];
        }
        for (v70 = 0; v70 < 513; v70++) {
            float v71;
            float r72;
            float v77;
            
            v71 = a3[v70];
            a3[v70] = carg(a67[v70]);
            r72 = carg(a67[v70]) - v71 - (float) v70 * 1.5707964;
            while (1) {
                float v73;
                float v74;
                
                v73 = r72;
                if (!(v73 > FELD_PI))
                    break;
                v74 = r72;
                r72 = v74 + -6.2831855;
            }
            while (1) {
                float v75;
                float v76;
                
                v75 = r72;
                if (!(v75 < -3.1415927))
                    break;
                v76 = r72;
                r72 = v76 + 6.2831855;
            }
            v77 = r72;
            a69[v70] = 2.0 * cabs(a67[v70]) + I * (((float) v70 + 4.0 * v77 /
                                                    (2.0 * FELD_PI)) *
                                                   43.066406);
        }
        for (v79 = 0; v79 < 513; v79++) {
            uint32_t r80;
            uint32_t v81;
            
            r80 = round((float) v79 * 2.0);
            v81 = r80;
            a78[v81] = round((float) v79 * 2.0) < 513 ? creal(a69[v79]) + I *
                (2.0 * cimag(a69[v79])) : 0.0;
        }
        for (v83 = 0; v83 < 513; v83++) {
            float v84;
            
            v84 = a4[v83];
            a4[v83] = v84 + (2.0 * FELD_PI * ((cimag(a78[v83]) - (float) v83 *
                                               43.066406) / 43.066406) / 4.0 +
                             (float) v83 * 1.5707964);
            a82[v83] = creal(a78[v83]) * cos(v84 + (2.0 * FELD_PI *
                                                    ((cimag(a78[v83]) -
                                                      (float) v83 * 43.066406) /
                                                     43.066406) / 4.0 +
                                                    (float) v83 * 1.5707964)) +
                I * (creal(a78[v83]) * sin(v84 + (2.0 * FELD_PI *
                                                  ((cimag(a78[v83]) -
                                                    (float) v83 * 43.066406) /
                                                   43.066406) / 4.0 +
                                                  (float) v83 * 1.5707964)));
        }
        r85 = 1024;
        for (v87 = 0; v87 < 1024; v87++) {
            a86[v87] = !((v87 & 512) == 0) ? exp(I * (FELD_PI * (float) (v87 &
                                                                         511) /
                                                      512.0)) * (((v87 ^ 512) <=
                                                                  513 ? a82[v87 ^
                                                                            512] : 0.0) -
                                                                 (v87 <=
                                                                  513 ? a82[v87] : 0.0)) : (v87 <=
                                                                                            513 ? a82[v87] : 0.0) +
                ((v87 ^ 512) <= 513 ? a82[v87 ^ 512] : 0.0);
        }
        r88 = r85;
        
        float _Complex _a89[r85];
        float _Complex *a89 = _a89;
        
        for (v90 = 0; v90 < r85; v90++) {
            a89[v90] = !((v90 & 256) == 0) ? exp(I * (FELD_PI * (float) (v90 &
                                                                         255) /
                                                      256.0)) * (a86[v90 ^
                                                                     256] -
                                                                 a86[v90]) : a86[v90] +
                a86[v90 ^ 256];
        }
        r91 = r88;
        
        float _Complex _a92[r88];
        float _Complex *a92 = _a92;
        
        for (v93 = 0; v93 < r88; v93++) {
            a92[v93] = !((v93 & 128) == 0) ? exp(I * (FELD_PI * (float) (v93 &
                                                                         127) /
                                                      128.0)) * (a89[v93 ^
                                                                     128] -
                                                                 a89[v93]) : a89[v93] +
                a89[v93 ^ 128];
        }
        r94 = r91;
        
        float _Complex _a95[r91];
        float _Complex *a95 = _a95;
        
        for (v96 = 0; v96 < r91; v96++) {
            a95[v96] = !((v96 & 64) == 0) ? exp(I * (FELD_PI * (float) (v96 &
                                                                        63) /
                                                     64.0)) * (a92[v96 ^ 64] -
                                                               a92[v96]) : a92[v96] +
                a92[v96 ^ 64];
        }
        r97 = r94;
        
        float _Complex _a98[r94];
        float _Complex *a98 = _a98;
        
        for (v99 = 0; v99 < r94; v99++) {
            a98[v99] = !((v99 & 32) == 0) ? exp(I * (FELD_PI * (float) (v99 &
                                                                        31) /
                                                     32.0)) * (a95[v99 ^ 32] -
                                                               a95[v99]) : a95[v99] +
                a95[v99 ^ 32];
        }
        r100 = r97;
        
        float _Complex _a101[r97];
        float _Complex *a101 = _a101;
        
        for (v102 = 0; v102 < r97; v102++) {
            a101[v102] = !((v102 & 16) == 0) ? exp(I * (FELD_PI *
                                                        (float) (v102 & 15) /
                                                        16.0)) * (a98[v102 ^
                                                                      16] -
                                                                  a98[v102]) : a98[v102] +
                a98[v102 ^ 16];
        }
        r103 = r100;
        
        float _Complex _a104[r100];
        float _Complex *a104 = _a104;
        
        for (v105 = 0; v105 < r100; v105++) {
            a104[v105] = !((v105 & 8) == 0) ? exp(I * (FELD_PI * (float) (v105 &
                                                                          7) /
                                                       8.0)) * (a101[v105 ^ 8] -
                                                                a101[v105]) : a101[v105] +
                a101[v105 ^ 8];
        }
        r106 = r103;
        
        float _Complex _a107[r103];
        float _Complex *a107 = _a107;
        
        for (v108 = 0; v108 < r103; v108++) {
            a107[v108] = !((v108 & 4) == 0) ? exp(I * (FELD_PI * (float) (v108 &
                                                                          3) /
                                                       4.0)) * (a104[v108 ^ 4] -
                                                                a104[v108]) : a104[v108] +
                a104[v108 ^ 4];
        }
        r109 = r106;
        
        float _Complex _a110[r106];
        float _Complex *a110 = _a110;
        
        for (v111 = 0; v111 < r106; v111++) {
            a110[v111] = !((v111 & 2) == 0) ? exp(I * (FELD_PI * (float) (v111 &
                                                                          1) /
                                                       2.0)) * (a107[v111 ^ 2] -
                                                                a107[v111]) : a107[v111] +
                a107[v111 ^ 2];
        }
        r112 = r109;
        
        float _Complex _a113[r109];
        float _Complex *a113 = _a113;
        
        for (v114 = 0; v114 < r109; v114++) {
            a113[v114] = !((v114 & 1) == 0) ? exp(I * (FELD_PI * (float) (v114 &
                                                                          0) /
                                                       1.0)) * (a110[v114 ^ 1] -
                                                                a110[v114]) : a110[v114] +
                a110[v114 ^ 1];
        }
        r115 = r112;
        
        float _Complex _a116[r112];
        float _Complex *a116 = _a116;
        
        for (v117 = 0; v117 < r112; v117++) {
            a116[v117] = a113[(v117 >> 1 >> 1 << 1 | (v117 & 1)) << 1 | (v117 >>
                                                                         1 &
                                                                         1)];
        }
        r118 = r115;
        
        float _Complex _a119[r115];
        float _Complex *a119 = _a119;
        
        for (v120 = 0; v120 < r115; v120++) {
            a119[v120] = a116[(v120 >> 1 >> 2 << 1 | (v120 & 1)) << 2 | (v120 >>
                                                                         1 &
                                                                         3)];
        }
        r121 = r118;
        
        float _Complex _a122[r118];
        float _Complex *a122 = _a122;
        
        for (v123 = 0; v123 < r118; v123++) {
            a122[v123] = a119[(v123 >> 1 >> 3 << 1 | (v123 & 1)) << 3 | (v123 >>
                                                                         1 &
                                                                         7)];
        }
        r124 = r121;
        
        float _Complex _a125[r121];
        float _Complex *a125 = _a125;
        
        for (v126 = 0; v126 < r121; v126++) {
            a125[v126] = a122[(v126 >> 1 >> 4 << 1 | (v126 & 1)) << 4 | (v126 >>
                                                                         1 &
                                                                         15)];
        }
        r127 = r124;
        
        float _Complex _a128[r124];
        float _Complex *a128 = _a128;
        
        for (v129 = 0; v129 < r124; v129++) {
            a128[v129] = a125[(v129 >> 1 >> 5 << 1 | (v129 & 1)) << 5 | (v129 >>
                                                                         1 &
                                                                         31)];
        }
        r130 = r127;
        
        float _Complex _a131[r127];
        float _Complex *a131 = _a131;
        
        for (v132 = 0; v132 < r127; v132++) {
            a131[v132] = a128[(v132 >> 1 >> 6 << 1 | (v132 & 1)) << 6 | (v132 >>
                                                                         1 &
                                                                         63)];
        }
        r133 = r130;
        
        float _Complex _a134[r130];
        float _Complex *a134 = _a134;
        
        for (v135 = 0; v135 < r130; v135++) {
            a134[v135] = a131[(v135 >> 1 >> 7 << 1 | (v135 & 1)) << 7 | (v135 >>
                                                                         1 &
                                                                         127)];
        }
        r136 = r133;
        
        float _Complex _a137[r133];
        float _Complex *a137 = _a137;
        
        for (v138 = 0; v138 < r133; v138++) {
            a137[v138] = a134[(v138 >> 1 >> 8 << 1 | (v138 & 1)) << 8 | (v138 >>
                                                                         1 &
                                                                         255)];
        }
        r139 = r136;
        
        float _Complex _a140[r136];
        float _Complex *a140 = _a140;
        
        for (v141 = 0; v141 < r136; v141++) {
            a140[v141] = a137[(v141 >> 1 >> 9 << 1 | (v141 & 1)) << 9 | (v141 >>
                                                                         1 &
                                                                         511)];
        }
        r142 = r139 <= 1024 ? r139 : 1024;
        
        float _a143[r139 <= 1024 ? r139 : 1024];
        float *a143 = _a143;
        
        for (v144 = 0; v144 < (r139 <= 1024 ? r139 : 1024); v144++) {
            a143[v144] = creal(a140[v144]) / 4096.0 * (-(0.5 * cos(2.0 *
                                                         FELD_PI *
                                                         (float) v144 /
                                                         1024.0)) + 0.5);
        }
        v145 = r142;
        v146 = v145;
        v147 = chan_write(chan1, sizeof(v146), &v146);
        v148 = chan_write(chan1, sizeof(*a143) * (v145 - 0), &a143[0]);
        if (!v148) {
            chan_close(chan0);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
    }
    chan_close(chan0);
    chan_close(chan1);
    return NULL;
}
void *thread_t149(void *unused)
{
    while (1) {
        uint32_t v150;
        bool v152;
        uint32_t r153;
        uint32_t v154;
        bool v156;
        uint32_t v158;
        bool v159;
        
        chan_read(chan1, sizeof(v150), &v150);
        
        float _a151[v150];
        float *a151 = _a151;
        
        chan_read(chan1, sizeof(*a151) * (v150 - 0), &a151[0]);
        v152 = chan_last_read_ok(chan1);
        r153 = v150;
        v154 = r153;
        
        float _a155[v154];
        float *a155 = _a155;
        
        memcpy(a155, a151, v154 * sizeof(float));
        v156 = chan_last_read_ok(chan1);
        if (!v156) {
            pthread_cancel(t149);
            pthread_join(t149, NULL);
        }
        
        float _a157[v154];
        float *a157 = _a157;
        
        for (v158 = 0; v158 < v154; v158++) {
            a157[v158] = a155[v158];
        }
        v159 = emit_samples(a157);
        if (!v159) {
            chan_close(chan1);
            pthread_cancel(t149);
            pthread_join(t149, NULL);
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
    pthread_create(&t149, NULL, thread_t149, NULL);
    while (1) {
        float _a160[1024];
        float *a160 = _a160;
        bool v161;
        uint32_t r162;
        float _a163[1024];
        float *a163 = _a163;
        uint32_t v164;
        uint32_t v165;
        uint32_t v166;
        bool v167;
        bool v168;
        
        v161 = receive_samples(a160);
        if (!v161) {
            break;
        }
        r162 = 1024;
        for (v164 = 0; v164 < 1024; v164++) {
            a163[v164] = a160[v164];
        }
        v165 = r162;
        v166 = v165;
        v167 = chan_write(chan0, sizeof(v166), &v166);
        v168 = chan_write(chan0, sizeof(*a163) * (v165 - 0), &a163[0]);
        if (!v168) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t149, NULL);
    teardown_queues();
    return 0;
}

