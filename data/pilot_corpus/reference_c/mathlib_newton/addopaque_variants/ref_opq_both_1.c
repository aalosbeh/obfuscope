#include <stdio.h>
static volatile int opq_f757 = 7;
static volatile int opq_f757_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    if ((((opq_f757 * opq_f757 + opq_f757_b * opq_f757_b) % 4) == 3)) {
        { int jv_71f30 = opq_f757 ^ 0x2F07;
            jv_71f30 = (jv_71f30 * 0x32) % 0x7FFFFFFF;
            jv_71f30 ^= (jv_71f30 << 3) | 0x233F;
          (void)jv_71f30; }
    }
    double x = 2.0;
    if ((((opq_f757 * opq_f757) % 4) == 2)) {
        { int jv_186cb = opq_f757 ^ 0xD61E;
            jv_186cb += (jv_186cb >> 2) + 0xAC;
            jv_186cb = (jv_186cb * 0x33) % 0x7FFFFFFF;
          (void)jv_186cb; }
    }
    int iters = 0;
    while (iters < 64) {
        double d = f(x) / fp(x);
        if ((((opq_f757 * opq_f757 + opq_f757) % 2) == 0)) { opq_f757_b ^= 0; }
        x -= d;
        iters++;
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    if ((((opq_f757 * opq_f757 + opq_f757) % 2) == 0)) { opq_f757_b ^= 0; }
    return 0;
}
