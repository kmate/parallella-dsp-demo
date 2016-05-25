#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la100 = (uint32_t *) 2359308384;
volatile uint32_t *const la101 = (uint32_t *) 8208;
volatile float _Complex *const la102 = (float _Complex *) 8224;
volatile bool *const la103 = (bool *) 12336;
volatile uint32_t *const la106 = (uint32_t *) 12368;
volatile uint32_t *const la107 = (uint32_t *) 12384;
volatile uint32_t *const la108 = (uint32_t *) 2357207056;
volatile float *const la109 = (float *) 2357207072;
volatile bool *const la96 = (bool *) 2359308336;
volatile bool *const la97 = (bool *) 2359308352;
volatile uint32_t *const la98 = (uint32_t *) 8192;
volatile uint32_t *const la99 = (uint32_t *) 2359308368;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,35");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,9");
int main()
{
    while (1) {
        uint32_t r0;
        float _Complex _a1[512] __attribute__((aligned(16)));
        float _Complex *a1 = _a1;
        bool v2;
        uint32_t r23;
        uint32_t v25;
        bool v26;
        bool r27;
        
        r0 = 512;
        v2 = la96[0];
        la97[0] = v2;
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
                
                v4 = la96[0];
                v5 = r3;
                if (!(v4 && v5 < r0))
                    break;
                v6 = r3;
                v7 = la98[0];
                v8 = la101[0];
                r9 = 513;
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
                        core_read_local(la102, a1, v7, v6, v6 + r14 - 1);
                    } else {
                        uint32_t r16;
                        uint32_t r17;
                        
                        r16 = r9 - v7;
                        core_read_local(la102, a1, v7, v6, v6 + r16 - 1);
                        r17 = v6 + r16;
                        core_read_local(la102, a1, 0, r17, r17 + r14 - r16 - 1);
                    }
                    let18 = v7 + r14;
                    let19 = r9;
                    r20 = let18 < let19 ? let18 : let18 - let19;
                    la98[0] = r20;
                    la99[0] = r20;
                    r15 = r14;
                } else {
                    r15 = 0;
                }
                if (!(0 == r15)) {
                    r3 = v6 + r15;
                }
            }
            v21 = la98[0];
            v22 = la101[0];
            if (v21 == v22 && v22 == 512) {
                la98[0] = 0;
                la99[0] = 0;
                la100[0] = 0;
                la101[0] = 0;
            }
        }
        if (!v2) {
            la103[0] = false;
            core_halt();
        }
        r23 = r0;
        
        float _a24[r0] __attribute__((aligned(16)));
        float *a24 = _a24;
        
        for (v25 = 0; v25 < r0; v25++) {
            a24[v25] = creal(a1[v25]) / 2048.0;
        }
        v26 = la103[0];
        if (v26) {
            uint32_t r28;
            
            r28 = 0;
            while (1) {
                bool v29;
                uint32_t v30;
                uint32_t v31;
                uint32_t v32;
                uint32_t v33;
                uint32_t r34;
                uint32_t let35;
                uint32_t let36;
                uint32_t r37;
                uint32_t r38;
                uint32_t let39;
                uint32_t r40;
                uint32_t r41;
                
                v29 = la103[0];
                v30 = r28;
                if (!(v29 && v30 < r23))
                    break;
                v31 = r28;
                v32 = la106[0];
                v33 = la107[0];
                r34 = 513;
                let35 = r34 + v33 - v32;
                let36 = r34;
                r37 = let35 < let36 ? let35 : let35 - let36;
                r38 = r34 - r37 - 1;
                let39 = r23 - 1 - v31 + 1;
                r40 = let39 <= r38 ? let39 : r38;
                if (r40 > 0) {
                    uint32_t let44;
                    uint32_t let45;
                    uint32_t r46;
                    
                    if (v33 + r40 <= r34) {
                        core_write_local(la109, a24, v33, v31, v31 + r40 - 1);
                    } else {
                        uint32_t r42;
                        uint32_t r43;
                        
                        r42 = r34 - v33;
                        core_write_local(la109, a24, v33, v31, v31 + r42 - 1);
                        r43 = v31 + r42;
                        core_write_local(la109, a24, 0, r43, r43 + (r40 - r42) -
                                         1);
                    }
                    let44 = v33 + r40;
                    let45 = r34;
                    r46 = let44 < let45 ? let44 : let44 - let45;
                    la107[0] = r46;
                    la108[0] = r46;
                    r41 = r40;
                } else {
                    r41 = 0;
                }
                if (!(0 == r41)) {
                    r28 = v31 + r41;
                }
            }
            r27 = true;
        } else {
            r27 = false;
        }
        if (!r27) {
            la96[0] = false;
            core_halt();
        }
    }
    return 0;
}
