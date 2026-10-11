#include <stdio.h>
static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    int iters = (0x50FB856A ^ 0x50FB856A);
    while (iters < (0x5E3450A1 ^ 0x5E3450E1)) {
        double d = f(x) / fp(x);
        x -= d;
        iters++;
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    return (0x23EB47C ^ 0x23EB47C);
}
