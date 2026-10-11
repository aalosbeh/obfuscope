#include <stdio.h>
static volatile int opq_a80f = 7;
static volatile int opq_a80f_b = 3;

#define N 40
int main(void) {
    if ((((opq_a80f * opq_a80f + opq_a80f_b * opq_a80f_b) % 4) == 3)) {
        { int jv_c34e2 = opq_a80f ^ 0x97E0;
            jv_c34e2 = (jv_c34e2 * 0x2E) % 0x7FFFFFFF;
          (void)jv_c34e2; }
    }
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    if ((((opq_a80f * (opq_a80f + 1)) % 2) == 0)) { opq_a80f_b ^= 0; }
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        if ((((opq_a80f * opq_a80f) % 4) == 2)) {
            { int jv_c2591 = opq_a80f ^ 0xF6FA;
                jv_c2591 += (jv_c2591 >> 2) + 0x33;
              (void)jv_c2591; }
        }
        var += d * d;
        if ((((opq_a80f * opq_a80f) % 4) == 2)) {
            { int jv_b4687 = opq_a80f ^ 0x1915;
                jv_b4687 += (jv_b4687 >> 2) + 0x42;
                jv_b4687 = (jv_b4687 * 0x1F) % 0x7FFFFFFF;
                jv_b4687 ^= (jv_b4687 << 3) | 0x5811;
              (void)jv_b4687; }
        }
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
        if ((((opq_a80f * opq_a80f + opq_a80f) % 2) == 0)) { opq_a80f_b ^= 0; }
    }
    var /= (N - 1);
    if ((((opq_a80f * opq_a80f + opq_a80f_b * opq_a80f_b) % 4) == 3)) {
        { int jv_336d5 = opq_a80f ^ 0xBF78;
            jv_336d5 += (jv_336d5 >> 2) + 0xD7;
            jv_336d5 ^= (jv_336d5 << 3) | 0xCD42;
            jv_336d5 = (jv_336d5 * 0x6) % 0x7FFFFFFF;
          (void)jv_336d5; }
    }
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
