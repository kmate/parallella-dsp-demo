#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la28 = (uint32_t *) 8192;
volatile uint32_t *const la29 = (uint32_t *) 2225088528;
volatile uint32_t *const la30 = (uint32_t *) 2225088532;
volatile uint32_t *const la31 = (uint32_t *) 8196;
volatile float _Complex *const la32 = (float _Complex *) 8200;
volatile uint32_t *const la34 = (uint32_t *) 10256;
volatile uint32_t *const la35 = (uint32_t *) 10260;
volatile uint32_t *const la36 = (uint32_t *) 2222989316;
volatile float _Complex *const la37 = (float _Complex *) 2222989320;
#define FELD_PI 3.141592653589793
int main()
{
    uint32_t r0;
    float _a1[129];
    float *a1 = _a1;
    uint32_t v2;
    
    r0 = 129;
    for (v2 = 0; v2 < 129; v2++) {
        a1[v2] = 0.0;
    }
    while (1) {
        float _Complex _a3[256];
        float _Complex *a3 = _a3;
        uint32_t r4;
        uint32_t v20;
        uint32_t v21;
        uint32_t r22;
        uint32_t r23;
        float _Complex _a24[129];
        float _Complex *a24 = _a24;
        uint32_t v25;
        uint32_t r28;
        uint32_t v45;
        
        r4 = 0;
        while (1) {
            uint32_t v5;
            uint32_t v6;
            uint32_t v9;
            uint32_t v10;
            uint32_t r11;
            uint32_t let12;
            uint32_t r13;
            uint32_t let14;
            uint32_t r15;
            uint32_t let18;
            uint32_t r19;
            
            v5 = r4;
            if (!(v5 < 256))
                break;
            v6 = r4;
            while (1) {
                uint32_t v7;
                uint32_t v8;
                
                v7 = la28[0];
                v8 = la31[0];
                if (!(v7 == v8))
                    break;
            }
            v9 = la28[0];
            v10 = la31[0];
            r11 = 257;
            let12 = r11 + v10 - v9;
            r13 = let12 < r11 ? let12 : let12 - r11;
            let14 = -v6 + 256;
            r15 = let14 <= r13 ? let14 : r13;
            if (v9 + r15 <= r11) {
                core_read_local(la32, a3, v9, v6, v6 + r15 - 1);
            } else {
                uint32_t r16;
                uint32_t r17;
                
                r16 = r11 - v9;
                core_read_local(la32, a3, v9, v6, v6 + r16 - 1);
                r17 = v6 + r16;
                core_read_local(la32, a3, 0, r17, r17 + r15 - r16 - 1);
            }
            let18 = v9 + r15;
            r19 = let18 < r11 ? let18 : let18 - r11;
            la28[0] = r19;
            la29[0] = r19;
            r4 = v6 + r15;
        }
        v20 = la28[0];
        v21 = la31[0];
        if (v20 == v21 && v21 == 256) {
            la28[0] = 0;
            la29[0] = 0;
            la30[0] = 0;
            la31[0] = 0;
        }
        r22 = 256;
        r23 = 129;
        for (v25 = 0; v25 < 129; v25++) {
            float _Complex let26;
            float let27;
            
            let26 = a3[v25];
            let27 = (float) v25;
            a24[v25] = 2.0 * cabs(let26) + I * ((let27 + 4.0 * (carg(let26) -
                                                                a1[v25] -
                                                                let27 *
                                                                1.5707964) /
                                                 (2.0 * FELD_PI)) * 172.26563);
        }
        r28 = 0;
        while (1) {
            uint32_t v29;
            uint32_t v30;
            uint32_t v34;
            uint32_t v35;
            uint32_t let36;
            uint32_t r37;
            uint32_t r38;
            uint32_t let39;
            uint32_t r40;
            uint32_t let43;
            uint32_t r44;
            
            v29 = r28;
            if (!(v29 < 129))
                break;
            v30 = r28;
            while (1) {
                uint32_t v31;
                uint32_t v32;
                uint32_t let33;
                
                v31 = la34[0];
                v32 = la35[0];
                let33 = v32 + 1;
                if (!((let33 < 130 ? let33 : v32 + 4294967167) == v31))
                    break;
            }
            v34 = la34[0];
            v35 = la35[0];
            let36 = v35 + 130 - v34;
            r37 = let36 < 130 ? let36 : let36 - 130;
            r38 = -r37 + 129;
            let39 = -v30 + 129;
            r40 = let39 <= r38 ? let39 : r38;
            if (v35 + r40 <= 130) {
                core_write_local(la37, a24, v35, v30, v30 + r40 - 1);
            } else {
                uint32_t r41;
                uint32_t r42;
                
                r41 = -v35 + 130;
                core_write_local(la37, a24, v35, v30, v30 + r41 - 1);
                r42 = v30 + r41;
                core_write_local(la37, a24, 0, r42, r42 + (r40 - r41) - 1);
            }
            let43 = v35 + r40;
            r44 = let43 < 130 ? let43 : let43 - 130;
            la35[0] = r44;
            la36[0] = r44;
            r28 = v30 + r40;
        }
        for (v45 = 0; v45 < 129; v45++) {
            a1[v45] = carg(a3[v45]);
        }
    }
    return 0;
}
