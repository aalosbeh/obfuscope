#include <stdio.h>
static volatile int opq_daaa = 7;
static volatile int opq_daaa_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    if ((((opq_daaa * opq_daaa + opq_daaa_b * opq_daaa_b) % 4) == 3)) {
        { int jv_e08b4 = opq_daaa ^ 0x5568;
            jv_e08b4 += (jv_e08b4 >> 2) + 0x59;
          (void)jv_e08b4; }
    }
    double x = 2.0;
    int iters = 0;
    while (iters < 64) {
        if ((((opq_daaa * opq_daaa) % 4) == 2)) {
            { int jv_8ffc4 = opq_daaa ^ 0xBB0B;
                jv_8ffc4 ^= (jv_8ffc4 << 3) | 0x44C7;
                jv_8ffc4 += (jv_8ffc4 >> 2) + 0x86;
                jv_8ffc4 = (jv_8ffc4 * 0x25) % 0x7FFFFFFF;
              (void)jv_8ffc4; }
        }
        double d = f(x) / fp(x);
        x -= d;
        if ((((opq_daaa * opq_daaa) % 4) == 2)) {
            { int jv_3d4ac = opq_daaa ^ 0x7B86;
                jv_3d4ac += (jv_3d4ac >> 2) + 0x4C;
              (void)jv_3d4ac; }
        }
        iters++;
        if ((((opq_daaa * opq_daaa) % 4) == 2)) {
            { int jv_6387e = opq_daaa ^ 0x7D16;
                jv_6387e ^= (jv_6387e << 3) | 0x22BC;
                jv_6387e = (jv_6387e * 0x29) % 0x7FFFFFFF;
                jv_6387e += (jv_6387e >> 2) + 0x2D;
              (void)jv_6387e; }
        }
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    return 0;
}
