#include <stdio.h>
static volatile int opq_3887 = 7;
static volatile int opq_3887_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    if ((((opq_3887 * (opq_3887 + 1)) % 2) == 0)) { opq_3887_b ^= 0; }
    int iters = 0;
    while (iters < 64) {
        double d = f(x) / fp(x);
        if ((((opq_3887 * (opq_3887 + 1)) % 2) == 0)) { opq_3887_b ^= 0; }
        x -= d;
        iters++;
        if (d < 1e-12 && d > -1e-12) break;
        if (((opq_3887 * opq_3887 - opq_3887) % 2 == 0)) { opq_3887_b ^= 0; }
    }
    printf("%.6f %d\n", x, iters);
    if ((((opq_3887 * (opq_3887 + 1)) % 2) == 0)) { opq_3887_b ^= 0; }
    return 0;
}
