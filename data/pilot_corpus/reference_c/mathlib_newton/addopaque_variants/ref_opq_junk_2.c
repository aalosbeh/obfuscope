#include <stdio.h>
static volatile int opq_d051 = 7;
static volatile int opq_d051_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    if ((((opq_d051 * opq_d051) % 4) == 2)) {
        { int jv_68f0c = opq_d051 ^ 0xF67D;
            jv_68f0c += (jv_68f0c >> 2) + 0x1D;
            jv_68f0c ^= (jv_68f0c << 3) | 0x7731;
          (void)jv_68f0c; }
    }
    double x = 2.0;
    if ((((opq_d051 * opq_d051) % 4) == 2)) {
        { int jv_3c9c0 = opq_d051 ^ 0xBA43;
            jv_3c9c0 += (jv_3c9c0 >> 2) + 0x8E;
            jv_3c9c0 = (jv_3c9c0 * 0x15) % 0x7FFFFFFF;
          (void)jv_3c9c0; }
    }
    int iters = 0;
    while (iters < 64) {
        if ((((opq_d051 * opq_d051 + opq_d051_b * opq_d051_b) % 4) == 3)) {
            { int jv_1d36e = opq_d051 ^ 0xA346;
                jv_1d36e = (jv_1d36e * 0x15) % 0x7FFFFFFF;
              (void)jv_1d36e; }
        }
        double d = f(x) / fp(x);
        x -= d;
        if ((((opq_d051 * opq_d051 + opq_d051_b * opq_d051_b) % 4) == 3)) {
            { int jv_21912 = opq_d051 ^ 0xF9A;
                jv_21912 ^= (jv_21912 << 3) | 0x4AD6;
              (void)jv_21912; }
        }
        iters++;
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    return 0;
}
