#include <stdio.h>
static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    int v_a707e0 = 0;
    while (v_a707e0 < 64) {
        double d = f(x) / fp(x);
        x -= d;
        v_a707e0++;
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, v_a707e0);
    return 0;
}
