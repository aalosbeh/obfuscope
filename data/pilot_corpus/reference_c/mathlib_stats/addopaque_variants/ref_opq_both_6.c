#include <stdio.h>
static volatile int opq_58a0 = 7;
static volatile int opq_58a0_b = 3;

#define N 40
int main(void) {
    double x[N];
    if (((opq_58a0 * opq_58a0 - opq_58a0) % 2 == 0)) { opq_58a0_b ^= 0; }
    unsigned s = 11;
    if ((((opq_58a0 * opq_58a0) % 4) == 2)) {
        { int jv_4a6d1 = opq_58a0 ^ 0xFE76;
            jv_4a6d1 ^= (jv_4a6d1 << 3) | 0x24ED;
            jv_4a6d1 += (jv_4a6d1 >> 2) + 0x43;
            jv_4a6d1 = (jv_4a6d1 * 0x12) % 0x7FFFFFFF;
          (void)jv_4a6d1; }
    }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    if ((((opq_58a0 * (opq_58a0 + 1)) % 2) == 0)) { opq_58a0_b ^= 0; }
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    if ((((opq_58a0 * opq_58a0 + opq_58a0_b * opq_58a0_b) % 4) == 3)) {
        { int jv_f965e = opq_58a0 ^ 0x5E90;
            jv_f965e += (jv_f965e >> 2) + 0xE8;
            jv_f965e ^= (jv_f965e << 3) | 0x8D5F;
            jv_f965e = (jv_f965e * 0xE) % 0x7FFFFFFF;
          (void)jv_f965e; }
    }
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if ((((opq_58a0 * opq_58a0 + opq_58a0_b * opq_58a0_b) % 4) == 3)) {
            { int jv_fde4a = opq_58a0 ^ 0x8432;
                jv_fde4a ^= (jv_fde4a << 3) | 0x7EE5;
              (void)jv_fde4a; }
        }
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    if ((((opq_58a0 * opq_58a0 + opq_58a0_b * opq_58a0_b) % 4) == 3)) {
        { int jv_a491b = opq_58a0 ^ 0x9A47;
            jv_a491b ^= (jv_a491b << 3) | 0xE713;
          (void)jv_a491b; }
    }
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
