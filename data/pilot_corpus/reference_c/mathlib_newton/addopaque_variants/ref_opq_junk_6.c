#include <stdio.h>
static volatile int opq_ea3a = 7;
static volatile int opq_ea3a_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    if ((((opq_ea3a * opq_ea3a + opq_ea3a_b * opq_ea3a_b) % 4) == 3)) {
        { int jv_13df1 = opq_ea3a ^ 0xF96;
            jv_13df1 ^= (jv_13df1 << 3) | 0x637B;
            jv_13df1 += (jv_13df1 >> 2) + 0xBF;
            jv_13df1 = (jv_13df1 * 0x2A) % 0x7FFFFFFF;
          (void)jv_13df1; }
    }
    int iters = 0;
    while (iters < 64) {
        if ((((opq_ea3a * opq_ea3a) % 4) == 2)) {
            { int jv_bfe60 = opq_ea3a ^ 0xE066;
                jv_bfe60 = (jv_bfe60 * 0x31) % 0x7FFFFFFF;
              (void)jv_bfe60; }
        }
        double d = f(x) / fp(x);
        x -= d;
        iters++;
        if (d < 1e-12 && d > -1e-12) break;
        if ((((opq_ea3a * opq_ea3a + opq_ea3a_b * opq_ea3a_b) % 4) == 3)) {
            { int jv_34da6 = opq_ea3a ^ 0x2906;
                jv_34da6 ^= (jv_34da6 << 3) | 0x5A88;
                jv_34da6 += (jv_34da6 >> 2) + 0x1F;
                jv_34da6 = (jv_34da6 * 0x8) % 0x7FFFFFFF;
              (void)jv_34da6; }
        }
    }
    printf("%.6f %d\n", x, iters);
    if ((((opq_ea3a * opq_ea3a + opq_ea3a_b * opq_ea3a_b) % 4) == 3)) {
        { int jv_59d34 = opq_ea3a ^ 0x26F9;
            jv_59d34 = (jv_59d34 * 0xC) % 0x7FFFFFFF;
          (void)jv_59d34; }
    }
    return 0;
}
