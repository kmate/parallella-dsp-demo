#include <assert.h>
#include <feldspar-parallella.h>
#include <stdbool.h>
#include <stdint.h>
#include <tgmath.h>
volatile bool *const la18 = (bool *) 8192;
volatile bool *const la19 = (bool *) 8208;
volatile float _Complex *const la20 = (float _Complex *) 8224;
volatile bool *const la21 = (bool *) 2222989312;
volatile bool *const la22 = (bool *) 2222989328;
volatile float _Complex *const la23 = (float _Complex *) 2222989344;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,33");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,9");
#define FELD_PI 3.141592653589793
int main()
{
    uint32_t r0;
    float _a1[257] __attribute__((aligned(16)));
    float *a1 = _a1;
    uint32_t v2;
    
    r0 = 257;
    r0 = 257;
    for (v2 = 0; v2 < 257; v2++) {
        assert(v2 < 257 && "setArr: index out of bounds");
        a1[v2] = 0.0;
    }
    while (1) {
        uint32_t r3;
        float _Complex _a4[512] __attribute__((aligned(16)));
        float _Complex *a4 = _a4;
        bool v5;
        uint32_t r6;
        float _Complex _a7[257] __attribute__((aligned(16)));
        float _Complex *a7 = _a7;
        uint32_t v8;
        bool v30;
        uint32_t v31;
        
        r3 = 512;
        v5 = core_read_c2c(la20, la18, la19, a4, 0, r3);
        if (!v5) {
            core_close_chan(la23, la21, la22);
            core_halt();
        }
        r6 = 257;
        r6 = 257;
        for (v8 = 0; v8 < 257; v8++) {
            uint32_t let9;
            uint32_t let10;
            uint32_t let11;
            float let12;
            uint32_t let13;
            uint32_t let14;
            uint32_t let15;
            float let16;
            uint32_t let17;
            float let18;
            uint32_t let19;
            uint32_t let20;
            uint32_t let21;
            float _Complex let22;
            float let23;
            float let24;
            float let25;
            float let26;
            uint32_t let27;
            uint32_t let28;
            uint32_t let29;
            
            assert(v8 < 257 && "setArr: index out of bounds");
            assert(v8 < 257 && "indexing outside of Pull vector");
            let9 = v8;
            assert(let9 < 257 && "indexing outside of Pull vector");
            let10 = let9;
            assert(r3 <= 512 && "invalid IArr slice");
            assert(let10 < r3 && "indexing outside of Pull vector");
            let11 = let10;
            assert(r3 <= 512 && "invalid IArr slice");
            assert(let11 < r3 && "arrIx: index out of bounds");
            let12 = fabs(creal(a4[let11]));
            assert(v8 < 257 && "indexing outside of Pull vector");
            let13 = v8;
            assert(let13 < 257 && "indexing outside of Pull vector");
            let14 = let13;
            assert(r3 <= 512 && "invalid IArr slice");
            assert(let14 < r3 && "indexing outside of Pull vector");
            let15 = let14;
            assert(r3 <= 512 && "invalid IArr slice");
            assert(let15 < r3 && "arrIx: index out of bounds");
            let16 = fabs(cimag(a4[let15]));
            assert(v8 < 257 && "indexing outside of Pull vector");
            let17 = v8;
            assert(let17 < 257 && "indexing outside of Pull vector");
            let18 = (float) let17;
            assert(v8 < 257 && "indexing outside of Pull vector");
            let19 = v8;
            assert(let19 < 257 && "indexing outside of Pull vector");
            let20 = let19;
            assert(r3 <= 512 && "invalid IArr slice");
            assert(let20 < r3 && "indexing outside of Pull vector");
            let21 = let20;
            assert(r3 <= 512 && "invalid IArr slice");
            assert(let21 < r3 && "arrIx: index out of bounds");
            let22 = a4[let21];
            let23 = creal(let22);
            let24 = let16 + 1.0e-10;
            let25 = let23 + let24;
            let26 = let23 >= 0.0 ? 0.7853982 - 0.7853982 * ((let23 - let24) /
                                                            let25) : 2.3561945 -
                0.7853982 * (let25 / (let24 - let23));
            assert(v8 < 257 && "indexing outside of Pull vector");
            let27 = v8;
            assert(let27 < 257 && "indexing outside of Pull vector");
            let28 = let27;
            assert(r0 <= 257 && "invalid IArr slice");
            assert(let28 < r0 && "indexing outside of Pull vector");
            let29 = let28;
            assert(r0 <= 257 && "invalid IArr slice");
            assert(let29 < r0 && "arrIx: index out of bounds");
            a7[v8] = 2.0 * (0.9375 * (let12 >= let16 ? let12 : let16) +
                            0.46875 * (let12 <= let16 ? let12 : let16)) + I *
                ((let18 + 4.0 * ((cimag(let22) < 0.0 ? -let26 : let26) -
                                 a1[let29] - let18 * 1.5707964) / (2.0 *
                                                                   FELD_PI)) *
                 86.13281);
        }
        v30 = core_write_c2c(la23, la21, la22, a7, 0, r6);
        if (!v30) {
            core_close_chan(la20, la18, la19);
            core_halt();
        }
        r0 = 257;
        for (v31 = 0; v31 < 257; v31++) {
            uint32_t let32;
            uint32_t let33;
            uint32_t let34;
            float let35;
            uint32_t let36;
            uint32_t let37;
            uint32_t let38;
            float let39;
            float let40;
            float let41;
            float let42;
            
            assert(v31 < 257 && "setArr: index out of bounds");
            assert(v31 < 257 && "indexing outside of Pull vector");
            let32 = v31;
            assert(let32 < 257 && "indexing outside of Pull vector");
            let33 = let32;
            assert(r3 <= 512 && "invalid IArr slice");
            assert(let33 < r3 && "indexing outside of Pull vector");
            let34 = let33;
            assert(r3 <= 512 && "invalid IArr slice");
            assert(let34 < r3 && "arrIx: index out of bounds");
            let35 = cimag(a4[let34]);
            assert(v31 < 257 && "indexing outside of Pull vector");
            let36 = v31;
            assert(let36 < 257 && "indexing outside of Pull vector");
            let37 = let36;
            assert(r3 <= 512 && "invalid IArr slice");
            assert(let37 < r3 && "indexing outside of Pull vector");
            let38 = let37;
            assert(r3 <= 512 && "invalid IArr slice");
            assert(let38 < r3 && "arrIx: index out of bounds");
            let39 = creal(a4[let38]);
            let40 = fabs(let35) + 1.0e-10;
            let41 = let39 + let40;
            let42 = let39 >= 0.0 ? 0.7853982 - 0.7853982 * ((let39 - let40) /
                                                            let41) : 2.3561945 -
                0.7853982 * (let41 / (let40 - let39));
            a1[v31] = let35 < 0.0 ? -let42 : let42;
        }
    }
    return 0;
}
