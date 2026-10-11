#include <stdio.h>
static volatile int opq_38ac = 7;
static volatile int opq_38ac_b = 3;

#define N 40
int main(void) {
    if ((((opq_38ac * opq_38ac) % 4) == 2)) {
        { int jv_2214d = opq_38ac ^ 0x86B0;
            jv_2214d = (jv_2214d * 0x6) % 0x7FFFFFFF;
            jv_2214d += (jv_2214d >> 2) + 0x8B;
            jv_2214d ^= (jv_2214d << 3) | 0x2BA1;
          (void)jv_2214d; }
    }
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    if ((((opq_38ac * opq_38ac) % 4) == 2)) {
        { int jv_c29ac = opq_38ac ^ 0x6A5F;
            jv_c29ac = (jv_c29ac * 0x1B) % 0x7FFFFFFF;
            jv_c29ac ^= (jv_c29ac << 3) | 0xCE13;
          (void)jv_c29ac; }
    }
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    if ((((opq_38ac * (opq_38ac + 1)) % 2) == 0)) { opq_38ac_b ^= 0; }
    double var = 0.0, mx = x[0], mn = x[0];
    if ((((opq_38ac * (opq_38ac + 1)) % 2) == 0)) { opq_38ac_b ^= 0; }
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if ((((opq_38ac * opq_38ac + opq_38ac_b * opq_38ac_b) % 4) == 3)) {
            { int jv_fd14d = opq_38ac ^ 0x8AD4;
                jv_fd14d ^= (jv_fd14d << 3) | 0xC8B5;
                jv_fd14d += (jv_fd14d >> 2) + 0x2E;
              (void)jv_fd14d; }
        }
        if (x[i] > mx) mx = x[i];
        if ((((opq_38ac * opq_38ac) % 4) == 2)) {
            { int jv_21f85 = opq_38ac ^ 0x5FF8;
                jv_21f85 = (jv_21f85 * 0x33) % 0x7FFFFFFF;
                jv_21f85 ^= (jv_21f85 << 3) | 0xAC21;
              (void)jv_21f85; }
        }
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
