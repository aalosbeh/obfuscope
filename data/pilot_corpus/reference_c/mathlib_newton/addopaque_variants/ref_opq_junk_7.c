#include <stdio.h>
static volatile int opq_4e46 = 7;
static volatile int opq_4e46_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    if ((((opq_4e46 * opq_4e46) % 4) == 2)) {
        { int jv_741cb = opq_4e46 ^ 0x2E5C;
            jv_741cb ^= (jv_741cb << 3) | 0x56BA;
            jv_741cb = (jv_741cb * 0x1A) % 0x7FFFFFFF;
            jv_741cb += (jv_741cb >> 2) + 0xE1;
          (void)jv_741cb; }
    }
    int iters = 0;
    while (iters < 64) {
        double d = f(x) / fp(x);
        x -= d;
        if ((((opq_4e46 * opq_4e46 + opq_4e46_b * opq_4e46_b) % 4) == 3)) {
            { int jv_d80da = opq_4e46 ^ 0xAC68;
                jv_d80da += (jv_d80da >> 2) + 0x64;
              (void)jv_d80da; }
        }
        iters++;
        if ((((opq_4e46 * opq_4e46) % 4) == 2)) {
            { int jv_2a6f6 = opq_4e46 ^ 0xDA56;
                jv_2a6f6 += (jv_2a6f6 >> 2) + 0x9F;
                jv_2a6f6 = (jv_2a6f6 * 0x28) % 0x7FFFFFFF;
                jv_2a6f6 ^= (jv_2a6f6 << 3) | 0xDB23;
              (void)jv_2a6f6; }
        }
        if (d < 1e-12 && d > -1e-12) break;
    }
    printf("%.6f %d\n", x, iters);
    if ((((opq_4e46 * opq_4e46) % 4) == 2)) {
        { int jv_5c38b = opq_4e46 ^ 0x71AA;
            jv_5c38b += (jv_5c38b >> 2) + 0x15;
            jv_5c38b = (jv_5c38b * 0x8) % 0x7FFFFFFF;
          (void)jv_5c38b; }
    }
    return 0;
}
