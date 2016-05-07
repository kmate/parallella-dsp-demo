#include <e-feldspar.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
uint32_t *const la18 = (uint32_t *) 8192;
uint32_t *const la19 = (uint32_t *) 2159027224;
uint32_t *const la20 = (uint32_t *) 2159027228;
uint32_t *const la21 = (uint32_t *) 8196;
float _Complex *const la22 = (float _Complex *) 8200;
uint32_t *const la24 = (uint32_t *) 9240;
uint32_t *const la25 = (uint32_t *) 9244;
uint32_t *const la26 = (uint32_t *) 2293243908;
float _Complex *const la27 = (float _Complex *) 2293243912;
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
        float _Complex _a3[129];
        float _Complex *a3 = _a3;
        uint32_t r4;
        uint32_t v11;
        uint32_t v12;
        uint32_t r13;
        uint32_t v14;
        uint32_t r15;
        float _Complex _a16[256];
        float _Complex *a16 = _a16;
        uint32_t v17;
        uint32_t r18;
        
        r4 = 0;
        while (1) {
            uint32_t v5;
            uint32_t v6;
            uint32_t v9;
            uint32_t v10;
            
            v5 = r4;
            if (!(v5 < 129))
                break;
            v6 = r4;
            while (1) {
                uint32_t v7;
                uint32_t v8;
                
                v7 = la18[0];
                v8 = la21[0];
                if (!(v7 == v8))
                    break;
            }
            v9 = la18[0];
            v10 = la21[0];
            if (v9 + (-v6 + 129 <= (v10 + 130 - v9) % 130 ? -v6 + 129 : (v10 +
                                                                         130 -
                                                                         v9) %
                      130) <= 130) {
                core_read_local(la22, a3, v9, v6, v6 + (-v6 + 129 <= (v10 +
                                                                      130 -
                                                                      v9) %
                                                        130 ? -v6 + 129 : (v10 +
                                                                           130 -
                                                                           v9) %
                                                        130) - 1);
            } else {
                core_read_local(la22, a3, v9, v6, v6 + (-v9 + 130) - 1);
                core_read_local(la22, a3, 0, v6 + (-v9 + 130), v6 + (-v9 +
                                                                     130) +
                                (-v6 + 129 <= (v10 + 130 - v9) % 130 ? -v6 +
                                 129 : (v10 + 130 - v9) % 130) - (-v9 + 130) -
                                1);
            }
            la18[0] = (v9 + (-v6 + 129 <= (v10 + 130 - v9) % 130 ? -v6 +
                             129 : (v10 + 130 - v9) % 130)) % 130;
            la19[0] = (v9 + (-v6 + 129 <= (v10 + 130 - v9) % 130 ? -v6 +
                             129 : (v10 + 130 - v9) % 130)) % 130;
            r4 = v6 + (-v6 + 129 <= (v10 + 130 - v9) % 130 ? -v6 + 129 : (v10 +
                                                                          130 -
                                                                          v9) %
                       130);
        }
        v11 = la18[0];
        v12 = la21[0];
        if (v11 == v12 && v12 == 129) {
            la18[0] = 0;
            la19[0] = 0;
            la20[0] = 0;
            la21[0] = 0;
        }
        r13 = 129;
        for (v14 = 0; v14 < 129; v14++) {
            a1[v14] = a1[v14] + (2.0 * FELD_PI * ((cimag(a3[v14]) -
                                                   (float) v14 * 172.26563) /
                                                  172.26563) / 4.0 +
                                 (float) v14 * 1.5707964);
        }
        r15 = 256;
        for (v17 = 0; v17 < 256; v17++) {
            a16[v17] = v17 <= 129 ? creal(a3[v17]) * exp(I * (a1[v17] + (2.0 *
                                                                         FELD_PI *
                                                                         ((cimag(a3[v17]) -
                                                                           (float) v17 *
                                                                           172.26563) /
                                                                          172.26563) /
                                                                         4.0 +
                                                                         (float) v17 *
                                                                         1.5707964))) : 0.0;
        }
        r18 = 0;
        while (1) {
            uint32_t v19;
            uint32_t v20;
            uint32_t v23;
            uint32_t v24;
            
            v19 = r18;
            if (!(v19 < 256))
                break;
            v20 = r18;
            while (1) {
                uint32_t v21;
                uint32_t v22;
                
                v21 = la24[0];
                v22 = la25[0];
                if (!((v22 + 1) % 257 == v21))
                    break;
            }
            v23 = la24[0];
            v24 = la25[0];
            if (v24 + (-v20 + 256 <= -((v24 + 257 - v23) % 257) + 256 ? -v20 +
                       256 : -((v24 + 257 - v23) % 257) + 256) <= 257) {
                core_write_local(la27, a16, v24, v20, v20 + (-v20 + 256 <=
                                                             -((v24 + 257 -
                                                                v23) % 257) +
                                                             256 ? -v20 +
                                                             256 : -((v24 +
                                                                      257 -
                                                                      v23) %
                                                                     257) +
                                                             256) - 1);
            } else {
                core_write_local(la27, a16, v24, v20, v20 + (-v24 + 257) - 1);
                core_write_local(la27, a16, 0, v20 + (-v24 + 257), v20 + (-v24 +
                                                                          257) +
                                 ((-v20 + 256 <= -((v24 + 257 - v23) % 257) +
                                   256 ? -v20 + 256 : -((v24 + 257 - v23) %
                                                        257) + 256) - (-v24 +
                                                                       257)) -
                                 1);
            }
            la25[0] = (v24 + (-v20 + 256 <= -((v24 + 257 - v23) % 257) +
                              256 ? -v20 + 256 : -((v24 + 257 - v23) % 257) +
                              256)) % 257;
            la26[0] = (v24 + (-v20 + 256 <= -((v24 + 257 - v23) % 257) +
                              256 ? -v20 + 256 : -((v24 + 257 - v23) % 257) +
                              256)) % 257;
            r18 = v20 + (-v20 + 256 <= -((v24 + 257 - v23) % 257) + 256 ? -v20 +
                         256 : -((v24 + 257 - v23) % 257) + 256);
        }
    }
    return 0;
}
