#include <stdio.h>
static volatile int opq_e3f4 = 7;
static volatile int opq_e3f4_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    if ((((opq_e3f4 * opq_e3f4) % 4) == 2)) {
        { int jv_813e7 = opq_e3f4 ^ 0x2273;
            jv_813e7 += (jv_813e7 >> 2) + 0xC7;
            jv_813e7 ^= (jv_813e7 << 3) | 0x38BF;
          (void)jv_813e7; }
    }
    double x = 2.0;
    int iters = 0;
    while (iters < 64) {
        if ((((opq_e3f4 * opq_e3f4 + opq_e3f4) % 2) == 0)) { opq_e3f4_b ^= 0; }
        double d = f(x) / fp(x);
        if (((opq_e3f4 * opq_e3f4 - opq_e3f4) % 2 == 0)) { opq_e3f4_b ^= 0; }
        x -= d;
        iters++;
        if ((((opq_e3f4 * opq_e3f4 + opq_e3f4_b * opq_e3f4_b) % 4) == 3)) {
            { int jv_d4e80 = opq_e3f4 ^ 0x428D;
                jv_d4e80 += (jv_d4e80 >> 2) + 0x7E;
                jv_d4e80 ^= (jv_d4e80 << 3) | 0x1367;
              (void)jv_d4e80; }
        }
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    return 0;
}
