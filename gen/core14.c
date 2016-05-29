#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
volatile bool *const la39 = (bool *) 8192;
volatile bool *const la40 = (bool *) 8208;
volatile float _Complex *const la41 = (float _Complex *) 8224;
volatile bool *const la42 = (bool *) 2358255616;
volatile bool *const la43 = (bool *) 2358255632;
volatile float _Complex *const la44 = (float _Complex *) 2358255648;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,35");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,10");
int main()
{
    while (1) {
        uint32_t r0;
        float _Complex _a1[512] __attribute__((aligned(16)));
        float _Complex *a1 = _a1;
        bool v2;
        uint32_t v3;
        bool v7;
        
        r0 = 512;
        v2 = core_read_c2c(la41, la39, la40, a1, 0, r0);
        if (!v2) {
            core_close_chan(la44, la42, la43);
            core_halt();
        }
        for (v3 = 0; v3 < 512; v3++) {
            uint32_t r4;
            
            r4 = v3;
            r4 = (r4 & 2863311530) >> 1 | (r4 & 1431655765) << 1;
            r4 = (r4 & 3435973836) >> 2 | (r4 & 858993459) << 2;
            r4 = (r4 & 4042322160) >> 4 | (r4 & 252645135) << 4;
            r4 = (r4 & 4278255360) >> 8 | (r4 & 16711935) << 8;
            r4 = (r4 >> 16 | r4 << 16) >> 23;
            if (r4 > v3) {
                float _Complex v5;
                float _Complex v6;
                
                v5 = a1[v3];
                v6 = a1[r4];
                a1[v3] = v6;
                a1[r4] = v5;
            }
        }
        v7 = core_write_c2c(la44, la42, la43, a1, 0, r0);
        if (!v7) {
            core_close_chan(la41, la39, la40);
            core_halt();
        }
    }
    return 0;
}
