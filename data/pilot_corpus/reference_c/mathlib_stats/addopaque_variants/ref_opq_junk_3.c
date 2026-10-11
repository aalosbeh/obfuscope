#include <stdio.h>
static volatile int opq_c876 = 7;
static volatile int opq_c876_b = 3;

#define N 40
int main(void) {
    if ((((opq_c876 * opq_c876 + opq_c876_b * opq_c876_b) % 4) == 3)) {
        { int jv_6b90d = opq_c876 ^ 0xC0B2;
            jv_6b90d += (jv_6b90d >> 2) + 0x86;
            jv_6b90d ^= (jv_6b90d << 3) | 0x9D2A;
            jv_6b90d = (jv_6b90d * 0x37) % 0x7FFFFFFF;
          (void)jv_6b90d; }
    }
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    if ((((opq_c876 * opq_c876) % 4) == 2)) {
        { int jv_b5319 = opq_c876 ^ 0xA946;
            jv_b5319 = (jv_b5319 * 0x20) % 0x7FFFFFFF;
            jv_b5319 ^= (jv_b5319 << 3) | 0xC855;
            jv_b5319 += (jv_b5319 >> 2) + 0xE2;
          (void)jv_b5319; }
    }
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        if ((((opq_c876 * opq_c876 + opq_c876_b * opq_c876_b) % 4) == 3)) {
            { int jv_e7d55 = opq_c876 ^ 0x7FA0;
                jv_e7d55 += (jv_e7d55 >> 2) + 0x27;
                jv_e7d55 = (jv_e7d55 * 0x18) % 0x7FFFFFFF;
              (void)jv_e7d55; }
        }
        double d = x[i] - mean;
        if ((((opq_c876 * opq_c876 + opq_c876_b * opq_c876_b) % 4) == 3)) {
            { int jv_cb6a1 = opq_c876 ^ 0xF28C;
                jv_cb6a1 ^= (jv_cb6a1 << 3) | 0x5548;
                jv_cb6a1 += (jv_cb6a1 >> 2) + 0x92;
              (void)jv_cb6a1; }
        }
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if ((((opq_c876 * opq_c876) % 4) == 2)) {
            { int jv_f5c17 = opq_c876 ^ 0x5BBA;
                jv_f5c17 = (jv_f5c17 * 0xB) % 0x7FFFFFFF;
                jv_f5c17 ^= (jv_f5c17 << 3) | 0x6856;
              (void)jv_f5c17; }
        }
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    if ((((opq_c876 * opq_c876) % 4) == 2)) {
        { int jv_5f6a2 = opq_c876 ^ 0xC3B3;
            jv_5f6a2 ^= (jv_5f6a2 << 3) | 0xC00A;
          (void)jv_5f6a2; }
    }
    return 0;
}
