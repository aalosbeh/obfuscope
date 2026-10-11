#include <stdio.h>
static volatile int opq_fd08 = 7;
static volatile int opq_fd08_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    if ((((opq_fd08 * opq_fd08 + opq_fd08) % 2) == 0)) { opq_fd08_b ^= 0; }
    int iters = 0;
    while (iters < 64) {
        double d = f(x) / fp(x);
        if ((((opq_fd08 * opq_fd08 + opq_fd08) % 2) == 0)) { opq_fd08_b ^= 0; }
        x -= d;
        if ((((opq_fd08 * opq_fd08) % 4) == 2)) {
            { int jv_adcbb = opq_fd08 ^ 0x8807;
                jv_adcbb ^= (jv_adcbb << 3) | 0x9F23;
                jv_adcbb += (jv_adcbb >> 2) + 0x19;
                jv_adcbb = (jv_adcbb * 0x16) % 0x7FFFFFFF;
              (void)jv_adcbb; }
        }
        iters++;
        if (d < 1e-12 && d > -1e-12) break;
        if (((opq_fd08 * opq_fd08 - opq_fd08) % 2 == 0)) { opq_fd08_b ^= 0; }
    }
    printf("%.6f %d\n", x, iters);
    return 0;
}
