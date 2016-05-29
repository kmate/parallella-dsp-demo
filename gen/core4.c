#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
volatile bool *const la21 = (bool *) 8192;
volatile bool *const la22 = (bool *) 8208;
volatile float _Complex *const la23 = (float _Complex *) 8224;
volatile bool *const la24 = (bool *) 2290098176;
volatile bool *const la25 = (bool *) 2290098192;
volatile float _Complex *const la26 = (float _Complex *) 2290098208;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,33");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,8");
int main()
{
    while (1) {
        uint32_t r0;
        float _Complex _a1[257] __attribute__((aligned(16)));
        float _Complex *a1 = _a1;
        bool v2;
        float _Complex _a3[] __attribute__((aligned(16))) = {0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0, 0.0, 0.0, 0.0,
                                                             0.0};
        float _Complex *a3 = _a3;
        uint32_t r4;
        uint32_t v5;
        bool v8;
        
        r0 = 257;
        v2 = core_read_c2c(la23, la21, la22, a1, 0, r0);
        if (!v2) {
            core_close_chan(la26, la24, la25);
            core_halt();
        }
        r4 = 257;
        for (v5 = 0; v5 < 257; v5++) {
            uint32_t r6;
            float _Complex let7;
            
            r6 = (uint32_t) lround((float) v5 * 2.0);
            let7 = a1[v5];
            a3[r6] = r6 < 257 ? creal(let7) + I * (2.0 * cimag(let7)) : 0.0;
        }
        v8 = core_write_c2c(la26, la24, la25, a3, 0, r4);
        if (!v8) {
            core_close_chan(la23, la21, la22);
            core_halt();
        }
    }
    return 0;
}
