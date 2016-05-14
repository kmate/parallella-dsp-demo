#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <tgmath.h>
volatile uint32_t *const la38 = (uint32_t *) 8192;
volatile uint32_t *const la39 = (uint32_t *) 2222990360;
volatile uint32_t *const la40 = (uint32_t *) 2222990364;
volatile uint32_t *const la41 = (uint32_t *) 8196;
volatile float _Complex *const la42 = (float _Complex *) 8200;
volatile uint32_t *const la44 = (uint32_t *) 9240;
volatile uint32_t *const la45 = (uint32_t *) 9244;
volatile uint32_t *const la46 = (uint32_t *) 2291146756;
volatile float _Complex *const la47 = (float _Complex *) 2291146760;
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
        uint32_t v20;
        uint32_t v21;
        uint32_t r22;
        uint32_t v23;
        uint32_t r25;
        float _Complex _a26[256];
        float _Complex *a26 = _a26;
        uint32_t v27;
        uint32_t r36;
        
        r4 = 0;
        while (1) {
            uint32_t v5;
            uint32_t v6;
            uint32_t v9;
            uint32_t v10;
            uint32_t r11;
            uint32_t let12;
            uint32_t r13;
            uint32_t let14;
            uint32_t r15;
            uint32_t let18;
            uint32_t r19;
            
            v5 = r4;
            if (!(v5 < 129))
                break;
            v6 = r4;
            while (1) {
                uint32_t v7;
                uint32_t v8;
                
                v7 = la38[0];
                v8 = la41[0];
                if (!(v7 == v8))
                    break;
            }
            v9 = la38[0];
            v10 = la41[0];
            r11 = 130;
            let12 = r11 + v10 - v9;
            r13 = let12 < r11 ? let12 : let12 - r11;
            let14 = -v6 + 129;
            r15 = let14 <= r13 ? let14 : r13;
            if (v9 + r15 <= r11) {
                core_read_local(la42, a3, v9, v6, v6 + r15 - 1);
            } else {
                uint32_t r16;
                uint32_t r17;
                
                r16 = r11 - v9;
                core_read_local(la42, a3, v9, v6, v6 + r16 - 1);
                r17 = v6 + r16;
                core_read_local(la42, a3, 0, r17, r17 + r15 - r16 - 1);
            }
            let18 = v9 + r15;
            r19 = let18 < r11 ? let18 : let18 - r11;
            la38[0] = r19;
            la39[0] = r19;
            r4 = v6 + r15;
        }
        v20 = la38[0];
        v21 = la41[0];
        if (v20 == v21 && v21 == 129) {
            la38[0] = 0;
            la39[0] = 0;
            la40[0] = 0;
            la41[0] = 0;
        }
        r22 = 129;
        for (v23 = 0; v23 < 129; v23++) {
            float let24;
            
            let24 = (float) v23;
            a1[v23] = a1[v23] + (2.0 * FELD_PI * ((cimag(a3[v23]) - let24 *
                                                   172.26563) / 172.26563) /
                                 4.0 + let24 * 1.5707964);
        }
        r25 = 256;
        for (v27 = 0; v27 < 256; v27++) {
            float let28;
            float let29;
            float let30;
            float let31;
            float let32;
            float _Complex v33;
            
            let28 = creal(a3[v27]);
            let29 = (float) v27;
            let30 = a1[v27] + (2.0 * FELD_PI * ((cimag(a3[v27]) - let29 *
                                                 172.26563) / 172.26563) / 4.0 +
                               let29 * 1.5707964);
            let31 = 2.0 * FELD_PI;
            let32 = 1.5707964 - let30;
            if (v27 <= 129) {
                float let34;
                float let35;
                
                let34 = let30 - let31 * (float) round(let30 / let31 + 0.5);
                let35 = let32 - let31 * (float) round(let32 / let31 + 0.5);
                v33 = let28 * (1.0 + (0.0 + (-0.4999999 + (0.0 + (4.1666523e-2 +
                                                                  (0.0 +
                                                                   (-1.3887971e-3 +
                                                                    (0.0 +
                                                                     (2.4773424e-5 +
                                                                      (0.0 +
                                                                       (-2.7113379e-7 +
                                                                        (0.0 +
                                                                         (1.736915e-9 +
                                                                          0.0 *
                                                                          let34) *
                                                                         let34) *
                                                                        let34) *
                                                                       let34) *
                                                                      let34) *
                                                                     let34) *
                                                                    let34) *
                                                                   let34) *
                                                                  let34) *
                                                           let34) * let34) *
                                      let34) * let34) + I * (let28 * (1.0 +
                                                                      (0.0 +
                                                                       (-0.4999999 +
                                                                        (0.0 +
                                                                         (4.1666523e-2 +
                                                                          (0.0 +
                                                                           (-1.3887971e-3 +
                                                                            (0.0 +
                                                                             (2.4773424e-5 +
                                                                              (0.0 +
                                                                               (-2.7113379e-7 +
                                                                                (0.0 +
                                                                                 (1.736915e-9 +
                                                                                  0.0 *
                                                                                  let35) *
                                                                                 let35) *
                                                                                let35) *
                                                                               let35) *
                                                                              let35) *
                                                                             let35) *
                                                                            let35) *
                                                                           let35) *
                                                                          let35) *
                                                                         let35) *
                                                                        let35) *
                                                                       let35) *
                                                                      let35));
            } else {
                v33 = 0.0;
            }
            a26[v27] = v33;
        }
        r36 = 0;
        while (1) {
            uint32_t v37;
            uint32_t v38;
            uint32_t v42;
            uint32_t v43;
            uint32_t let44;
            uint32_t r45;
            uint32_t r46;
            uint32_t let47;
            uint32_t r48;
            uint32_t let51;
            uint32_t r52;
            
            v37 = r36;
            if (!(v37 < 256))
                break;
            v38 = r36;
            while (1) {
                uint32_t v39;
                uint32_t v40;
                uint32_t let41;
                
                v39 = la44[0];
                v40 = la45[0];
                let41 = v40 + 1;
                if (!((let41 < 257 ? let41 : v40 + 4294967040) == v39))
                    break;
            }
            v42 = la44[0];
            v43 = la45[0];
            let44 = v43 + 257 - v42;
            r45 = let44 < 257 ? let44 : let44 - 257;
            r46 = -r45 + 256;
            let47 = -v38 + 256;
            r48 = let47 <= r46 ? let47 : r46;
            if (v43 + r48 <= 257) {
                core_write_local(la47, a26, v43, v38, v38 + r48 - 1);
            } else {
                uint32_t r49;
                uint32_t r50;
                
                r49 = -v43 + 257;
                core_write_local(la47, a26, v43, v38, v38 + r49 - 1);
                r50 = v38 + r49;
                core_write_local(la47, a26, 0, r50, r50 + (r48 - r49) - 1);
            }
            let51 = v43 + r48;
            r52 = let51 < 257 ? let51 : let51 - 257;
            la45[0] = r52;
            la46[0] = r52;
            r36 = v38 + r48;
        }
    }
    return 0;
}
