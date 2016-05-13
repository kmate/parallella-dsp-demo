#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la48 = (uint32_t *) 8192;
volatile uint32_t *const la49 = (uint32_t *) 2360354832;
volatile uint32_t *const la50 = (uint32_t *) 2360354836;
volatile uint32_t *const la51 = (uint32_t *) 8196;
volatile float _Complex *const la52 = (float _Complex *) 8200;
volatile uint32_t *const la54 = (uint32_t *) 10256;
volatile uint32_t *const la55 = (uint32_t *) 10260;
volatile uint32_t *const la56 = (uint32_t *) 2358255620;
volatile float _Complex *const la57 = (float _Complex *) 2358255624;
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
        uint32_t v23;
        uint32_t r27;
        uint32_t v29;
        uint32_t r30;
        
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
                
                v4 = la48[0];
                v5 = la51[0];
                if (!(v4 == v5))
                    break;
            }
            v6 = la48[0];
            v7 = la51[0];
            r8 = 257;
            let9 = r8 + v7 - v6;
            r10 = let9 < r8 ? let9 : let9 - r8;
            let11 = -v3 + 256;
            r12 = let11 <= r10 ? let11 : r10;
            if (v6 + r12 <= r8) {
                core_read_local(la52, a0, v6, v3, v3 + r12 - 1);
            } else {
                uint32_t r13;
                uint32_t r14;
                
                r13 = r8 - v6;
                core_read_local(la52, a0, v6, v3, v3 + r13 - 1);
                r14 = v3 + r13;
                core_read_local(la52, a0, 0, r14, r14 + r12 - r13 - 1);
            }
            let15 = v6 + r12;
            r16 = let15 < r8 ? let15 : let15 - r8;
            la48[0] = r16;
            la49[0] = r16;
            r1 = v3 + r12;
        }
        v17 = la48[0];
        v18 = la51[0];
        if (v17 == v18 && v18 == 256) {
            la48[0] = 0;
            la49[0] = 0;
            la50[0] = 0;
            la51[0] = 0;
        }
        r19 = 256;
        r20 = r19;
        
        float _Complex _a21[r19];
        float _Complex *a21 = _a21;
        
        for (v22 = 0; v22 < r19; v22++) {
            a21[v22] = a0[v22];
        }
        for (v23 = 0; v23 < 256; v23++) {
            uint32_t r24;
            
            r24 = v23;
            r24 = (r24 & 2863311530) >> 1 | (r24 & 1431655765) << 1;
            r24 = (r24 & 3435973836) >> 2 | (r24 & 858993459) << 2;
            r24 = (r24 & 4042322160) >> 4 | (r24 & 252645135) << 4;
            r24 = (r24 & 4278255360) >> 8 | (r24 & 16711935) << 8;
            r24 = (r24 >> 16 | r24 << 16) >> 24;
            if (r24 > v23) {
                float _Complex v25;
                float _Complex v26;
                
                v25 = a21[v23];
                v26 = a21[r24];
                a21[v23] = v26;
                a21[r24] = v25;
            }
        }
        r27 = r19;
        
        float _Complex _a28[r19];
        float _Complex *a28 = _a28;
        
        for (v29 = 0; v29 < r19; v29++) {
            a28[v29] = a21[v29];
        }
        r30 = 0;
        while (1) {
            uint32_t v31;
            uint32_t v32;
            uint32_t v36;
            uint32_t v37;
            uint32_t let38;
            uint32_t r39;
            uint32_t r40;
            uint32_t let41;
            uint32_t r42;
            uint32_t let45;
            uint32_t r46;
            
            v31 = r30;
            if (!(v31 < 256))
                break;
            v32 = r30;
            while (1) {
                uint32_t v33;
                uint32_t v34;
                uint32_t let35;
                
                v33 = la54[0];
                v34 = la55[0];
                let35 = v34 + 1;
                if (!((let35 < 257 ? let35 : v34 + 4294967040) == v33))
                    break;
            }
            v36 = la54[0];
            v37 = la55[0];
            let38 = v37 + 257 - v36;
            r39 = let38 < 257 ? let38 : let38 - 257;
            r40 = -r39 + 256;
            let41 = -v32 + 256;
            r42 = let41 <= r40 ? let41 : r40;
            if (v37 + r42 <= 257) {
                core_write_local(la57, a28, v37, v32, v32 + r42 - 1);
            } else {
                uint32_t r43;
                uint32_t r44;
                
                r43 = -v37 + 257;
                core_write_local(la57, a28, v37, v32, v32 + r43 - 1);
                r44 = v32 + r43;
                core_write_local(la57, a28, 0, r44, r44 + (r42 - r43) - 1);
            }
            let45 = v37 + r42;
            r46 = let45 < 257 ? let45 : let45 - 257;
            la55[0] = r46;
            la56[0] = r46;
            r30 = v32 + r42;
        }
    }
    return 0;
}
