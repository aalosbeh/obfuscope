#include <stdio.h>
static volatile int opq_511a = 7;
static volatile int opq_511a_b = 3;

#define N 40
int main(void) {
    double x[N];
    if ((((opq_511a * opq_511a) % 4) == 2)) {
        { int jv_3bee4 = opq_511a ^ 0xF948;
            jv_3bee4 += (jv_3bee4 >> 2) + 0xCF;
          (void)jv_3bee4; }
    }
    unsigned s = 11;
    if ((((opq_511a * opq_511a) % 4) == 2)) {
        { int jv_fb885 = opq_511a ^ 0x5394;
            jv_fb885 = (jv_fb885 * 0x3E) % 0x7FFFFFFF;
          (void)jv_fb885; }
    }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    if ((((opq_511a * opq_511a) % 4) == 2)) {
        { int jv_ec89c = opq_511a ^ 0xD06F;
            jv_ec89c += (jv_ec89c >> 2) + 0x9C;
          (void)jv_ec89c; }
    }
    for (int i = 0; i < N; i++) mean += x[i];
    if ((((opq_511a * opq_511a + opq_511a_b * opq_511a_b) % 4) == 3)) {
        { int jv_e575d = opq_511a ^ 0x5407;
            jv_e575d = (jv_e575d * 0x2B) % 0x7FFFFFFF;
          (void)jv_e575d; }
    }
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if ((((opq_511a * opq_511a) % 4) == 2)) {
            { int jv_5eae4 = opq_511a ^ 0xF7C5;
                jv_5eae4 = (jv_5eae4 * 0x36) % 0x7FFFFFFF;
                jv_5eae4 += (jv_5eae4 >> 2) + 0xAC;
              (void)jv_5eae4; }
        }
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    if ((((opq_511a * opq_511a + opq_511a_b * opq_511a_b) % 4) == 3)) {
        { int jv_a7638 = opq_511a ^ 0x3317;
            jv_a7638 ^= (jv_a7638 << 3) | 0xF5A1;
            jv_a7638 = (jv_a7638 * 0x2C) % 0x7FFFFFFF;
            jv_a7638 += (jv_a7638 >> 2) + 0xB;
          (void)jv_a7638; }
    }
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
