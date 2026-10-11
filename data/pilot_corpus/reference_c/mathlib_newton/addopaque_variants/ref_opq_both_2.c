#include <stdio.h>
static volatile int opq_56dd = 7;
static volatile int opq_56dd_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    int iters = 0;
    while (iters < 64) {
        if ((((opq_56dd * opq_56dd + opq_56dd) % 2) == 0)) { opq_56dd_b ^= 0; }
        double d = f(x) / fp(x);
        x -= d;
        iters++;
        if ((((opq_56dd * opq_56dd + opq_56dd) % 2) == 0)) { opq_56dd_b ^= 0; }
        if (d < 1e-12 && d > -1e-12) break;
        if ((((opq_56dd * opq_56dd + opq_56dd) % 2) == 0)) { opq_56dd_b ^= 0; }
    }
    printf("%.6f %d\n", x, iters);
    if ((((opq_56dd * (opq_56dd + 1)) % 2) == 0)) { opq_56dd_b ^= 0; }
    return 0;
}
