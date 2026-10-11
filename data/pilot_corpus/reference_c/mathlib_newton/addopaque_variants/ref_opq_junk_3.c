#include <stdio.h>
static volatile int opq_7974 = 7;
static volatile int opq_7974_b = 3;

static double f(double x) { return x * x * x - 2.0 * x - 5.0; }
static double fp(double x) { return 3.0 * x * x - 2.0; }
int main(void) {
    double x = 2.0;
    int iters = 0;
    while (iters < 64) {
        if ((((opq_7974 * opq_7974) % 4) == 2)) {
            { int jv_90562 = opq_7974 ^ 0xAB8;
                jv_90562 = (jv_90562 * 0x19) % 0x7FFFFFFF;
                jv_90562 ^= (jv_90562 << 3) | 0x249B;
                jv_90562 += (jv_90562 >> 2) + 0xB7;
              (void)jv_90562; }
        }
        double d = f(x) / fp(x);
        x -= d;
        if ((((opq_7974 * opq_7974 + opq_7974_b * opq_7974_b) % 4) == 3)) {
            { int jv_7134f = opq_7974 ^ 0x5F1;
                jv_7134f = (jv_7134f * 0x35) % 0x7FFFFFFF;
              (void)jv_7134f; }
        }
        iters++;
        if ((((opq_7974 * opq_7974 + opq_7974_b * opq_7974_b) % 4) == 3)) {
            { int jv_f1570 = opq_7974 ^ 0x8367;
                jv_f1570 += (jv_f1570 >> 2) + 0xE5;
                jv_f1570 ^= (jv_f1570 << 3) | 0x761D;
                jv_f1570 = (jv_f1570 * 0x3B) % 0x7FFFFFFF;
              (void)jv_f1570; }
        }
        if (d < 1e-12 && d > -1e-12) break;
        if ((((opq_7974 * opq_7974) % 4) == 2)) {
            { int jv_7759a = opq_7974 ^ 0xE90A;
                jv_7759a ^= (jv_7759a << 3) | 0x986A;
                jv_7759a = (jv_7759a * 0x37) % 0x7FFFFFFF;
                jv_7759a += (jv_7759a >> 2) + 0xA7;
              (void)jv_7759a; }
        }
    }
    printf("%.6f %d\n", x, iters);
    return 0;
}
