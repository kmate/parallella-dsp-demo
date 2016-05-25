#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile bool *const la40 = (bool *) 2225090608;
volatile bool *const la41 = (bool *) 2225090624;
volatile uint32_t *const la42 = (uint32_t *) 8192;
volatile uint32_t *const la43 = (uint32_t *) 2225090640;
volatile uint32_t *const la44 = (uint32_t *) 2225090656;
volatile uint32_t *const la45 = (uint32_t *) 8208;
volatile float _Complex *const la46 = (float _Complex *) 8224;
volatile bool *const la47 = (bool *) 12336;
volatile uint32_t *const la50 = (uint32_t *) 12368;
volatile uint32_t *const la51 = (uint32_t *) 12384;
volatile uint32_t *const la52 = (uint32_t *) 2222989328;
volatile float _Complex *const la53 = (float _Complex *) 2222989344;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,33");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,9");
#define FELD_PI 3.141592653589793
int main()
{
    uint32_t r0;
    float _a1[257] __attribute__((aligned(16)));
    float *a1 = _a1;
    uint32_t v2;
    
    r0 = 257;
    for (v2 = 0; v2 < 257; v2++) {
        a1[v2] = 0.0;
    }
    while (1) {
        uint32_t r3;
        float _Complex _a4[512] __attribute__((aligned(16)));
        float _Complex *a4 = _a4;
        bool v5;
        uint32_t r26;
        float _Complex _a27[257] __attribute__((aligned(16)));
        float _Complex *a27 = _a27;
        uint32_t v28;
        bool v37;
        bool r38;
        uint32_t v58;
        
        r3 = 512;
        v5 = la40[0];
        la41[0] = v5;
        if (v5) {
            uint32_t r6;
            uint32_t v24;
            uint32_t v25;
            
            r6 = 0;
            while (1) {
                bool v7;
                uint32_t v8;
                uint32_t v9;
                uint32_t v10;
                uint32_t v11;
                uint32_t r12;
                uint32_t let13;
                uint32_t let14;
                uint32_t r15;
                uint32_t let16;
                uint32_t r17;
                uint32_t r18;
                
                v7 = la40[0];
                v8 = r6;
                if (!(v7 && v8 < r3))
                    break;
                v9 = r6;
                v10 = la42[0];
                v11 = la45[0];
                r12 = 513;
                let13 = r12 + v11 - v10;
                let14 = r12;
                r15 = let13 < let14 ? let13 : let13 - let14;
                let16 = r3 - 1 - v9 + 1;
                r17 = let16 <= r15 ? let16 : r15;
                if (r17 > 0) {
                    uint32_t let21;
                    uint32_t let22;
                    uint32_t r23;
                    
                    if (v10 + r17 <= r12) {
                        core_read_local(la46, a4, v10, v9, v9 + r17 - 1);
                    } else {
                        uint32_t r19;
                        uint32_t r20;
                        
                        r19 = r12 - v10;
                        core_read_local(la46, a4, v10, v9, v9 + r19 - 1);
                        r20 = v9 + r19;
                        core_read_local(la46, a4, 0, r20, r20 + r17 - r19 - 1);
                    }
                    let21 = v10 + r17;
                    let22 = r12;
                    r23 = let21 < let22 ? let21 : let21 - let22;
                    la42[0] = r23;
                    la43[0] = r23;
                    r18 = r17;
                } else {
                    r18 = 0;
                }
                if (!(0 == r18)) {
                    r6 = v9 + r18;
                }
            }
            v24 = la42[0];
            v25 = la45[0];
            if (v24 == v25 && v25 == 512) {
                la42[0] = 0;
                la43[0] = 0;
                la44[0] = 0;
                la45[0] = 0;
            }
        }
        if (!v5) {
            la47[0] = false;
            core_halt();
        }
        r26 = 257;
        for (v28 = 0; v28 < 257; v28++) {
            float let29;
            float let30;
            float let31;
            float _Complex let32;
            float let33;
            float let34;
            float let35;
            float let36;
            
            let29 = fabs(creal(a4[v28]));
            let30 = fabs(cimag(a4[v28]));
            let31 = (float) v28;
            let32 = a4[v28];
            let33 = creal(let32);
            let34 = let30 + 1.0e-10;
            let35 = let33 + let34;
            let36 = let33 >= 0.0 ? 0.7853982 - 0.7853982 * ((let33 - let34) /
                                                            let35) : 2.3561945 -
                0.7853982 * (let35 / (let34 - let33));
            a27[v28] = 2.0 * (0.9375 * (let29 >= let30 ? let29 : let30) +
                              0.46875 * (let29 <= let30 ? let29 : let30)) + I *
                ((let31 + 4.0 * ((cimag(let32) < 0.0 ? -let36 : let36) -
                                 a1[v28] - let31 * 1.5707964) / (2.0 *
                                                                 FELD_PI)) *
                 86.13281);
        }
        v37 = la47[0];
        if (v37) {
            uint32_t r39;
            
            r39 = 0;
            while (1) {
                bool v40;
                uint32_t v41;
                uint32_t v42;
                uint32_t v43;
                uint32_t v44;
                uint32_t r45;
                uint32_t let46;
                uint32_t let47;
                uint32_t r48;
                uint32_t r49;
                uint32_t let50;
                uint32_t r51;
                uint32_t r52;
                
                v40 = la47[0];
                v41 = r39;
                if (!(v40 && v41 < r26))
                    break;
                v42 = r39;
                v43 = la50[0];
                v44 = la51[0];
                r45 = 258;
                let46 = r45 + v44 - v43;
                let47 = r45;
                r48 = let46 < let47 ? let46 : let46 - let47;
                r49 = r45 - r48 - 1;
                let50 = r26 - 1 - v42 + 1;
                r51 = let50 <= r49 ? let50 : r49;
                if (r51 > 0) {
                    uint32_t let55;
                    uint32_t let56;
                    uint32_t r57;
                    
                    if (v44 + r51 <= r45) {
                        core_write_local(la53, a27, v44, v42, v42 + r51 - 1);
                    } else {
                        uint32_t r53;
                        uint32_t r54;
                        
                        r53 = r45 - v44;
                        core_write_local(la53, a27, v44, v42, v42 + r53 - 1);
                        r54 = v42 + r53;
                        core_write_local(la53, a27, 0, r54, r54 + (r51 - r53) -
                                         1);
                    }
                    let55 = v44 + r51;
                    let56 = r45;
                    r57 = let55 < let56 ? let55 : let55 - let56;
                    la51[0] = r57;
                    la52[0] = r57;
                    r52 = r51;
                } else {
                    r52 = 0;
                }
                if (!(0 == r52)) {
                    r39 = v42 + r52;
                }
            }
            r38 = true;
        } else {
            r38 = false;
        }
        if (!r38) {
            la40[0] = false;
            core_halt();
        }
        for (v58 = 0; v58 < 257; v58++) {
            float let59;
            float let60;
            float let61;
            float let62;
            float let63;
            
            let59 = cimag(a4[v58]);
            let60 = creal(a4[v58]);
            let61 = fabs(let59) + 1.0e-10;
            let62 = let60 + let61;
            let63 = let60 >= 0.0 ? 0.7853982 - 0.7853982 * ((let60 - let61) /
                                                            let62) : 2.3561945 -
                0.7853982 * (let62 / (let61 - let60));
            a1[v58] = let59 < 0.0 ? -let63 : let63;
        }
    }
    return 0;
}
