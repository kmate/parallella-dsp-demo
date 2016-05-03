#include "c_processor.h"
#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
void *thread_t2(void *unused);
void *thread_t77(void *unused);
pthread_t t2;
pthread_t t77;
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
        uint32_t v73;
        uint32_t v74;
        bool v75;
        bool v76;
        
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
        r10 = v7 <= 1024 ? v7 : 1024;
        
        float _Complex _a11[v7 <= 1024 ? v7 : 1024];
        float _Complex *a11 = _a11;
        
        for (v12 = 0; v12 < (v7 <= 1024 ? v7 : 1024); v12++) {
            a11[v12] = !((v12 & 512) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v12 & 511) /
                                                      512.0)) * (a8[v12 ^ 512] *
                                                                 (-(0.5 *
                                                                    cos(2.0 *
                                                                    FELD_PI *
                                                                    (float) (v12 ^
                                                                             512) /
                                                                    1024.0)) +
                                                                  0.5) -
                                                                 a8[v12] *
                                                                 (-(0.5 *
                                                                    cos(2.0 *
                                                                    FELD_PI *
                                                                    (float) v12 /
                                                                    1024.0)) +
                                                                  0.5)) : a8[v12] *
                (-(0.5 * cos(2.0 * FELD_PI * (float) v12 / 1024.0)) + 0.5) +
                a8[v12 ^ 512] * (-(0.5 * cos(2.0 * FELD_PI * (float) (v12 ^
                                                                      512) /
                                   1024.0)) + 0.5);
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
        
        float _a69[r64];
        float *a69 = _a69;
        
        smbPitchShift(2.0, a67, a69);
        r70 = r64;
        
        float _a71[r64];
        float *a71 = _a71;
        
        for (v72 = 0; v72 < r64; v72++) {
            a71[v72] = a69[v72];
        }
        v73 = r70;
        v74 = v73;
        v75 = chan_write(chan1, sizeof(v74), &v74);
        v76 = chan_write(chan1, sizeof(*a71) * (v73 - 0), &a71[0]);
        if (!v76) {
            chan_close(chan0);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
    }
    chan_close(chan0);
    chan_close(chan1);
    return NULL;
}
void *thread_t77(void *unused)
{
    while (1) {
        uint32_t v78;
        bool v80;
        uint32_t r81;
        uint32_t v82;
        bool v84;
        uint32_t v86;
        bool v87;
        
        chan_read(chan1, sizeof(v78), &v78);
        
        float _a79[v78];
        float *a79 = _a79;
        
        chan_read(chan1, sizeof(*a79) * (v78 - 0), &a79[0]);
        v80 = chan_last_read_ok(chan1);
        r81 = v78;
        v82 = r81;
        
        float _a83[v82];
        float *a83 = _a83;
        
        memcpy(a83, a79, v82 * sizeof(float));
        v84 = chan_last_read_ok(chan1);
        if (!v84) {
            pthread_cancel(t77);
            pthread_join(t77, NULL);
        }
        
        float _a85[v82];
        float *a85 = _a85;
        
        for (v86 = 0; v86 < v82; v86++) {
            a85[v86] = a83[v86];
        }
        v87 = emit_samples(a85);
        if (!v87) {
            chan_close(chan1);
            pthread_cancel(t77);
            pthread_join(t77, NULL);
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
    pthread_create(&t77, NULL, thread_t77, NULL);
    while (1) {
        float _a88[1024];
        float *a88 = _a88;
        bool v89;
        uint32_t r90;
        float _a91[1024];
        float *a91 = _a91;
        uint32_t v92;
        uint32_t v93;
        uint32_t v94;
        bool v95;
        bool v96;
        
        v89 = receive_samples(a88);
        if (!v89) {
            break;
        }
        r90 = 1024;
        for (v92 = 0; v92 < 1024; v92++) {
            a91[v92] = a88[v92];
        }
        v93 = r90;
        v94 = v93;
        v95 = chan_write(chan0, sizeof(v94), &v94);
        v96 = chan_write(chan0, sizeof(*a91) * (v93 - 0), &a91[0]);
        if (!v96) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t77, NULL);
    teardown_queues();
    return 0;
}

