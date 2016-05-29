#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
volatile bool *const la42 = (bool *) 8192;
volatile bool *const la43 = (bool *) 8208;
volatile float _Complex *const la44 = (float _Complex *) 8224;
volatile bool *const la45 = (bool *) 2357207040;
volatile bool *const la46 = (bool *) 2357207056;
volatile float *const la47 = (float *) 2357207072;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,35");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,9");
int main()
{
    while (1) {
        uint32_t r0;
        float _Complex _a1[512] __attribute__((aligned(16)));
        float _Complex *a1 = _a1;
        bool v2;
        uint32_t r3;
        uint32_t v5;
        bool v6;
        
        r0 = 512;
        v2 = core_read_c2c(la44, la42, la43, a1, 0, r0);
        if (!v2) {
            core_close_chan(la47, la45, la46);
            core_halt();
        }
        r3 = r0;
        
        float _a4[r0] __attribute__((aligned(16)));
        float *a4 = _a4;
        
        for (v5 = 0; v5 < r0; v5++) {
            a4[v5] = creal(a1[v5]) / 2048.0;
        }
        v6 = core_write_c2c(la47, la45, la46, a4, 0, r3);
        if (!v6) {
            core_close_chan(la44, la42, la43);
            core_halt();
        }
    }
    return 0;
}
