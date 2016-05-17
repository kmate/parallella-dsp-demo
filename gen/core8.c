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
        uint32_t v21;
        uint32_t v22;
        uint32_t r23;
        uint32_t v24;
        uint32_t r26;
        float _Complex _a27[256];
        float _Complex *a27 = _a27;
        uint32_t v28;
        uint32_t r37;
        
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
            if (!(v5 < 129))
                break;
            v6 = r4;
            v7 = la38[0];
            v8 = la41[0];
            r9 = 130;
            let10 = r9 + v8 - v7;
            let11 = r9;
            r12 = let10 < let11 ? let10 : let10 - let11;
            let13 = -v6 + 129;
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
        if (v21 == v22 && v22 == 129) {
            la38[0] = 0;
            la39[0] = 0;
            la40[0] = 0;
            la41[0] = 0;
        }
        r23 = 129;
        for (v24 = 0; v24 < 129; v24++) {
            float let25;
            
            let25 = (float) v24;
            a1[v24] = a1[v24] + (2.0 * FELD_PI * ((cimag(a3[v24]) - let25 *
                                                   172.26563) / 172.26563) /
                                 4.0 + let25 * 1.5707964);
        }
        r26 = 256;
        for (v28 = 0; v28 < 256; v28++) {
            float let29;
            float let30;
            float let31;
            float let32;
            float let33;
            float _Complex v34;
            
            let29 = creal(a3[v28]);
            let30 = (float) v28;
            let31 = a1[v28] + (2.0 * FELD_PI * ((cimag(a3[v28]) - let30 *
                                                 172.26563) / 172.26563) / 4.0 +
                               let30 * 1.5707964);
            let32 = 2.0 * FELD_PI;
            let33 = 1.5707964 - let31;
            if (v28 <= 129) {
                float let35;
                float let36;
                
                let35 = let31 - let32 * (float) round(let31 / let32 + 0.5);
                let36 = let33 - let32 * (float) round(let33 / let32 + 0.5);
                v34 = let29 * (1.0 + (0.0 + (-0.4999999 + (0.0 + (4.1666523e-2 +
                                                                  (0.0 +
                                                                   (-1.3887971e-3 +
                                                                    (0.0 +
                                                                     (2.4773424e-5 +
                                                                      (0.0 +
                                                                       (-2.7113379e-7 +
                                                                        (0.0 +
                                                                         (1.736915e-9 +
                                                                          0.0 *
                                                                          let35) *
                                                                         let35) *
                                                                        let35) *
                                                                       let35) *
                                                                      let35) *
                                                                     let35) *
                                                                    let35) *
                                                                   let35) *
                                                                  let35) *
                                                           let35) * let35) *
                                      let35) * let35) + I * (let29 * (1.0 +
                                                                      (0.0 +
                                                                       (-0.4999999 +
                                                                        (0.0 +
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
                                                                                  let36) *
                                                                                 let36) *
                                                                                let36) *
                                                                               let36) *
                                                                              let36) *
                                                                             let36) *
                                                                            let36) *
                                                                           let36) *
                                                                          let36) *
                                                                         let36) *
                                                                        let36) *
                                                                       let36) *
                                                                      let36));
            } else {
                v34 = 0.0;
            }
            a27[v28] = v34;
        }
        r37 = 0;
        while (1) {
            uint32_t v38;
            uint32_t v39;
            uint32_t v40;
            uint32_t v41;
            uint32_t r42;
            uint32_t let43;
            uint32_t let44;
            uint32_t r45;
            uint32_t r46;
            uint32_t let47;
            uint32_t r48;
            uint32_t r49;
            
            v38 = r37;
            if (!(v38 < 256))
                break;
            v39 = r37;
            v40 = la44[0];
            v41 = la45[0];
            r42 = 257;
            let43 = r42 + v41 - v40;
            let44 = r42;
            r45 = let43 < let44 ? let43 : let43 - let44;
            r46 = r42 - r45 - 1;
            let47 = -v39 + 256;
            r48 = let47 <= r46 ? let47 : r46;
            if (r48 > 0) {
                uint32_t let52;
                uint32_t let53;
                uint32_t r54;
                
                if (v41 + r48 <= r42) {
                    core_write_local(la47, a27, v41, v39, v39 + r48 - 1);
                } else {
                    uint32_t r50;
                    uint32_t r51;
                    
                    r50 = r42 - v41;
                    core_write_local(la47, a27, v41, v39, v39 + r50 - 1);
                    r51 = v39 + r50;
                    core_write_local(la47, a27, 0, r51, r51 + (r48 - r50) - 1);
                }
                let52 = v41 + r48;
                let53 = r42;
                r54 = let52 < let53 ? let52 : let52 - let53;
                la45[0] = r54;
                la46[0] = r54;
                r49 = r48;
            } else {
                r49 = 0;
            }
            if (!(0 == r49)) {
                r37 = v39 + r49;
            }
        }
    }
    return 0;
}
