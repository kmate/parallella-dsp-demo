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
int main()
{
    while (1) {
        float _Complex _a0[129];
        float _Complex *a0 = _a0;
        uint32_t r1;
        uint32_t v17;
        uint32_t v18;
        uint32_t r19;
        float _Complex _a20[129];
        float _Complex *a20 = _a20;
        uint32_t v21;
        uint32_t r23;
        float _Complex _a24[129];
        float _Complex *a24 = _a24;
        uint32_t v25;
        uint32_t r26;
        
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
            if (!(v2 < 129))
                break;
            v3 = r1;
            while (1) {
                uint32_t v4;
                uint32_t v5;
                
                v4 = la33[0];
                v5 = la36[0];
                if (!(v4 == v5))
                    break;
            }
            v6 = la33[0];
            v7 = la36[0];
            r8 = 130;
            let9 = r8 + v7 - v6;
            r10 = let9 < r8 ? let9 : let9 - r8;
            let11 = -v3 + 129;
            r12 = let11 <= r10 ? let11 : r10;
            if (v6 + r12 <= r8) {
                core_read_local(la37, a0, v6, v3, v3 + r12 - 1);
            } else {
                uint32_t r13;
                uint32_t r14;
                
                r13 = r8 - v6;
                core_read_local(la37, a0, v6, v3, v3 + r13 - 1);
                r14 = v3 + r13;
                core_read_local(la37, a0, 0, r14, r14 + r12 - r13 - 1);
            }
            let15 = v6 + r12;
            r16 = let15 < r8 ? let15 : let15 - r8;
            la33[0] = r16;
            la34[0] = r16;
            r1 = v3 + r12;
        }
        v17 = la33[0];
        v18 = la36[0];
        if (v17 == v18 && v18 == 129) {
            la33[0] = 0;
            la34[0] = 0;
            la35[0] = 0;
            la36[0] = 0;
        }
        r19 = 129;
        for (v21 = 0; v21 < 129; v21++) {
            float _Complex let22;
            
            let22 = a0[v21];
            a20[(uint32_t) lround((float) v21 * 2.0)] =
                (uint32_t) lround((float) v21 * 2.0) < 129 ? creal(let22) + I *
                (2.0 * cimag(let22)) : 0.0;
        }
        r23 = 129;
        for (v25 = 0; v25 < 129; v25++) {
            a24[v25] = a20[v25];
        }
        r26 = 0;
        while (1) {
            uint32_t v27;
            uint32_t v28;
            uint32_t v32;
            uint32_t v33;
            uint32_t let34;
            uint32_t r35;
            uint32_t r36;
            uint32_t let37;
            uint32_t r38;
            uint32_t let41;
            uint32_t r42;
            
            v27 = r26;
            if (!(v27 < 129))
                break;
            v28 = r26;
            while (1) {
                uint32_t v29;
                uint32_t v30;
                uint32_t let31;
                
                v29 = la39[0];
                v30 = la40[0];
                let31 = v30 + 1;
                if (!((let31 < 130 ? let31 : v30 + 4294967167) == v29))
                    break;
            }
            v32 = la39[0];
            v33 = la40[0];
            let34 = v33 + 130 - v32;
            r35 = let34 < 130 ? let34 : let34 - 130;
            r36 = -r35 + 129;
            let37 = -v28 + 129;
            r38 = let37 <= r36 ? let37 : r36;
            if (v33 + r38 <= 130) {
                core_write_local(la42, a24, v33, v28, v28 + r38 - 1);
            } else {
                uint32_t r39;
                uint32_t r40;
                
                r39 = -v33 + 130;
                core_write_local(la42, a24, v33, v28, v28 + r39 - 1);
                r40 = v28 + r39;
                core_write_local(la42, a24, 0, r40, r40 + (r38 - r39) - 1);
            }
            let41 = v33 + r38;
            r42 = let41 < 130 ? let41 : let41 - 130;
            la40[0] = r42;
            la41[0] = r42;
            r26 = v28 + r38;
        }
    }
    return 0;
}
