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
        uint32_t r34;
        uint32_t v51;
        
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
            float let26;
            float let27;
            float let28;
            float _Complex let29;
            float let30;
            float let31;
            float let32;
            float let33;
            
            let26 = fabs(creal(a3[v25]));
            let27 = fabs(cimag(a3[v25]));
            let28 = (float) v25;
            let29 = a3[v25];
            let30 = creal(let29);
            let31 = let27 + 1.0e-10;
            let32 = let30 + let31;
            let33 = let30 >= 0.0 ? 0.7853982 - 0.7853982 * ((let30 - let31) /
                                                            let32) : 2.3561945 -
                0.7853982 * (let32 / (let31 - let30));
            a24[v25] = 2.0 * (0.9375 * (let26 >= let27 ? let26 : let27) +
                              0.46875 * (let26 <= let27 ? let26 : let27)) + I *
                ((let28 + 4.0 * ((cimag(let29) < 0.0 ? -let33 : let33) -
                                 a1[v25] - let28 * 1.5707964) / (2.0 *
                                                                 FELD_PI)) *
                 172.26563);
        }
        r34 = 0;
        while (1) {
            uint32_t v35;
            uint32_t v36;
            uint32_t v40;
            uint32_t v41;
            uint32_t let42;
            uint32_t r43;
            uint32_t r44;
            uint32_t let45;
            uint32_t r46;
            uint32_t let49;
            uint32_t r50;
            
            v35 = r34;
            if (!(v35 < 129))
                break;
            v36 = r34;
            while (1) {
                uint32_t v37;
                uint32_t v38;
                uint32_t let39;
                
                v37 = la34[0];
                v38 = la35[0];
                let39 = v38 + 1;
                if (!((let39 < 130 ? let39 : v38 + 4294967167) == v37))
                    break;
            }
            v40 = la34[0];
            v41 = la35[0];
            let42 = v41 + 130 - v40;
            r43 = let42 < 130 ? let42 : let42 - 130;
            r44 = -r43 + 129;
            let45 = -v36 + 129;
            r46 = let45 <= r44 ? let45 : r44;
            if (v41 + r46 <= 130) {
                core_write_local(la37, a24, v41, v36, v36 + r46 - 1);
            } else {
                uint32_t r47;
                uint32_t r48;
                
                r47 = -v41 + 130;
                core_write_local(la37, a24, v41, v36, v36 + r47 - 1);
                r48 = v36 + r47;
                core_write_local(la37, a24, 0, r48, r48 + (r46 - r47) - 1);
            }
            let49 = v41 + r46;
            r50 = let49 < 130 ? let49 : let49 - 130;
            la35[0] = r50;
            la36[0] = r50;
            r34 = v36 + r46;
        }
        for (v51 = 0; v51 < 129; v51++) {
            float let52;
            float let53;
            float let54;
            float let55;
            float let56;
            
            let52 = cimag(a3[v51]);
            let53 = creal(a3[v51]);
            let54 = fabs(let52) + 1.0e-10;
            let55 = let53 + let54;
            let56 = let53 >= 0.0 ? 0.7853982 - 0.7853982 * ((let53 - let54) /
                                                            let55) : 2.3561945 -
                0.7853982 * (let55 / (let54 - let53));
            a1[v51] = let52 < 0.0 ? -let56 : let56;
        }
    }
    return 0;
}
