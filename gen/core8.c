#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
volatile bool *const la24 = (bool *) 8192;
volatile bool *const la25 = (bool *) 8208;
volatile float _Complex *const la26 = (float _Complex *) 8224;
volatile bool *const la27 = (bool *) 2291146752;
volatile bool *const la28 = (bool *) 2291146768;
volatile float _Complex *const la29 = (float _Complex *) 2291146784;
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
        uint32_t v6;
        uint32_t r8;
        float _Complex _a9[512] __attribute__((aligned(16)));
        float _Complex *a9 = _a9;
        uint32_t v10;
        bool v19;
        
        r3 = 257;
        v5 = core_read_c2c(la26, la24, la25, a4, 0, r3);
        if (!v5) {
            core_close_chan(la29, la27, la28);
            core_halt();
        }
        for (v6 = 0; v6 < 257; v6++) {
            float let7;
            
            let7 = (float) v6;
            a1[v6] = a1[v6] + (2.0 * FELD_PI * ((cimag(a4[v6]) - let7 *
                                                 86.13281) / 86.13281) / 4.0 +
                               let7 * 1.5707964);
        }
        r8 = 512;
        for (v10 = 0; v10 < 512; v10++) {
            float let11;
            float let12;
            float let13;
            float let14;
            float let15;
            float _Complex v16;
            
            let11 = creal(a4[v10]);
            let12 = (float) v10;
            let13 = a1[v10] + (2.0 * FELD_PI * ((cimag(a4[v10]) - let12 *
                                                 86.13281) / 86.13281) / 4.0 +
                               let12 * 1.5707964);
            let14 = 2.0 * FELD_PI;
            let15 = 1.5707964 - let13;
            if (v10 <= 257) {
                float let17;
                float let18;
                
                let17 = let13 - let14 * (float) round(let13 / let14 + 0.5);
                let18 = let15 - let14 * (float) round(let15 / let14 + 0.5);
                v16 = let11 * (1.0 + (0.0 + (-0.4999999 + (0.0 + (4.1666523e-2 +
                                                                  (0.0 +
                                                                   (-1.3887971e-3 +
                                                                    (0.0 +
                                                                     (2.4773424e-5 +
                                                                      (0.0 +
                                                                       (-2.7113379e-7 +
                                                                        (0.0 +
                                                                         (1.736915e-9 +
                                                                          0.0 *
                                                                          let17) *
                                                                         let17) *
                                                                        let17) *
                                                                       let17) *
                                                                      let17) *
                                                                     let17) *
                                                                    let17) *
                                                                   let17) *
                                                                  let17) *
                                                           let17) * let17) *
                                      let17) * let17) + I * (let11 * (1.0 +
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
                                                                                  let18) *
                                                                                 let18) *
                                                                                let18) *
                                                                               let18) *
                                                                              let18) *
                                                                             let18) *
                                                                            let18) *
                                                                           let18) *
                                                                          let18) *
                                                                         let18) *
                                                                        let18) *
                                                                       let18) *
                                                                      let18));
            } else {
                v16 = 0.0;
            }
            a9[v10] = v16;
        }
        v19 = core_write_c2c(la29, la27, la28, a9, 0, r8);
        if (!v19) {
            core_close_chan(la26, la24, la25);
            core_halt();
        }
    }
    return 0;
}
