#include <e-feldspar.h>
#include <e-lib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
volatile uint32_t *const la73 = (uint32_t *) 8192;
volatile uint32_t *const la74 = (uint32_t *) 2358259728;
volatile uint32_t *const la75 = (uint32_t *) 2358259732;
volatile uint32_t *const la76 = (uint32_t *) 8196;
volatile float *const la77 = (float *) 8200;
volatile uint32_t *const la78 = (uint32_t *) 10252;
volatile uint32_t *const la79 = (uint32_t *) 10256;
volatile void *const sa80 = (void *) 16779268;
extern int _CORE_ROW_;
asm(".global __CORE_ROW_");
asm(".set __CORE_ROW_,35");
extern int _CORE_COL_;
asm(".global __CORE_COL_");
asm(".set __CORE_COL_,8");
int main()
{
    float _a0[] = {0.0, 3.7640333e-5, 1.5059114e-4, 3.388226e-4, 6.0227513e-4,
                   9.409487e-4, 1.3547838e-3, 1.8436909e-3, 2.4076402e-3,
                   3.0465126e-3, 3.7602186e-3, 4.548669e-3, 5.411744e-3,
                   6.3492954e-3, 7.3611736e-3, 8.44726e-3, 9.607375e-3,
                   1.084131e-2, 1.21489465e-2, 1.3530016e-2, 1.4984369e-2,
                   1.6511768e-2, 1.8111974e-2, 1.9784749e-2, 2.1529824e-2,
                   2.334699e-2, 2.5235921e-2, 2.7196348e-2, 2.9227972e-2,
                   3.1330496e-2, 3.3503592e-2, 3.574696e-2, 3.8060248e-2,
                   4.0443063e-2, 4.289514e-2, 4.5416027e-2, 4.8005342e-2,
                   5.0662756e-2, 5.338785e-2, 5.618018e-2, 5.9039384e-2,
                   6.196496e-2, 6.4956516e-2, 6.801358e-2, 7.11357e-2,
                   7.43224e-2, 7.757321e-2, 8.0887645e-2, 8.42652e-2,
                   8.7705374e-2, 9.120759e-2, 9.4771415e-2, 9.839624e-2,
                   0.10208154, 0.105826795, 0.10963139, 0.11349478, 0.11741638,
                   0.12139559, 0.1254318, 0.12952444, 0.13367286, 0.13787645,
                   0.1421346, 0.14644662, 0.15081188, 0.15522975, 0.1596995,
                   0.16422054, 0.16879213, 0.1734136, 0.17808422, 0.18280336,
                   0.18757027, 0.19238421, 0.1972445, 0.20215034, 0.20710108,
                   0.21209592, 0.21713409, 0.2222149, 0.22733751, 0.23250118,
                   0.23770517, 0.24294865, 0.24823079, 0.2535509, 0.25890815,
                   0.26430166, 0.26973063, 0.27519435, 0.28069192, 0.28622246,
                   0.29178524, 0.29737937, 0.30300403, 0.3086583, 0.31434143,
                   0.3200525, 0.32579064, 0.33155507, 0.33734488, 0.34315917,
                   0.34899703, 0.35485768, 0.36074018, 0.3666436, 0.37256718,
                   0.37850994, 0.38447094, 0.3904494, 0.39644432, 0.40245488,
                   0.40848005, 0.41451907, 0.42057097, 0.42663476, 0.43270966,
                   0.43879467, 0.44488895, 0.45099142, 0.45710137, 0.46321777,
                   0.46933964, 0.47546616, 0.4815964, 0.48772943, 0.49386424,
                   0.5, 0.5061358, 0.5122706, 0.51840365, 0.52453387, 0.5306604,
                   0.53678226, 0.54289865, 0.5490086, 0.5551111, 0.5612053,
                   0.56729037, 0.5733653, 0.5794291, 0.585481, 0.59152,
                   0.59754515, 0.6035557, 0.60955065, 0.6155291, 0.6214901,
                   0.6274328, 0.63335645, 0.6392598, 0.6451424, 0.651003,
                   0.65684086, 0.6626552, 0.668445, 0.67420936, 0.6799475,
                   0.68565863, 0.69134176, 0.69699603, 0.7026207, 0.70821476,
                   0.71377754, 0.71930814, 0.7248057, 0.73026943, 0.7356984,
                   0.74109197, 0.7464491, 0.7517692, 0.75705135, 0.7622949,
                   0.76749885, 0.7726625, 0.7777852, 0.7828659, 0.7879041,
                   0.79289895, 0.79784966, 0.8027556, 0.8076159, 0.8124298,
                   0.8171966, 0.82191575, 0.8265864, 0.8312079, 0.83577955,
                   0.84030056, 0.8447703, 0.8491881, 0.8535534, 0.85786545,
                   0.8621236, 0.86632717, 0.87047565, 0.8745682, 0.8786044,
                   0.8825836, 0.88650525, 0.89036864, 0.89417326, 0.89791846,
                   0.9016038, 0.9052286, 0.9087924, 0.9122946, 0.9157348,
                   0.9191124, 0.9224268, 0.92567766, 0.9288643, 0.93198645,
                   0.9350435, 0.9380351, 0.94096065, 0.9438199, 0.9466121,
                   0.94933724, 0.95199466, 0.954584, 0.9571049, 0.95955694,
                   0.9619398, 0.96425307, 0.9664964, 0.96866953, 0.970772,
                   0.9728037, 0.9747641, 0.97665304, 0.9784702, 0.98021525,
                   0.98188806, 0.9834882, 0.98501563, 0.98647, 0.9878511,
                   0.9891587, 0.9903927, 0.9915527, 0.9926388, 0.9936507,
                   0.99458826, 0.99545133, 0.9962398, 0.9969535, 0.99759233,
                   0.9981563, 0.99864525, 0.9990591, 0.99939775, 0.9996612,
                   0.99984944, 0.99996233, 1.0, 0.99996233, 0.99984944,
                   0.9996612, 0.99939775, 0.9990591, 0.9986452, 0.9981563,
                   0.99759233, 0.9969535, 0.9962398, 0.99545133, 0.99458826,
                   0.9936507, 0.9926388, 0.9915527, 0.9903926, 0.98915863,
                   0.987851, 0.98647, 0.98501563, 0.9834882, 0.98188806,
                   0.9802152, 0.97847015, 0.976653, 0.9747641, 0.97280365,
                   0.970772, 0.9686695, 0.96649635, 0.964253, 0.96193975,
                   0.95955694, 0.95710486, 0.954584, 0.95199466, 0.9493372,
                   0.9466121, 0.9438198, 0.94096065, 0.938035, 0.93504345,
                   0.9319864, 0.92886424, 0.9256776, 0.9224268, 0.9191123,
                   0.91573477, 0.9122946, 0.9087924, 0.90522856, 0.90160376,
                   0.89791846, 0.8941732, 0.8903686, 0.8865052, 0.8825836,
                   0.87860435, 0.8745682, 0.87047553, 0.8663271, 0.8621235,
                   0.85786533, 0.8535533, 0.8491881, 0.8447703, 0.8403005,
                   0.8357794, 0.8312079, 0.8265865, 0.8219158, 0.81719667,
                   0.8124298, 0.80761576, 0.8027555, 0.7978496, 0.7928989,
                   0.787904, 0.7828658, 0.777785, 0.7726624, 0.7674987,
                   0.76229465, 0.7570514, 0.7517692, 0.7464491, 0.74109185,
                   0.73569834, 0.7302693, 0.7248056, 0.719308, 0.7137775,
                   0.7082147, 0.7026205, 0.69699585, 0.6913416, 0.68565863,
                   0.67994756, 0.67420936, 0.66844493, 0.6626551, 0.65684086,
                   0.65100294, 0.64514226, 0.63925976, 0.6333563, 0.6274327,
                   0.62148994, 0.6155289, 0.6095505, 0.60355574, 0.5975452,
                   0.59151995, 0.5854809, 0.57942903, 0.5733652, 0.5672903,
                   0.56120527, 0.555111, 0.5490085, 0.54289854, 0.53678215,
                   0.5306602, 0.5245337, 0.51840365, 0.5122706, 0.50613576, 0.5,
                   0.4938642, 0.48772934, 0.48159632, 0.47546607, 0.46933955,
                   0.46321762, 0.45710123, 0.45099127, 0.44488874, 0.4387945,
                   0.4327097, 0.4266348, 0.42057094, 0.41451904, 0.40848002,
                   0.4024548, 0.39644426, 0.3904493, 0.38447085, 0.3785098,
                   0.37256706, 0.3666435, 0.36074, 0.3548575, 0.34899706,
                   0.34315914, 0.33734486, 0.33155507, 0.32579064, 0.32005244,
                   0.31434134, 0.30865818, 0.3030039, 0.29737923, 0.2917851,
                   0.2862223, 0.28069174, 0.27519417, 0.2697307, 0.26430166,
                   0.2589081, 0.2535509, 0.24823079, 0.24294859, 0.23770508,
                   0.23250112, 0.22733742, 0.22221479, 0.21713397, 0.21209577,
                   0.20710093, 0.20215037, 0.1972445, 0.19238421, 0.18757024,
                   0.18280333, 0.1780842, 0.17341354, 0.16879204, 0.16422045,
                   0.15969941, 0.15522963, 0.15081176, 0.1464465, 0.14213446,
                   0.13787648, 0.13367286, 0.12952444, 0.1254318, 0.12139556,
                   0.11741632, 0.113494724, 0.10963133, 0.105826735, 0.10208148,
                   9.839615e-2, 9.4771326e-2, 9.1207504e-2, 8.7705255e-2,
                   8.42652e-2, 8.0887645e-2, 7.757321e-2, 7.43224e-2,
                   7.113567e-2, 6.801355e-2, 6.495646e-2, 6.19649e-2,
                   5.9039325e-2, 5.618012e-2, 5.338779e-2, 5.0662696e-2,
                   4.8005283e-2, 4.5415938e-2, 4.289514e-2, 4.0443093e-2,
                   3.8060218e-2, 3.574696e-2, 3.3503592e-2, 3.1330466e-2,
                   2.9227942e-2, 2.7196318e-2, 2.5235862e-2, 2.334693e-2,
                   2.1529794e-2, 1.9784689e-2, 1.8111914e-2, 1.6511708e-2,
                   1.4984369e-2, 1.3530016e-2, 1.21489465e-2, 1.084131e-2,
                   9.607345e-3, 8.44723e-3, 7.3611736e-3, 6.3492656e-3,
                   5.4117143e-3, 4.548669e-3, 3.7602186e-3, 3.0464828e-3,
                   2.4076104e-3, 1.8436909e-3, 1.3547838e-3, 9.409487e-4,
                   6.0227513e-4, 3.387928e-4, 1.5059114e-4, 3.7640333e-5};
    float *a0 = _a0;
    
    while (1) {
        float _a1[512];
        float *a1 = _a1;
        uint32_t r2;
        uint32_t v19;
        uint32_t v20;
        uint32_t r21;
        uint32_t r22;
        uint32_t v24;
        uint32_t r25;
        
        r2 = 0;
        while (1) {
            uint32_t v3;
            uint32_t v4;
            uint32_t v5;
            uint32_t v6;
            uint32_t r7;
            uint32_t let8;
            uint32_t let9;
            uint32_t r10;
            uint32_t let11;
            uint32_t r12;
            uint32_t r13;
            
            v3 = r2;
            if (!(v3 < 512))
                break;
            v4 = r2;
            v5 = la73[0];
            v6 = la76[0];
            r7 = 513;
            let8 = r7 + v6 - v5;
            let9 = r7;
            r10 = let8 < let9 ? let8 : let8 - let9;
            let11 = -v4 + 512;
            r12 = let11 <= r10 ? let11 : r10;
            if (r12 > 0) {
                uint32_t let16;
                uint32_t let17;
                uint32_t r18;
                
                if (v5 + r12 <= r7) {
                    core_read_local(la77, a1, v5, v4, v4 + r12 - 1);
                } else {
                    uint32_t r14;
                    uint32_t r15;
                    
                    r14 = r7 - v5;
                    core_read_local(la77, a1, v5, v4, v4 + r14 - 1);
                    r15 = v4 + r14;
                    core_read_local(la77, a1, 0, r15, r15 + r12 - r14 - 1);
                }
                let16 = v5 + r12;
                let17 = r7;
                r18 = let16 < let17 ? let16 : let16 - let17;
                la73[0] = r18;
                la74[0] = r18;
                r13 = r12;
            } else {
                r13 = 0;
            }
            if (!(0 == r13)) {
                r2 = v4 + r13;
            }
        }
        v19 = la73[0];
        v20 = la76[0];
        if (v19 == v20 && v20 == 512) {
            la73[0] = 0;
            la74[0] = 0;
            la75[0] = 0;
            la76[0] = 0;
        }
        r21 = 512;
        r22 = r21 <= 512 ? r21 : 512;
        
        float _a23[r21 <= 512 ? r21 : 512];
        float *a23 = _a23;
        
        for (v24 = 0; v24 < (r21 <= 512 ? r21 : 512); v24++) {
            a23[v24] = a1[v24] * a0[v24];
        }
        r25 = 0;
        while (1) {
            uint32_t v26;
            uint32_t v27;
            uint32_t v28;
            uint32_t v29;
            uint32_t r30;
            uint32_t let31;
            uint32_t let32;
            uint32_t r33;
            uint32_t r34;
            uint32_t let35;
            uint32_t r36;
            uint32_t r37;
            
            v26 = r25;
            if (!(v26 < 512))
                break;
            v27 = r25;
            v28 = la78[0];
            v29 = la79[0];
            r30 = 513;
            let31 = r30 + v29 - v28;
            let32 = r30;
            r33 = let31 < let32 ? let31 : let31 - let32;
            r34 = r30 - r33 - 1;
            let35 = -v27 + 512;
            r36 = let35 <= r34 ? let35 : r34;
            if (r36 > 0) {
                uint32_t let40;
                uint32_t let41;
                uint32_t r42;
                
                if (v29 + r36 <= r30) {
                    core_write_shared(sa80, a23, v29, v27, v27 + r36 - 1);
                } else {
                    uint32_t r38;
                    uint32_t r39;
                    
                    r38 = r30 - v29;
                    core_write_shared(sa80, a23, v29, v27, v27 + r38 - 1);
                    r39 = v27 + r38;
                    core_write_shared(sa80, a23, 0, r39, r39 + (r36 - r38) - 1);
                }
                let40 = v29 + r36;
                let41 = r30;
                r42 = let40 < let41 ? let40 : let40 - let41;
                la79[0] = r42;
                r37 = r36;
            } else {
                r37 = 0;
            }
            if (!(0 == r37)) {
                r25 = v27 + r37;
            }
        }
    }
    return 0;
}
