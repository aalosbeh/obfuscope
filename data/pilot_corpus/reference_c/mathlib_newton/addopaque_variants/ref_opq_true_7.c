#include <stdio.h>
static volatile int opq_1263 = 7;
static volatile int opq_1263_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    if (((opq_1263 * opq_1263 - opq_1263) % 2 == 0)) { opq_1263_b ^= 0; }
    double x = 2.0;
    int iters = 0;
    while (iters < 64) {
        if ((((opq_1263 * (opq_1263 + 1)) % 2) == 0)) { opq_1263_b ^= 0; }
        double d = f(x) / fp(x);
        x -= d;
        iters++;
        if (((opq_1263 * opq_1263 - opq_1263) % 2 == 0)) { opq_1263_b ^= 0; }
        if (d < 1e-12 && d > -1e-12) break;
        if (((opq_1263 * opq_1263 - opq_1263) % 2 == 0)) { opq_1263_b ^= 0; }
    }
    printf("%.6f %d\n", x, iters);
    return 0;
}
