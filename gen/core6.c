#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la23 = (uint32_t *) 8192;
volatile uint32_t *const la24 = (uint32_t *) 2226139152;
volatile uint32_t *const la25 = (uint32_t *) 2226139156;
volatile uint32_t *const la26 = (uint32_t *) 8196;
volatile float _Complex *const la27 = (float _Complex *) 8200;
volatile uint32_t *const la29 = (uint32_t *) 12304;
volatile uint32_t *const la30 = (uint32_t *) 12308;
volatile uint32_t *const la31 = (uint32_t *) 2224037892;
volatile float _Complex *const la32 = (float _Complex *) 2224037896;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,33");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,10");
int main()
{
    while (1) {
        float _Complex _a0[512];
        float _Complex *a0 = _a0;
        uint32_t r1;
        uint32_t v18;
        uint32_t v19;
        uint32_t r20;
        uint32_t v21;
        uint32_t r25;
        
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
            v4 = la23[0];
            v5 = la26[0];
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
                    core_read_local(la27, a0, v4, v3, v3 + r11 - 1);
                } else {
                    uint32_t r13;
                    uint32_t r14;
                    
                    r13 = r6 - v4;
                    core_read_local(la27, a0, v4, v3, v3 + r13 - 1);
                    r14 = v3 + r13;
                    core_read_local(la27, a0, 0, r14, r14 + r11 - r13 - 1);
                }
                let15 = v4 + r11;
                let16 = r6;
                r17 = let15 < let16 ? let15 : let15 - let16;
                la23[0] = r17;
                la24[0] = r17;
                r12 = r11;
            } else {
                r12 = 0;
            }
            if (!(0 == r12)) {
                r1 = v3 + r12;
            }
        }
        v18 = la23[0];
        v19 = la26[0];
        if (v18 == v19 && v19 == 512) {
            la23[0] = 0;
            la24[0] = 0;
            la25[0] = 0;
            la26[0] = 0;
        }
        r20 = 512;
        for (v21 = 0; v21 < 512; v21++) {
            uint32_t r22;
            
            r22 = v21;
            r22 = (r22 & 2863311530) >> 1 | (r22 & 1431655765) << 1;
            r22 = (r22 & 3435973836) >> 2 | (r22 & 858993459) << 2;
            r22 = (r22 & 4042322160) >> 4 | (r22 & 252645135) << 4;
            r22 = (r22 & 4278255360) >> 8 | (r22 & 16711935) << 8;
            r22 = (r22 >> 16 | r22 << 16) >> 23;
            if (r22 > v21) {
                float _Complex v23;
                float _Complex v24;
                
                v23 = a0[v21];
                v24 = a0[r22];
                a0[v21] = v24;
                a0[r22] = v23;
            }
        }
        r25 = 0;
        while (1) {
            uint32_t v26;
            uint32_t v27;
            uint32_t v28;
            uint32_t v29;
            uint32_t r30;
            uint32_t let31;
            uint32_t let32;
            uint32_t r33;
            uint32_t r34;
            uint32_t let35;
            uint32_t r36;
            uint32_t r37;
            
            v26 = r25;
            if (!(v26 < 512))
                break;
            v27 = r25;
            v28 = la29[0];
            v29 = la30[0];
            r30 = 513;
            let31 = r30 + v29 - v28;
            let32 = r30;
            r33 = let31 < let32 ? let31 : let31 - let32;
            r34 = r30 - r33 - 1;
            let35 = -v27 + 512;
            r36 = let35 <= r34 ? let35 : r34;
            if (r36 > 0) {
                uint32_t let40;
                uint32_t let41;
                uint32_t r42;
                
                if (v29 + r36 <= r30) {
                    core_write_local(la32, a0, v29, v27, v27 + r36 - 1);
                } else {
                    uint32_t r38;
                    uint32_t r39;
                    
                    r38 = r30 - v29;
                    core_write_local(la32, a0, v29, v27, v27 + r38 - 1);
                    r39 = v27 + r38;
                    core_write_local(la32, a0, 0, r39, r39 + (r36 - r38) - 1);
                }
                let40 = v29 + r36;
                let41 = r30;
                r42 = let40 < let41 ? let40 : let40 - let41;
                la30[0] = r42;
                la31[0] = r42;
                r37 = r36;
            } else {
                r37 = 0;
            }
            if (!(0 == r37)) {
                r25 = v27 + r37;
            }
        }
    }
    return 0;
}
