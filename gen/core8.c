#include <assert.h>
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
    r0 = 257;
    for (v2 = 0; v2 < 257; v2++) {
        assert(v2 < 257 && "setArr: index out of bounds");
        a1[v2] = 0.0;
    }
    while (1) {
        uint32_t r3;
        float _Complex _a4[257] __attribute__((aligned(16)));
        float _Complex *a4 = _a4;
        bool v5;
        uint32_t v6;
        uint32_t r15;
        float _Complex _a16[512] __attribute__((aligned(16)));
        float _Complex *a16 = _a16;
        uint32_t v17;
        bool v37;
        
        r3 = 257;
        v5 = core_read_c2c(la26, la24, la25, a4, 0, r3);
        if (!v5) {
            core_close_chan(la29, la27, la28);
            core_halt();
        }
        r0 = 257;
        for (v6 = 0; v6 < 257; v6++) {
            uint32_t let7;
            uint32_t let8;
            uint32_t let9;
            uint32_t let10;
            uint32_t let11;
            uint32_t let12;
            uint32_t let13;
            float let14;
            
            assert(v6 < 257 && "setArr: index out of bounds");
            assert(v6 < 257 && "indexing outside of Pull vector");
            let7 = v6;
            assert(let7 < 257 && "indexing outside of Pull vector");
            let8 = let7;
            assert(r0 <= 257 && "invalid IArr slice");
            assert(let8 < r0 && "indexing outside of Pull vector");
            let9 = let8;
            assert(v6 < 257 && "indexing outside of Pull vector");
            let10 = v6;
            assert(let10 < 257 && "indexing outside of Pull vector");
            let11 = let10;
            assert(r3 <= 257 && "invalid IArr slice");
            assert(let11 < r3 && "indexing outside of Pull vector");
            let12 = let11;
            assert(v6 < 257 && "indexing outside of Pull vector");
            let13 = v6;
            assert(let13 < 257 && "indexing outside of Pull vector");
            let14 = (float) let13;
            assert(r0 <= 257 && "invalid IArr slice");
            assert(let9 < r0 && "arrIx: index out of bounds");
            assert(r3 <= 257 && "invalid IArr slice");
            assert(let12 < r3 && "arrIx: index out of bounds");
            a1[v6] = a1[let9] + (2.0 * FELD_PI * ((cimag(a4[let12]) - let14 *
                                                   86.13281) / 86.13281) / 4.0 +
                                 let14 * 1.5707964);
        }
        r15 = 512;
        r15 = 512;
        for (v17 = 0; v17 < 512; v17++) {
            uint32_t let18;
            uint32_t let19;
            uint32_t let20;
            uint32_t let21;
            float let22;
            uint32_t let23;
            uint32_t let24;
            uint32_t let25;
            uint32_t let26;
            uint32_t let27;
            uint32_t let28;
            uint32_t let29;
            float let30;
            float let31;
            float let32;
            float let33;
            float _Complex v34;
            
            assert(v17 < 512 && "setArr: index out of bounds");
            assert(v17 < 512 && "indexing outside of Pull vector");
            let18 = v17;
            assert(let18 < 257 && "indexing outside of Pull vector");
            let19 = let18;
            assert(let19 < 257 && "indexing outside of Pull vector");
            let20 = let19;
            assert(r3 <= 257 && "invalid IArr slice");
            assert(let20 < r3 && "indexing outside of Pull vector");
            let21 = let20;
            assert(r3 <= 257 && "invalid IArr slice");
            assert(let21 < r3 && "arrIx: index out of bounds");
            let22 = creal(a4[let21]);
            assert(let18 < 257 && "indexing outside of Pull vector");
            let23 = let18;
            assert(let23 < 257 && "indexing outside of Pull vector");
            let24 = let23;
            assert(r0 <= 257 && "invalid IArr slice");
            assert(let24 < r0 && "indexing outside of Pull vector");
            let25 = let24;
            assert(let18 < 257 && "indexing outside of Pull vector");
            let26 = let18;
            assert(let26 < 257 && "indexing outside of Pull vector");
            let27 = let26;
            assert(r3 <= 257 && "invalid IArr slice");
            assert(let27 < r3 && "indexing outside of Pull vector");
            let28 = let27;
            assert(let18 < 257 && "indexing outside of Pull vector");
            let29 = let18;
            assert(let29 < 257 && "indexing outside of Pull vector");
            let30 = (float) let29;
            assert(r0 <= 257 && "invalid IArr slice");
            assert(let25 < r0 && "arrIx: index out of bounds");
            assert(r3 <= 257 && "invalid IArr slice");
            assert(let28 < r3 && "arrIx: index out of bounds");
            let31 = a1[let25] + (2.0 * FELD_PI * ((cimag(a4[let28]) - let30 *
                                                   86.13281) / 86.13281) / 4.0 +
                                 let30 * 1.5707964);
            let32 = 2.0 * FELD_PI;
            let33 = 1.5707964 - let31;
            if (let18 <= 257) {
                float let35;
                float let36;
                
                let35 = let31 - let32 * (float) round(let31 / let32 + 0.5);
                let36 = let33 - let32 * (float) round(let33 / let32 + 0.5);
                v34 = let22 * (1.0 + (0.0 + (-0.4999999 + (0.0 + (4.1666523e-2 +
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
                                      let35) * let35) + I * (let22 * (1.0 +
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
            a16[v17] = v34;
        }
        v37 = core_write_c2c(la29, la27, la28, a16, 0, r15);
        if (!v37) {
            core_close_chan(la26, la24, la25);
            core_halt();
        }
    }
    return 0;
}
