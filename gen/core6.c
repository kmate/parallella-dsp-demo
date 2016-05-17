#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la23 = (uint32_t *) 8192;
volatile uint32_t *const la24 = (uint32_t *) 2226137104;
volatile uint32_t *const la25 = (uint32_t *) 2226137108;
volatile uint32_t *const la26 = (uint32_t *) 8196;
volatile float _Complex *const la27 = (float _Complex *) 8200;
volatile uint32_t *const la29 = (uint32_t *) 10256;
volatile uint32_t *const la30 = (uint32_t *) 10260;
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
        float _Complex _a0[256];
        float _Complex *a0 = _a0;
        uint32_t r1;
        uint32_t v18;
        uint32_t v19;
        uint32_t r20;
        uint32_t r21;
        uint32_t v23;
        uint32_t v24;
        uint32_t r28;
        uint32_t v30;
        uint32_t r31;
        
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
            v4 = la23[0];
            v5 = la26[0];
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
        if (v18 == v19 && v19 == 256) {
            la23[0] = 0;
            la24[0] = 0;
            la25[0] = 0;
            la26[0] = 0;
        }
        r20 = 256;
        r21 = r20;
        
        float _Complex _a22[r20];
        float _Complex *a22 = _a22;
        
        for (v23 = 0; v23 < r20; v23++) {
            a22[v23] = a0[v23];
        }
        for (v24 = 0; v24 < 256; v24++) {
            uint32_t r25;
            
            r25 = v24;
            r25 = (r25 & 2863311530) >> 1 | (r25 & 1431655765) << 1;
            r25 = (r25 & 3435973836) >> 2 | (r25 & 858993459) << 2;
            r25 = (r25 & 4042322160) >> 4 | (r25 & 252645135) << 4;
            r25 = (r25 & 4278255360) >> 8 | (r25 & 16711935) << 8;
            r25 = (r25 >> 16 | r25 << 16) >> 24;
            if (r25 > v24) {
                float _Complex v26;
                float _Complex v27;
                
                v26 = a22[v24];
                v27 = a22[r25];
                a22[v24] = v27;
                a22[r25] = v26;
            }
        }
        r28 = r20;
        
        float _Complex _a29[r20];
        float _Complex *a29 = _a29;
        
        for (v30 = 0; v30 < r20; v30++) {
            a29[v30] = a22[v30];
        }
        r31 = 0;
        while (1) {
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
            
            v32 = r31;
            if (!(v32 < 256))
                break;
            v33 = r31;
            v34 = la29[0];
            v35 = la30[0];
            r36 = 257;
            let37 = r36 + v35 - v34;
            let38 = r36;
            r39 = let37 < let38 ? let37 : let37 - let38;
            r40 = r36 - r39 - 1;
            let41 = -v33 + 256;
            r42 = let41 <= r40 ? let41 : r40;
            if (r42 > 0) {
                uint32_t let46;
                uint32_t let47;
                uint32_t r48;
                
                if (v35 + r42 <= r36) {
                    core_write_local(la32, a29, v35, v33, v33 + r42 - 1);
                } else {
                    uint32_t r44;
                    uint32_t r45;
                    
                    r44 = r36 - v35;
                    core_write_local(la32, a29, v35, v33, v33 + r44 - 1);
                    r45 = v33 + r44;
                    core_write_local(la32, a29, 0, r45, r45 + (r42 - r44) - 1);
                }
                let46 = v35 + r42;
                let47 = r36;
                r48 = let46 < let47 ? let46 : let46 - let47;
                la30[0] = r48;
                la31[0] = r48;
                r43 = r42;
            } else {
                r43 = 0;
            }
            if (!(0 == r43)) {
                r31 = v33 + r43;
            }
        }
    }
    return 0;
}
