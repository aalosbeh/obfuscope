#include <stdio.h>
static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    int iters = (0x20E3CCBD ^ 0x20E3CCBD);
    while (iters < (0x416BC6A ^ 0x416BC2A)) {
        double d = f(x) / fp(x);
        x -= d;
        iters++;
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    return (0x35ECDA08 ^ 0x35ECDA08);
}
