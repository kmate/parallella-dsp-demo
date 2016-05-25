#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la100 = (uint32_t *) 12384;
volatile uint32_t *const la101 = (uint32_t *) 2358255632;
volatile float _Complex *const la102 = (float _Complex *) 2358255648;
volatile bool *const la89 = (bool *) 2360356912;
volatile bool *const la90 = (bool *) 2360356928;
volatile uint32_t *const la91 = (uint32_t *) 8192;
volatile uint32_t *const la92 = (uint32_t *) 2360356944;
volatile uint32_t *const la93 = (uint32_t *) 2360356960;
volatile uint32_t *const la94 = (uint32_t *) 8208;
volatile float _Complex *const la95 = (float _Complex *) 8224;
volatile bool *const la96 = (bool *) 12336;
volatile uint32_t *const la99 = (uint32_t *) 12368;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,35");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,10");
int main()
{
    while (1) {
        uint32_t r0;
        float _Complex _a1[512] __attribute__((aligned(16)));
        float _Complex *a1 = _a1;
        bool v2;
        uint32_t v23;
        bool v27;
        bool r28;
        
        r0 = 512;
        v2 = la89[0];
        la90[0] = v2;
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
                
                v4 = la89[0];
                v5 = r3;
                if (!(v4 && v5 < r0))
                    break;
                v6 = r3;
                v7 = la91[0];
                v8 = la94[0];
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
                        core_read_local(la95, a1, v7, v6, v6 + r14 - 1);
                    } else {
                        uint32_t r16;
                        uint32_t r17;
                        
                        r16 = r9 - v7;
                        core_read_local(la95, a1, v7, v6, v6 + r16 - 1);
                        r17 = v6 + r16;
                        core_read_local(la95, a1, 0, r17, r17 + r14 - r16 - 1);
                    }
                    let18 = v7 + r14;
                    let19 = r9;
                    r20 = let18 < let19 ? let18 : let18 - let19;
                    la91[0] = r20;
                    la92[0] = r20;
                    r15 = r14;
                } else {
                    r15 = 0;
                }
                if (!(0 == r15)) {
                    r3 = v6 + r15;
                }
            }
            v21 = la91[0];
            v22 = la94[0];
            if (v21 == v22 && v22 == 512) {
                la91[0] = 0;
                la92[0] = 0;
                la93[0] = 0;
                la94[0] = 0;
            }
        }
        if (!v2) {
            la96[0] = false;
            core_halt();
        }
        for (v23 = 0; v23 < 512; v23++) {
            uint32_t r24;
            
            r24 = v23;
            r24 = (r24 & 2863311530) >> 1 | (r24 & 1431655765) << 1;
            r24 = (r24 & 3435973836) >> 2 | (r24 & 858993459) << 2;
            r24 = (r24 & 4042322160) >> 4 | (r24 & 252645135) << 4;
            r24 = (r24 & 4278255360) >> 8 | (r24 & 16711935) << 8;
            r24 = (r24 >> 16 | r24 << 16) >> 23;
            if (r24 > v23) {
                float _Complex v25;
                float _Complex v26;
                
                v25 = a1[v23];
                v26 = a1[r24];
                a1[v23] = v26;
                a1[r24] = v25;
            }
        }
        v27 = la96[0];
        if (v27) {
            uint32_t r29;
            
            r29 = 0;
            while (1) {
                bool v30;
                uint32_t v31;
                uint32_t v32;
                uint32_t v33;
                uint32_t v34;
                uint32_t r35;
                uint32_t let36;
                uint32_t let37;
                uint32_t r38;
                uint32_t r39;
                uint32_t let40;
                uint32_t r41;
                uint32_t r42;
                
                v30 = la96[0];
                v31 = r29;
                if (!(v30 && v31 < r0))
                    break;
                v32 = r29;
                v33 = la99[0];
                v34 = la100[0];
                r35 = 513;
                let36 = r35 + v34 - v33;
                let37 = r35;
                r38 = let36 < let37 ? let36 : let36 - let37;
                r39 = r35 - r38 - 1;
                let40 = r0 - 1 - v32 + 1;
                r41 = let40 <= r39 ? let40 : r39;
                if (r41 > 0) {
                    uint32_t let45;
                    uint32_t let46;
                    uint32_t r47;
                    
                    if (v34 + r41 <= r35) {
                        core_write_local(la102, a1, v34, v32, v32 + r41 - 1);
                    } else {
                        uint32_t r43;
                        uint32_t r44;
                        
                        r43 = r35 - v34;
                        core_write_local(la102, a1, v34, v32, v32 + r43 - 1);
                        r44 = v32 + r43;
                        core_write_local(la102, a1, 0, r44, r44 + (r41 - r43) -
                                         1);
                    }
                    let45 = v34 + r41;
                    let46 = r35;
                    r47 = let45 < let46 ? let45 : let45 - let46;
                    la100[0] = r47;
                    la101[0] = r47;
                    r42 = r41;
                } else {
                    r42 = 0;
                }
                if (!(0 == r42)) {
                    r29 = v32 + r42;
                }
            }
            r28 = true;
        } else {
            r28 = false;
        }
        if (!r28) {
            la89[0] = false;
            core_halt();
        }
    }
    return 0;
}
