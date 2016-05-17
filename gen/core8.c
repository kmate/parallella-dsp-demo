#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la38 = (uint32_t *) 8192;
volatile uint32_t *const la39 = (uint32_t *) 2222993432;
volatile uint32_t *const la40 = (uint32_t *) 2222993436;
volatile uint32_t *const la41 = (uint32_t *) 8196;
volatile float _Complex *const la42 = (float _Complex *) 8200;
volatile uint32_t *const la44 = (uint32_t *) 12312;
volatile uint32_t *const la45 = (uint32_t *) 12316;
volatile uint32_t *const la46 = (uint32_t *) 2291146756;
volatile float _Complex *const la47 = (float _Complex *) 2291146760;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,34");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,8");
#define FELD_PI 3.141592653589793
int main()
{
    uint32_t r0;
    float _a1[513];
    float *a1 = _a1;
    uint32_t v2;
    
    r0 = 513;
    for (v2 = 0; v2 < 513; v2++) {
        a1[v2] = 0.0;
    }
    while (1) {
        float _Complex _a3[513];
        float _Complex *a3 = _a3;
        uint32_t r4;
        uint32_t v21;
        uint32_t v22;
        uint32_t r23;
        uint32_t r24;
        float _Complex _a25[513];
        float _Complex *a25 = _a25;
        uint32_t v26;
        uint32_t v34;
        uint32_t r36;
        float _Complex _a37[1024];
        float _Complex *a37 = _a37;
        uint32_t v38;
        uint32_t r39;
        
        r4 = 0;
        while (1) {
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
            
            v5 = r4;
            if (!(v5 < 513))
                break;
            v6 = r4;
            v7 = la38[0];
            v8 = la41[0];
            r9 = 514;
            let10 = r9 + v8 - v7;
            let11 = r9;
            r12 = let10 < let11 ? let10 : let10 - let11;
            let13 = -v6 + 513;
            r14 = let13 <= r12 ? let13 : r12;
            if (r14 > 0) {
                uint32_t let18;
                uint32_t let19;
                uint32_t r20;
                
                if (v7 + r14 <= r9) {
                    core_read_local(la42, a3, v7, v6, v6 + r14 - 1);
                } else {
                    uint32_t r16;
                    uint32_t r17;
                    
                    r16 = r9 - v7;
                    core_read_local(la42, a3, v7, v6, v6 + r16 - 1);
                    r17 = v6 + r16;
                    core_read_local(la42, a3, 0, r17, r17 + r14 - r16 - 1);
                }
                let18 = v7 + r14;
                let19 = r9;
                r20 = let18 < let19 ? let18 : let18 - let19;
                la38[0] = r20;
                la39[0] = r20;
                r15 = r14;
            } else {
                r15 = 0;
            }
            if (!(0 == r15)) {
                r4 = v6 + r15;
            }
        }
        v21 = la38[0];
        v22 = la41[0];
        if (v21 == v22 && v22 == 513) {
            la38[0] = 0;
            la39[0] = 0;
            la40[0] = 0;
            la41[0] = 0;
        }
        r23 = 513;
        r24 = 513;
        for (v26 = 0; v26 < 513; v26++) {
            float let27;
            float let28;
            float let29;
            float let30;
            float let31;
            float let32;
            float let33;
            
            let27 = creal(a3[v26]);
            let28 = (float) v26;
            let29 = a1[v26] + (2.0 * FELD_PI * ((cimag(a3[v26]) - let28 *
                                                 43.066406) / 43.066406) / 4.0 +
                               let28 * 1.5707964);
            let30 = 2.0 * FELD_PI;
            let31 = 1.5707964 - let29;
            let32 = let29 - let30 * (float) round(let29 / let30 + 0.5);
            let33 = let31 - let30 * (float) round(let31 / let30 + 0.5);
            a25[v26] = let27 * (1.0 + (0.0 + (-0.4999999 + (0.0 +
                                                            (4.1666523e-2 +
                                                             (0.0 +
                                                              (-1.3887971e-3 +
                                                               (0.0 +
                                                                (2.4773424e-5 +
                                                                 (0.0 +
                                                                  (-2.7113379e-7 +
                                                                   (0.0 +
                                                                    (1.736915e-9 +
                                                                     0.0 *
                                                                     let32) *
                                                                    let32) *
                                                                   let32) *
                                                                  let32) *
                                                                 let32) *
                                                                let32) *
                                                               let32) * let32) *
                                                             let32) * let32) *
                                              let32) * let32) * let32) + I *
                (let27 * (1.0 + (0.0 + (-0.4999999 + (0.0 + (4.1666523e-2 +
                                                             (0.0 +
                                                              (-1.3887971e-3 +
                                                               (0.0 +
                                                                (2.4773424e-5 +
                                                                 (0.0 +
                                                                  (-2.7113379e-7 +
                                                                   (0.0 +
                                                                    (1.736915e-9 +
                                                                     0.0 *
                                                                     let33) *
                                                                    let33) *
                                                                   let33) *
                                                                  let33) *
                                                                 let33) *
                                                                let33) *
                                                               let33) * let33) *
                                                             let33) * let33) *
                                        let33) * let33) * let33));
        }
        for (v34 = 0; v34 < 513; v34++) {
            float let35;
            
            let35 = (float) v34;
            a1[v34] = a1[v34] + (2.0 * FELD_PI * ((cimag(a3[v34]) - let35 *
                                                   43.066406) / 43.066406) /
                                 4.0 + let35 * 1.5707964);
        }
        r36 = 1024;
        for (v38 = 0; v38 < 1024; v38++) {
            a37[v38] = v38 <= 513 ? a25[v38] : 0.0;
        }
        r39 = 0;
        while (1) {
            uint32_t v40;
            uint32_t v41;
            uint32_t v42;
            uint32_t v43;
            uint32_t r44;
            uint32_t let45;
            uint32_t let46;
            uint32_t r47;
            uint32_t r48;
            uint32_t let49;
            uint32_t r50;
            uint32_t r51;
            
            v40 = r39;
            if (!(v40 < 1024))
                break;
            v41 = r39;
            v42 = la44[0];
            v43 = la45[0];
            r44 = 1025;
            let45 = r44 + v43 - v42;
            let46 = r44;
            r47 = let45 < let46 ? let45 : let45 - let46;
            r48 = r44 - r47 - 1;
            let49 = -v41 + 1024;
            r50 = let49 <= r48 ? let49 : r48;
            if (r50 > 0) {
                uint32_t let54;
                uint32_t let55;
                uint32_t r56;
                
                if (v43 + r50 <= r44) {
                    core_write_local(la47, a37, v43, v41, v41 + r50 - 1);
                } else {
                    uint32_t r52;
                    uint32_t r53;
                    
                    r52 = r44 - v43;
                    core_write_local(la47, a37, v43, v41, v41 + r52 - 1);
                    r53 = v41 + r52;
                    core_write_local(la47, a37, 0, r53, r53 + (r50 - r52) - 1);
                }
                let54 = v43 + r50;
                let55 = r44;
                r56 = let54 < let55 ? let54 : let54 - let55;
                la45[0] = r56;
                la46[0] = r56;
                r51 = r50;
            } else {
                r51 = 0;
            }
            if (!(0 == r51)) {
                r39 = v41 + r51;
            }
        }
    }
    return 0;
}
