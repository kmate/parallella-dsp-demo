#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la33 = (uint32_t *) 8192;
volatile uint32_t *const la34 = (uint32_t *) 2224042032;
volatile uint32_t *const la35 = (uint32_t *) 2224042048;
volatile uint32_t *const la36 = (uint32_t *) 8208;
volatile float _Complex *const la37 = (float _Complex *) 8224;
volatile uint32_t *const la39 = (uint32_t *) 10288;
volatile uint32_t *const la40 = (uint32_t *) 10304;
volatile uint32_t *const la41 = (uint32_t *) 2290098192;
volatile float _Complex *const la42 = (float _Complex *) 2290098208;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,33");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,8");
int main()
{
    while (1) {
        float _Complex _a0[257] __attribute__((aligned(16)));
        float _Complex *a0 = _a0;
        uint32_t r1;
        uint32_t v18;
        uint32_t v19;
        uint32_t r20;
        float _Complex _a21[] __attribute__((aligned(16))) = {0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0, 0.0,
                                                              0.0, 0.0};
        float _Complex *a21 = _a21;
        uint32_t r22;
        uint32_t v23;
        uint32_t r26;
        
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
            if (!(v2 < 257))
                break;
            v3 = r1;
            v4 = la33[0];
            v5 = la36[0];
            r6 = 258;
            let7 = r6 + v5 - v4;
            let8 = r6;
            r9 = let7 < let8 ? let7 : let7 - let8;
            let10 = -v3 + 257;
            r11 = let10 <= r9 ? let10 : r9;
            if (r11 > 0) {
                uint32_t let15;
                uint32_t let16;
                uint32_t r17;
                
                if (v4 + r11 <= r6) {
                    core_read_local(la37, a0, v4, v3, v3 + r11 - 1);
                } else {
                    uint32_t r13;
                    uint32_t r14;
                    
                    r13 = r6 - v4;
                    core_read_local(la37, a0, v4, v3, v3 + r13 - 1);
                    r14 = v3 + r13;
                    core_read_local(la37, a0, 0, r14, r14 + r11 - r13 - 1);
                }
                let15 = v4 + r11;
                let16 = r6;
                r17 = let15 < let16 ? let15 : let15 - let16;
                la33[0] = r17;
                la34[0] = r17;
                r12 = r11;
            } else {
                r12 = 0;
            }
            if (!(0 == r12)) {
                r1 = v3 + r12;
            }
        }
        v18 = la33[0];
        v19 = la36[0];
        if (v18 == v19 && v19 == 257) {
            la33[0] = 0;
            la34[0] = 0;
            la35[0] = 0;
            la36[0] = 0;
        }
        r20 = 257;
        r22 = 257;
        for (v23 = 0; v23 < 257; v23++) {
            uint32_t r24;
            float _Complex let25;
            
            r24 = (uint32_t) lround((float) v23 * 2.0);
            let25 = a0[v23];
            a21[r24] = r24 < 257 ? creal(let25) + I * (2.0 *
                                                       cimag(let25)) : 0.0;
        }
        r26 = 0;
        while (1) {
            uint32_t v27;
            uint32_t v28;
            uint32_t v29;
            uint32_t v30;
            uint32_t r31;
            uint32_t let32;
            uint32_t let33;
            uint32_t r34;
            uint32_t r35;
            uint32_t let36;
            uint32_t r37;
            uint32_t r38;
            
            v27 = r26;
            if (!(v27 < 257))
                break;
            v28 = r26;
            v29 = la39[0];
            v30 = la40[0];
            r31 = 258;
            let32 = r31 + v30 - v29;
            let33 = r31;
            r34 = let32 < let33 ? let32 : let32 - let33;
            r35 = r31 - r34 - 1;
            let36 = -v28 + 257;
            r37 = let36 <= r35 ? let36 : r35;
            if (r37 > 0) {
                uint32_t let41;
                uint32_t let42;
                uint32_t r43;
                
                if (v30 + r37 <= r31) {
                    core_write_local(la42, a21, v30, v28, v28 + r37 - 1);
                } else {
                    uint32_t r39;
                    uint32_t r40;
                    
                    r39 = r31 - v30;
                    core_write_local(la42, a21, v30, v28, v28 + r39 - 1);
                    r40 = v28 + r39;
                    core_write_local(la42, a21, 0, r40, r40 + (r37 - r39) - 1);
                }
                let41 = v30 + r37;
                let42 = r31;
                r43 = let41 < let42 ? let41 : let41 - let42;
                la40[0] = r43;
                la41[0] = r43;
                r38 = r37;
            } else {
                r38 = 0;
            }
            if (!(0 == r38)) {
                r26 = v28 + r38;
            }
        }
    }
    return 0;
}
