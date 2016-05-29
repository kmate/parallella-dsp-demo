#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
volatile bool *const la18 = (bool *) 8192;
volatile bool *const la19 = (bool *) 8208;
volatile float _Complex *const la20 = (float _Complex *) 8224;
volatile bool *const la21 = (bool *) 2222989312;
volatile bool *const la22 = (bool *) 2222989328;
volatile float _Complex *const la23 = (float _Complex *) 2222989344;
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
        uint32_t r6;
        float _Complex _a7[257] __attribute__((aligned(16)));
        float _Complex *a7 = _a7;
        uint32_t v8;
        bool v17;
        uint32_t v18;
        
        r3 = 512;
        v5 = core_read_c2c(la20, la18, la19, a4, 0, r3);
        if (!v5) {
            core_close_chan(la23, la21, la22);
            core_halt();
        }
        r6 = 257;
        for (v8 = 0; v8 < 257; v8++) {
            float let9;
            float let10;
            float let11;
            float _Complex let12;
            float let13;
            float let14;
            float let15;
            float let16;
            
            let9 = fabs(creal(a4[v8]));
            let10 = fabs(cimag(a4[v8]));
            let11 = (float) v8;
            let12 = a4[v8];
            let13 = creal(let12);
            let14 = let10 + 1.0e-10;
            let15 = let13 + let14;
            let16 = let13 >= 0.0 ? 0.7853982 - 0.7853982 * ((let13 - let14) /
                                                            let15) : 2.3561945 -
                0.7853982 * (let15 / (let14 - let13));
            a7[v8] = 2.0 * (0.9375 * (let9 >= let10 ? let9 : let10) + 0.46875 *
                            (let9 <= let10 ? let9 : let10)) + I * ((let11 +
                                                                    4.0 *
                                                                    ((cimag(let12) <
                                                                      0.0 ? -let16 : let16) -
                                                                     a1[v8] -
                                                                     let11 *
                                                                     1.5707964) /
                                                                    (2.0 *
                                                                     FELD_PI)) *
                                                                   86.13281);
        }
        v17 = core_write_c2c(la23, la21, la22, a7, 0, r6);
        if (!v17) {
            core_close_chan(la20, la18, la19);
            core_halt();
        }
        for (v18 = 0; v18 < 257; v18++) {
            float let19;
            float let20;
            float let21;
            float let22;
            float let23;
            
            let19 = cimag(a4[v18]);
            let20 = creal(a4[v18]);
            let21 = fabs(let19) + 1.0e-10;
            let22 = let20 + let21;
            let23 = let20 >= 0.0 ? 0.7853982 - 0.7853982 * ((let20 - let21) /
                                                            let22) : 2.3561945 -
                0.7853982 * (let22 / (let21 - let20));
            a1[v18] = let19 < 0.0 ? -let23 : let23;
        }
    }
    return 0;
}
