#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la68 = (uint32_t *) 8192;
volatile uint32_t *const la69 = (uint32_t *) 2359306256;
volatile uint32_t *const la70 = (uint32_t *) 2359306260;
volatile uint32_t *const la71 = (uint32_t *) 8196;
volatile float _Complex *const la72 = (float _Complex *) 8200;
volatile uint32_t *const la74 = (uint32_t *) 10256;
volatile uint32_t *const la75 = (uint32_t *) 10260;
volatile uint32_t *const la76 = (uint32_t *) 2357207044;
volatile float *const la77 = (float *) 2357207048;
int main()
{
    while (1) {
        float _Complex _a0[256];
        float _Complex *a0 = _a0;
        uint32_t r1;
        uint32_t v17;
        uint32_t v18;
        uint32_t r19;
        uint32_t r20;
        uint32_t v22;
        uint32_t r23;
        
        r1 = 0;
        while (1) {
            uint32_t v2;
            uint32_t v3;
            uint32_t v6;
            uint32_t v7;
            uint32_t r8;
            uint32_t let9;
            uint32_t r10;
            uint32_t let11;
            uint32_t r12;
            uint32_t let15;
            uint32_t r16;
            
            v2 = r1;
            if (!(v2 < 256))
                break;
            v3 = r1;
            while (1) {
                uint32_t v4;
                uint32_t v5;
                
                v4 = la68[0];
                v5 = la71[0];
                if (!(v4 == v5))
                    break;
            }
            v6 = la68[0];
            v7 = la71[0];
            r8 = 257;
            let9 = r8 + v7 - v6;
            r10 = let9 < r8 ? let9 : let9 - r8;
            let11 = -v3 + 256;
            r12 = let11 <= r10 ? let11 : r10;
            if (v6 + r12 <= r8) {
                core_read_local(la72, a0, v6, v3, v3 + r12 - 1);
            } else {
                uint32_t r13;
                uint32_t r14;
                
                r13 = r8 - v6;
                core_read_local(la72, a0, v6, v3, v3 + r13 - 1);
                r14 = v3 + r13;
                core_read_local(la72, a0, 0, r14, r14 + r12 - r13 - 1);
            }
            let15 = v6 + r12;
            r16 = let15 < r8 ? let15 : let15 - r8;
            la68[0] = r16;
            la69[0] = r16;
            r1 = v3 + r12;
        }
        v17 = la68[0];
        v18 = la71[0];
        if (v17 == v18 && v18 == 256) {
            la68[0] = 0;
            la69[0] = 0;
            la70[0] = 0;
            la71[0] = 0;
        }
        r19 = 256;
        r20 = r19;
        
        float _a21[r19];
        float *a21 = _a21;
        
        for (v22 = 0; v22 < r19; v22++) {
            a21[v22] = creal(a0[v22]) / 1024.0;
        }
        r23 = 0;
        while (1) {
            uint32_t v24;
            uint32_t v25;
            uint32_t v29;
            uint32_t v30;
            uint32_t let31;
            uint32_t r32;
            uint32_t r33;
            uint32_t let34;
            uint32_t r35;
            uint32_t let38;
            uint32_t r39;
            
            v24 = r23;
            if (!(v24 < 256))
                break;
            v25 = r23;
            while (1) {
                uint32_t v26;
                uint32_t v27;
                uint32_t let28;
                
                v26 = la74[0];
                v27 = la75[0];
                let28 = v27 + 1;
                if (!((let28 < 257 ? let28 : v27 + 4294967040) == v26))
                    break;
            }
            v29 = la74[0];
            v30 = la75[0];
            let31 = v30 + 257 - v29;
            r32 = let31 < 257 ? let31 : let31 - 257;
            r33 = -r32 + 256;
            let34 = -v25 + 256;
            r35 = let34 <= r33 ? let34 : r33;
            if (v30 + r35 <= 257) {
                core_write_local(la77, a21, v30, v25, v25 + r35 - 1);
            } else {
                uint32_t r36;
                uint32_t r37;
                
                r36 = -v30 + 257;
                core_write_local(la77, a21, v30, v25, v25 + r36 - 1);
                r37 = v25 + r36;
                core_write_local(la77, a21, 0, r37, r37 + (r35 - r36) - 1);
            }
            let38 = v30 + r35;
            r39 = let38 < 257 ? let38 : let38 - 257;
            la75[0] = r39;
            la76[0] = r39;
            r23 = v25 + r35;
        }
    }
    return 0;
}
