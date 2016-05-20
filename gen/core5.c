#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la28 = (uint32_t *) 8192;
volatile uint32_t *const la29 = (uint32_t *) 2225090608;
volatile uint32_t *const la30 = (uint32_t *) 2225090624;
volatile uint32_t *const la31 = (uint32_t *) 8208;
volatile float _Complex *const la32 = (float _Complex *) 8224;
volatile uint32_t *const la34 = (uint32_t *) 12336;
volatile uint32_t *const la35 = (uint32_t *) 12352;
volatile uint32_t *const la36 = (uint32_t *) 2222989328;
volatile float _Complex *const la37 = (float _Complex *) 2222989344;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,33");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,9");
#define FELD_PI 3.141592653589793
int main()
{
    uint32_t r0;
    float _a1[257] __attribute__((aligned(16)));
    float *a1 = _a1;
    uint32_t v2;
    
    r0 = 257;
    for (v2 = 0; v2 < 257; v2++) {
        a1[v2] = 0.0;
    }
    while (1) {
        float _Complex _a3[512] __attribute__((aligned(16)));
        float _Complex *a3 = _a3;
        uint32_t r4;
        uint32_t v21;
        uint32_t v22;
        uint32_t r23;
        uint32_t r24;
        float _Complex _a25[257] __attribute__((aligned(16)));
        float _Complex *a25 = _a25;
        uint32_t v26;
        uint32_t r35;
        uint32_t v53;
        
        r4 = 0;
        while (1) {
            uint32_t v5;
            uint32_t v6;
            uint32_t v7;
            uint32_t v8;
            uint32_t r9;
            uint32_t let10;
            uint32_t let11;
            uint32_t r12;
            uint32_t let13;
            uint32_t r14;
            uint32_t r15;
            
            v5 = r4;
            if (!(v5 < 512))
                break;
            v6 = r4;
            v7 = la28[0];
            v8 = la31[0];
            r9 = 513;
            let10 = r9 + v8 - v7;
            let11 = r9;
            r12 = let10 < let11 ? let10 : let10 - let11;
            let13 = -v6 + 512;
            r14 = let13 <= r12 ? let13 : r12;
            if (r14 > 0) {
                uint32_t let18;
                uint32_t let19;
                uint32_t r20;
                
                if (v7 + r14 <= r9) {
                    core_read_local(la32, a3, v7, v6, v6 + r14 - 1);
                } else {
                    uint32_t r16;
                    uint32_t r17;
                    
                    r16 = r9 - v7;
                    core_read_local(la32, a3, v7, v6, v6 + r16 - 1);
                    r17 = v6 + r16;
                    core_read_local(la32, a3, 0, r17, r17 + r14 - r16 - 1);
                }
                let18 = v7 + r14;
                let19 = r9;
                r20 = let18 < let19 ? let18 : let18 - let19;
                la28[0] = r20;
                la29[0] = r20;
                r15 = r14;
            } else {
                r15 = 0;
            }
            if (!(0 == r15)) {
                r4 = v6 + r15;
            }
        }
        v21 = la28[0];
        v22 = la31[0];
        if (v21 == v22 && v22 == 512) {
            la28[0] = 0;
            la29[0] = 0;
            la30[0] = 0;
            la31[0] = 0;
        }
        r23 = 512;
        r24 = 257;
        for (v26 = 0; v26 < 257; v26++) {
            float let27;
            float let28;
            float let29;
            float _Complex let30;
            float let31;
            float let32;
            float let33;
            float let34;
            
            let27 = fabs(creal(a3[v26]));
            let28 = fabs(cimag(a3[v26]));
            let29 = (float) v26;
            let30 = a3[v26];
            let31 = creal(let30);
            let32 = let28 + 1.0e-10;
            let33 = let31 + let32;
            let34 = let31 >= 0.0 ? 0.7853982 - 0.7853982 * ((let31 - let32) /
                                                            let33) : 2.3561945 -
                0.7853982 * (let33 / (let32 - let31));
            a25[v26] = 2.0 * (0.9375 * (let27 >= let28 ? let27 : let28) +
                              0.46875 * (let27 <= let28 ? let27 : let28)) + I *
                ((let29 + 4.0 * ((cimag(let30) < 0.0 ? -let34 : let34) -
                                 a1[v26] - let29 * 1.5707964) / (2.0 *
                                                                 FELD_PI)) *
                 86.13281);
        }
        r35 = 0;
        while (1) {
            uint32_t v36;
            uint32_t v37;
            uint32_t v38;
            uint32_t v39;
            uint32_t r40;
            uint32_t let41;
            uint32_t let42;
            uint32_t r43;
            uint32_t r44;
            uint32_t let45;
            uint32_t r46;
            uint32_t r47;
            
            v36 = r35;
            if (!(v36 < 257))
                break;
            v37 = r35;
            v38 = la34[0];
            v39 = la35[0];
            r40 = 258;
            let41 = r40 + v39 - v38;
            let42 = r40;
            r43 = let41 < let42 ? let41 : let41 - let42;
            r44 = r40 - r43 - 1;
            let45 = -v37 + 257;
            r46 = let45 <= r44 ? let45 : r44;
            if (r46 > 0) {
                uint32_t let50;
                uint32_t let51;
                uint32_t r52;
                
                if (v39 + r46 <= r40) {
                    core_write_local(la37, a25, v39, v37, v37 + r46 - 1);
                } else {
                    uint32_t r48;
                    uint32_t r49;
                    
                    r48 = r40 - v39;
                    core_write_local(la37, a25, v39, v37, v37 + r48 - 1);
                    r49 = v37 + r48;
                    core_write_local(la37, a25, 0, r49, r49 + (r46 - r48) - 1);
                }
                let50 = v39 + r46;
                let51 = r40;
                r52 = let50 < let51 ? let50 : let50 - let51;
                la35[0] = r52;
                la36[0] = r52;
                r47 = r46;
            } else {
                r47 = 0;
            }
            if (!(0 == r47)) {
                r35 = v37 + r47;
            }
        }
        for (v53 = 0; v53 < 257; v53++) {
            float let54;
            float let55;
            float let56;
            float let57;
            float let58;
            
            let54 = cimag(a3[v53]);
            let55 = creal(a3[v53]);
            let56 = fabs(let54) + 1.0e-10;
            let57 = let55 + let56;
            let58 = let55 >= 0.0 ? 0.7853982 - 0.7853982 * ((let55 - let56) /
                                                            let57) : 2.3561945 -
                0.7853982 * (let57 / (let56 - let55));
            a1[v53] = let54 < 0.0 ? -let58 : let58;
        }
    }
    return 0;
}
