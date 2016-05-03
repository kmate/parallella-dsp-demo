#include "chan.h"
#include "processor.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
void *thread_t2(void *unused);
void *thread_t18(void *unused);
void *thread_t34(void *unused);
void *thread_t50(void *unused);
void *thread_t66(void *unused);
void *thread_t82(void *unused);
void *thread_t98(void *unused);
void *thread_t114(void *unused);
void *thread_t130(void *unused);
void *thread_t146(void *unused);
void *thread_t162(void *unused);
void *thread_t178(void *unused);
void *thread_t194(void *unused);
void *thread_t210(void *unused);
void *thread_t226(void *unused);
void *thread_t242(void *unused);
void *thread_t258(void *unused);
void *thread_t274(void *unused);
void *thread_t290(void *unused);
void *thread_t306(void *unused);
void *thread_t322(void *unused);
void *thread_t344(void *unused);
void *thread_t362(void *unused);
void *thread_t384(void *unused);
void *thread_t400(void *unused);
void *thread_t416(void *unused);
void *thread_t432(void *unused);
void *thread_t448(void *unused);
void *thread_t464(void *unused);
void *thread_t480(void *unused);
void *thread_t496(void *unused);
void *thread_t512(void *unused);
void *thread_t528(void *unused);
void *thread_t544(void *unused);
void *thread_t560(void *unused);
void *thread_t576(void *unused);
void *thread_t592(void *unused);
void *thread_t608(void *unused);
void *thread_t624(void *unused);
void *thread_t640(void *unused);
void *thread_t656(void *unused);
void *thread_t672(void *unused);
void *thread_t688(void *unused);
void *thread_t703(void *unused);
pthread_t t114;
pthread_t t130;
pthread_t t146;
pthread_t t162;
pthread_t t178;
pthread_t t18;
pthread_t t194;
pthread_t t2;
pthread_t t210;
pthread_t t226;
pthread_t t242;
pthread_t t258;
pthread_t t274;
pthread_t t290;
pthread_t t306;
pthread_t t322;
pthread_t t34;
pthread_t t344;
pthread_t t362;
pthread_t t384;
pthread_t t400;
pthread_t t416;
pthread_t t432;
pthread_t t448;
pthread_t t464;
pthread_t t480;
pthread_t t496;
pthread_t t50;
pthread_t t512;
pthread_t t528;
pthread_t t544;
pthread_t t560;
pthread_t t576;
pthread_t t592;
pthread_t t608;
pthread_t t624;
pthread_t t640;
pthread_t t656;
pthread_t t66;
pthread_t t672;
pthread_t t688;
pthread_t t703;
pthread_t t82;
pthread_t t98;
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
        uint32_t v13;
        uint32_t v14;
        bool v15;
        bool v16;
        
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
            a11[v12] = a8[v12] * (-(0.5 * cos(2.0 * FELD_PI * (float) v12 /
                                    1024.0)) + 0.5);
        }
        v13 = r10;
        v14 = v13;
        v15 = chan_write(chan1, sizeof(v14), &v14);
        v16 = chan_write(chan1, sizeof(*a11) * (v13 - 0), &a11[0]);
        if (!v16) {
            chan_close(chan0);
            pthread_cancel(t2);
            pthread_join(t2, NULL);
        }
    }
    chan_close(chan0);
    chan_close(chan1);
    return NULL;
}
chan_t chan17;
void *thread_t18(void *unused)
{
    while (1) {
        uint32_t v19;
        bool v21;
        uint32_t r22;
        uint32_t v23;
        bool v25;
        uint32_t r26;
        uint32_t v28;
        uint32_t v29;
        uint32_t v30;
        bool v31;
        bool v32;
        
        chan_read(chan1, sizeof(v19), &v19);
        
        float _Complex _a20[v19];
        float _Complex *a20 = _a20;
        
        chan_read(chan1, sizeof(*a20) * (v19 - 0), &a20[0]);
        v21 = chan_last_read_ok(chan1);
        r22 = v19;
        v23 = r22;
        
        float _Complex _a24[v23];
        float _Complex *a24 = _a24;
        
        memcpy(a24, a20, v23 * sizeof(float _Complex));
        v25 = chan_last_read_ok(chan1);
        if (!v25) {
            chan_close(chan17);
            pthread_cancel(t18);
            pthread_join(t18, NULL);
        }
        r26 = v23;
        
        float _Complex _a27[v23];
        float _Complex *a27 = _a27;
        
        for (v28 = 0; v28 < v23; v28++) {
            a27[v28] = !((v28 & 512) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v28 & 511) /
                                                      512.0)) * (a24[v28 ^
                                                                     512] -
                                                                 a24[v28]) : a24[v28] +
                a24[v28 ^ 512];
        }
        v29 = r26;
        v30 = v29;
        v31 = chan_write(chan17, sizeof(v30), &v30);
        v32 = chan_write(chan17, sizeof(*a27) * (v29 - 0), &a27[0]);
        if (!v32) {
            chan_close(chan1);
            pthread_cancel(t18);
            pthread_join(t18, NULL);
        }
    }
    chan_close(chan1);
    chan_close(chan17);
    return NULL;
}
chan_t chan33;
void *thread_t34(void *unused)
{
    while (1) {
        uint32_t v35;
        bool v37;
        uint32_t r38;
        uint32_t v39;
        bool v41;
        uint32_t r42;
        uint32_t v44;
        uint32_t v45;
        uint32_t v46;
        bool v47;
        bool v48;
        
        chan_read(chan17, sizeof(v35), &v35);
        
        float _Complex _a36[v35];
        float _Complex *a36 = _a36;
        
        chan_read(chan17, sizeof(*a36) * (v35 - 0), &a36[0]);
        v37 = chan_last_read_ok(chan17);
        r38 = v35;
        v39 = r38;
        
        float _Complex _a40[v39];
        float _Complex *a40 = _a40;
        
        memcpy(a40, a36, v39 * sizeof(float _Complex));
        v41 = chan_last_read_ok(chan17);
        if (!v41) {
            chan_close(chan33);
            pthread_cancel(t34);
            pthread_join(t34, NULL);
        }
        r42 = v39;
        
        float _Complex _a43[v39];
        float _Complex *a43 = _a43;
        
        for (v44 = 0; v44 < v39; v44++) {
            a43[v44] = !((v44 & 256) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v44 & 255) /
                                                      256.0)) * (a40[v44 ^
                                                                     256] -
                                                                 a40[v44]) : a40[v44] +
                a40[v44 ^ 256];
        }
        v45 = r42;
        v46 = v45;
        v47 = chan_write(chan33, sizeof(v46), &v46);
        v48 = chan_write(chan33, sizeof(*a43) * (v45 - 0), &a43[0]);
        if (!v48) {
            chan_close(chan17);
            pthread_cancel(t34);
            pthread_join(t34, NULL);
        }
    }
    chan_close(chan17);
    chan_close(chan33);
    return NULL;
}
chan_t chan49;
void *thread_t50(void *unused)
{
    while (1) {
        uint32_t v51;
        bool v53;
        uint32_t r54;
        uint32_t v55;
        bool v57;
        uint32_t r58;
        uint32_t v60;
        uint32_t v61;
        uint32_t v62;
        bool v63;
        bool v64;
        
        chan_read(chan33, sizeof(v51), &v51);
        
        float _Complex _a52[v51];
        float _Complex *a52 = _a52;
        
        chan_read(chan33, sizeof(*a52) * (v51 - 0), &a52[0]);
        v53 = chan_last_read_ok(chan33);
        r54 = v51;
        v55 = r54;
        
        float _Complex _a56[v55];
        float _Complex *a56 = _a56;
        
        memcpy(a56, a52, v55 * sizeof(float _Complex));
        v57 = chan_last_read_ok(chan33);
        if (!v57) {
            chan_close(chan49);
            pthread_cancel(t50);
            pthread_join(t50, NULL);
        }
        r58 = v55;
        
        float _Complex _a59[v55];
        float _Complex *a59 = _a59;
        
        for (v60 = 0; v60 < v55; v60++) {
            a59[v60] = !((v60 & 128) == 0) ? exp(I * (-3.1415927 *
                                                      (float) (v60 & 127) /
                                                      128.0)) * (a56[v60 ^
                                                                     128] -
                                                                 a56[v60]) : a56[v60] +
                a56[v60 ^ 128];
        }
        v61 = r58;
        v62 = v61;
        v63 = chan_write(chan49, sizeof(v62), &v62);
        v64 = chan_write(chan49, sizeof(*a59) * (v61 - 0), &a59[0]);
        if (!v64) {
            chan_close(chan33);
            pthread_cancel(t50);
            pthread_join(t50, NULL);
        }
    }
    chan_close(chan33);
    chan_close(chan49);
    return NULL;
}
chan_t chan65;
void *thread_t66(void *unused)
{
    while (1) {
        uint32_t v67;
        bool v69;
        uint32_t r70;
        uint32_t v71;
        bool v73;
        uint32_t r74;
        uint32_t v76;
        uint32_t v77;
        uint32_t v78;
        bool v79;
        bool v80;
        
        chan_read(chan49, sizeof(v67), &v67);
        
        float _Complex _a68[v67];
        float _Complex *a68 = _a68;
        
        chan_read(chan49, sizeof(*a68) * (v67 - 0), &a68[0]);
        v69 = chan_last_read_ok(chan49);
        r70 = v67;
        v71 = r70;
        
        float _Complex _a72[v71];
        float _Complex *a72 = _a72;
        
        memcpy(a72, a68, v71 * sizeof(float _Complex));
        v73 = chan_last_read_ok(chan49);
        if (!v73) {
            chan_close(chan65);
            pthread_cancel(t66);
            pthread_join(t66, NULL);
        }
        r74 = v71;
        
        float _Complex _a75[v71];
        float _Complex *a75 = _a75;
        
        for (v76 = 0; v76 < v71; v76++) {
            a75[v76] = !((v76 & 64) == 0) ? exp(I * (-3.1415927 * (float) (v76 &
                                                                           63) /
                                                     64.0)) * (a72[v76 ^ 64] -
                                                               a72[v76]) : a72[v76] +
                a72[v76 ^ 64];
        }
        v77 = r74;
        v78 = v77;
        v79 = chan_write(chan65, sizeof(v78), &v78);
        v80 = chan_write(chan65, sizeof(*a75) * (v77 - 0), &a75[0]);
        if (!v80) {
            chan_close(chan49);
            pthread_cancel(t66);
            pthread_join(t66, NULL);
        }
    }
    chan_close(chan49);
    chan_close(chan65);
    return NULL;
}
chan_t chan81;
void *thread_t82(void *unused)
{
    while (1) {
        uint32_t v83;
        bool v85;
        uint32_t r86;
        uint32_t v87;
        bool v89;
        uint32_t r90;
        uint32_t v92;
        uint32_t v93;
        uint32_t v94;
        bool v95;
        bool v96;
        
        chan_read(chan65, sizeof(v83), &v83);
        
        float _Complex _a84[v83];
        float _Complex *a84 = _a84;
        
        chan_read(chan65, sizeof(*a84) * (v83 - 0), &a84[0]);
        v85 = chan_last_read_ok(chan65);
        r86 = v83;
        v87 = r86;
        
        float _Complex _a88[v87];
        float _Complex *a88 = _a88;
        
        memcpy(a88, a84, v87 * sizeof(float _Complex));
        v89 = chan_last_read_ok(chan65);
        if (!v89) {
            chan_close(chan81);
            pthread_cancel(t82);
            pthread_join(t82, NULL);
        }
        r90 = v87;
        
        float _Complex _a91[v87];
        float _Complex *a91 = _a91;
        
        for (v92 = 0; v92 < v87; v92++) {
            a91[v92] = !((v92 & 32) == 0) ? exp(I * (-3.1415927 * (float) (v92 &
                                                                           31) /
                                                     32.0)) * (a88[v92 ^ 32] -
                                                               a88[v92]) : a88[v92] +
                a88[v92 ^ 32];
        }
        v93 = r90;
        v94 = v93;
        v95 = chan_write(chan81, sizeof(v94), &v94);
        v96 = chan_write(chan81, sizeof(*a91) * (v93 - 0), &a91[0]);
        if (!v96) {
            chan_close(chan65);
            pthread_cancel(t82);
            pthread_join(t82, NULL);
        }
    }
    chan_close(chan65);
    chan_close(chan81);
    return NULL;
}
chan_t chan97;
void *thread_t98(void *unused)
{
    while (1) {
        uint32_t v99;
        bool v101;
        uint32_t r102;
        uint32_t v103;
        bool v105;
        uint32_t r106;
        uint32_t v108;
        uint32_t v109;
        uint32_t v110;
        bool v111;
        bool v112;
        
        chan_read(chan81, sizeof(v99), &v99);
        
        float _Complex _a100[v99];
        float _Complex *a100 = _a100;
        
        chan_read(chan81, sizeof(*a100) * (v99 - 0), &a100[0]);
        v101 = chan_last_read_ok(chan81);
        r102 = v99;
        v103 = r102;
        
        float _Complex _a104[v103];
        float _Complex *a104 = _a104;
        
        memcpy(a104, a100, v103 * sizeof(float _Complex));
        v105 = chan_last_read_ok(chan81);
        if (!v105) {
            chan_close(chan97);
            pthread_cancel(t98);
            pthread_join(t98, NULL);
        }
        r106 = v103;
        
        float _Complex _a107[v103];
        float _Complex *a107 = _a107;
        
        for (v108 = 0; v108 < v103; v108++) {
            a107[v108] = !((v108 & 16) == 0) ? exp(I * (-3.1415927 *
                                                        (float) (v108 & 15) /
                                                        16.0)) * (a104[v108 ^
                                                                       16] -
                                                                  a104[v108]) : a104[v108] +
                a104[v108 ^ 16];
        }
        v109 = r106;
        v110 = v109;
        v111 = chan_write(chan97, sizeof(v110), &v110);
        v112 = chan_write(chan97, sizeof(*a107) * (v109 - 0), &a107[0]);
        if (!v112) {
            chan_close(chan81);
            pthread_cancel(t98);
            pthread_join(t98, NULL);
        }
    }
    chan_close(chan81);
    chan_close(chan97);
    return NULL;
}
chan_t chan113;
void *thread_t114(void *unused)
{
    while (1) {
        uint32_t v115;
        bool v117;
        uint32_t r118;
        uint32_t v119;
        bool v121;
        uint32_t r122;
        uint32_t v124;
        uint32_t v125;
        uint32_t v126;
        bool v127;
        bool v128;
        
        chan_read(chan97, sizeof(v115), &v115);
        
        float _Complex _a116[v115];
        float _Complex *a116 = _a116;
        
        chan_read(chan97, sizeof(*a116) * (v115 - 0), &a116[0]);
        v117 = chan_last_read_ok(chan97);
        r118 = v115;
        v119 = r118;
        
        float _Complex _a120[v119];
        float _Complex *a120 = _a120;
        
        memcpy(a120, a116, v119 * sizeof(float _Complex));
        v121 = chan_last_read_ok(chan97);
        if (!v121) {
            chan_close(chan113);
            pthread_cancel(t114);
            pthread_join(t114, NULL);
        }
        r122 = v119;
        
        float _Complex _a123[v119];
        float _Complex *a123 = _a123;
        
        for (v124 = 0; v124 < v119; v124++) {
            a123[v124] = !((v124 & 8) == 0) ? exp(I * (-3.1415927 *
                                                       (float) (v124 & 7) /
                                                       8.0)) * (a120[v124 ^ 8] -
                                                                a120[v124]) : a120[v124] +
                a120[v124 ^ 8];
        }
        v125 = r122;
        v126 = v125;
        v127 = chan_write(chan113, sizeof(v126), &v126);
        v128 = chan_write(chan113, sizeof(*a123) * (v125 - 0), &a123[0]);
        if (!v128) {
            chan_close(chan97);
            pthread_cancel(t114);
            pthread_join(t114, NULL);
        }
    }
    chan_close(chan97);
    chan_close(chan113);
    return NULL;
}
chan_t chan129;
void *thread_t130(void *unused)
{
    while (1) {
        uint32_t v131;
        bool v133;
        uint32_t r134;
        uint32_t v135;
        bool v137;
        uint32_t r138;
        uint32_t v140;
        uint32_t v141;
        uint32_t v142;
        bool v143;
        bool v144;
        
        chan_read(chan113, sizeof(v131), &v131);
        
        float _Complex _a132[v131];
        float _Complex *a132 = _a132;
        
        chan_read(chan113, sizeof(*a132) * (v131 - 0), &a132[0]);
        v133 = chan_last_read_ok(chan113);
        r134 = v131;
        v135 = r134;
        
        float _Complex _a136[v135];
        float _Complex *a136 = _a136;
        
        memcpy(a136, a132, v135 * sizeof(float _Complex));
        v137 = chan_last_read_ok(chan113);
        if (!v137) {
            chan_close(chan129);
            pthread_cancel(t130);
            pthread_join(t130, NULL);
        }
        r138 = v135;
        
        float _Complex _a139[v135];
        float _Complex *a139 = _a139;
        
        for (v140 = 0; v140 < v135; v140++) {
            a139[v140] = !((v140 & 4) == 0) ? exp(I * (-3.1415927 *
                                                       (float) (v140 & 3) /
                                                       4.0)) * (a136[v140 ^ 4] -
                                                                a136[v140]) : a136[v140] +
                a136[v140 ^ 4];
        }
        v141 = r138;
        v142 = v141;
        v143 = chan_write(chan129, sizeof(v142), &v142);
        v144 = chan_write(chan129, sizeof(*a139) * (v141 - 0), &a139[0]);
        if (!v144) {
            chan_close(chan113);
            pthread_cancel(t130);
            pthread_join(t130, NULL);
        }
    }
    chan_close(chan113);
    chan_close(chan129);
    return NULL;
}
chan_t chan145;
void *thread_t146(void *unused)
{
    while (1) {
        uint32_t v147;
        bool v149;
        uint32_t r150;
        uint32_t v151;
        bool v153;
        uint32_t r154;
        uint32_t v156;
        uint32_t v157;
        uint32_t v158;
        bool v159;
        bool v160;
        
        chan_read(chan129, sizeof(v147), &v147);
        
        float _Complex _a148[v147];
        float _Complex *a148 = _a148;
        
        chan_read(chan129, sizeof(*a148) * (v147 - 0), &a148[0]);
        v149 = chan_last_read_ok(chan129);
        r150 = v147;
        v151 = r150;
        
        float _Complex _a152[v151];
        float _Complex *a152 = _a152;
        
        memcpy(a152, a148, v151 * sizeof(float _Complex));
        v153 = chan_last_read_ok(chan129);
        if (!v153) {
            chan_close(chan145);
            pthread_cancel(t146);
            pthread_join(t146, NULL);
        }
        r154 = v151;
        
        float _Complex _a155[v151];
        float _Complex *a155 = _a155;
        
        for (v156 = 0; v156 < v151; v156++) {
            a155[v156] = !((v156 & 2) == 0) ? exp(I * (-3.1415927 *
                                                       (float) (v156 & 1) /
                                                       2.0)) * (a152[v156 ^ 2] -
                                                                a152[v156]) : a152[v156] +
                a152[v156 ^ 2];
        }
        v157 = r154;
        v158 = v157;
        v159 = chan_write(chan145, sizeof(v158), &v158);
        v160 = chan_write(chan145, sizeof(*a155) * (v157 - 0), &a155[0]);
        if (!v160) {
            chan_close(chan129);
            pthread_cancel(t146);
            pthread_join(t146, NULL);
        }
    }
    chan_close(chan129);
    chan_close(chan145);
    return NULL;
}
chan_t chan161;
void *thread_t162(void *unused)
{
    while (1) {
        uint32_t v163;
        bool v165;
        uint32_t r166;
        uint32_t v167;
        bool v169;
        uint32_t r170;
        uint32_t v172;
        uint32_t v173;
        uint32_t v174;
        bool v175;
        bool v176;
        
        chan_read(chan145, sizeof(v163), &v163);
        
        float _Complex _a164[v163];
        float _Complex *a164 = _a164;
        
        chan_read(chan145, sizeof(*a164) * (v163 - 0), &a164[0]);
        v165 = chan_last_read_ok(chan145);
        r166 = v163;
        v167 = r166;
        
        float _Complex _a168[v167];
        float _Complex *a168 = _a168;
        
        memcpy(a168, a164, v167 * sizeof(float _Complex));
        v169 = chan_last_read_ok(chan145);
        if (!v169) {
            chan_close(chan161);
            pthread_cancel(t162);
            pthread_join(t162, NULL);
        }
        r170 = v167;
        
        float _Complex _a171[v167];
        float _Complex *a171 = _a171;
        
        for (v172 = 0; v172 < v167; v172++) {
            a171[v172] = !((v172 & 1) == 0) ? exp(I * (-3.1415927 *
                                                       (float) (v172 & 0) /
                                                       1.0)) * (a168[v172 ^ 1] -
                                                                a168[v172]) : a168[v172] +
                a168[v172 ^ 1];
        }
        v173 = r170;
        v174 = v173;
        v175 = chan_write(chan161, sizeof(v174), &v174);
        v176 = chan_write(chan161, sizeof(*a171) * (v173 - 0), &a171[0]);
        if (!v176) {
            chan_close(chan145);
            pthread_cancel(t162);
            pthread_join(t162, NULL);
        }
    }
    chan_close(chan145);
    chan_close(chan161);
    return NULL;
}
chan_t chan177;
void *thread_t178(void *unused)
{
    while (1) {
        uint32_t v179;
        bool v181;
        uint32_t r182;
        uint32_t v183;
        bool v185;
        uint32_t r186;
        uint32_t v188;
        uint32_t v189;
        uint32_t v190;
        bool v191;
        bool v192;
        
        chan_read(chan161, sizeof(v179), &v179);
        
        float _Complex _a180[v179];
        float _Complex *a180 = _a180;
        
        chan_read(chan161, sizeof(*a180) * (v179 - 0), &a180[0]);
        v181 = chan_last_read_ok(chan161);
        r182 = v179;
        v183 = r182;
        
        float _Complex _a184[v183];
        float _Complex *a184 = _a184;
        
        memcpy(a184, a180, v183 * sizeof(float _Complex));
        v185 = chan_last_read_ok(chan161);
        if (!v185) {
            chan_close(chan177);
            pthread_cancel(t178);
            pthread_join(t178, NULL);
        }
        r186 = v183;
        
        float _Complex _a187[v183];
        float _Complex *a187 = _a187;
        
        for (v188 = 0; v188 < v183; v188++) {
            a187[v188] = a184[(v188 >> 1 >> 1 << 1 | (v188 & 1)) << 1 | (v188 >>
                                                                         1 &
                                                                         1)];
        }
        v189 = r186;
        v190 = v189;
        v191 = chan_write(chan177, sizeof(v190), &v190);
        v192 = chan_write(chan177, sizeof(*a187) * (v189 - 0), &a187[0]);
        if (!v192) {
            chan_close(chan161);
            pthread_cancel(t178);
            pthread_join(t178, NULL);
        }
    }
    chan_close(chan161);
    chan_close(chan177);
    return NULL;
}
chan_t chan193;
void *thread_t194(void *unused)
{
    while (1) {
        uint32_t v195;
        bool v197;
        uint32_t r198;
        uint32_t v199;
        bool v201;
        uint32_t r202;
        uint32_t v204;
        uint32_t v205;
        uint32_t v206;
        bool v207;
        bool v208;
        
        chan_read(chan177, sizeof(v195), &v195);
        
        float _Complex _a196[v195];
        float _Complex *a196 = _a196;
        
        chan_read(chan177, sizeof(*a196) * (v195 - 0), &a196[0]);
        v197 = chan_last_read_ok(chan177);
        r198 = v195;
        v199 = r198;
        
        float _Complex _a200[v199];
        float _Complex *a200 = _a200;
        
        memcpy(a200, a196, v199 * sizeof(float _Complex));
        v201 = chan_last_read_ok(chan177);
        if (!v201) {
            chan_close(chan193);
            pthread_cancel(t194);
            pthread_join(t194, NULL);
        }
        r202 = v199;
        
        float _Complex _a203[v199];
        float _Complex *a203 = _a203;
        
        for (v204 = 0; v204 < v199; v204++) {
            a203[v204] = a200[(v204 >> 1 >> 2 << 1 | (v204 & 1)) << 2 | (v204 >>
                                                                         1 &
                                                                         3)];
        }
        v205 = r202;
        v206 = v205;
        v207 = chan_write(chan193, sizeof(v206), &v206);
        v208 = chan_write(chan193, sizeof(*a203) * (v205 - 0), &a203[0]);
        if (!v208) {
            chan_close(chan177);
            pthread_cancel(t194);
            pthread_join(t194, NULL);
        }
    }
    chan_close(chan177);
    chan_close(chan193);
    return NULL;
}
chan_t chan209;
void *thread_t210(void *unused)
{
    while (1) {
        uint32_t v211;
        bool v213;
        uint32_t r214;
        uint32_t v215;
        bool v217;
        uint32_t r218;
        uint32_t v220;
        uint32_t v221;
        uint32_t v222;
        bool v223;
        bool v224;
        
        chan_read(chan193, sizeof(v211), &v211);
        
        float _Complex _a212[v211];
        float _Complex *a212 = _a212;
        
        chan_read(chan193, sizeof(*a212) * (v211 - 0), &a212[0]);
        v213 = chan_last_read_ok(chan193);
        r214 = v211;
        v215 = r214;
        
        float _Complex _a216[v215];
        float _Complex *a216 = _a216;
        
        memcpy(a216, a212, v215 * sizeof(float _Complex));
        v217 = chan_last_read_ok(chan193);
        if (!v217) {
            chan_close(chan209);
            pthread_cancel(t210);
            pthread_join(t210, NULL);
        }
        r218 = v215;
        
        float _Complex _a219[v215];
        float _Complex *a219 = _a219;
        
        for (v220 = 0; v220 < v215; v220++) {
            a219[v220] = a216[(v220 >> 1 >> 3 << 1 | (v220 & 1)) << 3 | (v220 >>
                                                                         1 &
                                                                         7)];
        }
        v221 = r218;
        v222 = v221;
        v223 = chan_write(chan209, sizeof(v222), &v222);
        v224 = chan_write(chan209, sizeof(*a219) * (v221 - 0), &a219[0]);
        if (!v224) {
            chan_close(chan193);
            pthread_cancel(t210);
            pthread_join(t210, NULL);
        }
    }
    chan_close(chan193);
    chan_close(chan209);
    return NULL;
}
chan_t chan225;
void *thread_t226(void *unused)
{
    while (1) {
        uint32_t v227;
        bool v229;
        uint32_t r230;
        uint32_t v231;
        bool v233;
        uint32_t r234;
        uint32_t v236;
        uint32_t v237;
        uint32_t v238;
        bool v239;
        bool v240;
        
        chan_read(chan209, sizeof(v227), &v227);
        
        float _Complex _a228[v227];
        float _Complex *a228 = _a228;
        
        chan_read(chan209, sizeof(*a228) * (v227 - 0), &a228[0]);
        v229 = chan_last_read_ok(chan209);
        r230 = v227;
        v231 = r230;
        
        float _Complex _a232[v231];
        float _Complex *a232 = _a232;
        
        memcpy(a232, a228, v231 * sizeof(float _Complex));
        v233 = chan_last_read_ok(chan209);
        if (!v233) {
            chan_close(chan225);
            pthread_cancel(t226);
            pthread_join(t226, NULL);
        }
        r234 = v231;
        
        float _Complex _a235[v231];
        float _Complex *a235 = _a235;
        
        for (v236 = 0; v236 < v231; v236++) {
            a235[v236] = a232[(v236 >> 1 >> 4 << 1 | (v236 & 1)) << 4 | (v236 >>
                                                                         1 &
                                                                         15)];
        }
        v237 = r234;
        v238 = v237;
        v239 = chan_write(chan225, sizeof(v238), &v238);
        v240 = chan_write(chan225, sizeof(*a235) * (v237 - 0), &a235[0]);
        if (!v240) {
            chan_close(chan209);
            pthread_cancel(t226);
            pthread_join(t226, NULL);
        }
    }
    chan_close(chan209);
    chan_close(chan225);
    return NULL;
}
chan_t chan241;
void *thread_t242(void *unused)
{
    while (1) {
        uint32_t v243;
        bool v245;
        uint32_t r246;
        uint32_t v247;
        bool v249;
        uint32_t r250;
        uint32_t v252;
        uint32_t v253;
        uint32_t v254;
        bool v255;
        bool v256;
        
        chan_read(chan225, sizeof(v243), &v243);
        
        float _Complex _a244[v243];
        float _Complex *a244 = _a244;
        
        chan_read(chan225, sizeof(*a244) * (v243 - 0), &a244[0]);
        v245 = chan_last_read_ok(chan225);
        r246 = v243;
        v247 = r246;
        
        float _Complex _a248[v247];
        float _Complex *a248 = _a248;
        
        memcpy(a248, a244, v247 * sizeof(float _Complex));
        v249 = chan_last_read_ok(chan225);
        if (!v249) {
            chan_close(chan241);
            pthread_cancel(t242);
            pthread_join(t242, NULL);
        }
        r250 = v247;
        
        float _Complex _a251[v247];
        float _Complex *a251 = _a251;
        
        for (v252 = 0; v252 < v247; v252++) {
            a251[v252] = a248[(v252 >> 1 >> 5 << 1 | (v252 & 1)) << 5 | (v252 >>
                                                                         1 &
                                                                         31)];
        }
        v253 = r250;
        v254 = v253;
        v255 = chan_write(chan241, sizeof(v254), &v254);
        v256 = chan_write(chan241, sizeof(*a251) * (v253 - 0), &a251[0]);
        if (!v256) {
            chan_close(chan225);
            pthread_cancel(t242);
            pthread_join(t242, NULL);
        }
    }
    chan_close(chan225);
    chan_close(chan241);
    return NULL;
}
chan_t chan257;
void *thread_t258(void *unused)
{
    while (1) {
        uint32_t v259;
        bool v261;
        uint32_t r262;
        uint32_t v263;
        bool v265;
        uint32_t r266;
        uint32_t v268;
        uint32_t v269;
        uint32_t v270;
        bool v271;
        bool v272;
        
        chan_read(chan241, sizeof(v259), &v259);
        
        float _Complex _a260[v259];
        float _Complex *a260 = _a260;
        
        chan_read(chan241, sizeof(*a260) * (v259 - 0), &a260[0]);
        v261 = chan_last_read_ok(chan241);
        r262 = v259;
        v263 = r262;
        
        float _Complex _a264[v263];
        float _Complex *a264 = _a264;
        
        memcpy(a264, a260, v263 * sizeof(float _Complex));
        v265 = chan_last_read_ok(chan241);
        if (!v265) {
            chan_close(chan257);
            pthread_cancel(t258);
            pthread_join(t258, NULL);
        }
        r266 = v263;
        
        float _Complex _a267[v263];
        float _Complex *a267 = _a267;
        
        for (v268 = 0; v268 < v263; v268++) {
            a267[v268] = a264[(v268 >> 1 >> 6 << 1 | (v268 & 1)) << 6 | (v268 >>
                                                                         1 &
                                                                         63)];
        }
        v269 = r266;
        v270 = v269;
        v271 = chan_write(chan257, sizeof(v270), &v270);
        v272 = chan_write(chan257, sizeof(*a267) * (v269 - 0), &a267[0]);
        if (!v272) {
            chan_close(chan241);
            pthread_cancel(t258);
            pthread_join(t258, NULL);
        }
    }
    chan_close(chan241);
    chan_close(chan257);
    return NULL;
}
chan_t chan273;
void *thread_t274(void *unused)
{
    while (1) {
        uint32_t v275;
        bool v277;
        uint32_t r278;
        uint32_t v279;
        bool v281;
        uint32_t r282;
        uint32_t v284;
        uint32_t v285;
        uint32_t v286;
        bool v287;
        bool v288;
        
        chan_read(chan257, sizeof(v275), &v275);
        
        float _Complex _a276[v275];
        float _Complex *a276 = _a276;
        
        chan_read(chan257, sizeof(*a276) * (v275 - 0), &a276[0]);
        v277 = chan_last_read_ok(chan257);
        r278 = v275;
        v279 = r278;
        
        float _Complex _a280[v279];
        float _Complex *a280 = _a280;
        
        memcpy(a280, a276, v279 * sizeof(float _Complex));
        v281 = chan_last_read_ok(chan257);
        if (!v281) {
            chan_close(chan273);
            pthread_cancel(t274);
            pthread_join(t274, NULL);
        }
        r282 = v279;
        
        float _Complex _a283[v279];
        float _Complex *a283 = _a283;
        
        for (v284 = 0; v284 < v279; v284++) {
            a283[v284] = a280[(v284 >> 1 >> 7 << 1 | (v284 & 1)) << 7 | (v284 >>
                                                                         1 &
                                                                         127)];
        }
        v285 = r282;
        v286 = v285;
        v287 = chan_write(chan273, sizeof(v286), &v286);
        v288 = chan_write(chan273, sizeof(*a283) * (v285 - 0), &a283[0]);
        if (!v288) {
            chan_close(chan257);
            pthread_cancel(t274);
            pthread_join(t274, NULL);
        }
    }
    chan_close(chan257);
    chan_close(chan273);
    return NULL;
}
chan_t chan289;
void *thread_t290(void *unused)
{
    while (1) {
        uint32_t v291;
        bool v293;
        uint32_t r294;
        uint32_t v295;
        bool v297;
        uint32_t r298;
        uint32_t v300;
        uint32_t v301;
        uint32_t v302;
        bool v303;
        bool v304;
        
        chan_read(chan273, sizeof(v291), &v291);
        
        float _Complex _a292[v291];
        float _Complex *a292 = _a292;
        
        chan_read(chan273, sizeof(*a292) * (v291 - 0), &a292[0]);
        v293 = chan_last_read_ok(chan273);
        r294 = v291;
        v295 = r294;
        
        float _Complex _a296[v295];
        float _Complex *a296 = _a296;
        
        memcpy(a296, a292, v295 * sizeof(float _Complex));
        v297 = chan_last_read_ok(chan273);
        if (!v297) {
            chan_close(chan289);
            pthread_cancel(t290);
            pthread_join(t290, NULL);
        }
        r298 = v295;
        
        float _Complex _a299[v295];
        float _Complex *a299 = _a299;
        
        for (v300 = 0; v300 < v295; v300++) {
            a299[v300] = a296[(v300 >> 1 >> 8 << 1 | (v300 & 1)) << 8 | (v300 >>
                                                                         1 &
                                                                         255)];
        }
        v301 = r298;
        v302 = v301;
        v303 = chan_write(chan289, sizeof(v302), &v302);
        v304 = chan_write(chan289, sizeof(*a299) * (v301 - 0), &a299[0]);
        if (!v304) {
            chan_close(chan273);
            pthread_cancel(t290);
            pthread_join(t290, NULL);
        }
    }
    chan_close(chan273);
    chan_close(chan289);
    return NULL;
}
chan_t chan305;
void *thread_t306(void *unused)
{
    while (1) {
        uint32_t v307;
        bool v309;
        uint32_t r310;
        uint32_t v311;
        bool v313;
        uint32_t r314;
        uint32_t v316;
        uint32_t v317;
        uint32_t v318;
        bool v319;
        bool v320;
        
        chan_read(chan289, sizeof(v307), &v307);
        
        float _Complex _a308[v307];
        float _Complex *a308 = _a308;
        
        chan_read(chan289, sizeof(*a308) * (v307 - 0), &a308[0]);
        v309 = chan_last_read_ok(chan289);
        r310 = v307;
        v311 = r310;
        
        float _Complex _a312[v311];
        float _Complex *a312 = _a312;
        
        memcpy(a312, a308, v311 * sizeof(float _Complex));
        v313 = chan_last_read_ok(chan289);
        if (!v313) {
            chan_close(chan305);
            pthread_cancel(t306);
            pthread_join(t306, NULL);
        }
        r314 = v311;
        
        float _Complex _a315[v311];
        float _Complex *a315 = _a315;
        
        for (v316 = 0; v316 < v311; v316++) {
            a315[v316] = a312[(v316 >> 1 >> 9 << 1 | (v316 & 1)) << 9 | (v316 >>
                                                                         1 &
                                                                         511)];
        }
        v317 = r314;
        v318 = v317;
        v319 = chan_write(chan305, sizeof(v318), &v318);
        v320 = chan_write(chan305, sizeof(*a315) * (v317 - 0), &a315[0]);
        if (!v320) {
            chan_close(chan289);
            pthread_cancel(t306);
            pthread_join(t306, NULL);
        }
    }
    chan_close(chan289);
    chan_close(chan305);
    return NULL;
}
chan_t chan321;
void *thread_t322(void *unused)
{
    uint32_t r323;
    float _a324[513];
    float *a324 = _a324;
    uint32_t v325;
    
    r323 = 513;
    for (v325 = 0; v325 < 513; v325++) {
        a324[v325] = 0.0;
    }
    while (1) {
        uint32_t v326;
        bool v328;
        uint32_t r329;
        uint32_t v330;
        bool v332;
        uint32_t v333;
        uint32_t v335;
        uint32_t r336;
        float _Complex _a337[513];
        float _Complex *a337 = _a337;
        uint32_t v338;
        uint32_t v339;
        uint32_t v340;
        bool v341;
        bool v342;
        
        chan_read(chan305, sizeof(v326), &v326);
        
        float _Complex _a327[v326];
        float _Complex *a327 = _a327;
        
        chan_read(chan305, sizeof(*a327) * (v326 - 0), &a327[0]);
        v328 = chan_last_read_ok(chan305);
        r329 = v326;
        v330 = r329;
        
        float _Complex _a331[v330];
        float _Complex *a331 = _a331;
        
        memcpy(a331, a327, v330 * sizeof(float _Complex));
        v332 = chan_last_read_ok(chan305);
        if (!v332) {
            chan_close(chan321);
            pthread_cancel(t322);
            pthread_join(t322, NULL);
        }
        v333 = r323;
        
        float _a334[v333];
        float *a334 = _a334;
        
        memcpy(a334, a324, v333 * sizeof(float));
        for (v335 = 0; v335 < 513; v335++) {
            a324[v335] = carg(a331[v335]);
        }
        r336 = 513;
        for (v338 = 0; v338 < 513; v338++) {
            a337[v338] = 2.0 * cabs(a331[v338]) + I * (((float) v338 + 4.0 *
                                                        (carg(a331[v338]) -
                                                         a334[v338] -
                                                         (float) v338 *
                                                         1.5707964) / (2.0 *
                                                                       FELD_PI)) *
                                                       43.066406);
        }
        v339 = r336;
        v340 = v339;
        v341 = chan_write(chan321, sizeof(v340), &v340);
        v342 = chan_write(chan321, sizeof(*a337) * (v339 - 0), &a337[0]);
        if (!v342) {
            chan_close(chan305);
            pthread_cancel(t322);
            pthread_join(t322, NULL);
        }
    }
    chan_close(chan305);
    chan_close(chan321);
    return NULL;
}
chan_t chan343;
void *thread_t344(void *unused)
{
    while (1) {
        uint32_t v345;
        bool v347;
        uint32_t r348;
        uint32_t v349;
        bool v351;
        float _Complex _a352[513];
        float _Complex *a352 = _a352;
        uint32_t v353;
        uint32_t r354;
        float _Complex _a355[513];
        float _Complex *a355 = _a355;
        uint32_t v356;
        uint32_t v357;
        uint32_t v358;
        bool v359;
        bool v360;
        
        chan_read(chan321, sizeof(v345), &v345);
        
        float _Complex _a346[v345];
        float _Complex *a346 = _a346;
        
        chan_read(chan321, sizeof(*a346) * (v345 - 0), &a346[0]);
        v347 = chan_last_read_ok(chan321);
        r348 = v345;
        v349 = r348;
        
        float _Complex _a350[v349];
        float _Complex *a350 = _a350;
        
        memcpy(a350, a346, v349 * sizeof(float _Complex));
        v351 = chan_last_read_ok(chan321);
        if (!v351) {
            chan_close(chan343);
            pthread_cancel(t344);
            pthread_join(t344, NULL);
        }
        for (v353 = 0; v353 < 513; v353++) {
            a352[(uint32_t) round((float) v353 * 2.0)] =
                (uint32_t) round((float) v353 * 2.0) < 513 ? creal(a350[v353]) +
                I * (2.0 * cimag(a350[v353])) : 0.0;
        }
        r354 = 513;
        for (v356 = 0; v356 < 513; v356++) {
            a355[v356] = a352[v356];
        }
        v357 = r354;
        v358 = v357;
        v359 = chan_write(chan343, sizeof(v358), &v358);
        v360 = chan_write(chan343, sizeof(*a355) * (v357 - 0), &a355[0]);
        if (!v360) {
            chan_close(chan321);
            pthread_cancel(t344);
            pthread_join(t344, NULL);
        }
    }
    chan_close(chan321);
    chan_close(chan343);
    return NULL;
}
chan_t chan361;
void *thread_t362(void *unused)
{
    uint32_t r363;
    float _a364[513];
    float *a364 = _a364;
    uint32_t v365;
    
    r363 = 513;
    for (v365 = 0; v365 < 513; v365++) {
        a364[v365] = 0.0;
    }
    while (1) {
        uint32_t v366;
        bool v368;
        uint32_t r369;
        uint32_t v370;
        bool v372;
        uint32_t v373;
        uint32_t v375;
        uint32_t r376;
        float _Complex _a377[1024];
        float _Complex *a377 = _a377;
        uint32_t v378;
        uint32_t v379;
        uint32_t v380;
        bool v381;
        bool v382;
        
        chan_read(chan343, sizeof(v366), &v366);
        
        float _Complex _a367[v366];
        float _Complex *a367 = _a367;
        
        chan_read(chan343, sizeof(*a367) * (v366 - 0), &a367[0]);
        v368 = chan_last_read_ok(chan343);
        r369 = v366;
        v370 = r369;
        
        float _Complex _a371[v370];
        float _Complex *a371 = _a371;
        
        memcpy(a371, a367, v370 * sizeof(float _Complex));
        v372 = chan_last_read_ok(chan343);
        if (!v372) {
            chan_close(chan361);
            pthread_cancel(t362);
            pthread_join(t362, NULL);
        }
        v373 = r363;
        
        float _a374[v373];
        float *a374 = _a374;
        
        memcpy(a374, a364, v373 * sizeof(float));
        for (v375 = 0; v375 < 513; v375++) {
            a364[v375] = a374[v375] + (2.0 * FELD_PI * ((cimag(a371[v375]) -
                                                         (float) v375 *
                                                         43.066406) /
                                                        43.066406) / 4.0 +
                                       (float) v375 * 1.5707964);
        }
        r376 = 1024;
        for (v378 = 0; v378 < 1024; v378++) {
            a377[v378] = v378 <= 513 ? creal(a371[v378]) * exp(I * (a374[v378] +
                                                                    (2.0 *
                                                                     FELD_PI *
                                                                     ((cimag(a371[v378]) -
                                                                       (float) v378 *
                                                                       43.066406) /
                                                                      43.066406) /
                                                                     4.0 +
                                                                     (float) v378 *
                                                                     1.5707964))) : 0.0;
        }
        v379 = r376;
        v380 = v379;
        v381 = chan_write(chan361, sizeof(v380), &v380);
        v382 = chan_write(chan361, sizeof(*a377) * (v379 - 0), &a377[0]);
        if (!v382) {
            chan_close(chan343);
            pthread_cancel(t362);
            pthread_join(t362, NULL);
        }
    }
    chan_close(chan343);
    chan_close(chan361);
    return NULL;
}
chan_t chan383;
void *thread_t384(void *unused)
{
    while (1) {
        uint32_t v385;
        bool v387;
        uint32_t r388;
        uint32_t v389;
        bool v391;
        uint32_t r392;
        uint32_t v394;
        uint32_t v395;
        uint32_t v396;
        bool v397;
        bool v398;
        
        chan_read(chan361, sizeof(v385), &v385);
        
        float _Complex _a386[v385];
        float _Complex *a386 = _a386;
        
        chan_read(chan361, sizeof(*a386) * (v385 - 0), &a386[0]);
        v387 = chan_last_read_ok(chan361);
        r388 = v385;
        v389 = r388;
        
        float _Complex _a390[v389];
        float _Complex *a390 = _a390;
        
        memcpy(a390, a386, v389 * sizeof(float _Complex));
        v391 = chan_last_read_ok(chan361);
        if (!v391) {
            chan_close(chan383);
            pthread_cancel(t384);
            pthread_join(t384, NULL);
        }
        r392 = v389;
        
        float _Complex _a393[v389];
        float _Complex *a393 = _a393;
        
        for (v394 = 0; v394 < v389; v394++) {
            a393[v394] = !((v394 & 512) == 0) ? exp(I * (FELD_PI *
                                                         (float) (v394 & 511) /
                                                         512.0)) * (a390[v394 ^
                                                                         512] -
                                                                    a390[v394]) : a390[v394] +
                a390[v394 ^ 512];
        }
        v395 = r392;
        v396 = v395;
        v397 = chan_write(chan383, sizeof(v396), &v396);
        v398 = chan_write(chan383, sizeof(*a393) * (v395 - 0), &a393[0]);
        if (!v398) {
            chan_close(chan361);
            pthread_cancel(t384);
            pthread_join(t384, NULL);
        }
    }
    chan_close(chan361);
    chan_close(chan383);
    return NULL;
}
chan_t chan399;
void *thread_t400(void *unused)
{
    while (1) {
        uint32_t v401;
        bool v403;
        uint32_t r404;
        uint32_t v405;
        bool v407;
        uint32_t r408;
        uint32_t v410;
        uint32_t v411;
        uint32_t v412;
        bool v413;
        bool v414;
        
        chan_read(chan383, sizeof(v401), &v401);
        
        float _Complex _a402[v401];
        float _Complex *a402 = _a402;
        
        chan_read(chan383, sizeof(*a402) * (v401 - 0), &a402[0]);
        v403 = chan_last_read_ok(chan383);
        r404 = v401;
        v405 = r404;
        
        float _Complex _a406[v405];
        float _Complex *a406 = _a406;
        
        memcpy(a406, a402, v405 * sizeof(float _Complex));
        v407 = chan_last_read_ok(chan383);
        if (!v407) {
            chan_close(chan399);
            pthread_cancel(t400);
            pthread_join(t400, NULL);
        }
        r408 = v405;
        
        float _Complex _a409[v405];
        float _Complex *a409 = _a409;
        
        for (v410 = 0; v410 < v405; v410++) {
            a409[v410] = !((v410 & 256) == 0) ? exp(I * (FELD_PI *
                                                         (float) (v410 & 255) /
                                                         256.0)) * (a406[v410 ^
                                                                         256] -
                                                                    a406[v410]) : a406[v410] +
                a406[v410 ^ 256];
        }
        v411 = r408;
        v412 = v411;
        v413 = chan_write(chan399, sizeof(v412), &v412);
        v414 = chan_write(chan399, sizeof(*a409) * (v411 - 0), &a409[0]);
        if (!v414) {
            chan_close(chan383);
            pthread_cancel(t400);
            pthread_join(t400, NULL);
        }
    }
    chan_close(chan383);
    chan_close(chan399);
    return NULL;
}
chan_t chan415;
void *thread_t416(void *unused)
{
    while (1) {
        uint32_t v417;
        bool v419;
        uint32_t r420;
        uint32_t v421;
        bool v423;
        uint32_t r424;
        uint32_t v426;
        uint32_t v427;
        uint32_t v428;
        bool v429;
        bool v430;
        
        chan_read(chan399, sizeof(v417), &v417);
        
        float _Complex _a418[v417];
        float _Complex *a418 = _a418;
        
        chan_read(chan399, sizeof(*a418) * (v417 - 0), &a418[0]);
        v419 = chan_last_read_ok(chan399);
        r420 = v417;
        v421 = r420;
        
        float _Complex _a422[v421];
        float _Complex *a422 = _a422;
        
        memcpy(a422, a418, v421 * sizeof(float _Complex));
        v423 = chan_last_read_ok(chan399);
        if (!v423) {
            chan_close(chan415);
            pthread_cancel(t416);
            pthread_join(t416, NULL);
        }
        r424 = v421;
        
        float _Complex _a425[v421];
        float _Complex *a425 = _a425;
        
        for (v426 = 0; v426 < v421; v426++) {
            a425[v426] = !((v426 & 128) == 0) ? exp(I * (FELD_PI *
                                                         (float) (v426 & 127) /
                                                         128.0)) * (a422[v426 ^
                                                                         128] -
                                                                    a422[v426]) : a422[v426] +
                a422[v426 ^ 128];
        }
        v427 = r424;
        v428 = v427;
        v429 = chan_write(chan415, sizeof(v428), &v428);
        v430 = chan_write(chan415, sizeof(*a425) * (v427 - 0), &a425[0]);
        if (!v430) {
            chan_close(chan399);
            pthread_cancel(t416);
            pthread_join(t416, NULL);
        }
    }
    chan_close(chan399);
    chan_close(chan415);
    return NULL;
}
chan_t chan431;
void *thread_t432(void *unused)
{
    while (1) {
        uint32_t v433;
        bool v435;
        uint32_t r436;
        uint32_t v437;
        bool v439;
        uint32_t r440;
        uint32_t v442;
        uint32_t v443;
        uint32_t v444;
        bool v445;
        bool v446;
        
        chan_read(chan415, sizeof(v433), &v433);
        
        float _Complex _a434[v433];
        float _Complex *a434 = _a434;
        
        chan_read(chan415, sizeof(*a434) * (v433 - 0), &a434[0]);
        v435 = chan_last_read_ok(chan415);
        r436 = v433;
        v437 = r436;
        
        float _Complex _a438[v437];
        float _Complex *a438 = _a438;
        
        memcpy(a438, a434, v437 * sizeof(float _Complex));
        v439 = chan_last_read_ok(chan415);
        if (!v439) {
            chan_close(chan431);
            pthread_cancel(t432);
            pthread_join(t432, NULL);
        }
        r440 = v437;
        
        float _Complex _a441[v437];
        float _Complex *a441 = _a441;
        
        for (v442 = 0; v442 < v437; v442++) {
            a441[v442] = !((v442 & 64) == 0) ? exp(I * (FELD_PI *
                                                        (float) (v442 & 63) /
                                                        64.0)) * (a438[v442 ^
                                                                       64] -
                                                                  a438[v442]) : a438[v442] +
                a438[v442 ^ 64];
        }
        v443 = r440;
        v444 = v443;
        v445 = chan_write(chan431, sizeof(v444), &v444);
        v446 = chan_write(chan431, sizeof(*a441) * (v443 - 0), &a441[0]);
        if (!v446) {
            chan_close(chan415);
            pthread_cancel(t432);
            pthread_join(t432, NULL);
        }
    }
    chan_close(chan415);
    chan_close(chan431);
    return NULL;
}
chan_t chan447;
void *thread_t448(void *unused)
{
    while (1) {
        uint32_t v449;
        bool v451;
        uint32_t r452;
        uint32_t v453;
        bool v455;
        uint32_t r456;
        uint32_t v458;
        uint32_t v459;
        uint32_t v460;
        bool v461;
        bool v462;
        
        chan_read(chan431, sizeof(v449), &v449);
        
        float _Complex _a450[v449];
        float _Complex *a450 = _a450;
        
        chan_read(chan431, sizeof(*a450) * (v449 - 0), &a450[0]);
        v451 = chan_last_read_ok(chan431);
        r452 = v449;
        v453 = r452;
        
        float _Complex _a454[v453];
        float _Complex *a454 = _a454;
        
        memcpy(a454, a450, v453 * sizeof(float _Complex));
        v455 = chan_last_read_ok(chan431);
        if (!v455) {
            chan_close(chan447);
            pthread_cancel(t448);
            pthread_join(t448, NULL);
        }
        r456 = v453;
        
        float _Complex _a457[v453];
        float _Complex *a457 = _a457;
        
        for (v458 = 0; v458 < v453; v458++) {
            a457[v458] = !((v458 & 32) == 0) ? exp(I * (FELD_PI *
                                                        (float) (v458 & 31) /
                                                        32.0)) * (a454[v458 ^
                                                                       32] -
                                                                  a454[v458]) : a454[v458] +
                a454[v458 ^ 32];
        }
        v459 = r456;
        v460 = v459;
        v461 = chan_write(chan447, sizeof(v460), &v460);
        v462 = chan_write(chan447, sizeof(*a457) * (v459 - 0), &a457[0]);
        if (!v462) {
            chan_close(chan431);
            pthread_cancel(t448);
            pthread_join(t448, NULL);
        }
    }
    chan_close(chan431);
    chan_close(chan447);
    return NULL;
}
chan_t chan463;
void *thread_t464(void *unused)
{
    while (1) {
        uint32_t v465;
        bool v467;
        uint32_t r468;
        uint32_t v469;
        bool v471;
        uint32_t r472;
        uint32_t v474;
        uint32_t v475;
        uint32_t v476;
        bool v477;
        bool v478;
        
        chan_read(chan447, sizeof(v465), &v465);
        
        float _Complex _a466[v465];
        float _Complex *a466 = _a466;
        
        chan_read(chan447, sizeof(*a466) * (v465 - 0), &a466[0]);
        v467 = chan_last_read_ok(chan447);
        r468 = v465;
        v469 = r468;
        
        float _Complex _a470[v469];
        float _Complex *a470 = _a470;
        
        memcpy(a470, a466, v469 * sizeof(float _Complex));
        v471 = chan_last_read_ok(chan447);
        if (!v471) {
            chan_close(chan463);
            pthread_cancel(t464);
            pthread_join(t464, NULL);
        }
        r472 = v469;
        
        float _Complex _a473[v469];
        float _Complex *a473 = _a473;
        
        for (v474 = 0; v474 < v469; v474++) {
            a473[v474] = !((v474 & 16) == 0) ? exp(I * (FELD_PI *
                                                        (float) (v474 & 15) /
                                                        16.0)) * (a470[v474 ^
                                                                       16] -
                                                                  a470[v474]) : a470[v474] +
                a470[v474 ^ 16];
        }
        v475 = r472;
        v476 = v475;
        v477 = chan_write(chan463, sizeof(v476), &v476);
        v478 = chan_write(chan463, sizeof(*a473) * (v475 - 0), &a473[0]);
        if (!v478) {
            chan_close(chan447);
            pthread_cancel(t464);
            pthread_join(t464, NULL);
        }
    }
    chan_close(chan447);
    chan_close(chan463);
    return NULL;
}
chan_t chan479;
void *thread_t480(void *unused)
{
    while (1) {
        uint32_t v481;
        bool v483;
        uint32_t r484;
        uint32_t v485;
        bool v487;
        uint32_t r488;
        uint32_t v490;
        uint32_t v491;
        uint32_t v492;
        bool v493;
        bool v494;
        
        chan_read(chan463, sizeof(v481), &v481);
        
        float _Complex _a482[v481];
        float _Complex *a482 = _a482;
        
        chan_read(chan463, sizeof(*a482) * (v481 - 0), &a482[0]);
        v483 = chan_last_read_ok(chan463);
        r484 = v481;
        v485 = r484;
        
        float _Complex _a486[v485];
        float _Complex *a486 = _a486;
        
        memcpy(a486, a482, v485 * sizeof(float _Complex));
        v487 = chan_last_read_ok(chan463);
        if (!v487) {
            chan_close(chan479);
            pthread_cancel(t480);
            pthread_join(t480, NULL);
        }
        r488 = v485;
        
        float _Complex _a489[v485];
        float _Complex *a489 = _a489;
        
        for (v490 = 0; v490 < v485; v490++) {
            a489[v490] = !((v490 & 8) == 0) ? exp(I * (FELD_PI * (float) (v490 &
                                                                          7) /
                                                       8.0)) * (a486[v490 ^ 8] -
                                                                a486[v490]) : a486[v490] +
                a486[v490 ^ 8];
        }
        v491 = r488;
        v492 = v491;
        v493 = chan_write(chan479, sizeof(v492), &v492);
        v494 = chan_write(chan479, sizeof(*a489) * (v491 - 0), &a489[0]);
        if (!v494) {
            chan_close(chan463);
            pthread_cancel(t480);
            pthread_join(t480, NULL);
        }
    }
    chan_close(chan463);
    chan_close(chan479);
    return NULL;
}
chan_t chan495;
void *thread_t496(void *unused)
{
    while (1) {
        uint32_t v497;
        bool v499;
        uint32_t r500;
        uint32_t v501;
        bool v503;
        uint32_t r504;
        uint32_t v506;
        uint32_t v507;
        uint32_t v508;
        bool v509;
        bool v510;
        
        chan_read(chan479, sizeof(v497), &v497);
        
        float _Complex _a498[v497];
        float _Complex *a498 = _a498;
        
        chan_read(chan479, sizeof(*a498) * (v497 - 0), &a498[0]);
        v499 = chan_last_read_ok(chan479);
        r500 = v497;
        v501 = r500;
        
        float _Complex _a502[v501];
        float _Complex *a502 = _a502;
        
        memcpy(a502, a498, v501 * sizeof(float _Complex));
        v503 = chan_last_read_ok(chan479);
        if (!v503) {
            chan_close(chan495);
            pthread_cancel(t496);
            pthread_join(t496, NULL);
        }
        r504 = v501;
        
        float _Complex _a505[v501];
        float _Complex *a505 = _a505;
        
        for (v506 = 0; v506 < v501; v506++) {
            a505[v506] = !((v506 & 4) == 0) ? exp(I * (FELD_PI * (float) (v506 &
                                                                          3) /
                                                       4.0)) * (a502[v506 ^ 4] -
                                                                a502[v506]) : a502[v506] +
                a502[v506 ^ 4];
        }
        v507 = r504;
        v508 = v507;
        v509 = chan_write(chan495, sizeof(v508), &v508);
        v510 = chan_write(chan495, sizeof(*a505) * (v507 - 0), &a505[0]);
        if (!v510) {
            chan_close(chan479);
            pthread_cancel(t496);
            pthread_join(t496, NULL);
        }
    }
    chan_close(chan479);
    chan_close(chan495);
    return NULL;
}
chan_t chan511;
void *thread_t512(void *unused)
{
    while (1) {
        uint32_t v513;
        bool v515;
        uint32_t r516;
        uint32_t v517;
        bool v519;
        uint32_t r520;
        uint32_t v522;
        uint32_t v523;
        uint32_t v524;
        bool v525;
        bool v526;
        
        chan_read(chan495, sizeof(v513), &v513);
        
        float _Complex _a514[v513];
        float _Complex *a514 = _a514;
        
        chan_read(chan495, sizeof(*a514) * (v513 - 0), &a514[0]);
        v515 = chan_last_read_ok(chan495);
        r516 = v513;
        v517 = r516;
        
        float _Complex _a518[v517];
        float _Complex *a518 = _a518;
        
        memcpy(a518, a514, v517 * sizeof(float _Complex));
        v519 = chan_last_read_ok(chan495);
        if (!v519) {
            chan_close(chan511);
            pthread_cancel(t512);
            pthread_join(t512, NULL);
        }
        r520 = v517;
        
        float _Complex _a521[v517];
        float _Complex *a521 = _a521;
        
        for (v522 = 0; v522 < v517; v522++) {
            a521[v522] = !((v522 & 2) == 0) ? exp(I * (FELD_PI * (float) (v522 &
                                                                          1) /
                                                       2.0)) * (a518[v522 ^ 2] -
                                                                a518[v522]) : a518[v522] +
                a518[v522 ^ 2];
        }
        v523 = r520;
        v524 = v523;
        v525 = chan_write(chan511, sizeof(v524), &v524);
        v526 = chan_write(chan511, sizeof(*a521) * (v523 - 0), &a521[0]);
        if (!v526) {
            chan_close(chan495);
            pthread_cancel(t512);
            pthread_join(t512, NULL);
        }
    }
    chan_close(chan495);
    chan_close(chan511);
    return NULL;
}
chan_t chan527;
void *thread_t528(void *unused)
{
    while (1) {
        uint32_t v529;
        bool v531;
        uint32_t r532;
        uint32_t v533;
        bool v535;
        uint32_t r536;
        uint32_t v538;
        uint32_t v539;
        uint32_t v540;
        bool v541;
        bool v542;
        
        chan_read(chan511, sizeof(v529), &v529);
        
        float _Complex _a530[v529];
        float _Complex *a530 = _a530;
        
        chan_read(chan511, sizeof(*a530) * (v529 - 0), &a530[0]);
        v531 = chan_last_read_ok(chan511);
        r532 = v529;
        v533 = r532;
        
        float _Complex _a534[v533];
        float _Complex *a534 = _a534;
        
        memcpy(a534, a530, v533 * sizeof(float _Complex));
        v535 = chan_last_read_ok(chan511);
        if (!v535) {
            chan_close(chan527);
            pthread_cancel(t528);
            pthread_join(t528, NULL);
        }
        r536 = v533;
        
        float _Complex _a537[v533];
        float _Complex *a537 = _a537;
        
        for (v538 = 0; v538 < v533; v538++) {
            a537[v538] = !((v538 & 1) == 0) ? exp(I * (FELD_PI * (float) (v538 &
                                                                          0) /
                                                       1.0)) * (a534[v538 ^ 1] -
                                                                a534[v538]) : a534[v538] +
                a534[v538 ^ 1];
        }
        v539 = r536;
        v540 = v539;
        v541 = chan_write(chan527, sizeof(v540), &v540);
        v542 = chan_write(chan527, sizeof(*a537) * (v539 - 0), &a537[0]);
        if (!v542) {
            chan_close(chan511);
            pthread_cancel(t528);
            pthread_join(t528, NULL);
        }
    }
    chan_close(chan511);
    chan_close(chan527);
    return NULL;
}
chan_t chan543;
void *thread_t544(void *unused)
{
    while (1) {
        uint32_t v545;
        bool v547;
        uint32_t r548;
        uint32_t v549;
        bool v551;
        uint32_t r552;
        uint32_t v554;
        uint32_t v555;
        uint32_t v556;
        bool v557;
        bool v558;
        
        chan_read(chan527, sizeof(v545), &v545);
        
        float _Complex _a546[v545];
        float _Complex *a546 = _a546;
        
        chan_read(chan527, sizeof(*a546) * (v545 - 0), &a546[0]);
        v547 = chan_last_read_ok(chan527);
        r548 = v545;
        v549 = r548;
        
        float _Complex _a550[v549];
        float _Complex *a550 = _a550;
        
        memcpy(a550, a546, v549 * sizeof(float _Complex));
        v551 = chan_last_read_ok(chan527);
        if (!v551) {
            chan_close(chan543);
            pthread_cancel(t544);
            pthread_join(t544, NULL);
        }
        r552 = v549;
        
        float _Complex _a553[v549];
        float _Complex *a553 = _a553;
        
        for (v554 = 0; v554 < v549; v554++) {
            a553[v554] = a550[(v554 >> 1 >> 1 << 1 | (v554 & 1)) << 1 | (v554 >>
                                                                         1 &
                                                                         1)];
        }
        v555 = r552;
        v556 = v555;
        v557 = chan_write(chan543, sizeof(v556), &v556);
        v558 = chan_write(chan543, sizeof(*a553) * (v555 - 0), &a553[0]);
        if (!v558) {
            chan_close(chan527);
            pthread_cancel(t544);
            pthread_join(t544, NULL);
        }
    }
    chan_close(chan527);
    chan_close(chan543);
    return NULL;
}
chan_t chan559;
void *thread_t560(void *unused)
{
    while (1) {
        uint32_t v561;
        bool v563;
        uint32_t r564;
        uint32_t v565;
        bool v567;
        uint32_t r568;
        uint32_t v570;
        uint32_t v571;
        uint32_t v572;
        bool v573;
        bool v574;
        
        chan_read(chan543, sizeof(v561), &v561);
        
        float _Complex _a562[v561];
        float _Complex *a562 = _a562;
        
        chan_read(chan543, sizeof(*a562) * (v561 - 0), &a562[0]);
        v563 = chan_last_read_ok(chan543);
        r564 = v561;
        v565 = r564;
        
        float _Complex _a566[v565];
        float _Complex *a566 = _a566;
        
        memcpy(a566, a562, v565 * sizeof(float _Complex));
        v567 = chan_last_read_ok(chan543);
        if (!v567) {
            chan_close(chan559);
            pthread_cancel(t560);
            pthread_join(t560, NULL);
        }
        r568 = v565;
        
        float _Complex _a569[v565];
        float _Complex *a569 = _a569;
        
        for (v570 = 0; v570 < v565; v570++) {
            a569[v570] = a566[(v570 >> 1 >> 2 << 1 | (v570 & 1)) << 2 | (v570 >>
                                                                         1 &
                                                                         3)];
        }
        v571 = r568;
        v572 = v571;
        v573 = chan_write(chan559, sizeof(v572), &v572);
        v574 = chan_write(chan559, sizeof(*a569) * (v571 - 0), &a569[0]);
        if (!v574) {
            chan_close(chan543);
            pthread_cancel(t560);
            pthread_join(t560, NULL);
        }
    }
    chan_close(chan543);
    chan_close(chan559);
    return NULL;
}
chan_t chan575;
void *thread_t576(void *unused)
{
    while (1) {
        uint32_t v577;
        bool v579;
        uint32_t r580;
        uint32_t v581;
        bool v583;
        uint32_t r584;
        uint32_t v586;
        uint32_t v587;
        uint32_t v588;
        bool v589;
        bool v590;
        
        chan_read(chan559, sizeof(v577), &v577);
        
        float _Complex _a578[v577];
        float _Complex *a578 = _a578;
        
        chan_read(chan559, sizeof(*a578) * (v577 - 0), &a578[0]);
        v579 = chan_last_read_ok(chan559);
        r580 = v577;
        v581 = r580;
        
        float _Complex _a582[v581];
        float _Complex *a582 = _a582;
        
        memcpy(a582, a578, v581 * sizeof(float _Complex));
        v583 = chan_last_read_ok(chan559);
        if (!v583) {
            chan_close(chan575);
            pthread_cancel(t576);
            pthread_join(t576, NULL);
        }
        r584 = v581;
        
        float _Complex _a585[v581];
        float _Complex *a585 = _a585;
        
        for (v586 = 0; v586 < v581; v586++) {
            a585[v586] = a582[(v586 >> 1 >> 3 << 1 | (v586 & 1)) << 3 | (v586 >>
                                                                         1 &
                                                                         7)];
        }
        v587 = r584;
        v588 = v587;
        v589 = chan_write(chan575, sizeof(v588), &v588);
        v590 = chan_write(chan575, sizeof(*a585) * (v587 - 0), &a585[0]);
        if (!v590) {
            chan_close(chan559);
            pthread_cancel(t576);
            pthread_join(t576, NULL);
        }
    }
    chan_close(chan559);
    chan_close(chan575);
    return NULL;
}
chan_t chan591;
void *thread_t592(void *unused)
{
    while (1) {
        uint32_t v593;
        bool v595;
        uint32_t r596;
        uint32_t v597;
        bool v599;
        uint32_t r600;
        uint32_t v602;
        uint32_t v603;
        uint32_t v604;
        bool v605;
        bool v606;
        
        chan_read(chan575, sizeof(v593), &v593);
        
        float _Complex _a594[v593];
        float _Complex *a594 = _a594;
        
        chan_read(chan575, sizeof(*a594) * (v593 - 0), &a594[0]);
        v595 = chan_last_read_ok(chan575);
        r596 = v593;
        v597 = r596;
        
        float _Complex _a598[v597];
        float _Complex *a598 = _a598;
        
        memcpy(a598, a594, v597 * sizeof(float _Complex));
        v599 = chan_last_read_ok(chan575);
        if (!v599) {
            chan_close(chan591);
            pthread_cancel(t592);
            pthread_join(t592, NULL);
        }
        r600 = v597;
        
        float _Complex _a601[v597];
        float _Complex *a601 = _a601;
        
        for (v602 = 0; v602 < v597; v602++) {
            a601[v602] = a598[(v602 >> 1 >> 4 << 1 | (v602 & 1)) << 4 | (v602 >>
                                                                         1 &
                                                                         15)];
        }
        v603 = r600;
        v604 = v603;
        v605 = chan_write(chan591, sizeof(v604), &v604);
        v606 = chan_write(chan591, sizeof(*a601) * (v603 - 0), &a601[0]);
        if (!v606) {
            chan_close(chan575);
            pthread_cancel(t592);
            pthread_join(t592, NULL);
        }
    }
    chan_close(chan575);
    chan_close(chan591);
    return NULL;
}
chan_t chan607;
void *thread_t608(void *unused)
{
    while (1) {
        uint32_t v609;
        bool v611;
        uint32_t r612;
        uint32_t v613;
        bool v615;
        uint32_t r616;
        uint32_t v618;
        uint32_t v619;
        uint32_t v620;
        bool v621;
        bool v622;
        
        chan_read(chan591, sizeof(v609), &v609);
        
        float _Complex _a610[v609];
        float _Complex *a610 = _a610;
        
        chan_read(chan591, sizeof(*a610) * (v609 - 0), &a610[0]);
        v611 = chan_last_read_ok(chan591);
        r612 = v609;
        v613 = r612;
        
        float _Complex _a614[v613];
        float _Complex *a614 = _a614;
        
        memcpy(a614, a610, v613 * sizeof(float _Complex));
        v615 = chan_last_read_ok(chan591);
        if (!v615) {
            chan_close(chan607);
            pthread_cancel(t608);
            pthread_join(t608, NULL);
        }
        r616 = v613;
        
        float _Complex _a617[v613];
        float _Complex *a617 = _a617;
        
        for (v618 = 0; v618 < v613; v618++) {
            a617[v618] = a614[(v618 >> 1 >> 5 << 1 | (v618 & 1)) << 5 | (v618 >>
                                                                         1 &
                                                                         31)];
        }
        v619 = r616;
        v620 = v619;
        v621 = chan_write(chan607, sizeof(v620), &v620);
        v622 = chan_write(chan607, sizeof(*a617) * (v619 - 0), &a617[0]);
        if (!v622) {
            chan_close(chan591);
            pthread_cancel(t608);
            pthread_join(t608, NULL);
        }
    }
    chan_close(chan591);
    chan_close(chan607);
    return NULL;
}
chan_t chan623;
void *thread_t624(void *unused)
{
    while (1) {
        uint32_t v625;
        bool v627;
        uint32_t r628;
        uint32_t v629;
        bool v631;
        uint32_t r632;
        uint32_t v634;
        uint32_t v635;
        uint32_t v636;
        bool v637;
        bool v638;
        
        chan_read(chan607, sizeof(v625), &v625);
        
        float _Complex _a626[v625];
        float _Complex *a626 = _a626;
        
        chan_read(chan607, sizeof(*a626) * (v625 - 0), &a626[0]);
        v627 = chan_last_read_ok(chan607);
        r628 = v625;
        v629 = r628;
        
        float _Complex _a630[v629];
        float _Complex *a630 = _a630;
        
        memcpy(a630, a626, v629 * sizeof(float _Complex));
        v631 = chan_last_read_ok(chan607);
        if (!v631) {
            chan_close(chan623);
            pthread_cancel(t624);
            pthread_join(t624, NULL);
        }
        r632 = v629;
        
        float _Complex _a633[v629];
        float _Complex *a633 = _a633;
        
        for (v634 = 0; v634 < v629; v634++) {
            a633[v634] = a630[(v634 >> 1 >> 6 << 1 | (v634 & 1)) << 6 | (v634 >>
                                                                         1 &
                                                                         63)];
        }
        v635 = r632;
        v636 = v635;
        v637 = chan_write(chan623, sizeof(v636), &v636);
        v638 = chan_write(chan623, sizeof(*a633) * (v635 - 0), &a633[0]);
        if (!v638) {
            chan_close(chan607);
            pthread_cancel(t624);
            pthread_join(t624, NULL);
        }
    }
    chan_close(chan607);
    chan_close(chan623);
    return NULL;
}
chan_t chan639;
void *thread_t640(void *unused)
{
    while (1) {
        uint32_t v641;
        bool v643;
        uint32_t r644;
        uint32_t v645;
        bool v647;
        uint32_t r648;
        uint32_t v650;
        uint32_t v651;
        uint32_t v652;
        bool v653;
        bool v654;
        
        chan_read(chan623, sizeof(v641), &v641);
        
        float _Complex _a642[v641];
        float _Complex *a642 = _a642;
        
        chan_read(chan623, sizeof(*a642) * (v641 - 0), &a642[0]);
        v643 = chan_last_read_ok(chan623);
        r644 = v641;
        v645 = r644;
        
        float _Complex _a646[v645];
        float _Complex *a646 = _a646;
        
        memcpy(a646, a642, v645 * sizeof(float _Complex));
        v647 = chan_last_read_ok(chan623);
        if (!v647) {
            chan_close(chan639);
            pthread_cancel(t640);
            pthread_join(t640, NULL);
        }
        r648 = v645;
        
        float _Complex _a649[v645];
        float _Complex *a649 = _a649;
        
        for (v650 = 0; v650 < v645; v650++) {
            a649[v650] = a646[(v650 >> 1 >> 7 << 1 | (v650 & 1)) << 7 | (v650 >>
                                                                         1 &
                                                                         127)];
        }
        v651 = r648;
        v652 = v651;
        v653 = chan_write(chan639, sizeof(v652), &v652);
        v654 = chan_write(chan639, sizeof(*a649) * (v651 - 0), &a649[0]);
        if (!v654) {
            chan_close(chan623);
            pthread_cancel(t640);
            pthread_join(t640, NULL);
        }
    }
    chan_close(chan623);
    chan_close(chan639);
    return NULL;
}
chan_t chan655;
void *thread_t656(void *unused)
{
    while (1) {
        uint32_t v657;
        bool v659;
        uint32_t r660;
        uint32_t v661;
        bool v663;
        uint32_t r664;
        uint32_t v666;
        uint32_t v667;
        uint32_t v668;
        bool v669;
        bool v670;
        
        chan_read(chan639, sizeof(v657), &v657);
        
        float _Complex _a658[v657];
        float _Complex *a658 = _a658;
        
        chan_read(chan639, sizeof(*a658) * (v657 - 0), &a658[0]);
        v659 = chan_last_read_ok(chan639);
        r660 = v657;
        v661 = r660;
        
        float _Complex _a662[v661];
        float _Complex *a662 = _a662;
        
        memcpy(a662, a658, v661 * sizeof(float _Complex));
        v663 = chan_last_read_ok(chan639);
        if (!v663) {
            chan_close(chan655);
            pthread_cancel(t656);
            pthread_join(t656, NULL);
        }
        r664 = v661;
        
        float _Complex _a665[v661];
        float _Complex *a665 = _a665;
        
        for (v666 = 0; v666 < v661; v666++) {
            a665[v666] = a662[(v666 >> 1 >> 8 << 1 | (v666 & 1)) << 8 | (v666 >>
                                                                         1 &
                                                                         255)];
        }
        v667 = r664;
        v668 = v667;
        v669 = chan_write(chan655, sizeof(v668), &v668);
        v670 = chan_write(chan655, sizeof(*a665) * (v667 - 0), &a665[0]);
        if (!v670) {
            chan_close(chan639);
            pthread_cancel(t656);
            pthread_join(t656, NULL);
        }
    }
    chan_close(chan639);
    chan_close(chan655);
    return NULL;
}
chan_t chan671;
void *thread_t672(void *unused)
{
    while (1) {
        uint32_t v673;
        bool v675;
        uint32_t r676;
        uint32_t v677;
        bool v679;
        uint32_t r680;
        uint32_t v682;
        uint32_t v683;
        uint32_t v684;
        bool v685;
        bool v686;
        
        chan_read(chan655, sizeof(v673), &v673);
        
        float _Complex _a674[v673];
        float _Complex *a674 = _a674;
        
        chan_read(chan655, sizeof(*a674) * (v673 - 0), &a674[0]);
        v675 = chan_last_read_ok(chan655);
        r676 = v673;
        v677 = r676;
        
        float _Complex _a678[v677];
        float _Complex *a678 = _a678;
        
        memcpy(a678, a674, v677 * sizeof(float _Complex));
        v679 = chan_last_read_ok(chan655);
        if (!v679) {
            chan_close(chan671);
            pthread_cancel(t672);
            pthread_join(t672, NULL);
        }
        r680 = v677;
        
        float _Complex _a681[v677];
        float _Complex *a681 = _a681;
        
        for (v682 = 0; v682 < v677; v682++) {
            a681[v682] = a678[(v682 >> 1 >> 9 << 1 | (v682 & 1)) << 9 | (v682 >>
                                                                         1 &
                                                                         511)];
        }
        v683 = r680;
        v684 = v683;
        v685 = chan_write(chan671, sizeof(v684), &v684);
        v686 = chan_write(chan671, sizeof(*a681) * (v683 - 0), &a681[0]);
        if (!v686) {
            chan_close(chan655);
            pthread_cancel(t672);
            pthread_join(t672, NULL);
        }
    }
    chan_close(chan655);
    chan_close(chan671);
    return NULL;
}
chan_t chan687;
void *thread_t688(void *unused)
{
    while (1) {
        uint32_t v689;
        bool v691;
        uint32_t r692;
        uint32_t v693;
        bool v695;
        uint32_t r696;
        uint32_t v698;
        uint32_t v699;
        uint32_t v700;
        bool v701;
        bool v702;
        
        chan_read(chan671, sizeof(v689), &v689);
        
        float _Complex _a690[v689];
        float _Complex *a690 = _a690;
        
        chan_read(chan671, sizeof(*a690) * (v689 - 0), &a690[0]);
        v691 = chan_last_read_ok(chan671);
        r692 = v689;
        v693 = r692;
        
        float _Complex _a694[v693];
        float _Complex *a694 = _a694;
        
        memcpy(a694, a690, v693 * sizeof(float _Complex));
        v695 = chan_last_read_ok(chan671);
        if (!v695) {
            chan_close(chan687);
            pthread_cancel(t688);
            pthread_join(t688, NULL);
        }
        r696 = v693 <= 1024 ? v693 : 1024;
        
        float _a697[v693 <= 1024 ? v693 : 1024];
        float *a697 = _a697;
        
        for (v698 = 0; v698 < (v693 <= 1024 ? v693 : 1024); v698++) {
            a697[v698] = creal(a694[v698]) / 4096.0 * (-(0.5 * cos(2.0 *
                                                         FELD_PI *
                                                         (float) v698 /
                                                         1024.0)) + 0.5);
        }
        v699 = r696;
        v700 = v699;
        v701 = chan_write(chan687, sizeof(v700), &v700);
        v702 = chan_write(chan687, sizeof(*a697) * (v699 - 0), &a697[0]);
        if (!v702) {
            chan_close(chan671);
            pthread_cancel(t688);
            pthread_join(t688, NULL);
        }
    }
    chan_close(chan671);
    chan_close(chan687);
    return NULL;
}
void *thread_t703(void *unused)
{
    while (1) {
        uint32_t v704;
        bool v706;
        uint32_t r707;
        uint32_t v708;
        bool v710;
        uint32_t v712;
        bool v713;
        
        chan_read(chan687, sizeof(v704), &v704);
        
        float _a705[v704];
        float *a705 = _a705;
        
        chan_read(chan687, sizeof(*a705) * (v704 - 0), &a705[0]);
        v706 = chan_last_read_ok(chan687);
        r707 = v704;
        v708 = r707;
        
        float _a709[v708];
        float *a709 = _a709;
        
        memcpy(a709, a705, v708 * sizeof(float));
        v710 = chan_last_read_ok(chan687);
        if (!v710) {
            pthread_cancel(t703);
            pthread_join(t703, NULL);
        }
        
        float _a711[v708];
        float *a711 = _a711;
        
        for (v712 = 0; v712 < v708; v712++) {
            a711[v712] = a709[v712];
        }
        v713 = emit_samples(a711);
        if (!v713) {
            chan_close(chan687);
            pthread_cancel(t703);
            pthread_join(t703, NULL);
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
    chan17 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                    sizeof(float _Complex)));
    pthread_create(&t18, NULL, thread_t18, NULL);
    chan33 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                    sizeof(float _Complex)));
    pthread_create(&t34, NULL, thread_t34, NULL);
    chan49 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                    sizeof(float _Complex)));
    pthread_create(&t50, NULL, thread_t50, NULL);
    chan65 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                    sizeof(float _Complex)));
    pthread_create(&t66, NULL, thread_t66, NULL);
    chan81 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                    sizeof(float _Complex)));
    pthread_create(&t82, NULL, thread_t82, NULL);
    chan97 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                    sizeof(float _Complex)));
    pthread_create(&t98, NULL, thread_t98, NULL);
    chan113 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t114, NULL, thread_t114, NULL);
    chan129 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t130, NULL, thread_t130, NULL);
    chan145 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t146, NULL, thread_t146, NULL);
    chan161 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t162, NULL, thread_t162, NULL);
    chan177 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t178, NULL, thread_t178, NULL);
    chan193 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t194, NULL, thread_t194, NULL);
    chan209 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t210, NULL, thread_t210, NULL);
    chan225 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t226, NULL, thread_t226, NULL);
    chan241 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t242, NULL, thread_t242, NULL);
    chan257 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t258, NULL, thread_t258, NULL);
    chan273 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t274, NULL, thread_t274, NULL);
    chan289 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t290, NULL, thread_t290, NULL);
    chan305 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t306, NULL, thread_t306, NULL);
    chan321 = chan_new(10 * sizeof(uint32_t) + 10 * (513 *
                                                     sizeof(float _Complex)));
    pthread_create(&t322, NULL, thread_t322, NULL);
    chan343 = chan_new(10 * sizeof(uint32_t) + 10 * (513 *
                                                     sizeof(float _Complex)));
    pthread_create(&t344, NULL, thread_t344, NULL);
    chan361 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t362, NULL, thread_t362, NULL);
    chan383 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t384, NULL, thread_t384, NULL);
    chan399 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t400, NULL, thread_t400, NULL);
    chan415 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t416, NULL, thread_t416, NULL);
    chan431 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t432, NULL, thread_t432, NULL);
    chan447 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t448, NULL, thread_t448, NULL);
    chan463 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t464, NULL, thread_t464, NULL);
    chan479 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t480, NULL, thread_t480, NULL);
    chan495 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t496, NULL, thread_t496, NULL);
    chan511 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t512, NULL, thread_t512, NULL);
    chan527 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t528, NULL, thread_t528, NULL);
    chan543 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t544, NULL, thread_t544, NULL);
    chan559 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t560, NULL, thread_t560, NULL);
    chan575 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t576, NULL, thread_t576, NULL);
    chan591 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t592, NULL, thread_t592, NULL);
    chan607 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t608, NULL, thread_t608, NULL);
    chan623 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t624, NULL, thread_t624, NULL);
    chan639 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t640, NULL, thread_t640, NULL);
    chan655 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t656, NULL, thread_t656, NULL);
    chan671 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t672, NULL, thread_t672, NULL);
    chan687 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 * sizeof(float)));
    pthread_create(&t688, NULL, thread_t688, NULL);
    pthread_create(&t703, NULL, thread_t703, NULL);
    while (1) {
        float _a714[1024];
        float *a714 = _a714;
        bool v715;
        uint32_t r716;
        float _a717[1024];
        float *a717 = _a717;
        uint32_t v718;
        uint32_t v719;
        uint32_t v720;
        bool v721;
        bool v722;
        
        v715 = receive_samples(a714);
        if (!v715) {
            break;
        }
        r716 = 1024;
        for (v718 = 0; v718 < 1024; v718++) {
            a717[v718] = a714[v718];
        }
        v719 = r716;
        v720 = v719;
        v721 = chan_write(chan0, sizeof(v720), &v720);
        v722 = chan_write(chan0, sizeof(*a717) * (v719 - 0), &a717[0]);
        if (!v722) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t703, NULL);
    teardown_queues();
    return 0;
}

