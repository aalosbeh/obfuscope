#include <stdio.h>
static volatile int opq_37c7 = 7;
static volatile int opq_37c7_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    if ((((opq_37c7 * opq_37c7) % 4) == 2)) {
        { int jv_54386 = opq_37c7 ^ 0xB548;
            jv_54386 ^= (jv_54386 << 3) | 0x2E03;
            jv_54386 += (jv_54386 >> 2) + 0x17;
          (void)jv_54386; }
    }
    double x = 2.0;
    if ((((opq_37c7 * opq_37c7) % 4) == 2)) {
        { int jv_96175 = opq_37c7 ^ 0xB9B;
            jv_96175 ^= (jv_96175 << 3) | 0xCF3C;
            jv_96175 = (jv_96175 * 0x14) % 0x7FFFFFFF;
          (void)jv_96175; }
    }
    int iters = 0;
    while (iters < 64) {
        double d = f(x) / fp(x);
        x -= d;
        iters++;
        if ((((opq_37c7 * opq_37c7) % 4) == 2)) {
            { int jv_ad925 = opq_37c7 ^ 0xC33D;
                jv_ad925 ^= (jv_ad925 << 3) | 0x127D;
                jv_ad925 += (jv_ad925 >> 2) + 0xDC;
                jv_ad925 = (jv_ad925 * 0x2D) % 0x7FFFFFFF;
              (void)jv_ad925; }
        }
        if (d < 1e-12 && d > -1e-12) break;
        if ((((opq_37c7 * opq_37c7) % 4) == 2)) {
            { int jv_c2c9e = opq_37c7 ^ 0xD585;
                jv_c2c9e = (jv_c2c9e * 0x1C) % 0x7FFFFFFF;
                jv_c2c9e ^= (jv_c2c9e << 3) | 0x35E2;
              (void)jv_c2c9e; }
        }
    }
    printf("%.6f %d\n", x, iters);
    return 0;
}
