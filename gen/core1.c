#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la10 = (uint32_t *) 10260;
volatile uint32_t *const la11 = (uint32_t *) 2157977604;
volatile float _Complex *const la12 = (float _Complex *) 2157977608;
volatile uint32_t *const la3 = (uint32_t *) 8192;
volatile uint32_t *const la4 = (uint32_t *) 2155880456;
volatile uint32_t *const la5 = (uint32_t *) 2155880460;
volatile uint32_t *const la6 = (uint32_t *) 8196;
volatile float _Complex *const la7 = (float _Complex *) 8200;
volatile uint32_t *const la9 = (uint32_t *) 10256;
int main()
{
    while (1) {
        float _Complex _a0[256];
        float _Complex *a0 = _a0;
        uint32_t r1;
        uint32_t v17;
        uint32_t v18;
        uint32_t r19;
        uint32_t r20;
        uint32_t v22;
        float _Complex _a23[] = {1.0, 0.9996988 + -2.4541229e-2 * I,
                                 0.99879545 + -4.9067676e-2 * I, 0.99729043 +
                                 -7.356457e-2 * I, 0.9951847 + -9.801714e-2 * I,
                                 0.99247956 + -0.12241068 * I, 0.9891765 +
                                 -0.14673047 * I, 0.98527765 + -0.1709619 * I,
                                 0.98078525 + -0.19509032 * I, 0.9757021 +
                                 -0.21910124 * I, 0.97003126 + -0.2429802 * I,
                                 0.96377605 + -0.26671278 * I, 0.95694035 +
                                 -0.29028466 * I, 0.94952816 + -0.31368175 * I,
                                 0.94154406 + -0.33688986 * I, 0.9329928 +
                                 -0.35989505 * I, 0.9238795 + -0.38268346 * I,
                                 0.9142097 + -0.40524134 * I, 0.9039893 +
                                 -0.42755508 * I, 0.8932243 + -0.44961134 * I,
                                 0.88192123 + -0.47139674 * I, 0.87008697 +
                                 -0.49289823 * I, 0.8577286 + -0.51410276 * I,
                                 0.8448536 + -0.53499764 * I, 0.8314696 +
                                 -0.55557024 * I, 0.8175848 + -0.5758082 * I,
                                 0.8032075 + -0.5956993 * I, 0.7883464 +
                                 -0.61523163 * I, 0.77301043 + -0.63439333 * I,
                                 0.7572088 + -0.65317285 * I, 0.7409511 +
                                 -0.671559 * I, 0.7242471 + -0.68954057 * I,
                                 0.70710677 + -0.70710677 * I, 0.6895405 +
                                 -0.7242471 * I, 0.6715589 + -0.7409512 * I,
                                 0.6531728 + -0.7572089 * I, 0.6343933 +
                                 -0.77301043 * I, 0.6152316 + -0.7883464 * I,
                                 0.5956993 + -0.8032075 * I, 0.57580817 +
                                 -0.8175848 * I, 0.5555702 + -0.83146966 * I,
                                 0.53499764 + -0.8448536 * I, 0.5141027 +
                                 -0.85772866 * I, 0.4928982 + -0.87008697 * I,
                                 0.47139665 + -0.8819213 * I, 0.4496113 +
                                 -0.8932243 * I, 0.4275551 + -0.9039893 * I,
                                 0.40524128 + -0.9142098 * I, 0.38268343 +
                                 -0.9238795 * I, 0.35989496 + -0.9329928 * I,
                                 0.33688983 + -0.94154406 * I, 0.31368166 +
                                 -0.9495282 * I, 0.29028463 + -0.95694035 * I,
                                 0.26671275 + -0.96377605 * I, 0.24298012 +
                                 -0.97003126 * I, 0.21910122 + -0.9757021 * I,
                                 0.19509023 + -0.9807853 * I, 0.17096186 +
                                 -0.98527765 * I, 0.1467305 + -0.9891765 * I,
                                 0.122410625 + -0.99247956 * I, 9.8017134e-2 +
                                 -0.9951847 * I, 7.356449e-2 + -0.99729043 * I,
                                 4.906765e-2 + -0.99879545 * I, 2.4541136e-2 +
                                 -0.9996988 * I, -4.371139e-8 + -1.0 * I,
                                 -2.4541223e-2 + -0.9996988 * I, -4.906774e-2 +
                                 -0.99879545 * I, -7.3564574e-2 + -0.99729043 *
                                 I, -9.801722e-2 + -0.9951847 * I, -0.12241071 +
                                 -0.9924795 * I, -0.14673057 + -0.9891765 * I,
                                 -0.17096195 + -0.98527765 * I, -0.19509032 +
                                 -0.98078525 * I, -0.21910131 + -0.9757021 * I,
                                 -0.2429802 + -0.97003126 * I, -0.26671284 +
                                 -0.96377605 * I, -0.29028472 + -0.9569403 * I,
                                 -0.31368172 + -0.94952816 * I, -0.33688992 +
                                 -0.94154406 * I, -0.35989505 + -0.9329928 * I,
                                 -0.38268352 + -0.9238795 * I, -0.40524134 +
                                 -0.9142097 * I, -0.42755508 + -0.9039893 * I,
                                 -0.44961137 + -0.8932243 * I, -0.47139683 +
                                 -0.88192123 * I, -0.49289817 + -0.870087 * I,
                                 -0.51410276 + -0.8577286 * I, -0.5349977 +
                                 -0.8448535 * I, -0.55557036 + -0.83146954 * I,
                                 -0.57580817 + -0.8175848 * I, -0.59569937 +
                                 -0.8032075 * I, -0.6152317 + -0.78834635 * I,
                                 -0.6343933 + -0.7730105 * I, -0.65317285 +
                                 -0.7572088 * I, -0.67155904 + -0.74095106 * I,
                                 -0.6895407 + -0.724247 * I, -0.70710677 +
                                 -0.70710677 * I, -0.72424716 + -0.6895405 * I,
                                 -0.74095124 + -0.67155886 * I, -0.7572088 +
                                 -0.65317285 * I, -0.7730105 + -0.6343933 * I,
                                 -0.78834647 + -0.6152315 * I, -0.80320764 +
                                 -0.59569913 * I, -0.8175848 + -0.57580817 * I,
                                 -0.83146966 + -0.5555702 * I, -0.84485364 +
                                 -0.53499746 * I, -0.8577286 + -0.51410276 * I,
                                 -0.870087 + -0.49289814 * I, -0.88192135 +
                                 -0.47139663 * I, -0.8932243 + -0.44961137 * I,
                                 -0.9039893 + -0.42755505 * I, -0.9142098 +
                                 -0.40524122 * I, -0.9238796 + -0.38268328 * I,
                                 -0.9329928 + -0.35989505 * I, -0.9415441 +
                                 -0.3368898 * I, -0.9495282 + -0.3136816 * I,
                                 -0.95694035 + -0.29028472 * I, -0.96377605 +
                                 -0.26671273 * I, -0.97003126 + -0.24298008 * I,
                                 -0.97570217 + -0.21910107 * I, -0.9807853 +
                                 -0.19509031 * I, -0.98527765 + -0.17096181 * I,
                                 -0.9891765 + -0.14673033 * I, -0.9924795 +
                                 -0.1224107 * I, -0.9951847 + -9.80171e-2 * I,
                                 -0.9972905 + -7.356445e-2 * I, -0.99879545 +
                                 -4.9067486e-2 * I, -0.9996988 + -2.454121e-2 *
                                 I};
        float _Complex *a23 = _a23;
        uint32_t v24;
        uint32_t v32;
        uint32_t r40;
        uint32_t v42;
        uint32_t r43;
        
        r1 = 0;
        while (1) {
            uint32_t v2;
            uint32_t v3;
            uint32_t v6;
            uint32_t v7;
            uint32_t r8;
            uint32_t let9;
            uint32_t r10;
            uint32_t let11;
            uint32_t r12;
            uint32_t let15;
            uint32_t r16;
            
            v2 = r1;
            if (!(v2 < 256))
                break;
            v3 = r1;
            while (1) {
                uint32_t v4;
                uint32_t v5;
                
                v4 = la3[0];
                v5 = la6[0];
                if (!(v4 == v5))
                    break;
            }
            v6 = la3[0];
            v7 = la6[0];
            r8 = 257;
            let9 = r8 + v7 - v6;
            r10 = let9 < r8 ? let9 : let9 - r8;
            let11 = -v3 + 256;
            r12 = let11 <= r10 ? let11 : r10;
            if (v6 + r12 <= r8) {
                core_read_local(la7, a0, v6, v3, v3 + r12 - 1);
            } else {
                uint32_t r13;
                uint32_t r14;
                
                r13 = r8 - v6;
                core_read_local(la7, a0, v6, v3, v3 + r13 - 1);
                r14 = v3 + r13;
                core_read_local(la7, a0, 0, r14, r14 + r12 - r13 - 1);
            }
            let15 = v6 + r12;
            r16 = let15 < r8 ? let15 : let15 - r8;
            la3[0] = r16;
            la4[0] = r16;
            r1 = v3 + r12;
        }
        v17 = la3[0];
        v18 = la6[0];
        if (v17 == v18 && v18 == 256) {
            la3[0] = 0;
            la4[0] = 0;
            la5[0] = 0;
            la6[0] = 0;
        }
        r19 = 256;
        r20 = r19;
        
        float _Complex _a21[r19];
        float _Complex *a21 = _a21;
        
        for (v22 = 0; v22 < r19; v22++) {
            a21[v22] = a0[v22];
        }
        for (v24 = 0; v24 < 1; v24++) {
            uint32_t r25;
            uint32_t v26;
            
            r25 = 0;
            for (v26 = 0; v26 < 128; v26++) {
                uint32_t r27;
                uint32_t r28;
                uint32_t v29;
                float _Complex v30;
                float _Complex v31;
                
                r27 = (uint32_t) v24 * 256 + v26;
                r28 = r27 + 128;
                v29 = r25;
                r25 = r25 + 1;
                v30 = a21[r27];
                v31 = a21[r28];
                a21[r27] = v30 + v31;
                a21[r28] = (v30 - v31) * a23[v29];
            }
        }
        for (v32 = 0; v32 < 2; v32++) {
            uint32_t r33;
            uint32_t v34;
            
            r33 = 0;
            for (v34 = 0; v34 < 64; v34++) {
                uint32_t r35;
                uint32_t r36;
                uint32_t v37;
                float _Complex v38;
                float _Complex v39;
                
                r35 = (uint32_t) v32 * 128 + v34;
                r36 = r35 + 64;
                v37 = r33;
                r33 = r33 + 2;
                v38 = a21[r35];
                v39 = a21[r36];
                a21[r35] = v38 + v39;
                a21[r36] = (v38 - v39) * a23[v37];
            }
        }
        r40 = r19;
        
        float _Complex _a41[r19];
        float _Complex *a41 = _a41;
        
        for (v42 = 0; v42 < r19; v42++) {
            a41[v42] = a21[v42];
        }
        r43 = 0;
        while (1) {
            uint32_t v44;
            uint32_t v45;
            uint32_t v49;
            uint32_t v50;
            uint32_t let51;
            uint32_t r52;
            uint32_t r53;
            uint32_t let54;
            uint32_t r55;
            uint32_t let58;
            uint32_t r59;
            
            v44 = r43;
            if (!(v44 < 256))
                break;
            v45 = r43;
            while (1) {
                uint32_t v46;
                uint32_t v47;
                uint32_t let48;
                
                v46 = la9[0];
                v47 = la10[0];
                let48 = v47 + 1;
                if (!((let48 < 257 ? let48 : v47 + 4294967040) == v46))
                    break;
            }
            v49 = la9[0];
            v50 = la10[0];
            let51 = v50 + 257 - v49;
            r52 = let51 < 257 ? let51 : let51 - 257;
            r53 = -r52 + 256;
            let54 = -v45 + 256;
            r55 = let54 <= r53 ? let54 : r53;
            if (v50 + r55 <= 257) {
                core_write_local(la12, a41, v50, v45, v45 + r55 - 1);
            } else {
                uint32_t r56;
                uint32_t r57;
                
                r56 = -v50 + 257;
                core_write_local(la12, a41, v50, v45, v45 + r56 - 1);
                r57 = v45 + r56;
                core_write_local(la12, a41, 0, r57, r57 + (r55 - r56) - 1);
            }
            let58 = v50 + r55;
            r59 = let58 < 257 ? let58 : let58 - 257;
            la10[0] = r59;
            la11[0] = r59;
            r43 = v45 + r55;
        }
    }
    return 0;
}
