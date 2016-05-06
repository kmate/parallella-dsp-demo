#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
uint32_t *const la0 = (uint32_t *) 8192;
uint32_t *const la1 = (uint32_t *) 8196;
uint32_t *const la4 = (uint32_t *) 8200;
uint32_t *const la5 = (uint32_t *) 8204;
uint32_t *const la6 = (uint32_t *) 2156929028;
float _Complex *const la7 = (float _Complex *) 2156929032;
void *const sa2 = (void *) 16777216;
#define FELD_PI 3.141592653589793
int main()
{
    uint32_t r0;
    float _a1[1024];
    float *a1 = _a1;
    uint32_t v2;
    
    r0 = 1024;
    for (v2 = 0; v2 < 1024; v2++) {
        a1[v2] = -(0.5 * cos(2.0 * FELD_PI * (float) v2 / 1024.0)) + 0.5;
    }
    while (1) {
        float _a3[1024];
        float *a3 = _a3;
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
            if (!(v5 < 1024))
                break;
            v6 = r4;
            while (1) {
                uint32_t v7;
                uint32_t v8;
                
                v7 = la0[0];
                v8 = la1[0];
                if (!(v7 == v8))
                    break;
            }
            v9 = la0[0];
            v10 = la1[0];
            if (v9 + (-v6 + 1024 <= (v10 + 1025 - v9) % 1025 ? -v6 +
                      1024 : (v10 + 1025 - v9) % 1025) <= 1025) {
                core_read_shared(sa2, a3, v9, v6, v6 + (-v6 + 1024 <= (v10 +
                                                                       1025 -
                                                                       v9) %
                                                        1025 ? -v6 +
                                                        1024 : (v10 + 1025 -
                                                                v9) % 1025) -
                                 1);
            } else {
                core_read_shared(sa2, a3, v9, v6, v6 + (-v9 + 1025) - 1);
                core_read_shared(sa2, a3, 0, v6 + (-v9 + 1025), v6 + (-v9 +
                                                                      1025) +
                                 (-v6 + 1024 <= (v10 + 1025 - v9) % 1025 ? -v6 +
                                  1024 : (v10 + 1025 - v9) % 1025) - (-v9 +
                                                                      1025) -
                                 1);
            }
            la0[0] = (v9 + (-v6 + 1024 <= (v10 + 1025 - v9) % 1025 ? -v6 +
                            1024 : (v10 + 1025 - v9) % 1025)) % 1025;
            r4 = v6 + (-v6 + 1024 <= (v10 + 1025 - v9) % 1025 ? -v6 +
                       1024 : (v10 + 1025 - v9) % 1025);
        }
        v11 = la0[0];
        v12 = la1[0];
        if (v11 == v12 && v12 == 1024) {
            la0[0] = 0;
            la1[0] = 0;
        }
        r13 = 1024;
        r14 = r13 <= r0 ? r13 : r0;
        
        float _Complex _a15[r13 <= r0 ? r13 : r0];
        float _Complex *a15 = _a15;
        
        for (v16 = 0; v16 < (r13 <= r0 ? r13 : r0); v16++) {
            a15[v16] = a3[v16] * a1[v16];
        }
        r17 = 0;
        while (1) {
            uint32_t v18;
            uint32_t v19;
            uint32_t v22;
            uint32_t v23;
            
            v18 = r17;
            if (!(v18 < 1024))
                break;
            v19 = r17;
            while (1) {
                uint32_t v20;
                uint32_t v21;
                
                v20 = la4[0];
                v21 = la5[0];
                if (!((v21 + 1) % 1025 == v20))
                    break;
            }
            v22 = la4[0];
            v23 = la5[0];
            if (v23 + (-v19 + 1024 <= -((v23 + 1025 - v22) % 1025) +
                       1024 ? -v19 + 1024 : -((v23 + 1025 - v22) % 1025) +
                       1024) <= 1025) {
                core_write_local(la7, a15, v23, v19, v19 + (-v19 + 1024 <=
                                                            -((v23 + 1025 -
                                                               v22) % 1025) +
                                                            1024 ? -v19 +
                                                            1024 : -((v23 +
                                                                      1025 -
                                                                      v22) %
                                                                     1025) +
                                                            1024) - 1);
            } else {
                core_write_local(la7, a15, v23, v19, v19 + (-v23 + 1025) - 1);
                core_write_local(la7, a15, 0, v19 + (-v23 + 1025), v19 + (-v23 +
                                                                          1025) +
                                 ((-v19 + 1024 <= -((v23 + 1025 - v22) % 1025) +
                                   1024 ? -v19 + 1024 : -((v23 + 1025 - v22) %
                                                          1025) + 1024) -
                                  (-v23 + 1025)) - 1);
            }
            la5[0] = (v23 + (-v19 + 1024 <= -((v23 + 1025 - v22) % 1025) +
                             1024 ? -v19 + 1024 : -((v23 + 1025 - v22) % 1025) +
                             1024)) % 1025;
            la6[0] = (v23 + (-v19 + 1024 <= -((v23 + 1025 - v22) % 1025) +
                             1024 ? -v19 + 1024 : -((v23 + 1025 - v22) % 1025) +
                             1024)) % 1025;
            r17 = v19 + (-v19 + 1024 <= -((v23 + 1025 - v22) % 1025) +
                         1024 ? -v19 + 1024 : -((v23 + 1025 - v22) % 1025) +
                         1024);
        }
    }
    return 0;
}
