#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile bool *const la47 = (bool *) 2224042032;
volatile bool *const la48 = (bool *) 2224042048;
volatile uint32_t *const la49 = (uint32_t *) 8192;
volatile uint32_t *const la50 = (uint32_t *) 2224042064;
volatile uint32_t *const la51 = (uint32_t *) 2224042080;
volatile uint32_t *const la52 = (uint32_t *) 8208;
volatile float _Complex *const la53 = (float _Complex *) 8224;
volatile bool *const la54 = (bool *) 10288;
volatile uint32_t *const la57 = (uint32_t *) 10320;
volatile uint32_t *const la58 = (uint32_t *) 10336;
volatile uint32_t *const la59 = (uint32_t *) 2290098192;
volatile float _Complex *const la60 = (float _Complex *) 2290098208;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,33");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,8");
int main()
{
    while (1) {
        uint32_t r0;
        float _Complex _a1[257] __attribute__((aligned(16)));
        float _Complex *a1 = _a1;
        bool v2;
        float _Complex _a23[] __attribute__((aligned(16))) = {0.0, 0.0, 0.0,
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
        float _Complex *a23 = _a23;
        uint32_t r24;
        uint32_t v25;
        bool v28;
        bool r29;
        
        r0 = 257;
        v2 = la47[0];
        la48[0] = v2;
        if (v2) {
            uint32_t r3;
            uint32_t v21;
            uint32_t v22;
            
            r3 = 0;
            while (1) {
                bool v4;
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
                
                v4 = la47[0];
                v5 = r3;
                if (!(v4 && v5 < r0))
                    break;
                v6 = r3;
                v7 = la49[0];
                v8 = la52[0];
                r9 = 258;
                let10 = r9 + v8 - v7;
                let11 = r9;
                r12 = let10 < let11 ? let10 : let10 - let11;
                let13 = r0 - 1 - v6 + 1;
                r14 = let13 <= r12 ? let13 : r12;
                if (r14 > 0) {
                    uint32_t let18;
                    uint32_t let19;
                    uint32_t r20;
                    
                    if (v7 + r14 <= r9) {
                        core_read_local(la53, a1, v7, v6, v6 + r14 - 1);
                    } else {
                        uint32_t r16;
                        uint32_t r17;
                        
                        r16 = r9 - v7;
                        core_read_local(la53, a1, v7, v6, v6 + r16 - 1);
                        r17 = v6 + r16;
                        core_read_local(la53, a1, 0, r17, r17 + r14 - r16 - 1);
                    }
                    let18 = v7 + r14;
                    let19 = r9;
                    r20 = let18 < let19 ? let18 : let18 - let19;
                    la49[0] = r20;
                    la50[0] = r20;
                    r15 = r14;
                } else {
                    r15 = 0;
                }
                if (!(0 == r15)) {
                    r3 = v6 + r15;
                }
            }
            v21 = la49[0];
            v22 = la52[0];
            if (v21 == v22 && v22 == 257) {
                la49[0] = 0;
                la50[0] = 0;
                la51[0] = 0;
                la52[0] = 0;
            }
        }
        if (!v2) {
            la54[0] = false;
            core_halt();
        }
        r24 = 257;
        for (v25 = 0; v25 < 257; v25++) {
            uint32_t r26;
            float _Complex let27;
            
            r26 = (uint32_t) lround((float) v25 * 2.0);
            let27 = a1[v25];
            a23[r26] = r26 < 257 ? creal(let27) + I * (2.0 *
                                                       cimag(let27)) : 0.0;
        }
        v28 = la54[0];
        if (v28) {
            uint32_t r30;
            
            r30 = 0;
            while (1) {
                bool v31;
                uint32_t v32;
                uint32_t v33;
                uint32_t v34;
                uint32_t v35;
                uint32_t r36;
                uint32_t let37;
                uint32_t let38;
                uint32_t r39;
                uint32_t r40;
                uint32_t let41;
                uint32_t r42;
                uint32_t r43;
                
                v31 = la54[0];
                v32 = r30;
                if (!(v31 && v32 < r24))
                    break;
                v33 = r30;
                v34 = la57[0];
                v35 = la58[0];
                r36 = 258;
                let37 = r36 + v35 - v34;
                let38 = r36;
                r39 = let37 < let38 ? let37 : let37 - let38;
                r40 = r36 - r39 - 1;
                let41 = r24 - 1 - v33 + 1;
                r42 = let41 <= r40 ? let41 : r40;
                if (r42 > 0) {
                    uint32_t let46;
                    uint32_t let47;
                    uint32_t r48;
                    
                    if (v35 + r42 <= r36) {
                        core_write_local(la60, a23, v35, v33, v33 + r42 - 1);
                    } else {
                        uint32_t r44;
                        uint32_t r45;
                        
                        r44 = r36 - v35;
                        core_write_local(la60, a23, v35, v33, v33 + r44 - 1);
                        r45 = v33 + r44;
                        core_write_local(la60, a23, 0, r45, r45 + (r42 - r44) -
                                         1);
                    }
                    let46 = v35 + r42;
                    let47 = r36;
                    r48 = let46 < let47 ? let46 : let46 - let47;
                    la58[0] = r48;
                    la59[0] = r48;
                    r43 = r42;
                } else {
                    r43 = 0;
                }
                if (!(0 == r43)) {
                    r30 = v33 + r43;
                }
            }
            r29 = true;
        } else {
            r29 = false;
        }
        if (!r29) {
            la47[0] = false;
            core_halt();
        }
    }
    return 0;
}
