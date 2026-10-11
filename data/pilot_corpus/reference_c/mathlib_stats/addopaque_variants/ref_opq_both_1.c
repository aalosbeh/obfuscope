#include <stdio.h>
static volatile int opq_3e23 = 7;
static volatile int opq_3e23_b = 3;

#define N 40
int main(void) {
    if (((opq_3e23 * opq_3e23 - opq_3e23) % 2 == 0)) { opq_3e23_b ^= 0; }
    double x[N];
    if ((((opq_3e23 * opq_3e23 + opq_3e23) % 2) == 0)) { opq_3e23_b ^= 0; }
    unsigned s = 11;
    if ((((opq_3e23 * opq_3e23) % 4) == 2)) {
        { int jv_2695d = opq_3e23 ^ 0x7E75;
            jv_2695d += (jv_2695d >> 2) + 0x71;
          (void)jv_2695d; }
    }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    if ((((opq_3e23 * opq_3e23) % 4) == 2)) {
        { int jv_d06b3 = opq_3e23 ^ 0xC648;
            jv_d06b3 = (jv_d06b3 * 0x39) % 0x7FFFFFFF;
            jv_d06b3 ^= (jv_d06b3 << 3) | 0x544A;
            jv_d06b3 += (jv_d06b3 >> 2) + 0x4C;
          (void)jv_d06b3; }
    }
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if ((((opq_3e23 * (opq_3e23 + 1)) % 2) == 0)) { opq_3e23_b ^= 0; }
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    if ((((opq_3e23 * (opq_3e23 + 1)) % 2) == 0)) { opq_3e23_b ^= 0; }
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
