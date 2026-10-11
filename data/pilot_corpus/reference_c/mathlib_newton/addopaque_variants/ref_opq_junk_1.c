#include <stdio.h>
static volatile int opq_20de = 7;
static volatile int opq_20de_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    int iters = 0;
    while (iters < 64) {
        if ((((opq_20de * opq_20de + opq_20de_b * opq_20de_b) % 4) == 3)) {
            { int jv_60cb1 = opq_20de ^ 0x25E7;
                jv_60cb1 += (jv_60cb1 >> 2) + 0x18;
                jv_60cb1 = (jv_60cb1 * 0x31) % 0x7FFFFFFF;
                jv_60cb1 ^= (jv_60cb1 << 3) | 0x4292;
              (void)jv_60cb1; }
        }
        double d = f(x) / fp(x);
        x -= d;
        if ((((opq_20de * opq_20de + opq_20de_b * opq_20de_b) % 4) == 3)) {
            { int jv_2b45e = opq_20de ^ 0x6548;
                jv_2b45e += (jv_2b45e >> 2) + 0xC0;
              (void)jv_2b45e; }
        }
        iters++;
        if ((((opq_20de * opq_20de + opq_20de_b * opq_20de_b) % 4) == 3)) {
            { int jv_afb59 = opq_20de ^ 0xAF5D;
                jv_afb59 = (jv_afb59 * 0x6) % 0x7FFFFFFF;
                jv_afb59 ^= (jv_afb59 << 3) | 0xD9B9;
              (void)jv_afb59; }
        }
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    if ((((opq_20de * opq_20de + opq_20de_b * opq_20de_b) % 4) == 3)) {
        { int jv_fd2e2 = opq_20de ^ 0x5BA5;
            jv_fd2e2 = (jv_fd2e2 * 0x26) % 0x7FFFFFFF;
          (void)jv_fd2e2; }
    }
    return 0;
}
