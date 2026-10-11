#include <stdio.h>
static volatile int opq_dc50 = 7;
static volatile int opq_dc50_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    int iters = 0;
    while (iters < 64) {
        if ((((opq_dc50 * opq_dc50 + opq_dc50) % 2) == 0)) { opq_dc50_b ^= 0; }
        double d = f(x) / fp(x);
        x -= d;
        if ((((opq_dc50 * opq_dc50 + opq_dc50_b * opq_dc50_b) % 4) == 3)) {
            { int jv_59160 = opq_dc50 ^ 0x5882;
                jv_59160 = (jv_59160 * 0xA) % 0x7FFFFFFF;
                jv_59160 += (jv_59160 >> 2) + 0xBD;
                jv_59160 ^= (jv_59160 << 3) | 0x4E15;
              (void)jv_59160; }
        }
        iters++;
        if ((((opq_dc50 * opq_dc50) % 4) == 2)) {
            { int jv_26e3b = opq_dc50 ^ 0x72A1;
                jv_26e3b += (jv_26e3b >> 2) + 0x66;
                jv_26e3b = (jv_26e3b * 0x14) % 0x7FFFFFFF;
                jv_26e3b ^= (jv_26e3b << 3) | 0x4BEB;
              (void)jv_26e3b; }
        }
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    if ((((opq_dc50 * opq_dc50) % 4) == 2)) {
        { int jv_72d48 = opq_dc50 ^ 0xE154;
            jv_72d48 += (jv_72d48 >> 2) + 0x9E;
            jv_72d48 = (jv_72d48 * 0x6) % 0x7FFFFFFF;
            jv_72d48 ^= (jv_72d48 << 3) | 0x7349;
          (void)jv_72d48; }
    }
    return 0;
}
