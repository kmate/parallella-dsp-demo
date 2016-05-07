#include <e-feldspar.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
uint32_t *const la10 = (uint32_t *) 2156931092;
uint32_t *const la11 = (uint32_t *) 8196;
float _Complex *const la12 = (float _Complex *) 8200;
uint32_t *const la14 = (uint32_t *) 10256;
uint32_t *const la15 = (uint32_t *) 10260;
uint32_t *const la16 = (uint32_t *) 2159026180;
float _Complex *const la17 = (float _Complex *) 2159026184;
uint32_t *const la8 = (uint32_t *) 8192;
uint32_t *const la9 = (uint32_t *) 2156931088;
#define FELD_PI 3.141592653589793
int main()
{
    uint32_t r0;
    float _a1[129];
    float *a1 = _a1;
    uint32_t v2;
    
    r0 = 129;
    for (v2 = 0; v2 < 129; v2++) {
        a1[v2] = 0.0;
    }
    while (1) {
        float _Complex _a3[256];
        float _Complex *a3 = _a3;
        uint32_t r4;
        uint32_t v11;
        uint32_t v12;
        uint32_t r13;
        uint32_t r14;
        float _Complex _a15[129];
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
            if (!(v5 < 256))
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
            if (v9 + (-v6 + 256 <= (v10 + 257 - v9) % 257 ? -v6 + 256 : (v10 +
                                                                         257 -
                                                                         v9) %
                      257) <= 257) {
                core_read_local(la12, a3, v9, v6, v6 + (-v6 + 256 <= (v10 +
                                                                      257 -
                                                                      v9) %
                                                        257 ? -v6 + 256 : (v10 +
                                                                           257 -
                                                                           v9) %
                                                        257) - 1);
            } else {
                core_read_local(la12, a3, v9, v6, v6 + (-v9 + 257) - 1);
                core_read_local(la12, a3, 0, v6 + (-v9 + 257), v6 + (-v9 +
                                                                     257) +
                                (-v6 + 256 <= (v10 + 257 - v9) % 257 ? -v6 +
                                 256 : (v10 + 257 - v9) % 257) - (-v9 + 257) -
                                1);
            }
            la8[0] = (v9 + (-v6 + 256 <= (v10 + 257 - v9) % 257 ? -v6 +
                            256 : (v10 + 257 - v9) % 257)) % 257;
            la9[0] = (v9 + (-v6 + 256 <= (v10 + 257 - v9) % 257 ? -v6 +
                            256 : (v10 + 257 - v9) % 257)) % 257;
            r4 = v6 + (-v6 + 256 <= (v10 + 257 - v9) % 257 ? -v6 + 256 : (v10 +
                                                                          257 -
                                                                          v9) %
                       257);
        }
        v11 = la8[0];
        v12 = la11[0];
        if (v11 == v12 && v12 == 256) {
            la8[0] = 0;
            la9[0] = 0;
            la10[0] = 0;
            la11[0] = 0;
        }
        r13 = 256;
        r14 = 129;
        for (v16 = 0; v16 < 129; v16++) {
            a15[v16] = 2.0 * cabs(a3[v16]) + I * (((float) v16 + 4.0 *
                                                   (carg(a3[v16]) - a1[v16] -
                                                    (float) v16 * 1.5707964) /
                                                   (2.0 * FELD_PI)) *
                                                  172.26563);
        }
        r17 = 0;
        while (1) {
            uint32_t v18;
            uint32_t v19;
            uint32_t v22;
            uint32_t v23;
            
            v18 = r17;
            if (!(v18 < 129))
                break;
            v19 = r17;
            while (1) {
                uint32_t v20;
                uint32_t v21;
                
                v20 = la14[0];
                v21 = la15[0];
                if (!((v21 + 1) % 130 == v20))
                    break;
            }
            v22 = la14[0];
            v23 = la15[0];
            if (v23 + (-v19 + 129 <= -((v23 + 130 - v22) % 130) + 129 ? -v19 +
                       129 : -((v23 + 130 - v22) % 130) + 129) <= 130) {
                core_write_local(la17, a15, v23, v19, v19 + (-v19 + 129 <=
                                                             -((v23 + 130 -
                                                                v22) % 130) +
                                                             129 ? -v19 +
                                                             129 : -((v23 +
                                                                      130 -
                                                                      v22) %
                                                                     130) +
                                                             129) - 1);
            } else {
                core_write_local(la17, a15, v23, v19, v19 + (-v23 + 130) - 1);
                core_write_local(la17, a15, 0, v19 + (-v23 + 130), v19 + (-v23 +
                                                                          130) +
                                 ((-v19 + 129 <= -((v23 + 130 - v22) % 130) +
                                   129 ? -v19 + 129 : -((v23 + 130 - v22) %
                                                        130) + 129) - (-v23 +
                                                                       130)) -
                                 1);
            }
            la15[0] = (v23 + (-v19 + 129 <= -((v23 + 130 - v22) % 130) +
                              129 ? -v19 + 129 : -((v23 + 130 - v22) % 130) +
                              129)) % 130;
            la16[0] = (v23 + (-v19 + 129 <= -((v23 + 130 - v22) % 130) +
                              129 ? -v19 + 129 : -((v23 + 130 - v22) % 130) +
                              129)) % 130;
            r17 = v19 + (-v19 + 129 <= -((v23 + 130 - v22) % 130) + 129 ? -v19 +
                         129 : -((v23 + 130 - v22) % 130) + 129);
        }
        for (v24 = 0; v24 < 129; v24++) {
            a1[v24] = carg(a3[v24]);
        }
    }
    return 0;
}
