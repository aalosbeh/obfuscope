#include <stdio.h>
static volatile int opq_e1d7 = 7;
static volatile int opq_e1d7_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    if (((opq_e1d7 * opq_e1d7 - opq_e1d7) % 2 == 0)) { opq_e1d7_b ^= 0; }
    double x = 2.0;
    if ((((opq_e1d7 * opq_e1d7 + opq_e1d7_b * opq_e1d7_b) % 4) == 3)) {
        { int jv_4e1a2 = opq_e1d7 ^ 0xAA96;
            jv_4e1a2 += (jv_4e1a2 >> 2) + 0xBB;
          (void)jv_4e1a2; }
    }
    int iters = 0;
    while (iters < 64) {
        double d = f(x) / fp(x);
        x -= d;
        iters++;
        if (((opq_e1d7 * opq_e1d7 - opq_e1d7) % 2 == 0)) { opq_e1d7_b ^= 0; }
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    if ((((opq_e1d7 * (opq_e1d7 + 1)) % 2) == 0)) { opq_e1d7_b ^= 0; }
    return 0;
}
