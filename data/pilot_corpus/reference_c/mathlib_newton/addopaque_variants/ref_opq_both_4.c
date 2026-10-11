#include <stdio.h>
static volatile int opq_a53b = 7;
static volatile int opq_a53b_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    if ((((opq_a53b * opq_a53b + opq_a53b_b * opq_a53b_b) % 4) == 3)) {
        { int jv_c518c = opq_a53b ^ 0xD379;
            jv_c518c ^= (jv_c518c << 3) | 0x4421;
            jv_c518c = (jv_c518c * 0x1A) % 0x7FFFFFFF;
          (void)jv_c518c; }
    }
    int iters = 0;
    while (iters < 64) {
        if ((((opq_a53b * opq_a53b) % 4) == 2)) {
            { int jv_81d57 = opq_a53b ^ 0x1AAF;
                jv_81d57 ^= (jv_81d57 << 3) | 0x49EF;
              (void)jv_81d57; }
        }
        double d = f(x) / fp(x);
        x -= d;
        if ((((opq_a53b * opq_a53b + opq_a53b) % 2) == 0)) { opq_a53b_b ^= 0; }
        iters++;
        if (((opq_a53b * opq_a53b - opq_a53b) % 2 == 0)) { opq_a53b_b ^= 0; }
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    return 0;
}
