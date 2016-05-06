#include <e-feldspar.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
uint32_t *const la10 = (uint32_t *) 2156937236;
uint32_t *const la11 = (uint32_t *) 8196;
float _Complex *const la12 = (float _Complex *) 8200;
uint32_t *const la14 = (uint32_t *) 16400;
uint32_t *const la15 = (uint32_t *) 16404;
uint32_t *const la16 = (uint32_t *) 2159026180;
float _Complex *const la17 = (float _Complex *) 2159026184;
uint32_t *const la8 = (uint32_t *) 8192;
uint32_t *const la9 = (uint32_t *) 2156937232;
#define FELD_PI 3.141592653589793
int main()
{
    uint32_t r0;
    float _a1[513];
    float *a1 = _a1;
    uint32_t v2;
    
    r0 = 513;
    for (v2 = 0; v2 < 513; v2++) {
        a1[v2] = 0.0;
    }
    while (1) {
        float _Complex _a3[1024];
        float _Complex *a3 = _a3;
        uint32_t r4;
        uint32_t v11;
        uint32_t v12;
        uint32_t r13;
        uint32_t r14;
        float _Complex _a15[513];
        float _Complex *a15 = _a15;
        uint32_t v16;
        uint32_t r17;
        uint32_t v24;
        
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
                
                v7 = la8[0];
                v8 = la11[0];
                if (!(v7 == v8))
                    break;
            }
            v9 = la8[0];
            v10 = la11[0];
            if (v9 + (-v6 + 1024 <= (v10 + 1025 - v9) % 1025 ? -v6 +
                      1024 : (v10 + 1025 - v9) % 1025) <= 1025) {
                core_read_local(la12, a3, v9, v6, v6 + (-v6 + 1024 <= (v10 +
                                                                       1025 -
                                                                       v9) %
                                                        1025 ? -v6 +
                                                        1024 : (v10 + 1025 -
                                                                v9) % 1025) -
                                1);
            } else {
                core_read_local(la12, a3, v9, v6, v6 + (-v9 + 1025) - 1);
                core_read_local(la12, a3, 0, v6 + (-v9 + 1025), v6 + (-v9 +
                                                                      1025) +
                                (-v6 + 1024 <= (v10 + 1025 - v9) % 1025 ? -v6 +
                                 1024 : (v10 + 1025 - v9) % 1025) - (-v9 +
                                                                     1025) - 1);
            }
            la8[0] = (v9 + (-v6 + 1024 <= (v10 + 1025 - v9) % 1025 ? -v6 +
                            1024 : (v10 + 1025 - v9) % 1025)) % 1025;
            la9[0] = (v9 + (-v6 + 1024 <= (v10 + 1025 - v9) % 1025 ? -v6 +
                            1024 : (v10 + 1025 - v9) % 1025)) % 1025;
            r4 = v6 + (-v6 + 1024 <= (v10 + 1025 - v9) % 1025 ? -v6 +
                       1024 : (v10 + 1025 - v9) % 1025);
        }
        v11 = la8[0];
        v12 = la11[0];
        if (v11 == v12 && v12 == 1024) {
            la8[0] = 0;
            la9[0] = 0;
            la10[0] = 0;
            la11[0] = 0;
        }
        r13 = 1024;
        r14 = 513;
        for (v16 = 0; v16 < 513; v16++) {
            a15[v16] = 2.0 * cabs(a3[v16]) + I * (((float) v16 + 4.0 *
                                                   (carg(a3[v16]) - a1[v16] -
                                                    (float) v16 * 1.5707964) /
                                                   (2.0 * FELD_PI)) *
                                                  43.066406);
        }
        r17 = 0;
        while (1) {
            uint32_t v18;
            uint32_t v19;
            uint32_t v22;
            uint32_t v23;
            
            v18 = r17;
            if (!(v18 < 513))
                break;
            v19 = r17;
            while (1) {
                uint32_t v20;
                uint32_t v21;
                
                v20 = la14[0];
                v21 = la15[0];
                if (!((v21 + 1) % 514 == v20))
                    break;
            }
            v22 = la14[0];
            v23 = la15[0];
            if (v23 + (-v19 + 513 <= -((v23 + 514 - v22) % 514) + 513 ? -v19 +
                       513 : -((v23 + 514 - v22) % 514) + 513) <= 514) {
                core_write_local(la17, a15, v23, v19, v19 + (-v19 + 513 <=
                                                             -((v23 + 514 -
                                                                v22) % 514) +
                                                             513 ? -v19 +
                                                             513 : -((v23 +
                                                                      514 -
                                                                      v22) %
                                                                     514) +
                                                             513) - 1);
            } else {
                core_write_local(la17, a15, v23, v19, v19 + (-v23 + 514) - 1);
                core_write_local(la17, a15, 0, v19 + (-v23 + 514), v19 + (-v23 +
                                                                          514) +
                                 ((-v19 + 513 <= -((v23 + 514 - v22) % 514) +
                                   513 ? -v19 + 513 : -((v23 + 514 - v22) %
                                                        514) + 513) - (-v23 +
                                                                       514)) -
                                 1);
            }
            la15[0] = (v23 + (-v19 + 513 <= -((v23 + 514 - v22) % 514) +
                              513 ? -v19 + 513 : -((v23 + 514 - v22) % 514) +
                              513)) % 514;
            la16[0] = (v23 + (-v19 + 513 <= -((v23 + 514 - v22) % 514) +
                              513 ? -v19 + 513 : -((v23 + 514 - v22) % 514) +
                              513)) % 514;
            r17 = v19 + (-v19 + 513 <= -((v23 + 514 - v22) % 514) + 513 ? -v19 +
                         513 : -((v23 + 514 - v22) % 514) + 513);
        }
        for (v24 = 0; v24 < 513; v24++) {
            a1[v24] = carg(a3[v24]);
        }
    }
    return 0;
}
