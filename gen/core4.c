#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la33 = (uint32_t *) 8192;
volatile uint32_t *const la34 = (uint32_t *) 2224039952;
volatile uint32_t *const la35 = (uint32_t *) 2224039956;
volatile uint32_t *const la36 = (uint32_t *) 8196;
volatile float _Complex *const la37 = (float _Complex *) 8200;
volatile uint32_t *const la39 = (uint32_t *) 9240;
volatile uint32_t *const la40 = (uint32_t *) 9244;
volatile uint32_t *const la41 = (uint32_t *) 2290098180;
volatile float _Complex *const la42 = (float _Complex *) 2290098184;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,33");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,8");
int main()
{
    while (1) {
        float _Complex _a0[129];
        float _Complex *a0 = _a0;
        uint32_t r1;
        uint32_t v18;
        uint32_t v19;
        uint32_t r20;
        float _Complex _a21[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
                                 0.0, 0.0, 0.0};
        float _Complex *a21 = _a21;
        uint32_t v22;
        uint32_t r25;
        float _Complex _a26[129];
        float _Complex *a26 = _a26;
        uint32_t v27;
        uint32_t r28;
        
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
            if (!(v2 < 129))
                break;
            v3 = r1;
            v4 = la33[0];
            v5 = la36[0];
            r6 = 130;
            let7 = r6 + v5 - v4;
            let8 = r6;
            r9 = let7 < let8 ? let7 : let7 - let8;
            let10 = -v3 + 129;
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
        if (v18 == v19 && v19 == 129) {
            la33[0] = 0;
            la34[0] = 0;
            la35[0] = 0;
            la36[0] = 0;
        }
        r20 = 129;
        for (v22 = 0; v22 < 129; v22++) {
            uint32_t r23;
            float _Complex let24;
            
            r23 = (uint32_t) lround((float) v22 * 2.0);
            let24 = a0[v22];
            a21[r23] = r23 < 129 ? creal(let24) + I * (2.0 *
                                                       cimag(let24)) : 0.0;
        }
        r25 = 129;
        for (v27 = 0; v27 < 129; v27++) {
            a26[v27] = a21[v27];
        }
        r28 = 0;
        while (1) {
            uint32_t v29;
            uint32_t v30;
            uint32_t v31;
            uint32_t v32;
            uint32_t r33;
            uint32_t let34;
            uint32_t let35;
            uint32_t r36;
            uint32_t r37;
            uint32_t let38;
            uint32_t r39;
            uint32_t r40;
            
            v29 = r28;
            if (!(v29 < 129))
                break;
            v30 = r28;
            v31 = la39[0];
            v32 = la40[0];
            r33 = 130;
            let34 = r33 + v32 - v31;
            let35 = r33;
            r36 = let34 < let35 ? let34 : let34 - let35;
            r37 = r33 - r36 - 1;
            let38 = -v30 + 129;
            r39 = let38 <= r37 ? let38 : r37;
            if (r39 > 0) {
                uint32_t let43;
                uint32_t let44;
                uint32_t r45;
                
                if (v32 + r39 <= r33) {
                    core_write_local(la42, a26, v32, v30, v30 + r39 - 1);
                } else {
                    uint32_t r41;
                    uint32_t r42;
                    
                    r41 = r33 - v32;
                    core_write_local(la42, a26, v32, v30, v30 + r41 - 1);
                    r42 = v30 + r41;
                    core_write_local(la42, a26, 0, r42, r42 + (r39 - r41) - 1);
                }
                let43 = v32 + r39;
                let44 = r33;
                r45 = let43 < let44 ? let43 : let43 - let44;
                la40[0] = r45;
                la41[0] = r45;
                r40 = r39;
            } else {
                r40 = 0;
            }
            if (!(0 == r40)) {
                r28 = v30 + r40;
            }
        }
    }
    return 0;
}
