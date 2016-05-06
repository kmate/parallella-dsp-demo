#include <e-feldspar.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
uint32_t *const la13 = (uint32_t *) 8192;
uint32_t *const la14 = (uint32_t *) 2157985808;
uint32_t *const la15 = (uint32_t *) 2157985812;
uint32_t *const la16 = (uint32_t *) 8196;
float _Complex *const la17 = (float _Complex *) 8200;
uint32_t *const la19 = (uint32_t *) 12312;
uint32_t *const la20 = (uint32_t *) 12316;
uint32_t *const la21 = (uint32_t *) 2226135044;
float _Complex *const la22 = (float _Complex *) 2226135048;
int main()
{
    while (1) {
        float _Complex _a0[513];
        float _Complex *a0 = _a0;
        uint32_t r1;
        uint32_t v8;
        uint32_t v9;
        uint32_t r10;
        float _Complex _a11[513];
        float _Complex *a11 = _a11;
        uint32_t v12;
        uint32_t r13;
        float _Complex _a14[513];
        float _Complex *a14 = _a14;
        uint32_t v15;
        uint32_t r16;
        
        r1 = 0;
        while (1) {
            uint32_t v2;
            uint32_t v3;
            uint32_t v6;
            uint32_t v7;
            
            v2 = r1;
            if (!(v2 < 513))
                break;
            v3 = r1;
            while (1) {
                uint32_t v4;
                uint32_t v5;
                
                v4 = la13[0];
                v5 = la16[0];
                if (!(v4 == v5))
                    break;
            }
            v6 = la13[0];
            v7 = la16[0];
            if (v6 + (-v3 + 513 <= (v7 + 514 - v6) % 514 ? -v3 + 513 : (v7 +
                                                                        514 -
                                                                        v6) %
                      514) <= 514) {
                core_read_local(la17, a0, v6, v3, v3 + (-v3 + 513 <= (v7 + 514 -
                                                                      v6) %
                                                        514 ? -v3 + 513 : (v7 +
                                                                           514 -
                                                                           v6) %
                                                        514) - 1);
            } else {
                core_read_local(la17, a0, v6, v3, v3 + (-v6 + 514) - 1);
                core_read_local(la17, a0, 0, v3 + (-v6 + 514), v3 + (-v6 +
                                                                     514) +
                                (-v3 + 513 <= (v7 + 514 - v6) % 514 ? -v3 +
                                 513 : (v7 + 514 - v6) % 514) - (-v6 + 514) -
                                1);
            }
            la13[0] = (v6 + (-v3 + 513 <= (v7 + 514 - v6) % 514 ? -v3 +
                             513 : (v7 + 514 - v6) % 514)) % 514;
            la14[0] = (v6 + (-v3 + 513 <= (v7 + 514 - v6) % 514 ? -v3 +
                             513 : (v7 + 514 - v6) % 514)) % 514;
            r1 = v3 + (-v3 + 513 <= (v7 + 514 - v6) % 514 ? -v3 + 513 : (v7 +
                                                                         514 -
                                                                         v6) %
                       514);
        }
        v8 = la13[0];
        v9 = la16[0];
        if (v8 == v9 && v9 == 513) {
            la13[0] = 0;
            la14[0] = 0;
            la15[0] = 0;
            la16[0] = 0;
        }
        r10 = 513;
        for (v12 = 0; v12 < 513; v12++) {
            a11[(uint32_t) lround((float) v12 * 2.0)] =
                (uint32_t) lround((float) v12 * 2.0) < 513 ? creal(a0[v12]) +
                I * (2.0 * cimag(a0[v12])) : 0.0;
        }
        r13 = 513;
        for (v15 = 0; v15 < 513; v15++) {
            a14[v15] = a11[v15];
        }
        r16 = 0;
        while (1) {
            uint32_t v17;
            uint32_t v18;
            uint32_t v21;
            uint32_t v22;
            
            v17 = r16;
            if (!(v17 < 513))
                break;
            v18 = r16;
            while (1) {
                uint32_t v19;
                uint32_t v20;
                
                v19 = la19[0];
                v20 = la20[0];
                if (!((v20 + 1) % 514 == v19))
                    break;
            }
            v21 = la19[0];
            v22 = la20[0];
            if (v22 + (-v18 + 513 <= -((v22 + 514 - v21) % 514) + 513 ? -v18 +
                       513 : -((v22 + 514 - v21) % 514) + 513) <= 514) {
                core_write_local(la22, a14, v22, v18, v18 + (-v18 + 513 <=
                                                             -((v22 + 514 -
                                                                v21) % 514) +
                                                             513 ? -v18 +
                                                             513 : -((v22 +
                                                                      514 -
                                                                      v21) %
                                                                     514) +
                                                             513) - 1);
            } else {
                core_write_local(la22, a14, v22, v18, v18 + (-v22 + 514) - 1);
                core_write_local(la22, a14, 0, v18 + (-v22 + 514), v18 + (-v22 +
                                                                          514) +
                                 ((-v18 + 513 <= -((v22 + 514 - v21) % 514) +
                                   513 ? -v18 + 513 : -((v22 + 514 - v21) %
                                                        514) + 513) - (-v22 +
                                                                       514)) -
                                 1);
            }
            la20[0] = (v22 + (-v18 + 513 <= -((v22 + 514 - v21) % 514) +
                              513 ? -v18 + 513 : -((v22 + 514 - v21) % 514) +
                              513)) % 514;
            la21[0] = (v22 + (-v18 + 513 <= -((v22 + 514 - v21) % 514) +
                              513 ? -v18 + 513 : -((v22 + 514 - v21) % 514) +
                              513)) % 514;
            r16 = v18 + (-v18 + 513 <= -((v22 + 514 - v21) % 514) + 513 ? -v18 +
                         513 : -((v22 + 514 - v21) % 514) + 513);
        }
    }
    return 0;
}
