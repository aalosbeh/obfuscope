#include <stdio.h>
static volatile int opq_74fd = 7;
static volatile int opq_74fd_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    int iters = 0;
    while (iters < 64) {
        if ((((opq_74fd * opq_74fd) % 4) == 2)) {
            { int jv_7eabe = opq_74fd ^ 0xCB3;
                jv_7eabe = (jv_7eabe * 0x13) % 0x7FFFFFFF;
              (void)jv_7eabe; }
        }
        double d = f(x) / fp(x);
        x -= d;
        if ((((opq_74fd * opq_74fd) % 4) == 2)) {
            { int jv_48375 = opq_74fd ^ 0xA675;
                jv_48375 = (jv_48375 * 0x3A) % 0x7FFFFFFF;
              (void)jv_48375; }
        }
        iters++;
        if ((((opq_74fd * (opq_74fd + 1)) % 2) == 0)) { opq_74fd_b ^= 0; }
        if (d < 1e-12 && d > -1e-12) break;
        if ((((opq_74fd * (opq_74fd + 1)) % 2) == 0)) { opq_74fd_b ^= 0; }
    }
    printf("%.6f %d\n", x, iters);
    return 0;
}
