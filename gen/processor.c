#include "c_processor.h"
#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
void *thread_t2(void *unused);
void *thread_t144(void *unused);
pthread_t t144;
pthread_t t2;
chan_t chan0;
chan_t chan1;
#define FELD_PI 3.141592653589793
void *thread_t2(void *unused)
{
    float _a3[513];
    float *a3 = _a3;
    
    while (1) {
        uint32_t v4;
        bool v6;
        uint32_t r7;
        uint32_t v8;
        bool v10;
        uint32_t r11;
        uint32_t v13;
        uint32_t r14;
        uint32_t v16;
        uint32_t r17;
        uint32_t v19;
        uint32_t r20;
        uint32_t v22;
        uint32_t r23;
        uint32_t v25;
        uint32_t r26;
        uint32_t v28;
        uint32_t r29;
        uint32_t v31;
        uint32_t r32;
        uint32_t v34;
        uint32_t r35;
        uint32_t v37;
        uint32_t r38;
        uint32_t v40;
        uint32_t r41;
        uint32_t v43;
        uint32_t r44;
        uint32_t v46;
        uint32_t r47;
        uint32_t v49;
        uint32_t r50;
        uint32_t v52;
        uint32_t r53;
        uint32_t v55;
        uint32_t r56;
        uint32_t v58;
        uint32_t r59;
        uint32_t v61;
        uint32_t r62;
        uint32_t v64;
        uint32_t r65;
        uint32_t v67;
        float _Complex _a68[513];
        float _Complex *a68 = _a68;
        uint32_t v69;
        float _Complex _a77[1024];
        float _Complex *a77 = _a77;
        uint32_t v78;
        float _Complex _a79[1024];
        float _Complex *a79 = _a79;
        uint32_t r80;
        float _Complex _a81[1024];
        float _Complex *a81 = _a81;
        uint32_t v82;
        uint32_t r83;
        uint32_t v85;
        uint32_t r86;
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
        uint32_t r116;
        uint32_t v118;
        uint32_t r119;
        uint32_t v121;
        uint32_t r122;
        uint32_t v124;
        uint32_t r125;
        uint32_t v127;
        uint32_t r128;
        uint32_t v130;
        uint32_t r131;
        uint32_t v133;
        uint32_t r134;
        uint32_t v136;
        uint32_t r137;
        uint32_t v139;
        uint32_t v140;
        uint32_t v141;
        bool v142;
        bool v143;
        
        chan_read(chan0, sizeof(v4), &v4);
        
        float _a5[v4];
        float *a5 = _a5;
        
        chan_read(chan0, sizeof(*a5) * (v4 - 0), &a5[0]);
        v6 = chan_last_read_ok(chan0);
        r7 = v4;
        v8 = r7;
        
        float _a9[v8];
        float *a9 = _a9;
        
        memcpy(a9, a5, v8 * sizeof(float));
        v10 = chan_last_read_ok(chan0);
        if (!v10) {
            chan_close(chan1);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
        r11 = v8;
        
        float _Complex _a12[v8];
        float _Complex *a12 = _a12;
        
        for (v13 = 0; v13 < v8; v13++) {
            a12[v13] = !((v13 & 512) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v13 & 511) /
                                                      512.0)) * (a9[v13 ^ 512] *
                                                                 (-(0.5 *
                                                                    cos(2.0 *
                                                                    FELD_PI *
                                                                    (float) (v13 ^
                                                                             512) /
                                                                    (float) v8)) +
                                                                  0.5) -
                                                                 a9[v13] *
                                                                 (-(0.5 *
                                                                    cos(2.0 *
                                                                    FELD_PI *
                                                                    (float) v13 /
                                                                    (float) v8)) +
                                                                  0.5)) : a9[v13] *
                (-(0.5 * cos(2.0 * FELD_PI * (float) v13 / (float) v8)) + 0.5) +
                a9[v13 ^ 512] * (-(0.5 * cos(2.0 * FELD_PI * (float) (v13 ^
                                                                      512) /
                                   (float) v8)) + 0.5);
        }
        r14 = r11;
        
        float _Complex _a15[r11];
        float _Complex *a15 = _a15;
        
        for (v16 = 0; v16 < r11; v16++) {
            a15[v16] = !((v16 & 256) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v16 & 255) /
                                                      256.0)) * (a12[v16 ^
                                                                     256] -
                                                                 a12[v16]) : a12[v16] +
                a12[v16 ^ 256];
        }
        r17 = r14;
        
        float _Complex _a18[r14];
        float _Complex *a18 = _a18;
        
        for (v19 = 0; v19 < r14; v19++) {
            a18[v19] = !((v19 & 128) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v19 & 127) /
                                                      128.0)) * (a15[v19 ^
                                                                     128] -
                                                                 a15[v19]) : a15[v19] +
                a15[v19 ^ 128];
        }
        r20 = r17;
        
        float _Complex _a21[r17];
        float _Complex *a21 = _a21;
        
        for (v22 = 0; v22 < r17; v22++) {
            a21[v22] = !((v22 & 64) == 0) ? exp(I * (-3.1415927 * (float) (v22 &
                                                                           63) /
                                                     64.0)) * (a18[v22 ^ 64] -
                                                               a18[v22]) : a18[v22] +
                a18[v22 ^ 64];
        }
        r23 = r20;
        
        float _Complex _a24[r20];
        float _Complex *a24 = _a24;
        
        for (v25 = 0; v25 < r20; v25++) {
            a24[v25] = !((v25 & 32) == 0) ? exp(I * (-3.1415927 * (float) (v25 &
                                                                           31) /
                                                     32.0)) * (a21[v25 ^ 32] -
                                                               a21[v25]) : a21[v25] +
                a21[v25 ^ 32];
        }
        r26 = r23;
        
        float _Complex _a27[r23];
        float _Complex *a27 = _a27;
        
        for (v28 = 0; v28 < r23; v28++) {
            a27[v28] = !((v28 & 16) == 0) ? exp(I * (-3.1415927 * (float) (v28 &
                                                                           15) /
                                                     16.0)) * (a24[v28 ^ 16] -
                                                               a24[v28]) : a24[v28] +
                a24[v28 ^ 16];
        }
        r29 = r26;
        
        float _Complex _a30[r26];
        float _Complex *a30 = _a30;
        
        for (v31 = 0; v31 < r26; v31++) {
            a30[v31] = !((v31 & 8) == 0) ? exp(I * (-3.1415927 * (float) (v31 &
                                                                          7) /
                                                    8.0)) * (a27[v31 ^ 8] -
                                                             a27[v31]) : a27[v31] +
                a27[v31 ^ 8];
        }
        r32 = r29;
        
        float _Complex _a33[r29];
        float _Complex *a33 = _a33;
        
        for (v34 = 0; v34 < r29; v34++) {
            a33[v34] = !((v34 & 4) == 0) ? exp(I * (-3.1415927 * (float) (v34 &
                                                                          3) /
                                                    4.0)) * (a30[v34 ^ 4] -
                                                             a30[v34]) : a30[v34] +
                a30[v34 ^ 4];
        }
        r35 = r32;
        
        float _Complex _a36[r32];
        float _Complex *a36 = _a36;
        
        for (v37 = 0; v37 < r32; v37++) {
            a36[v37] = !((v37 & 2) == 0) ? exp(I * (-3.1415927 * (float) (v37 &
                                                                          1) /
                                                    2.0)) * (a33[v37 ^ 2] -
                                                             a33[v37]) : a33[v37] +
                a33[v37 ^ 2];
        }
        r38 = r35;
        
        float _Complex _a39[r35];
        float _Complex *a39 = _a39;
        
        for (v40 = 0; v40 < r35; v40++) {
            a39[v40] = !((v40 & 1) == 0) ? exp(I * (-3.1415927 * (float) (v40 &
                                                                          0) /
                                                    1.0)) * (a36[v40 ^ 1] -
                                                             a36[v40]) : a36[v40] +
                a36[v40 ^ 1];
        }
        r41 = r38;
        
        float _Complex _a42[r38];
        float _Complex *a42 = _a42;
        
        for (v43 = 0; v43 < r38; v43++) {
            a42[v43] = a39[(v43 >> 1 >> 1 << 1 | (v43 & 1)) << 1 | (v43 >> 1 &
                                                                    1)];
        }
        r44 = r41;
        
        float _Complex _a45[r41];
        float _Complex *a45 = _a45;
        
        for (v46 = 0; v46 < r41; v46++) {
            a45[v46] = a42[(v46 >> 1 >> 2 << 1 | (v46 & 1)) << 2 | (v46 >> 1 &
                                                                    3)];
        }
        r47 = r44;
        
        float _Complex _a48[r44];
        float _Complex *a48 = _a48;
        
        for (v49 = 0; v49 < r44; v49++) {
            a48[v49] = a45[(v49 >> 1 >> 3 << 1 | (v49 & 1)) << 3 | (v49 >> 1 &
                                                                    7)];
        }
        r50 = r47;
        
        float _Complex _a51[r47];
        float _Complex *a51 = _a51;
        
        for (v52 = 0; v52 < r47; v52++) {
            a51[v52] = a48[(v52 >> 1 >> 4 << 1 | (v52 & 1)) << 4 | (v52 >> 1 &
                                                                    15)];
        }
        r53 = r50;
        
        float _Complex _a54[r50];
        float _Complex *a54 = _a54;
        
        for (v55 = 0; v55 < r50; v55++) {
            a54[v55] = a51[(v55 >> 1 >> 5 << 1 | (v55 & 1)) << 5 | (v55 >> 1 &
                                                                    31)];
        }
        r56 = r53;
        
        float _Complex _a57[r53];
        float _Complex *a57 = _a57;
        
        for (v58 = 0; v58 < r53; v58++) {
            a57[v58] = a54[(v58 >> 1 >> 6 << 1 | (v58 & 1)) << 6 | (v58 >> 1 &
                                                                    63)];
        }
        r59 = r56;
        
        float _Complex _a60[r56];
        float _Complex *a60 = _a60;
        
        for (v61 = 0; v61 < r56; v61++) {
            a60[v61] = a57[(v61 >> 1 >> 7 << 1 | (v61 & 1)) << 7 | (v61 >> 1 &
                                                                    127)];
        }
        r62 = r59;
        
        float _Complex _a63[r59];
        float _Complex *a63 = _a63;
        
        for (v64 = 0; v64 < r59; v64++) {
            a63[v64] = a60[(v64 >> 1 >> 8 << 1 | (v64 & 1)) << 8 | (v64 >> 1 &
                                                                    255)];
        }
        r65 = r62;
        
        float _Complex _a66[r62];
        float _Complex *a66 = _a66;
        
        for (v67 = 0; v67 < r62; v67++) {
            a66[v67] = a63[(v67 >> 1 >> 9 << 1 | (v67 & 1)) << 9 | (v67 >> 1 &
                                                                    511)];
        }
        for (v69 = 0; v69 <= 513; v69++) {
            float v70;
            float r71;
            float v76;
            
            v70 = a3[v69];
            a3[v69] = carg(a66[v69]);
            r71 = carg(a66[v69]) - v70 - (float) v69 * 1.5707964;
            while (1) {
                float v72;
                float v73;
                
                v72 = r71;
                if (!(v72 > FELD_PI))
                    break;
                v73 = r71;
                r71 = v73 + -6.2831855;
            }
            while (1) {
                float v74;
                float v75;
                
                v74 = r71;
                if (!(v74 < -3.1415927))
                    break;
                v75 = r71;
                r71 = v75 + 6.2831855;
            }
            v76 = r71;
            a68[v69] = 2.0 * cabs(a66[v69]) + I * (((float) v69 + 4.0 * v76 /
                                                    (2.0 * FELD_PI)) *
                                                   43.066406);
        }
        for (v78 = 0; v78 < 1024; v78++) {
            a77[v78] = a68[v78];
        }
        smbPitchShift(2.0, a77, a79);
        r80 = 1024;
        for (v82 = 0; v82 < 1024; v82++) {
            a81[v82] = !((v82 & 512) == 0) ? exp(I * (FELD_PI * (float) (v82 &
                                                                         511) /
                                                      512.0)) * (((v82 ^ 512) <=
                                                                  513 ? a79[v82 ^
                                                                            512] : 0.0) -
                                                                 (v82 <=
                                                                  513 ? a79[v82] : 0.0)) : (v82 <=
                                                                                            513 ? a79[v82] : 0.0) +
                ((v82 ^ 512) <= 513 ? a79[v82 ^ 512] : 0.0);
        }
        r83 = r80;
        
        float _Complex _a84[r80];
        float _Complex *a84 = _a84;
        
        for (v85 = 0; v85 < r80; v85++) {
            a84[v85] = !((v85 & 256) == 0) ? exp(I * (FELD_PI * (float) (v85 &
                                                                         255) /
                                                      256.0)) * (a81[v85 ^
                                                                     256] -
                                                                 a81[v85]) : a81[v85] +
                a81[v85 ^ 256];
        }
        r86 = r83;
        
        float _Complex _a87[r83];
        float _Complex *a87 = _a87;
        
        for (v88 = 0; v88 < r83; v88++) {
            a87[v88] = !((v88 & 128) == 0) ? exp(I * (FELD_PI * (float) (v88 &
                                                                         127) /
                                                      128.0)) * (a84[v88 ^
                                                                     128] -
                                                                 a84[v88]) : a84[v88] +
                a84[v88 ^ 128];
        }
        r89 = r86;
        
        float _Complex _a90[r86];
        float _Complex *a90 = _a90;
        
        for (v91 = 0; v91 < r86; v91++) {
            a90[v91] = !((v91 & 64) == 0) ? exp(I * (FELD_PI * (float) (v91 &
                                                                        63) /
                                                     64.0)) * (a87[v91 ^ 64] -
                                                               a87[v91]) : a87[v91] +
                a87[v91 ^ 64];
        }
        r92 = r89;
        
        float _Complex _a93[r89];
        float _Complex *a93 = _a93;
        
        for (v94 = 0; v94 < r89; v94++) {
            a93[v94] = !((v94 & 32) == 0) ? exp(I * (FELD_PI * (float) (v94 &
                                                                        31) /
                                                     32.0)) * (a90[v94 ^ 32] -
                                                               a90[v94]) : a90[v94] +
                a90[v94 ^ 32];
        }
        r95 = r92;
        
        float _Complex _a96[r92];
        float _Complex *a96 = _a96;
        
        for (v97 = 0; v97 < r92; v97++) {
            a96[v97] = !((v97 & 16) == 0) ? exp(I * (FELD_PI * (float) (v97 &
                                                                        15) /
                                                     16.0)) * (a93[v97 ^ 16] -
                                                               a93[v97]) : a93[v97] +
                a93[v97 ^ 16];
        }
        r98 = r95;
        
        float _Complex _a99[r95];
        float _Complex *a99 = _a99;
        
        for (v100 = 0; v100 < r95; v100++) {
            a99[v100] = !((v100 & 8) == 0) ? exp(I * (FELD_PI * (float) (v100 &
                                                                         7) /
                                                      8.0)) * (a96[v100 ^ 8] -
                                                               a96[v100]) : a96[v100] +
                a96[v100 ^ 8];
        }
        r101 = r98;
        
        float _Complex _a102[r98];
        float _Complex *a102 = _a102;
        
        for (v103 = 0; v103 < r98; v103++) {
            a102[v103] = !((v103 & 4) == 0) ? exp(I * (FELD_PI * (float) (v103 &
                                                                          3) /
                                                       4.0)) * (a99[v103 ^ 4] -
                                                                a99[v103]) : a99[v103] +
                a99[v103 ^ 4];
        }
        r104 = r101;
        
        float _Complex _a105[r101];
        float _Complex *a105 = _a105;
        
        for (v106 = 0; v106 < r101; v106++) {
            a105[v106] = !((v106 & 2) == 0) ? exp(I * (FELD_PI * (float) (v106 &
                                                                          1) /
                                                       2.0)) * (a102[v106 ^ 2] -
                                                                a102[v106]) : a102[v106] +
                a102[v106 ^ 2];
        }
        r107 = r104;
        
        float _Complex _a108[r104];
        float _Complex *a108 = _a108;
        
        for (v109 = 0; v109 < r104; v109++) {
            a108[v109] = !((v109 & 1) == 0) ? exp(I * (FELD_PI * (float) (v109 &
                                                                          0) /
                                                       1.0)) * (a105[v109 ^ 1] -
                                                                a105[v109]) : a105[v109] +
                a105[v109 ^ 1];
        }
        r110 = r107;
        
        float _Complex _a111[r107];
        float _Complex *a111 = _a111;
        
        for (v112 = 0; v112 < r107; v112++) {
            a111[v112] = a108[(v112 >> 1 >> 1 << 1 | (v112 & 1)) << 1 | (v112 >>
                                                                         1 &
                                                                         1)];
        }
        r113 = r110;
        
        float _Complex _a114[r110];
        float _Complex *a114 = _a114;
        
        for (v115 = 0; v115 < r110; v115++) {
            a114[v115] = a111[(v115 >> 1 >> 2 << 1 | (v115 & 1)) << 2 | (v115 >>
                                                                         1 &
                                                                         3)];
        }
        r116 = r113;
        
        float _Complex _a117[r113];
        float _Complex *a117 = _a117;
        
        for (v118 = 0; v118 < r113; v118++) {
            a117[v118] = a114[(v118 >> 1 >> 3 << 1 | (v118 & 1)) << 3 | (v118 >>
                                                                         1 &
                                                                         7)];
        }
        r119 = r116;
        
        float _Complex _a120[r116];
        float _Complex *a120 = _a120;
        
        for (v121 = 0; v121 < r116; v121++) {
            a120[v121] = a117[(v121 >> 1 >> 4 << 1 | (v121 & 1)) << 4 | (v121 >>
                                                                         1 &
                                                                         15)];
        }
        r122 = r119;
        
        float _Complex _a123[r119];
        float _Complex *a123 = _a123;
        
        for (v124 = 0; v124 < r119; v124++) {
            a123[v124] = a120[(v124 >> 1 >> 5 << 1 | (v124 & 1)) << 5 | (v124 >>
                                                                         1 &
                                                                         31)];
        }
        r125 = r122;
        
        float _Complex _a126[r122];
        float _Complex *a126 = _a126;
        
        for (v127 = 0; v127 < r122; v127++) {
            a126[v127] = a123[(v127 >> 1 >> 6 << 1 | (v127 & 1)) << 6 | (v127 >>
                                                                         1 &
                                                                         63)];
        }
        r128 = r125;
        
        float _Complex _a129[r125];
        float _Complex *a129 = _a129;
        
        for (v130 = 0; v130 < r125; v130++) {
            a129[v130] = a126[(v130 >> 1 >> 7 << 1 | (v130 & 1)) << 7 | (v130 >>
                                                                         1 &
                                                                         127)];
        }
        r131 = r128;
        
        float _Complex _a132[r128];
        float _Complex *a132 = _a132;
        
        for (v133 = 0; v133 < r128; v133++) {
            a132[v133] = a129[(v133 >> 1 >> 8 << 1 | (v133 & 1)) << 8 | (v133 >>
                                                                         1 &
                                                                         255)];
        }
        r134 = r131;
        
        float _Complex _a135[r131];
        float _Complex *a135 = _a135;
        
        for (v136 = 0; v136 < r131; v136++) {
            a135[v136] = a132[(v136 >> 1 >> 9 << 1 | (v136 & 1)) << 9 | (v136 >>
                                                                         1 &
                                                                         511)];
        }
        r137 = r134;
        
        float _a138[r134];
        float *a138 = _a138;
        
        for (v139 = 0; v139 < r134; v139++) {
            a138[v139] = creal(a135[v139]) / 4096.0 * (-(0.5 * cos(2.0 *
                                                         FELD_PI *
                                                         (float) v139 /
                                                         (float) r134)) + 0.5);
        }
        v140 = r137;
        v141 = v140;
        v142 = chan_write(chan1, sizeof(v141), &v141);
        v143 = chan_write(chan1, sizeof(*a138) * (v140 - 0), &a138[0]);
        if (!v143) {
            chan_close(chan0);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
    }
    chan_close(chan0);
    chan_close(chan1);
    return NULL;
}
void *thread_t144(void *unused)
{
    while (1) {
        uint32_t v145;
        bool v147;
        uint32_t r148;
        uint32_t v149;
        bool v151;
        uint32_t v153;
        bool v154;
        
        chan_read(chan1, sizeof(v145), &v145);
        
        float _a146[v145];
        float *a146 = _a146;
        
        chan_read(chan1, sizeof(*a146) * (v145 - 0), &a146[0]);
        v147 = chan_last_read_ok(chan1);
        r148 = v145;
        v149 = r148;
        
        float _a150[v149];
        float *a150 = _a150;
        
        memcpy(a150, a146, v149 * sizeof(float));
        v151 = chan_last_read_ok(chan1);
        if (!v151) {
            pthread_cancel(t144);
            pthread_join(t144, NULL);
        }
        
        float _a152[v149];
        float *a152 = _a152;
        
        for (v153 = 0; v153 < v149; v153++) {
            a152[v153] = a150[v153];
        }
        v154 = emit_samples(a152);
        if (!v154) {
            chan_close(chan1);
            pthread_cancel(t144);
            pthread_join(t144, NULL);
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
    pthread_create(&t144, NULL, thread_t144, NULL);
    while (1) {
        float _a155[1024];
        float *a155 = _a155;
        bool v156;
        uint32_t r157;
        float _a158[1024];
        float *a158 = _a158;
        uint32_t v159;
        uint32_t v160;
        uint32_t v161;
        bool v162;
        bool v163;
        
        v156 = receive_samples(a155);
        if (!v156) {
            break;
        }
        r157 = 1024;
        for (v159 = 0; v159 < 1024; v159++) {
            a158[v159] = a155[v159];
        }
        v160 = r157;
        v161 = v160;
        v162 = chan_write(chan0, sizeof(v161), &v161);
        v163 = chan_write(chan0, sizeof(*a158) * (v160 - 0), &a158[0]);
        if (!v163) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t144, NULL);
    teardown_queues();
    return 0;
}

