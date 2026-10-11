#include <stdio.h>
static volatile int opq_ad92 = 7;
static volatile int opq_ad92_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    if ((((opq_ad92 * opq_ad92 + opq_ad92_b * opq_ad92_b) % 4) == 3)) {
        { int jv_d591f = opq_ad92 ^ 0x44CF;
            jv_d591f ^= (jv_d591f << 3) | 0xE3F;
          (void)jv_d591f; }
    }
    int iters = 0;
    while (iters < 64) {
        double d = f(x) / fp(x);
        if ((((opq_ad92 * opq_ad92) % 4) == 2)) {
            { int jv_69470 = opq_ad92 ^ 0x1A84;
                jv_69470 += (jv_69470 >> 2) + 0xED;
                jv_69470 ^= (jv_69470 << 3) | 0x4E0D;
              (void)jv_69470; }
        }
        x -= d;
        iters++;
        if (d < 1e-12 && d > -1e-12) break;
        if ((((opq_ad92 * opq_ad92 + opq_ad92_b * opq_ad92_b) % 4) == 3)) {
            { int jv_5d6c1 = opq_ad92 ^ 0xB7B6;
                jv_5d6c1 += (jv_5d6c1 >> 2) + 0xB7;
                jv_5d6c1 = (jv_5d6c1 * 0x17) % 0x7FFFFFFF;
              (void)jv_5d6c1; }
        }
    }
    printf("%.6f %d\n", x, iters);
    if ((((opq_ad92 * opq_ad92 + opq_ad92_b * opq_ad92_b) % 4) == 3)) {
        { int jv_c27f1 = opq_ad92 ^ 0xAE7F;
            jv_c27f1 = (jv_c27f1 * 0x28) % 0x7FFFFFFF;
            jv_c27f1 += (jv_c27f1 >> 2) + 0x4;
          (void)jv_c27f1; }
    }
    return 0;
}
