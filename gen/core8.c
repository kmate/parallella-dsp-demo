#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile bool *const la54 = (bool *) 2222991408;
volatile bool *const la55 = (bool *) 2222991424;
volatile uint32_t *const la56 = (uint32_t *) 8192;
volatile uint32_t *const la57 = (uint32_t *) 2222991440;
volatile uint32_t *const la58 = (uint32_t *) 2222991456;
volatile uint32_t *const la59 = (uint32_t *) 8208;
volatile float _Complex *const la60 = (float _Complex *) 8224;
volatile bool *const la61 = (bool *) 10288;
volatile uint32_t *const la64 = (uint32_t *) 10320;
volatile uint32_t *const la65 = (uint32_t *) 10336;
volatile uint32_t *const la66 = (uint32_t *) 2291146768;
volatile float _Complex *const la67 = (float _Complex *) 2291146784;
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
    float _a1[257] __attribute__((aligned(16)));
    float *a1 = _a1;
    uint32_t v2;
    
    r0 = 257;
    for (v2 = 0; v2 < 257; v2++) {
        a1[v2] = 0.0;
    }
    while (1) {
        uint32_t r3;
        float _Complex _a4[257] __attribute__((aligned(16)));
        float _Complex *a4 = _a4;
        bool v5;
        uint32_t v26;
        uint32_t r28;
        float _Complex _a29[512] __attribute__((aligned(16)));
        float _Complex *a29 = _a29;
        uint32_t v30;
        bool v39;
        bool r40;
        
        r3 = 257;
        v5 = la54[0];
        la55[0] = v5;
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
                
                v7 = la54[0];
                v8 = r6;
                if (!(v7 && v8 < r3))
                    break;
                v9 = r6;
                v10 = la56[0];
                v11 = la59[0];
                r12 = 258;
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
                        core_read_local(la60, a4, v10, v9, v9 + r17 - 1);
                    } else {
                        uint32_t r19;
                        uint32_t r20;
                        
                        r19 = r12 - v10;
                        core_read_local(la60, a4, v10, v9, v9 + r19 - 1);
                        r20 = v9 + r19;
                        core_read_local(la60, a4, 0, r20, r20 + r17 - r19 - 1);
                    }
                    let21 = v10 + r17;
                    let22 = r12;
                    r23 = let21 < let22 ? let21 : let21 - let22;
                    la56[0] = r23;
                    la57[0] = r23;
                    r18 = r17;
                } else {
                    r18 = 0;
                }
                if (!(0 == r18)) {
                    r6 = v9 + r18;
                }
            }
            v24 = la56[0];
            v25 = la59[0];
            if (v24 == v25 && v25 == 257) {
                la56[0] = 0;
                la57[0] = 0;
                la58[0] = 0;
                la59[0] = 0;
            }
        }
        if (!v5) {
            la61[0] = false;
            core_halt();
        }
        for (v26 = 0; v26 < 257; v26++) {
            float let27;
            
            let27 = (float) v26;
            a1[v26] = a1[v26] + (2.0 * FELD_PI * ((cimag(a4[v26]) - let27 *
                                                   86.13281) / 86.13281) / 4.0 +
                                 let27 * 1.5707964);
        }
        r28 = 512;
        for (v30 = 0; v30 < 512; v30++) {
            float let31;
            float let32;
            float let33;
            float let34;
            float let35;
            float _Complex v36;
            
            let31 = creal(a4[v30]);
            let32 = (float) v30;
            let33 = a1[v30] + (2.0 * FELD_PI * ((cimag(a4[v30]) - let32 *
                                                 86.13281) / 86.13281) / 4.0 +
                               let32 * 1.5707964);
            let34 = 2.0 * FELD_PI;
            let35 = 1.5707964 - let33;
            if (v30 <= 257) {
                float let37;
                float let38;
                
                let37 = let33 - let34 * (float) round(let33 / let34 + 0.5);
                let38 = let35 - let34 * (float) round(let35 / let34 + 0.5);
                v36 = let31 * (1.0 + (0.0 + (-0.4999999 + (0.0 + (4.1666523e-2 +
                                                                  (0.0 +
                                                                   (-1.3887971e-3 +
                                                                    (0.0 +
                                                                     (2.4773424e-5 +
                                                                      (0.0 +
                                                                       (-2.7113379e-7 +
                                                                        (0.0 +
                                                                         (1.736915e-9 +
                                                                          0.0 *
                                                                          let37) *
                                                                         let37) *
                                                                        let37) *
                                                                       let37) *
                                                                      let37) *
                                                                     let37) *
                                                                    let37) *
                                                                   let37) *
                                                                  let37) *
                                                           let37) * let37) *
                                      let37) * let37) + I * (let31 * (1.0 +
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
                                                                                  let38) *
                                                                                 let38) *
                                                                                let38) *
                                                                               let38) *
                                                                              let38) *
                                                                             let38) *
                                                                            let38) *
                                                                           let38) *
                                                                          let38) *
                                                                         let38) *
                                                                        let38) *
                                                                       let38) *
                                                                      let38));
            } else {
                v36 = 0.0;
            }
            a29[v30] = v36;
        }
        v39 = la61[0];
        if (v39) {
            uint32_t r41;
            
            r41 = 0;
            while (1) {
                bool v42;
                uint32_t v43;
                uint32_t v44;
                uint32_t v45;
                uint32_t v46;
                uint32_t r47;
                uint32_t let48;
                uint32_t let49;
                uint32_t r50;
                uint32_t r51;
                uint32_t let52;
                uint32_t r53;
                uint32_t r54;
                
                v42 = la61[0];
                v43 = r41;
                if (!(v42 && v43 < r28))
                    break;
                v44 = r41;
                v45 = la64[0];
                v46 = la65[0];
                r47 = 513;
                let48 = r47 + v46 - v45;
                let49 = r47;
                r50 = let48 < let49 ? let48 : let48 - let49;
                r51 = r47 - r50 - 1;
                let52 = r28 - 1 - v44 + 1;
                r53 = let52 <= r51 ? let52 : r51;
                if (r53 > 0) {
                    uint32_t let57;
                    uint32_t let58;
                    uint32_t r59;
                    
                    if (v46 + r53 <= r47) {
                        core_write_local(la67, a29, v46, v44, v44 + r53 - 1);
                    } else {
                        uint32_t r55;
                        uint32_t r56;
                        
                        r55 = r47 - v46;
                        core_write_local(la67, a29, v46, v44, v44 + r55 - 1);
                        r56 = v44 + r55;
                        core_write_local(la67, a29, 0, r56, r56 + (r53 - r55) -
                                         1);
                    }
                    let57 = v46 + r53;
                    let58 = r47;
                    r59 = let57 < let58 ? let57 : let57 - let58;
                    la65[0] = r59;
                    la66[0] = r59;
                    r54 = r53;
                } else {
                    r54 = 0;
                }
                if (!(0 == r54)) {
                    r41 = v44 + r54;
                }
            }
            r40 = true;
        } else {
            r40 = false;
        }
        if (!r40) {
            la54[0] = false;
            core_halt();
        }
    }
    return 0;
}
