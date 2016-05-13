#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la38 = (uint32_t *) 8192;
volatile uint32_t *const la39 = (uint32_t *) 2222990360;
volatile uint32_t *const la40 = (uint32_t *) 2222990364;
volatile uint32_t *const la41 = (uint32_t *) 8196;
volatile float _Complex *const la42 = (float _Complex *) 8200;
volatile uint32_t *const la44 = (uint32_t *) 9240;
volatile uint32_t *const la45 = (uint32_t *) 9244;
volatile uint32_t *const la46 = (uint32_t *) 2291146756;
volatile float _Complex *const la47 = (float _Complex *) 2291146760;
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
        float _Complex _a3[129];
        float _Complex *a3 = _a3;
        uint32_t r4;
        uint32_t v20;
        uint32_t v21;
        uint32_t r22;
        uint32_t v23;
        uint32_t r25;
        float _Complex _a26[256];
        float _Complex *a26 = _a26;
        uint32_t v27;
        uint32_t r30;
        
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
            if (!(v5 < 129))
                break;
            v6 = r4;
            while (1) {
                uint32_t v7;
                uint32_t v8;
                
                v7 = la38[0];
                v8 = la41[0];
                if (!(v7 == v8))
                    break;
            }
            v9 = la38[0];
            v10 = la41[0];
            r11 = 130;
            let12 = r11 + v10 - v9;
            r13 = let12 < r11 ? let12 : let12 - r11;
            let14 = -v6 + 129;
            r15 = let14 <= r13 ? let14 : r13;
            if (v9 + r15 <= r11) {
                core_read_local(la42, a3, v9, v6, v6 + r15 - 1);
            } else {
                uint32_t r16;
                uint32_t r17;
                
                r16 = r11 - v9;
                core_read_local(la42, a3, v9, v6, v6 + r16 - 1);
                r17 = v6 + r16;
                core_read_local(la42, a3, 0, r17, r17 + r15 - r16 - 1);
            }
            let18 = v9 + r15;
            r19 = let18 < r11 ? let18 : let18 - r11;
            la38[0] = r19;
            la39[0] = r19;
            r4 = v6 + r15;
        }
        v20 = la38[0];
        v21 = la41[0];
        if (v20 == v21 && v21 == 129) {
            la38[0] = 0;
            la39[0] = 0;
            la40[0] = 0;
            la41[0] = 0;
        }
        r22 = 129;
        for (v23 = 0; v23 < 129; v23++) {
            float let24;
            
            let24 = (float) v23;
            a1[v23] = a1[v23] + (2.0 * FELD_PI * ((cimag(a3[v23]) - let24 *
                                                   172.26563) / 172.26563) /
                                 4.0 + let24 * 1.5707964);
        }
        r25 = 256;
        for (v27 = 0; v27 < 256; v27++) {
            float _Complex let28;
            float let29;
            
            let28 = a3[v27];
            let29 = (float) v27;
            a26[v27] = v27 <= 129 ? creal(let28) * exp(I * (a1[v27] + (2.0 *
                                                                       FELD_PI *
                                                                       ((cimag(let28) -
                                                                         let29 *
                                                                         172.26563) /
                                                                        172.26563) /
                                                                       4.0 +
                                                                       let29 *
                                                                       1.5707964))) : 0.0;
        }
        r30 = 0;
        while (1) {
            uint32_t v31;
            uint32_t v32;
            uint32_t v36;
            uint32_t v37;
            uint32_t let38;
            uint32_t r39;
            uint32_t r40;
            uint32_t let41;
            uint32_t r42;
            uint32_t let45;
            uint32_t r46;
            
            v31 = r30;
            if (!(v31 < 256))
                break;
            v32 = r30;
            while (1) {
                uint32_t v33;
                uint32_t v34;
                uint32_t let35;
                
                v33 = la44[0];
                v34 = la45[0];
                let35 = v34 + 1;
                if (!((let35 < 257 ? let35 : v34 + 4294967040) == v33))
                    break;
            }
            v36 = la44[0];
            v37 = la45[0];
            let38 = v37 + 257 - v36;
            r39 = let38 < 257 ? let38 : let38 - 257;
            r40 = -r39 + 256;
            let41 = -v32 + 256;
            r42 = let41 <= r40 ? let41 : r40;
            if (v37 + r42 <= 257) {
                core_write_local(la47, a26, v37, v32, v32 + r42 - 1);
            } else {
                uint32_t r43;
                uint32_t r44;
                
                r43 = -v37 + 257;
                core_write_local(la47, a26, v37, v32, v32 + r43 - 1);
                r44 = v32 + r43;
                core_write_local(la47, a26, 0, r44, r44 + (r42 - r43) - 1);
            }
            let45 = v37 + r42;
            r46 = let45 < 257 ? let45 : let45 - 257;
            la45[0] = r46;
            la46[0] = r46;
            r30 = v32 + r42;
        }
    }
    return 0;
}
