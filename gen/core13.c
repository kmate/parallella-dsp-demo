#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la68 = (uint32_t *) 8192;
volatile uint32_t *const la69 = (uint32_t *) 2359308304;
volatile uint32_t *const la70 = (uint32_t *) 2359308308;
volatile uint32_t *const la71 = (uint32_t *) 8196;
volatile float _Complex *const la72 = (float _Complex *) 8200;
volatile uint32_t *const la74 = (uint32_t *) 12304;
volatile uint32_t *const la75 = (uint32_t *) 12308;
volatile uint32_t *const la76 = (uint32_t *) 2357207044;
volatile float *const la77 = (float *) 2357207048;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,35");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,9");
int main()
{
    while (1) {
        float _Complex _a0[512];
        float _Complex *a0 = _a0;
        uint32_t r1;
        uint32_t v18;
        uint32_t v19;
        uint32_t r20;
        uint32_t r21;
        uint32_t v23;
        uint32_t r24;
        
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
            if (!(v2 < 512))
                break;
            v3 = r1;
            v4 = la68[0];
            v5 = la71[0];
            r6 = 513;
            let7 = r6 + v5 - v4;
            let8 = r6;
            r9 = let7 < let8 ? let7 : let7 - let8;
            let10 = -v3 + 512;
            r11 = let10 <= r9 ? let10 : r9;
            if (r11 > 0) {
                uint32_t let15;
                uint32_t let16;
                uint32_t r17;
                
                if (v4 + r11 <= r6) {
                    core_read_local(la72, a0, v4, v3, v3 + r11 - 1);
                } else {
                    uint32_t r13;
                    uint32_t r14;
                    
                    r13 = r6 - v4;
                    core_read_local(la72, a0, v4, v3, v3 + r13 - 1);
                    r14 = v3 + r13;
                    core_read_local(la72, a0, 0, r14, r14 + r11 - r13 - 1);
                }
                let15 = v4 + r11;
                let16 = r6;
                r17 = let15 < let16 ? let15 : let15 - let16;
                la68[0] = r17;
                la69[0] = r17;
                r12 = r11;
            } else {
                r12 = 0;
            }
            if (!(0 == r12)) {
                r1 = v3 + r12;
            }
        }
        v18 = la68[0];
        v19 = la71[0];
        if (v18 == v19 && v19 == 512) {
            la68[0] = 0;
            la69[0] = 0;
            la70[0] = 0;
            la71[0] = 0;
        }
        r20 = 512;
        r21 = r20;
        
        float _a22[r20];
        float *a22 = _a22;
        
        for (v23 = 0; v23 < r20; v23++) {
            a22[v23] = creal(a0[v23]) / 2048.0;
        }
        r24 = 0;
        while (1) {
            uint32_t v25;
            uint32_t v26;
            uint32_t v27;
            uint32_t v28;
            uint32_t r29;
            uint32_t let30;
            uint32_t let31;
            uint32_t r32;
            uint32_t r33;
            uint32_t let34;
            uint32_t r35;
            uint32_t r36;
            
            v25 = r24;
            if (!(v25 < 512))
                break;
            v26 = r24;
            v27 = la74[0];
            v28 = la75[0];
            r29 = 513;
            let30 = r29 + v28 - v27;
            let31 = r29;
            r32 = let30 < let31 ? let30 : let30 - let31;
            r33 = r29 - r32 - 1;
            let34 = -v26 + 512;
            r35 = let34 <= r33 ? let34 : r33;
            if (r35 > 0) {
                uint32_t let39;
                uint32_t let40;
                uint32_t r41;
                
                if (v28 + r35 <= r29) {
                    core_write_local(la77, a22, v28, v26, v26 + r35 - 1);
                } else {
                    uint32_t r37;
                    uint32_t r38;
                    
                    r37 = r29 - v28;
                    core_write_local(la77, a22, v28, v26, v26 + r37 - 1);
                    r38 = v26 + r37;
                    core_write_local(la77, a22, 0, r38, r38 + (r35 - r37) - 1);
                }
                let39 = v28 + r35;
                let40 = r29;
                r41 = let39 < let40 ? let39 : let39 - let40;
                la75[0] = r41;
                la76[0] = r41;
                r36 = r35;
            } else {
                r36 = 0;
            }
            if (!(0 == r36)) {
                r24 = v26 + r36;
            }
        }
    }
    return 0;
}
