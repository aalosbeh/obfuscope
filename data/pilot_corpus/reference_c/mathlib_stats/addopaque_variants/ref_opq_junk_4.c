#include <stdio.h>
static volatile int opq_8a70 = 7;
static volatile int opq_8a70_b = 3;

#define N 40
int main(void) {
    double x[N];
    if ((((opq_8a70 * opq_8a70) % 4) == 2)) {
        { int jv_2c8f0 = opq_8a70 ^ 0x8F5B;
            jv_2c8f0 = (jv_2c8f0 * 0x14) % 0x7FFFFFFF;
            jv_2c8f0 ^= (jv_2c8f0 << 3) | 0x25CE;
          (void)jv_2c8f0; }
    }
    unsigned s = 11;
    if ((((opq_8a70 * opq_8a70 + opq_8a70_b * opq_8a70_b) % 4) == 3)) {
        { int jv_cd769 = opq_8a70 ^ 0xD862;
            jv_cd769 = (jv_cd769 * 0x20) % 0x7FFFFFFF;
            jv_cd769 += (jv_cd769 >> 2) + 0x26;
          (void)jv_cd769; }
    }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    if ((((opq_8a70 * opq_8a70 + opq_8a70_b * opq_8a70_b) % 4) == 3)) {
        { int jv_95a1d = opq_8a70 ^ 0x3339;
            jv_95a1d = (jv_95a1d * 0x2C) % 0x7FFFFFFF;
            jv_95a1d ^= (jv_95a1d << 3) | 0xE753;
          (void)jv_95a1d; }
    }
    for (int i = 0; i < N; i++) mean += x[i];
    if ((((opq_8a70 * opq_8a70) % 4) == 2)) {
        { int jv_81ef0 = opq_8a70 ^ 0xE19A;
            jv_81ef0 ^= (jv_81ef0 << 3) | 0x7E28;
            jv_81ef0 += (jv_81ef0 >> 2) + 0x3B;
          (void)jv_81ef0; }
    }
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if ((((opq_8a70 * opq_8a70) % 4) == 2)) {
            { int jv_e3257 = opq_8a70 ^ 0xACA;
                jv_e3257 = (jv_e3257 * 0x25) % 0x7FFFFFFF;
                jv_e3257 ^= (jv_e3257 << 3) | 0xDFB2;
                jv_e3257 += (jv_e3257 >> 2) + 0x49;
              (void)jv_e3257; }
        }
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    if ((((opq_8a70 * opq_8a70 + opq_8a70_b * opq_8a70_b) % 4) == 3)) {
        { int jv_aa02e = opq_8a70 ^ 0xC635;
            jv_aa02e += (jv_aa02e >> 2) + 0x29;
            jv_aa02e = (jv_aa02e * 0x2B) % 0x7FFFFFFF;
          (void)jv_aa02e; }
    }
    return 0;
}
