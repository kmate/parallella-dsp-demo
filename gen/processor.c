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
void *thread_t343(void *unused);
void *thread_t363(void *unused);
void *thread_t383(void *unused);
void *thread_t399(void *unused);
void *thread_t415(void *unused);
void *thread_t431(void *unused);
void *thread_t447(void *unused);
void *thread_t463(void *unused);
void *thread_t479(void *unused);
void *thread_t495(void *unused);
void *thread_t511(void *unused);
void *thread_t527(void *unused);
void *thread_t543(void *unused);
void *thread_t559(void *unused);
void *thread_t575(void *unused);
void *thread_t591(void *unused);
void *thread_t607(void *unused);
void *thread_t623(void *unused);
void *thread_t639(void *unused);
void *thread_t655(void *unused);
void *thread_t671(void *unused);
void *thread_t687(void *unused);
void *thread_t702(void *unused);
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
pthread_t t343;
pthread_t t363;
pthread_t t383;
pthread_t t399;
pthread_t t415;
pthread_t t431;
pthread_t t447;
pthread_t t463;
pthread_t t479;
pthread_t t495;
pthread_t t50;
pthread_t t511;
pthread_t t527;
pthread_t t543;
pthread_t t559;
pthread_t t575;
pthread_t t591;
pthread_t t607;
pthread_t t623;
pthread_t t639;
pthread_t t655;
pthread_t t66;
pthread_t t671;
pthread_t t687;
pthread_t t702;
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
    float _a323[513];
    float *a323 = _a323;
    
    while (1) {
        uint32_t v324;
        bool v326;
        uint32_t r327;
        uint32_t v328;
        bool v330;
        float _Complex _a331[513];
        float _Complex *a331 = _a331;
        uint32_t v332;
        uint32_t r335;
        float _Complex _a336[1024];
        float _Complex *a336 = _a336;
        uint32_t v337;
        uint32_t v338;
        uint32_t v339;
        bool v340;
        bool v341;
        
        chan_read(chan305, sizeof(v324), &v324);
        
        float _Complex _a325[v324];
        float _Complex *a325 = _a325;
        
        chan_read(chan305, sizeof(*a325) * (v324 - 0), &a325[0]);
        v326 = chan_last_read_ok(chan305);
        r327 = v324;
        v328 = r327;
        
        float _Complex _a329[v328];
        float _Complex *a329 = _a329;
        
        memcpy(a329, a325, v328 * sizeof(float _Complex));
        v330 = chan_last_read_ok(chan305);
        if (!v330) {
            chan_close(chan321);
            pthread_cancel(t322);
            pthread_join(t322, NULL);
        }
        for (v332 = 0; v332 < 513; v332++) {
            float v333;
            float v334;
            
            v333 = a323[v332];
            a323[v332] = carg(a329[v332]);
            v334 = clampPhase(carg(a329[v332]) - v333 - (float) v332 *
                1.5707964);
            a331[v332] = 2.0 * cabs(a329[v332]) + I * (((float) v332 + 4.0 *
                                                        v334 / (2.0 *
                                                                FELD_PI)) *
                                                       43.066406);
        }
        r335 = 1024;
        for (v337 = 0; v337 < 1024; v337++) {
            a336[v337] = a331[v337];
        }
        v338 = r335;
        v339 = v338;
        v340 = chan_write(chan321, sizeof(v339), &v339);
        v341 = chan_write(chan321, sizeof(*a336) * (v338 - 0), &a336[0]);
        if (!v341) {
            chan_close(chan305);
            pthread_cancel(t322);
            pthread_join(t322, NULL);
        }
    }
    chan_close(chan305);
    chan_close(chan321);
    return NULL;
}
chan_t chan342;
void *thread_t343(void *unused)
{
    while (1) {
        uint32_t v344;
        bool v346;
        uint32_t r347;
        uint32_t v348;
        bool v350;
        float _Complex _a351[513];
        float _Complex *a351 = _a351;
        uint32_t v352;
        uint32_t r355;
        float _Complex _a356[1024];
        float _Complex *a356 = _a356;
        uint32_t v357;
        uint32_t v358;
        uint32_t v359;
        bool v360;
        bool v361;
        
        chan_read(chan321, sizeof(v344), &v344);
        
        float _Complex _a345[v344];
        float _Complex *a345 = _a345;
        
        chan_read(chan321, sizeof(*a345) * (v344 - 0), &a345[0]);
        v346 = chan_last_read_ok(chan321);
        r347 = v344;
        v348 = r347;
        
        float _Complex _a349[v348];
        float _Complex *a349 = _a349;
        
        memcpy(a349, a345, v348 * sizeof(float _Complex));
        v350 = chan_last_read_ok(chan321);
        if (!v350) {
            chan_close(chan342);
            pthread_cancel(t343);
            pthread_join(t343, NULL);
        }
        for (v352 = 0; v352 < 513; v352++) {
            uint32_t r353;
            uint32_t v354;
            
            r353 = round((float) v352 * 2.0);
            v354 = r353;
            a351[v354] = round((float) v352 * 2.0) < 513 ? creal(a349[v352]) +
                I * (2.0 * cimag(a349[v352])) : 0.0;
        }
        r355 = 1024;
        for (v357 = 0; v357 < 1024; v357++) {
            a356[v357] = a351[v357];
        }
        v358 = r355;
        v359 = v358;
        v360 = chan_write(chan342, sizeof(v359), &v359);
        v361 = chan_write(chan342, sizeof(*a356) * (v358 - 0), &a356[0]);
        if (!v361) {
            chan_close(chan321);
            pthread_cancel(t343);
            pthread_join(t343, NULL);
        }
    }
    chan_close(chan321);
    chan_close(chan342);
    return NULL;
}
chan_t chan362;
void *thread_t363(void *unused)
{
    float _a364[513];
    float *a364 = _a364;
    
    while (1) {
        uint32_t v365;
        bool v367;
        uint32_t r368;
        uint32_t v369;
        bool v371;
        float _Complex _a372[513];
        float _Complex *a372 = _a372;
        uint32_t v373;
        uint32_t r375;
        float _Complex _a376[1024];
        float _Complex *a376 = _a376;
        uint32_t v377;
        uint32_t v378;
        uint32_t v379;
        bool v380;
        bool v381;
        
        chan_read(chan342, sizeof(v365), &v365);
        
        float _Complex _a366[v365];
        float _Complex *a366 = _a366;
        
        chan_read(chan342, sizeof(*a366) * (v365 - 0), &a366[0]);
        v367 = chan_last_read_ok(chan342);
        r368 = v365;
        v369 = r368;
        
        float _Complex _a370[v369];
        float _Complex *a370 = _a370;
        
        memcpy(a370, a366, v369 * sizeof(float _Complex));
        v371 = chan_last_read_ok(chan342);
        if (!v371) {
            chan_close(chan362);
            pthread_cancel(t363);
            pthread_join(t363, NULL);
        }
        for (v373 = 0; v373 < 513; v373++) {
            float v374;
            
            v374 = a364[v373];
            a364[v373] = v374 + (2.0 * FELD_PI * ((cimag(a370[v373]) -
                                                   (float) v373 * 43.066406) /
                                                  43.066406) / 4.0 +
                                 (float) v373 * 1.5707964);
            a372[v373] = creal(a370[v373]) * exp(I * (v374 + (2.0 * FELD_PI *
                                                              ((cimag(a370[v373]) -
                                                                (float) v373 *
                                                                43.066406) /
                                                               43.066406) /
                                                              4.0 +
                                                              (float) v373 *
                                                              1.5707964)));
        }
        r375 = 1024;
        for (v377 = 0; v377 < 1024; v377++) {
            a376[v377] = v377 <= 513 ? a372[v377] : 0.0;
        }
        v378 = r375;
        v379 = v378;
        v380 = chan_write(chan362, sizeof(v379), &v379);
        v381 = chan_write(chan362, sizeof(*a376) * (v378 - 0), &a376[0]);
        if (!v381) {
            chan_close(chan342);
            pthread_cancel(t363);
            pthread_join(t363, NULL);
        }
    }
    chan_close(chan342);
    chan_close(chan362);
    return NULL;
}
chan_t chan382;
void *thread_t383(void *unused)
{
    while (1) {
        uint32_t v384;
        bool v386;
        uint32_t r387;
        uint32_t v388;
        bool v390;
        uint32_t r391;
        uint32_t v393;
        uint32_t v394;
        uint32_t v395;
        bool v396;
        bool v397;
        
        chan_read(chan362, sizeof(v384), &v384);
        
        float _Complex _a385[v384];
        float _Complex *a385 = _a385;
        
        chan_read(chan362, sizeof(*a385) * (v384 - 0), &a385[0]);
        v386 = chan_last_read_ok(chan362);
        r387 = v384;
        v388 = r387;
        
        float _Complex _a389[v388];
        float _Complex *a389 = _a389;
        
        memcpy(a389, a385, v388 * sizeof(float _Complex));
        v390 = chan_last_read_ok(chan362);
        if (!v390) {
            chan_close(chan382);
            pthread_cancel(t383);
            pthread_join(t383, NULL);
        }
        r391 = v388;
        
        float _Complex _a392[v388];
        float _Complex *a392 = _a392;
        
        for (v393 = 0; v393 < v388; v393++) {
            a392[v393] = !((v393 & 512) == 0) ? exp(I * (FELD_PI *
                                                         (float) (v393 & 511) /
                                                         512.0)) * (a389[v393 ^
                                                                         512] -
                                                                    a389[v393]) : a389[v393] +
                a389[v393 ^ 512];
        }
        v394 = r391;
        v395 = v394;
        v396 = chan_write(chan382, sizeof(v395), &v395);
        v397 = chan_write(chan382, sizeof(*a392) * (v394 - 0), &a392[0]);
        if (!v397) {
            chan_close(chan362);
            pthread_cancel(t383);
            pthread_join(t383, NULL);
        }
    }
    chan_close(chan362);
    chan_close(chan382);
    return NULL;
}
chan_t chan398;
void *thread_t399(void *unused)
{
    while (1) {
        uint32_t v400;
        bool v402;
        uint32_t r403;
        uint32_t v404;
        bool v406;
        uint32_t r407;
        uint32_t v409;
        uint32_t v410;
        uint32_t v411;
        bool v412;
        bool v413;
        
        chan_read(chan382, sizeof(v400), &v400);
        
        float _Complex _a401[v400];
        float _Complex *a401 = _a401;
        
        chan_read(chan382, sizeof(*a401) * (v400 - 0), &a401[0]);
        v402 = chan_last_read_ok(chan382);
        r403 = v400;
        v404 = r403;
        
        float _Complex _a405[v404];
        float _Complex *a405 = _a405;
        
        memcpy(a405, a401, v404 * sizeof(float _Complex));
        v406 = chan_last_read_ok(chan382);
        if (!v406) {
            chan_close(chan398);
            pthread_cancel(t399);
            pthread_join(t399, NULL);
        }
        r407 = v404;
        
        float _Complex _a408[v404];
        float _Complex *a408 = _a408;
        
        for (v409 = 0; v409 < v404; v409++) {
            a408[v409] = !((v409 & 256) == 0) ? exp(I * (FELD_PI *
                                                         (float) (v409 & 255) /
                                                         256.0)) * (a405[v409 ^
                                                                         256] -
                                                                    a405[v409]) : a405[v409] +
                a405[v409 ^ 256];
        }
        v410 = r407;
        v411 = v410;
        v412 = chan_write(chan398, sizeof(v411), &v411);
        v413 = chan_write(chan398, sizeof(*a408) * (v410 - 0), &a408[0]);
        if (!v413) {
            chan_close(chan382);
            pthread_cancel(t399);
            pthread_join(t399, NULL);
        }
    }
    chan_close(chan382);
    chan_close(chan398);
    return NULL;
}
chan_t chan414;
void *thread_t415(void *unused)
{
    while (1) {
        uint32_t v416;
        bool v418;
        uint32_t r419;
        uint32_t v420;
        bool v422;
        uint32_t r423;
        uint32_t v425;
        uint32_t v426;
        uint32_t v427;
        bool v428;
        bool v429;
        
        chan_read(chan398, sizeof(v416), &v416);
        
        float _Complex _a417[v416];
        float _Complex *a417 = _a417;
        
        chan_read(chan398, sizeof(*a417) * (v416 - 0), &a417[0]);
        v418 = chan_last_read_ok(chan398);
        r419 = v416;
        v420 = r419;
        
        float _Complex _a421[v420];
        float _Complex *a421 = _a421;
        
        memcpy(a421, a417, v420 * sizeof(float _Complex));
        v422 = chan_last_read_ok(chan398);
        if (!v422) {
            chan_close(chan414);
            pthread_cancel(t415);
            pthread_join(t415, NULL);
        }
        r423 = v420;
        
        float _Complex _a424[v420];
        float _Complex *a424 = _a424;
        
        for (v425 = 0; v425 < v420; v425++) {
            a424[v425] = !((v425 & 128) == 0) ? exp(I * (FELD_PI *
                                                         (float) (v425 & 127) /
                                                         128.0)) * (a421[v425 ^
                                                                         128] -
                                                                    a421[v425]) : a421[v425] +
                a421[v425 ^ 128];
        }
        v426 = r423;
        v427 = v426;
        v428 = chan_write(chan414, sizeof(v427), &v427);
        v429 = chan_write(chan414, sizeof(*a424) * (v426 - 0), &a424[0]);
        if (!v429) {
            chan_close(chan398);
            pthread_cancel(t415);
            pthread_join(t415, NULL);
        }
    }
    chan_close(chan398);
    chan_close(chan414);
    return NULL;
}
chan_t chan430;
void *thread_t431(void *unused)
{
    while (1) {
        uint32_t v432;
        bool v434;
        uint32_t r435;
        uint32_t v436;
        bool v438;
        uint32_t r439;
        uint32_t v441;
        uint32_t v442;
        uint32_t v443;
        bool v444;
        bool v445;
        
        chan_read(chan414, sizeof(v432), &v432);
        
        float _Complex _a433[v432];
        float _Complex *a433 = _a433;
        
        chan_read(chan414, sizeof(*a433) * (v432 - 0), &a433[0]);
        v434 = chan_last_read_ok(chan414);
        r435 = v432;
        v436 = r435;
        
        float _Complex _a437[v436];
        float _Complex *a437 = _a437;
        
        memcpy(a437, a433, v436 * sizeof(float _Complex));
        v438 = chan_last_read_ok(chan414);
        if (!v438) {
            chan_close(chan430);
            pthread_cancel(t431);
            pthread_join(t431, NULL);
        }
        r439 = v436;
        
        float _Complex _a440[v436];
        float _Complex *a440 = _a440;
        
        for (v441 = 0; v441 < v436; v441++) {
            a440[v441] = !((v441 & 64) == 0) ? exp(I * (FELD_PI *
                                                        (float) (v441 & 63) /
                                                        64.0)) * (a437[v441 ^
                                                                       64] -
                                                                  a437[v441]) : a437[v441] +
                a437[v441 ^ 64];
        }
        v442 = r439;
        v443 = v442;
        v444 = chan_write(chan430, sizeof(v443), &v443);
        v445 = chan_write(chan430, sizeof(*a440) * (v442 - 0), &a440[0]);
        if (!v445) {
            chan_close(chan414);
            pthread_cancel(t431);
            pthread_join(t431, NULL);
        }
    }
    chan_close(chan414);
    chan_close(chan430);
    return NULL;
}
chan_t chan446;
void *thread_t447(void *unused)
{
    while (1) {
        uint32_t v448;
        bool v450;
        uint32_t r451;
        uint32_t v452;
        bool v454;
        uint32_t r455;
        uint32_t v457;
        uint32_t v458;
        uint32_t v459;
        bool v460;
        bool v461;
        
        chan_read(chan430, sizeof(v448), &v448);
        
        float _Complex _a449[v448];
        float _Complex *a449 = _a449;
        
        chan_read(chan430, sizeof(*a449) * (v448 - 0), &a449[0]);
        v450 = chan_last_read_ok(chan430);
        r451 = v448;
        v452 = r451;
        
        float _Complex _a453[v452];
        float _Complex *a453 = _a453;
        
        memcpy(a453, a449, v452 * sizeof(float _Complex));
        v454 = chan_last_read_ok(chan430);
        if (!v454) {
            chan_close(chan446);
            pthread_cancel(t447);
            pthread_join(t447, NULL);
        }
        r455 = v452;
        
        float _Complex _a456[v452];
        float _Complex *a456 = _a456;
        
        for (v457 = 0; v457 < v452; v457++) {
            a456[v457] = !((v457 & 32) == 0) ? exp(I * (FELD_PI *
                                                        (float) (v457 & 31) /
                                                        32.0)) * (a453[v457 ^
                                                                       32] -
                                                                  a453[v457]) : a453[v457] +
                a453[v457 ^ 32];
        }
        v458 = r455;
        v459 = v458;
        v460 = chan_write(chan446, sizeof(v459), &v459);
        v461 = chan_write(chan446, sizeof(*a456) * (v458 - 0), &a456[0]);
        if (!v461) {
            chan_close(chan430);
            pthread_cancel(t447);
            pthread_join(t447, NULL);
        }
    }
    chan_close(chan430);
    chan_close(chan446);
    return NULL;
}
chan_t chan462;
void *thread_t463(void *unused)
{
    while (1) {
        uint32_t v464;
        bool v466;
        uint32_t r467;
        uint32_t v468;
        bool v470;
        uint32_t r471;
        uint32_t v473;
        uint32_t v474;
        uint32_t v475;
        bool v476;
        bool v477;
        
        chan_read(chan446, sizeof(v464), &v464);
        
        float _Complex _a465[v464];
        float _Complex *a465 = _a465;
        
        chan_read(chan446, sizeof(*a465) * (v464 - 0), &a465[0]);
        v466 = chan_last_read_ok(chan446);
        r467 = v464;
        v468 = r467;
        
        float _Complex _a469[v468];
        float _Complex *a469 = _a469;
        
        memcpy(a469, a465, v468 * sizeof(float _Complex));
        v470 = chan_last_read_ok(chan446);
        if (!v470) {
            chan_close(chan462);
            pthread_cancel(t463);
            pthread_join(t463, NULL);
        }
        r471 = v468;
        
        float _Complex _a472[v468];
        float _Complex *a472 = _a472;
        
        for (v473 = 0; v473 < v468; v473++) {
            a472[v473] = !((v473 & 16) == 0) ? exp(I * (FELD_PI *
                                                        (float) (v473 & 15) /
                                                        16.0)) * (a469[v473 ^
                                                                       16] -
                                                                  a469[v473]) : a469[v473] +
                a469[v473 ^ 16];
        }
        v474 = r471;
        v475 = v474;
        v476 = chan_write(chan462, sizeof(v475), &v475);
        v477 = chan_write(chan462, sizeof(*a472) * (v474 - 0), &a472[0]);
        if (!v477) {
            chan_close(chan446);
            pthread_cancel(t463);
            pthread_join(t463, NULL);
        }
    }
    chan_close(chan446);
    chan_close(chan462);
    return NULL;
}
chan_t chan478;
void *thread_t479(void *unused)
{
    while (1) {
        uint32_t v480;
        bool v482;
        uint32_t r483;
        uint32_t v484;
        bool v486;
        uint32_t r487;
        uint32_t v489;
        uint32_t v490;
        uint32_t v491;
        bool v492;
        bool v493;
        
        chan_read(chan462, sizeof(v480), &v480);
        
        float _Complex _a481[v480];
        float _Complex *a481 = _a481;
        
        chan_read(chan462, sizeof(*a481) * (v480 - 0), &a481[0]);
        v482 = chan_last_read_ok(chan462);
        r483 = v480;
        v484 = r483;
        
        float _Complex _a485[v484];
        float _Complex *a485 = _a485;
        
        memcpy(a485, a481, v484 * sizeof(float _Complex));
        v486 = chan_last_read_ok(chan462);
        if (!v486) {
            chan_close(chan478);
            pthread_cancel(t479);
            pthread_join(t479, NULL);
        }
        r487 = v484;
        
        float _Complex _a488[v484];
        float _Complex *a488 = _a488;
        
        for (v489 = 0; v489 < v484; v489++) {
            a488[v489] = !((v489 & 8) == 0) ? exp(I * (FELD_PI * (float) (v489 &
                                                                          7) /
                                                       8.0)) * (a485[v489 ^ 8] -
                                                                a485[v489]) : a485[v489] +
                a485[v489 ^ 8];
        }
        v490 = r487;
        v491 = v490;
        v492 = chan_write(chan478, sizeof(v491), &v491);
        v493 = chan_write(chan478, sizeof(*a488) * (v490 - 0), &a488[0]);
        if (!v493) {
            chan_close(chan462);
            pthread_cancel(t479);
            pthread_join(t479, NULL);
        }
    }
    chan_close(chan462);
    chan_close(chan478);
    return NULL;
}
chan_t chan494;
void *thread_t495(void *unused)
{
    while (1) {
        uint32_t v496;
        bool v498;
        uint32_t r499;
        uint32_t v500;
        bool v502;
        uint32_t r503;
        uint32_t v505;
        uint32_t v506;
        uint32_t v507;
        bool v508;
        bool v509;
        
        chan_read(chan478, sizeof(v496), &v496);
        
        float _Complex _a497[v496];
        float _Complex *a497 = _a497;
        
        chan_read(chan478, sizeof(*a497) * (v496 - 0), &a497[0]);
        v498 = chan_last_read_ok(chan478);
        r499 = v496;
        v500 = r499;
        
        float _Complex _a501[v500];
        float _Complex *a501 = _a501;
        
        memcpy(a501, a497, v500 * sizeof(float _Complex));
        v502 = chan_last_read_ok(chan478);
        if (!v502) {
            chan_close(chan494);
            pthread_cancel(t495);
            pthread_join(t495, NULL);
        }
        r503 = v500;
        
        float _Complex _a504[v500];
        float _Complex *a504 = _a504;
        
        for (v505 = 0; v505 < v500; v505++) {
            a504[v505] = !((v505 & 4) == 0) ? exp(I * (FELD_PI * (float) (v505 &
                                                                          3) /
                                                       4.0)) * (a501[v505 ^ 4] -
                                                                a501[v505]) : a501[v505] +
                a501[v505 ^ 4];
        }
        v506 = r503;
        v507 = v506;
        v508 = chan_write(chan494, sizeof(v507), &v507);
        v509 = chan_write(chan494, sizeof(*a504) * (v506 - 0), &a504[0]);
        if (!v509) {
            chan_close(chan478);
            pthread_cancel(t495);
            pthread_join(t495, NULL);
        }
    }
    chan_close(chan478);
    chan_close(chan494);
    return NULL;
}
chan_t chan510;
void *thread_t511(void *unused)
{
    while (1) {
        uint32_t v512;
        bool v514;
        uint32_t r515;
        uint32_t v516;
        bool v518;
        uint32_t r519;
        uint32_t v521;
        uint32_t v522;
        uint32_t v523;
        bool v524;
        bool v525;
        
        chan_read(chan494, sizeof(v512), &v512);
        
        float _Complex _a513[v512];
        float _Complex *a513 = _a513;
        
        chan_read(chan494, sizeof(*a513) * (v512 - 0), &a513[0]);
        v514 = chan_last_read_ok(chan494);
        r515 = v512;
        v516 = r515;
        
        float _Complex _a517[v516];
        float _Complex *a517 = _a517;
        
        memcpy(a517, a513, v516 * sizeof(float _Complex));
        v518 = chan_last_read_ok(chan494);
        if (!v518) {
            chan_close(chan510);
            pthread_cancel(t511);
            pthread_join(t511, NULL);
        }
        r519 = v516;
        
        float _Complex _a520[v516];
        float _Complex *a520 = _a520;
        
        for (v521 = 0; v521 < v516; v521++) {
            a520[v521] = !((v521 & 2) == 0) ? exp(I * (FELD_PI * (float) (v521 &
                                                                          1) /
                                                       2.0)) * (a517[v521 ^ 2] -
                                                                a517[v521]) : a517[v521] +
                a517[v521 ^ 2];
        }
        v522 = r519;
        v523 = v522;
        v524 = chan_write(chan510, sizeof(v523), &v523);
        v525 = chan_write(chan510, sizeof(*a520) * (v522 - 0), &a520[0]);
        if (!v525) {
            chan_close(chan494);
            pthread_cancel(t511);
            pthread_join(t511, NULL);
        }
    }
    chan_close(chan494);
    chan_close(chan510);
    return NULL;
}
chan_t chan526;
void *thread_t527(void *unused)
{
    while (1) {
        uint32_t v528;
        bool v530;
        uint32_t r531;
        uint32_t v532;
        bool v534;
        uint32_t r535;
        uint32_t v537;
        uint32_t v538;
        uint32_t v539;
        bool v540;
        bool v541;
        
        chan_read(chan510, sizeof(v528), &v528);
        
        float _Complex _a529[v528];
        float _Complex *a529 = _a529;
        
        chan_read(chan510, sizeof(*a529) * (v528 - 0), &a529[0]);
        v530 = chan_last_read_ok(chan510);
        r531 = v528;
        v532 = r531;
        
        float _Complex _a533[v532];
        float _Complex *a533 = _a533;
        
        memcpy(a533, a529, v532 * sizeof(float _Complex));
        v534 = chan_last_read_ok(chan510);
        if (!v534) {
            chan_close(chan526);
            pthread_cancel(t527);
            pthread_join(t527, NULL);
        }
        r535 = v532;
        
        float _Complex _a536[v532];
        float _Complex *a536 = _a536;
        
        for (v537 = 0; v537 < v532; v537++) {
            a536[v537] = !((v537 & 1) == 0) ? exp(I * (FELD_PI * (float) (v537 &
                                                                          0) /
                                                       1.0)) * (a533[v537 ^ 1] -
                                                                a533[v537]) : a533[v537] +
                a533[v537 ^ 1];
        }
        v538 = r535;
        v539 = v538;
        v540 = chan_write(chan526, sizeof(v539), &v539);
        v541 = chan_write(chan526, sizeof(*a536) * (v538 - 0), &a536[0]);
        if (!v541) {
            chan_close(chan510);
            pthread_cancel(t527);
            pthread_join(t527, NULL);
        }
    }
    chan_close(chan510);
    chan_close(chan526);
    return NULL;
}
chan_t chan542;
void *thread_t543(void *unused)
{
    while (1) {
        uint32_t v544;
        bool v546;
        uint32_t r547;
        uint32_t v548;
        bool v550;
        uint32_t r551;
        uint32_t v553;
        uint32_t v554;
        uint32_t v555;
        bool v556;
        bool v557;
        
        chan_read(chan526, sizeof(v544), &v544);
        
        float _Complex _a545[v544];
        float _Complex *a545 = _a545;
        
        chan_read(chan526, sizeof(*a545) * (v544 - 0), &a545[0]);
        v546 = chan_last_read_ok(chan526);
        r547 = v544;
        v548 = r547;
        
        float _Complex _a549[v548];
        float _Complex *a549 = _a549;
        
        memcpy(a549, a545, v548 * sizeof(float _Complex));
        v550 = chan_last_read_ok(chan526);
        if (!v550) {
            chan_close(chan542);
            pthread_cancel(t543);
            pthread_join(t543, NULL);
        }
        r551 = v548;
        
        float _Complex _a552[v548];
        float _Complex *a552 = _a552;
        
        for (v553 = 0; v553 < v548; v553++) {
            a552[v553] = a549[(v553 >> 1 >> 1 << 1 | (v553 & 1)) << 1 | (v553 >>
                                                                         1 &
                                                                         1)];
        }
        v554 = r551;
        v555 = v554;
        v556 = chan_write(chan542, sizeof(v555), &v555);
        v557 = chan_write(chan542, sizeof(*a552) * (v554 - 0), &a552[0]);
        if (!v557) {
            chan_close(chan526);
            pthread_cancel(t543);
            pthread_join(t543, NULL);
        }
    }
    chan_close(chan526);
    chan_close(chan542);
    return NULL;
}
chan_t chan558;
void *thread_t559(void *unused)
{
    while (1) {
        uint32_t v560;
        bool v562;
        uint32_t r563;
        uint32_t v564;
        bool v566;
        uint32_t r567;
        uint32_t v569;
        uint32_t v570;
        uint32_t v571;
        bool v572;
        bool v573;
        
        chan_read(chan542, sizeof(v560), &v560);
        
        float _Complex _a561[v560];
        float _Complex *a561 = _a561;
        
        chan_read(chan542, sizeof(*a561) * (v560 - 0), &a561[0]);
        v562 = chan_last_read_ok(chan542);
        r563 = v560;
        v564 = r563;
        
        float _Complex _a565[v564];
        float _Complex *a565 = _a565;
        
        memcpy(a565, a561, v564 * sizeof(float _Complex));
        v566 = chan_last_read_ok(chan542);
        if (!v566) {
            chan_close(chan558);
            pthread_cancel(t559);
            pthread_join(t559, NULL);
        }
        r567 = v564;
        
        float _Complex _a568[v564];
        float _Complex *a568 = _a568;
        
        for (v569 = 0; v569 < v564; v569++) {
            a568[v569] = a565[(v569 >> 1 >> 2 << 1 | (v569 & 1)) << 2 | (v569 >>
                                                                         1 &
                                                                         3)];
        }
        v570 = r567;
        v571 = v570;
        v572 = chan_write(chan558, sizeof(v571), &v571);
        v573 = chan_write(chan558, sizeof(*a568) * (v570 - 0), &a568[0]);
        if (!v573) {
            chan_close(chan542);
            pthread_cancel(t559);
            pthread_join(t559, NULL);
        }
    }
    chan_close(chan542);
    chan_close(chan558);
    return NULL;
}
chan_t chan574;
void *thread_t575(void *unused)
{
    while (1) {
        uint32_t v576;
        bool v578;
        uint32_t r579;
        uint32_t v580;
        bool v582;
        uint32_t r583;
        uint32_t v585;
        uint32_t v586;
        uint32_t v587;
        bool v588;
        bool v589;
        
        chan_read(chan558, sizeof(v576), &v576);
        
        float _Complex _a577[v576];
        float _Complex *a577 = _a577;
        
        chan_read(chan558, sizeof(*a577) * (v576 - 0), &a577[0]);
        v578 = chan_last_read_ok(chan558);
        r579 = v576;
        v580 = r579;
        
        float _Complex _a581[v580];
        float _Complex *a581 = _a581;
        
        memcpy(a581, a577, v580 * sizeof(float _Complex));
        v582 = chan_last_read_ok(chan558);
        if (!v582) {
            chan_close(chan574);
            pthread_cancel(t575);
            pthread_join(t575, NULL);
        }
        r583 = v580;
        
        float _Complex _a584[v580];
        float _Complex *a584 = _a584;
        
        for (v585 = 0; v585 < v580; v585++) {
            a584[v585] = a581[(v585 >> 1 >> 3 << 1 | (v585 & 1)) << 3 | (v585 >>
                                                                         1 &
                                                                         7)];
        }
        v586 = r583;
        v587 = v586;
        v588 = chan_write(chan574, sizeof(v587), &v587);
        v589 = chan_write(chan574, sizeof(*a584) * (v586 - 0), &a584[0]);
        if (!v589) {
            chan_close(chan558);
            pthread_cancel(t575);
            pthread_join(t575, NULL);
        }
    }
    chan_close(chan558);
    chan_close(chan574);
    return NULL;
}
chan_t chan590;
void *thread_t591(void *unused)
{
    while (1) {
        uint32_t v592;
        bool v594;
        uint32_t r595;
        uint32_t v596;
        bool v598;
        uint32_t r599;
        uint32_t v601;
        uint32_t v602;
        uint32_t v603;
        bool v604;
        bool v605;
        
        chan_read(chan574, sizeof(v592), &v592);
        
        float _Complex _a593[v592];
        float _Complex *a593 = _a593;
        
        chan_read(chan574, sizeof(*a593) * (v592 - 0), &a593[0]);
        v594 = chan_last_read_ok(chan574);
        r595 = v592;
        v596 = r595;
        
        float _Complex _a597[v596];
        float _Complex *a597 = _a597;
        
        memcpy(a597, a593, v596 * sizeof(float _Complex));
        v598 = chan_last_read_ok(chan574);
        if (!v598) {
            chan_close(chan590);
            pthread_cancel(t591);
            pthread_join(t591, NULL);
        }
        r599 = v596;
        
        float _Complex _a600[v596];
        float _Complex *a600 = _a600;
        
        for (v601 = 0; v601 < v596; v601++) {
            a600[v601] = a597[(v601 >> 1 >> 4 << 1 | (v601 & 1)) << 4 | (v601 >>
                                                                         1 &
                                                                         15)];
        }
        v602 = r599;
        v603 = v602;
        v604 = chan_write(chan590, sizeof(v603), &v603);
        v605 = chan_write(chan590, sizeof(*a600) * (v602 - 0), &a600[0]);
        if (!v605) {
            chan_close(chan574);
            pthread_cancel(t591);
            pthread_join(t591, NULL);
        }
    }
    chan_close(chan574);
    chan_close(chan590);
    return NULL;
}
chan_t chan606;
void *thread_t607(void *unused)
{
    while (1) {
        uint32_t v608;
        bool v610;
        uint32_t r611;
        uint32_t v612;
        bool v614;
        uint32_t r615;
        uint32_t v617;
        uint32_t v618;
        uint32_t v619;
        bool v620;
        bool v621;
        
        chan_read(chan590, sizeof(v608), &v608);
        
        float _Complex _a609[v608];
        float _Complex *a609 = _a609;
        
        chan_read(chan590, sizeof(*a609) * (v608 - 0), &a609[0]);
        v610 = chan_last_read_ok(chan590);
        r611 = v608;
        v612 = r611;
        
        float _Complex _a613[v612];
        float _Complex *a613 = _a613;
        
        memcpy(a613, a609, v612 * sizeof(float _Complex));
        v614 = chan_last_read_ok(chan590);
        if (!v614) {
            chan_close(chan606);
            pthread_cancel(t607);
            pthread_join(t607, NULL);
        }
        r615 = v612;
        
        float _Complex _a616[v612];
        float _Complex *a616 = _a616;
        
        for (v617 = 0; v617 < v612; v617++) {
            a616[v617] = a613[(v617 >> 1 >> 5 << 1 | (v617 & 1)) << 5 | (v617 >>
                                                                         1 &
                                                                         31)];
        }
        v618 = r615;
        v619 = v618;
        v620 = chan_write(chan606, sizeof(v619), &v619);
        v621 = chan_write(chan606, sizeof(*a616) * (v618 - 0), &a616[0]);
        if (!v621) {
            chan_close(chan590);
            pthread_cancel(t607);
            pthread_join(t607, NULL);
        }
    }
    chan_close(chan590);
    chan_close(chan606);
    return NULL;
}
chan_t chan622;
void *thread_t623(void *unused)
{
    while (1) {
        uint32_t v624;
        bool v626;
        uint32_t r627;
        uint32_t v628;
        bool v630;
        uint32_t r631;
        uint32_t v633;
        uint32_t v634;
        uint32_t v635;
        bool v636;
        bool v637;
        
        chan_read(chan606, sizeof(v624), &v624);
        
        float _Complex _a625[v624];
        float _Complex *a625 = _a625;
        
        chan_read(chan606, sizeof(*a625) * (v624 - 0), &a625[0]);
        v626 = chan_last_read_ok(chan606);
        r627 = v624;
        v628 = r627;
        
        float _Complex _a629[v628];
        float _Complex *a629 = _a629;
        
        memcpy(a629, a625, v628 * sizeof(float _Complex));
        v630 = chan_last_read_ok(chan606);
        if (!v630) {
            chan_close(chan622);
            pthread_cancel(t623);
            pthread_join(t623, NULL);
        }
        r631 = v628;
        
        float _Complex _a632[v628];
        float _Complex *a632 = _a632;
        
        for (v633 = 0; v633 < v628; v633++) {
            a632[v633] = a629[(v633 >> 1 >> 6 << 1 | (v633 & 1)) << 6 | (v633 >>
                                                                         1 &
                                                                         63)];
        }
        v634 = r631;
        v635 = v634;
        v636 = chan_write(chan622, sizeof(v635), &v635);
        v637 = chan_write(chan622, sizeof(*a632) * (v634 - 0), &a632[0]);
        if (!v637) {
            chan_close(chan606);
            pthread_cancel(t623);
            pthread_join(t623, NULL);
        }
    }
    chan_close(chan606);
    chan_close(chan622);
    return NULL;
}
chan_t chan638;
void *thread_t639(void *unused)
{
    while (1) {
        uint32_t v640;
        bool v642;
        uint32_t r643;
        uint32_t v644;
        bool v646;
        uint32_t r647;
        uint32_t v649;
        uint32_t v650;
        uint32_t v651;
        bool v652;
        bool v653;
        
        chan_read(chan622, sizeof(v640), &v640);
        
        float _Complex _a641[v640];
        float _Complex *a641 = _a641;
        
        chan_read(chan622, sizeof(*a641) * (v640 - 0), &a641[0]);
        v642 = chan_last_read_ok(chan622);
        r643 = v640;
        v644 = r643;
        
        float _Complex _a645[v644];
        float _Complex *a645 = _a645;
        
        memcpy(a645, a641, v644 * sizeof(float _Complex));
        v646 = chan_last_read_ok(chan622);
        if (!v646) {
            chan_close(chan638);
            pthread_cancel(t639);
            pthread_join(t639, NULL);
        }
        r647 = v644;
        
        float _Complex _a648[v644];
        float _Complex *a648 = _a648;
        
        for (v649 = 0; v649 < v644; v649++) {
            a648[v649] = a645[(v649 >> 1 >> 7 << 1 | (v649 & 1)) << 7 | (v649 >>
                                                                         1 &
                                                                         127)];
        }
        v650 = r647;
        v651 = v650;
        v652 = chan_write(chan638, sizeof(v651), &v651);
        v653 = chan_write(chan638, sizeof(*a648) * (v650 - 0), &a648[0]);
        if (!v653) {
            chan_close(chan622);
            pthread_cancel(t639);
            pthread_join(t639, NULL);
        }
    }
    chan_close(chan622);
    chan_close(chan638);
    return NULL;
}
chan_t chan654;
void *thread_t655(void *unused)
{
    while (1) {
        uint32_t v656;
        bool v658;
        uint32_t r659;
        uint32_t v660;
        bool v662;
        uint32_t r663;
        uint32_t v665;
        uint32_t v666;
        uint32_t v667;
        bool v668;
        bool v669;
        
        chan_read(chan638, sizeof(v656), &v656);
        
        float _Complex _a657[v656];
        float _Complex *a657 = _a657;
        
        chan_read(chan638, sizeof(*a657) * (v656 - 0), &a657[0]);
        v658 = chan_last_read_ok(chan638);
        r659 = v656;
        v660 = r659;
        
        float _Complex _a661[v660];
        float _Complex *a661 = _a661;
        
        memcpy(a661, a657, v660 * sizeof(float _Complex));
        v662 = chan_last_read_ok(chan638);
        if (!v662) {
            chan_close(chan654);
            pthread_cancel(t655);
            pthread_join(t655, NULL);
        }
        r663 = v660;
        
        float _Complex _a664[v660];
        float _Complex *a664 = _a664;
        
        for (v665 = 0; v665 < v660; v665++) {
            a664[v665] = a661[(v665 >> 1 >> 8 << 1 | (v665 & 1)) << 8 | (v665 >>
                                                                         1 &
                                                                         255)];
        }
        v666 = r663;
        v667 = v666;
        v668 = chan_write(chan654, sizeof(v667), &v667);
        v669 = chan_write(chan654, sizeof(*a664) * (v666 - 0), &a664[0]);
        if (!v669) {
            chan_close(chan638);
            pthread_cancel(t655);
            pthread_join(t655, NULL);
        }
    }
    chan_close(chan638);
    chan_close(chan654);
    return NULL;
}
chan_t chan670;
void *thread_t671(void *unused)
{
    while (1) {
        uint32_t v672;
        bool v674;
        uint32_t r675;
        uint32_t v676;
        bool v678;
        uint32_t r679;
        uint32_t v681;
        uint32_t v682;
        uint32_t v683;
        bool v684;
        bool v685;
        
        chan_read(chan654, sizeof(v672), &v672);
        
        float _Complex _a673[v672];
        float _Complex *a673 = _a673;
        
        chan_read(chan654, sizeof(*a673) * (v672 - 0), &a673[0]);
        v674 = chan_last_read_ok(chan654);
        r675 = v672;
        v676 = r675;
        
        float _Complex _a677[v676];
        float _Complex *a677 = _a677;
        
        memcpy(a677, a673, v676 * sizeof(float _Complex));
        v678 = chan_last_read_ok(chan654);
        if (!v678) {
            chan_close(chan670);
            pthread_cancel(t671);
            pthread_join(t671, NULL);
        }
        r679 = v676;
        
        float _Complex _a680[v676];
        float _Complex *a680 = _a680;
        
        for (v681 = 0; v681 < v676; v681++) {
            a680[v681] = a677[(v681 >> 1 >> 9 << 1 | (v681 & 1)) << 9 | (v681 >>
                                                                         1 &
                                                                         511)];
        }
        v682 = r679;
        v683 = v682;
        v684 = chan_write(chan670, sizeof(v683), &v683);
        v685 = chan_write(chan670, sizeof(*a680) * (v682 - 0), &a680[0]);
        if (!v685) {
            chan_close(chan654);
            pthread_cancel(t671);
            pthread_join(t671, NULL);
        }
    }
    chan_close(chan654);
    chan_close(chan670);
    return NULL;
}
chan_t chan686;
void *thread_t687(void *unused)
{
    while (1) {
        uint32_t v688;
        bool v690;
        uint32_t r691;
        uint32_t v692;
        bool v694;
        uint32_t r695;
        uint32_t v697;
        uint32_t v698;
        uint32_t v699;
        bool v700;
        bool v701;
        
        chan_read(chan670, sizeof(v688), &v688);
        
        float _Complex _a689[v688];
        float _Complex *a689 = _a689;
        
        chan_read(chan670, sizeof(*a689) * (v688 - 0), &a689[0]);
        v690 = chan_last_read_ok(chan670);
        r691 = v688;
        v692 = r691;
        
        float _Complex _a693[v692];
        float _Complex *a693 = _a693;
        
        memcpy(a693, a689, v692 * sizeof(float _Complex));
        v694 = chan_last_read_ok(chan670);
        if (!v694) {
            chan_close(chan686);
            pthread_cancel(t687);
            pthread_join(t687, NULL);
        }
        r695 = v692 <= 1024 ? v692 : 1024;
        
        float _a696[v692 <= 1024 ? v692 : 1024];
        float *a696 = _a696;
        
        for (v697 = 0; v697 < (v692 <= 1024 ? v692 : 1024); v697++) {
            a696[v697] = creal(a693[v697]) / 4096.0 * (-(0.5 * cos(2.0 *
                                                         FELD_PI *
                                                         (float) v697 /
                                                         1024.0)) + 0.5);
        }
        v698 = r695;
        v699 = v698;
        v700 = chan_write(chan686, sizeof(v699), &v699);
        v701 = chan_write(chan686, sizeof(*a696) * (v698 - 0), &a696[0]);
        if (!v701) {
            chan_close(chan670);
            pthread_cancel(t687);
            pthread_join(t687, NULL);
        }
    }
    chan_close(chan670);
    chan_close(chan686);
    return NULL;
}
void *thread_t702(void *unused)
{
    while (1) {
        uint32_t v703;
        bool v705;
        uint32_t r706;
        uint32_t v707;
        bool v709;
        uint32_t v711;
        bool v712;
        
        chan_read(chan686, sizeof(v703), &v703);
        
        float _a704[v703];
        float *a704 = _a704;
        
        chan_read(chan686, sizeof(*a704) * (v703 - 0), &a704[0]);
        v705 = chan_last_read_ok(chan686);
        r706 = v703;
        v707 = r706;
        
        float _a708[v707];
        float *a708 = _a708;
        
        memcpy(a708, a704, v707 * sizeof(float));
        v709 = chan_last_read_ok(chan686);
        if (!v709) {
            pthread_cancel(t702);
            pthread_join(t702, NULL);
        }
        
        float _a710[v707];
        float *a710 = _a710;
        
        for (v711 = 0; v711 < v707; v711++) {
            a710[v711] = a708[v711];
        }
        v712 = emit_samples(a710);
        if (!v712) {
            chan_close(chan686);
            pthread_cancel(t702);
            pthread_join(t702, NULL);
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
    chan321 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t322, NULL, thread_t322, NULL);
    chan342 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t343, NULL, thread_t343, NULL);
    chan362 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t363, NULL, thread_t363, NULL);
    chan382 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t383, NULL, thread_t383, NULL);
    chan398 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t399, NULL, thread_t399, NULL);
    chan414 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t415, NULL, thread_t415, NULL);
    chan430 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t431, NULL, thread_t431, NULL);
    chan446 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t447, NULL, thread_t447, NULL);
    chan462 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t463, NULL, thread_t463, NULL);
    chan478 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t479, NULL, thread_t479, NULL);
    chan494 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t495, NULL, thread_t495, NULL);
    chan510 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t511, NULL, thread_t511, NULL);
    chan526 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t527, NULL, thread_t527, NULL);
    chan542 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t543, NULL, thread_t543, NULL);
    chan558 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t559, NULL, thread_t559, NULL);
    chan574 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t575, NULL, thread_t575, NULL);
    chan590 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t591, NULL, thread_t591, NULL);
    chan606 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t607, NULL, thread_t607, NULL);
    chan622 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t623, NULL, thread_t623, NULL);
    chan638 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t639, NULL, thread_t639, NULL);
    chan654 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t655, NULL, thread_t655, NULL);
    chan670 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 *
                                                     sizeof(float _Complex)));
    pthread_create(&t671, NULL, thread_t671, NULL);
    chan686 = chan_new(10 * sizeof(uint32_t) + 10 * (1024 * sizeof(float)));
    pthread_create(&t687, NULL, thread_t687, NULL);
    pthread_create(&t702, NULL, thread_t702, NULL);
    while (1) {
        float _a713[1024];
        float *a713 = _a713;
        bool v714;
        uint32_t r715;
        float _a716[1024];
        float *a716 = _a716;
        uint32_t v717;
        uint32_t v718;
        uint32_t v719;
        bool v720;
        bool v721;
        
        v714 = receive_samples(a713);
        if (!v714) {
            break;
        }
        r715 = 1024;
        for (v717 = 0; v717 < 1024; v717++) {
            a716[v717] = a713[v717];
        }
        v718 = r715;
        v719 = v718;
        v720 = chan_write(chan0, sizeof(v719), &v719);
        v721 = chan_write(chan0, sizeof(*a716) * (v718 - 0), &a716[0]);
        if (!v721) {
            break;
        }
    }
    chan_close(chan0);
    pthread_join(t702, NULL);
    teardown_queues();
    return 0;
}

