#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la58 = (uint32_t *) 8192;
volatile uint32_t *const la59 = (uint32_t *) 2293245968;
volatile uint32_t *const la60 = (uint32_t *) 2293245972;
volatile uint32_t *const la61 = (uint32_t *) 8196;
volatile float _Complex *const la62 = (float _Complex *) 8200;
volatile uint32_t *const la64 = (uint32_t *) 10256;
volatile uint32_t *const la65 = (uint32_t *) 10260;
volatile uint32_t *const la66 = (uint32_t *) 2359304196;
volatile float _Complex *const la67 = (float _Complex *) 2359304200;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,35");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,11");
int main()
{
    while (1) {
        float _Complex _a0[256];
        float _Complex *a0 = _a0;
        uint32_t r1;
        uint32_t v18;
        uint32_t v19;
        uint32_t r20;
        uint32_t r21;
        uint32_t v23;
        float _Complex _a24[] = {1.0, 0.9996988 + 2.4541229e-2 * I, 0.99879545 +
                                 4.9067676e-2 * I, 0.99729043 + 7.356457e-2 * I,
                                 0.9951847 + 9.801714e-2 * I, 0.99247956 +
                                 0.12241068 * I, 0.9891765 + 0.14673047 * I,
                                 0.98527765 + 0.1709619 * I, 0.98078525 +
                                 0.19509032 * I, 0.9757021 + 0.21910124 * I,
                                 0.97003126 + 0.2429802 * I, 0.96377605 +
                                 0.26671278 * I, 0.95694035 + 0.29028466 * I,
                                 0.94952816 + 0.31368175 * I, 0.94154406 +
                                 0.33688986 * I, 0.9329928 + 0.35989505 * I,
                                 0.9238795 + 0.38268346 * I, 0.9142097 +
                                 0.40524134 * I, 0.9039893 + 0.42755508 * I,
                                 0.8932243 + 0.44961134 * I, 0.88192123 +
                                 0.47139674 * I, 0.87008697 + 0.49289823 * I,
                                 0.8577286 + 0.51410276 * I, 0.8448536 +
                                 0.53499764 * I, 0.8314696 + 0.55557024 * I,
                                 0.8175848 + 0.5758082 * I, 0.8032075 +
                                 0.5956993 * I, 0.7883464 + 0.61523163 * I,
                                 0.77301043 + 0.63439333 * I, 0.7572088 +
                                 0.65317285 * I, 0.7409511 + 0.671559 * I,
                                 0.7242471 + 0.68954057 * I, 0.70710677 +
                                 0.70710677 * I, 0.6895405 + 0.7242471 * I,
                                 0.6715589 + 0.7409512 * I, 0.6531728 +
                                 0.7572089 * I, 0.6343933 + 0.77301043 * I,
                                 0.6152316 + 0.7883464 * I, 0.5956993 +
                                 0.8032075 * I, 0.57580817 + 0.8175848 * I,
                                 0.5555702 + 0.83146966 * I, 0.53499764 +
                                 0.8448536 * I, 0.5141027 + 0.85772866 * I,
                                 0.4928982 + 0.87008697 * I, 0.47139665 +
                                 0.8819213 * I, 0.4496113 + 0.8932243 * I,
                                 0.4275551 + 0.9039893 * I, 0.40524128 +
                                 0.9142098 * I, 0.38268343 + 0.9238795 * I,
                                 0.35989496 + 0.9329928 * I, 0.33688983 +
                                 0.94154406 * I, 0.31368166 + 0.9495282 * I,
                                 0.29028463 + 0.95694035 * I, 0.26671275 +
                                 0.96377605 * I, 0.24298012 + 0.97003126 * I,
                                 0.21910122 + 0.9757021 * I, 0.19509023 +
                                 0.9807853 * I, 0.17096186 + 0.98527765 * I,
                                 0.1467305 + 0.9891765 * I, 0.122410625 +
                                 0.99247956 * I, 9.8017134e-2 + 0.9951847 * I,
                                 7.356449e-2 + 0.99729043 * I, 4.906765e-2 +
                                 0.99879545 * I, 2.4541136e-2 + 0.9996988 * I,
                                 -4.371139e-8 + 1.0 * I, -2.4541223e-2 +
                                 0.9996988 * I, -4.906774e-2 + 0.99879545 * I,
                                 -7.3564574e-2 + 0.99729043 * I, -9.801722e-2 +
                                 0.9951847 * I, -0.12241071 + 0.9924795 * I,
                                 -0.14673057 + 0.9891765 * I, -0.17096195 +
                                 0.98527765 * I, -0.19509032 + 0.98078525 * I,
                                 -0.21910131 + 0.9757021 * I, -0.2429802 +
                                 0.97003126 * I, -0.26671284 + 0.96377605 * I,
                                 -0.29028472 + 0.9569403 * I, -0.31368172 +
                                 0.94952816 * I, -0.33688992 + 0.94154406 * I,
                                 -0.35989505 + 0.9329928 * I, -0.38268352 +
                                 0.9238795 * I, -0.40524134 + 0.9142097 * I,
                                 -0.42755508 + 0.9039893 * I, -0.44961137 +
                                 0.8932243 * I, -0.47139683 + 0.88192123 * I,
                                 -0.49289817 + 0.870087 * I, -0.51410276 +
                                 0.8577286 * I, -0.5349977 + 0.8448535 * I,
                                 -0.55557036 + 0.83146954 * I, -0.57580817 +
                                 0.8175848 * I, -0.59569937 + 0.8032075 * I,
                                 -0.6152317 + 0.78834635 * I, -0.6343933 +
                                 0.7730105 * I, -0.65317285 + 0.7572088 * I,
                                 -0.67155904 + 0.74095106 * I, -0.6895407 +
                                 0.724247 * I, -0.70710677 + 0.70710677 * I,
                                 -0.72424716 + 0.6895405 * I, -0.74095124 +
                                 0.67155886 * I, -0.7572088 + 0.65317285 * I,
                                 -0.7730105 + 0.6343933 * I, -0.78834647 +
                                 0.6152315 * I, -0.80320764 + 0.59569913 * I,
                                 -0.8175848 + 0.57580817 * I, -0.83146966 +
                                 0.5555702 * I, -0.84485364 + 0.53499746 * I,
                                 -0.8577286 + 0.51410276 * I, -0.870087 +
                                 0.49289814 * I, -0.88192135 + 0.47139663 * I,
                                 -0.8932243 + 0.44961137 * I, -0.9039893 +
                                 0.42755505 * I, -0.9142098 + 0.40524122 * I,
                                 -0.9238796 + 0.38268328 * I, -0.9329928 +
                                 0.35989505 * I, -0.9415441 + 0.3368898 * I,
                                 -0.9495282 + 0.3136816 * I, -0.95694035 +
                                 0.29028472 * I, -0.96377605 + 0.26671273 * I,
                                 -0.97003126 + 0.24298008 * I, -0.97570217 +
                                 0.21910107 * I, -0.9807853 + 0.19509031 * I,
                                 -0.98527765 + 0.17096181 * I, -0.9891765 +
                                 0.14673033 * I, -0.9924795 + 0.1224107 * I,
                                 -0.9951847 + 9.80171e-2 * I, -0.9972905 +
                                 7.356445e-2 * I, -0.99879545 + 4.9067486e-2 *
                                 I, -0.9996988 + 2.454121e-2 * I};
        float _Complex *a24 = _a24;
        uint32_t v25;
        uint32_t v33;
        uint32_t r41;
        uint32_t v43;
        uint32_t r44;
        
        r1 = 0;
        while (1) {
            uint32_t v2;
            uint32_t v3;
            uint32_t v4;
            uint32_t v5;
            uint32_t r6;
            uint32_t let7;
            uint32_t let8;
            uint32_t r9;
            uint32_t let10;
            uint32_t r11;
            uint32_t r12;
            
            v2 = r1;
            if (!(v2 < 256))
                break;
            v3 = r1;
            v4 = la58[0];
            v5 = la61[0];
            r6 = 257;
            let7 = r6 + v5 - v4;
            let8 = r6;
            r9 = let7 < let8 ? let7 : let7 - let8;
            let10 = -v3 + 256;
            r11 = let10 <= r9 ? let10 : r9;
            if (r11 > 0) {
                uint32_t let15;
                uint32_t let16;
                uint32_t r17;
                
                if (v4 + r11 <= r6) {
                    core_read_local(la62, a0, v4, v3, v3 + r11 - 1);
                } else {
                    uint32_t r13;
                    uint32_t r14;
                    
                    r13 = r6 - v4;
                    core_read_local(la62, a0, v4, v3, v3 + r13 - 1);
                    r14 = v3 + r13;
                    core_read_local(la62, a0, 0, r14, r14 + r11 - r13 - 1);
                }
                let15 = v4 + r11;
                let16 = r6;
                r17 = let15 < let16 ? let15 : let15 - let16;
                la58[0] = r17;
                la59[0] = r17;
                r12 = r11;
            } else {
                r12 = 0;
            }
            if (!(0 == r12)) {
                r1 = v3 + r12;
            }
        }
        v18 = la58[0];
        v19 = la61[0];
        if (v18 == v19 && v19 == 256) {
            la58[0] = 0;
            la59[0] = 0;
            la60[0] = 0;
            la61[0] = 0;
        }
        r20 = 256;
        r21 = r20;
        
        float _Complex _a22[r20];
        float _Complex *a22 = _a22;
        
        for (v23 = 0; v23 < r20; v23++) {
            a22[v23] = a0[v23];
        }
        for (v25 = 0; v25 < 64; v25++) {
            uint32_t r26;
            uint32_t v27;
            
            r26 = 0;
            for (v27 = 0; v27 < 2; v27++) {
                uint32_t r28;
                uint32_t r29;
                uint32_t v30;
                float _Complex v31;
                float _Complex v32;
                
                r28 = (uint32_t) v25 * 4 + v27;
                r29 = r28 + 2;
                v30 = r26;
                r26 = r26 + 64;
                v31 = a22[r28];
                v32 = a22[r29];
                a22[r28] = v31 + v32;
                a22[r29] = (v31 - v32) * a24[v30];
            }
        }
        for (v33 = 0; v33 < 128; v33++) {
            uint32_t r34;
            uint32_t v35;
            
            r34 = 0;
            for (v35 = 0; v35 < 1; v35++) {
                uint32_t r36;
                uint32_t r37;
                uint32_t v38;
                float _Complex v39;
                float _Complex v40;
                
                r36 = (uint32_t) v33 * 2 + v35;
                r37 = r36 + 1;
                v38 = r34;
                r34 = r34 + 128;
                v39 = a22[r36];
                v40 = a22[r37];
                a22[r36] = v39 + v40;
                a22[r37] = (v39 - v40) * a24[v38];
            }
        }
        r41 = r20;
        
        float _Complex _a42[r20];
        float _Complex *a42 = _a42;
        
        for (v43 = 0; v43 < r20; v43++) {
            a42[v43] = a22[v43];
        }
        r44 = 0;
        while (1) {
            uint32_t v45;
            uint32_t v46;
            uint32_t v47;
            uint32_t v48;
            uint32_t r49;
            uint32_t let50;
            uint32_t let51;
            uint32_t r52;
            uint32_t r53;
            uint32_t let54;
            uint32_t r55;
            uint32_t r56;
            
            v45 = r44;
            if (!(v45 < 256))
                break;
            v46 = r44;
            v47 = la64[0];
            v48 = la65[0];
            r49 = 257;
            let50 = r49 + v48 - v47;
            let51 = r49;
            r52 = let50 < let51 ? let50 : let50 - let51;
            r53 = r49 - r52 - 1;
            let54 = -v46 + 256;
            r55 = let54 <= r53 ? let54 : r53;
            if (r55 > 0) {
                uint32_t let59;
                uint32_t let60;
                uint32_t r61;
                
                if (v48 + r55 <= r49) {
                    core_write_local(la67, a42, v48, v46, v46 + r55 - 1);
                } else {
                    uint32_t r57;
                    uint32_t r58;
                    
                    r57 = r49 - v48;
                    core_write_local(la67, a42, v48, v46, v46 + r57 - 1);
                    r58 = v46 + r57;
                    core_write_local(la67, a42, 0, r58, r58 + (r55 - r57) - 1);
                }
                let59 = v48 + r55;
                let60 = r49;
                r61 = let59 < let60 ? let59 : let59 - let60;
                la65[0] = r61;
                la66[0] = r61;
                r56 = r55;
            } else {
                r56 = 0;
            }
            if (!(0 == r56)) {
                r44 = v46 + r56;
            }
        }
    }
    return 0;
}
