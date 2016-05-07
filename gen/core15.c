#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
uint32_t *const la28 = (uint32_t *) 8192;
uint32_t *const la29 = (uint32_t *) 2293245968;
uint32_t *const la30 = (uint32_t *) 2293245972;
uint32_t *const la31 = (uint32_t *) 8196;
float _Complex *const la32 = (float _Complex *) 8200;
uint32_t *const la33 = (uint32_t *) 10256;
uint32_t *const la34 = (uint32_t *) 10260;
void *const sa35 = (void *) 16778244;
#define FELD_PI 3.141592653589793
int main()
{
    uint32_t r0;
    float _a1[256];
    float *a1 = _a1;
    uint32_t v2;
    
    r0 = 256;
    for (v2 = 0; v2 < 256; v2++) {
        a1[v2] = -(0.5 * cos(2.0 * FELD_PI * (float) v2 / 256.0)) + 0.5;
    }
    while (1) {
        float _Complex _a3[256];
        float _Complex *a3 = _a3;
        uint32_t r4;
        uint32_t v11;
        uint32_t v12;
        uint32_t r13;
        uint32_t r14;
        uint32_t v16;
        uint32_t r17;
        
        r4 = 0;
        while (1) {
            uint32_t v5;
            uint32_t v6;
            uint32_t v9;
            uint32_t v10;
            
            v5 = r4;
            if (!(v5 < 256))
                break;
            v6 = r4;
            while (1) {
                uint32_t v7;
                uint32_t v8;
                
                v7 = la28[0];
                v8 = la31[0];
                if (!(v7 == v8))
                    break;
            }
            v9 = la28[0];
            v10 = la31[0];
            if (v9 + (-v6 + 256 <= (v10 + 257 - v9) % 257 ? -v6 + 256 : (v10 +
                                                                         257 -
                                                                         v9) %
                      257) <= 257) {
                core_read_local(la32, a3, v9, v6, v6 + (-v6 + 256 <= (v10 +
                                                                      257 -
                                                                      v9) %
                                                        257 ? -v6 + 256 : (v10 +
                                                                           257 -
                                                                           v9) %
                                                        257) - 1);
            } else {
                core_read_local(la32, a3, v9, v6, v6 + (-v9 + 257) - 1);
                core_read_local(la32, a3, 0, v6 + (-v9 + 257), v6 + (-v9 +
                                                                     257) +
                                (-v6 + 256 <= (v10 + 257 - v9) % 257 ? -v6 +
                                 256 : (v10 + 257 - v9) % 257) - (-v9 + 257) -
                                1);
            }
            la28[0] = (v9 + (-v6 + 256 <= (v10 + 257 - v9) % 257 ? -v6 +
                             256 : (v10 + 257 - v9) % 257)) % 257;
            la29[0] = (v9 + (-v6 + 256 <= (v10 + 257 - v9) % 257 ? -v6 +
                             256 : (v10 + 257 - v9) % 257)) % 257;
            r4 = v6 + (-v6 + 256 <= (v10 + 257 - v9) % 257 ? -v6 + 256 : (v10 +
                                                                          257 -
                                                                          v9) %
                       257);
        }
        v11 = la28[0];
        v12 = la31[0];
        if (v11 == v12 && v12 == 256) {
            la28[0] = 0;
            la29[0] = 0;
            la30[0] = 0;
            la31[0] = 0;
        }
        r13 = 256;
        r14 = r13 <= r0 ? r13 : r0;
        
        float _a15[r13 <= r0 ? r13 : r0];
        float *a15 = _a15;
        
        for (v16 = 0; v16 < (r13 <= r0 ? r13 : r0); v16++) {
            a15[v16] = creal(a3[v16]) / 1024.0 * a1[v16];
        }
        r17 = 0;
        while (1) {
            uint32_t v18;
            uint32_t v19;
            uint32_t v22;
            uint32_t v23;
            
            v18 = r17;
            if (!(v18 < 256))
                break;
            v19 = r17;
            while (1) {
                uint32_t v20;
                uint32_t v21;
                
                v20 = la33[0];
                v21 = la34[0];
                if (!((v21 + 1) % 257 == v20))
                    break;
            }
            v22 = la33[0];
            v23 = la34[0];
            if (v23 + (-v19 + 256 <= -((v23 + 257 - v22) % 257) + 256 ? -v19 +
                       256 : -((v23 + 257 - v22) % 257) + 256) <= 257) {
                core_write_shared(sa35, a15, v23, v19, v19 + (-v19 + 256 <=
                                                              -((v23 + 257 -
                                                                 v22) % 257) +
                                                              256 ? -v19 +
                                                              256 : -((v23 +
                                                                       257 -
                                                                       v22) %
                                                                      257) +
                                                              256) - 1);
            } else {
                core_write_shared(sa35, a15, v23, v19, v19 + (-v23 + 257) - 1);
                core_write_shared(sa35, a15, 0, v19 + (-v23 + 257), v19 +
                                  (-v23 + 257) + ((-v19 + 256 <= -((v23 + 257 -
                                                                    v22) %
                                                                   257) +
                                                   256 ? -v19 + 256 : -((v23 +
                                                                         257 -
                                                                         v22) %
                                                                        257) +
                                                   256) - (-v23 + 257)) - 1);
            }
            la34[0] = (v23 + (-v19 + 256 <= -((v23 + 257 - v22) % 257) +
                              256 ? -v19 + 256 : -((v23 + 257 - v22) % 257) +
                              256)) % 257;
            r17 = v19 + (-v19 + 256 <= -((v23 + 257 - v22) % 257) + 256 ? -v19 +
                         256 : -((v23 + 257 - v22) % 257) + 256);
        }
    }
    return 0;
}
