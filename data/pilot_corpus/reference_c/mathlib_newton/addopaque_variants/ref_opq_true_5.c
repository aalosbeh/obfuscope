#include <stdio.h>
static volatile int opq_b1ba = 7;
static volatile int opq_b1ba_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    if (((opq_b1ba * opq_b1ba - opq_b1ba) % 2 == 0)) { opq_b1ba_b ^= 0; }
    double x = 2.0;
    int iters = 0;
    while (iters < 64) {
        double d = f(x) / fp(x);
        x -= d;
        if ((((opq_b1ba * opq_b1ba + opq_b1ba) % 2) == 0)) { opq_b1ba_b ^= 0; }
        iters++;
        if ((((opq_b1ba * opq_b1ba + opq_b1ba) % 2) == 0)) { opq_b1ba_b ^= 0; }
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    if (((opq_b1ba * opq_b1ba - opq_b1ba) % 2 == 0)) { opq_b1ba_b ^= 0; }
    return 0;
}
