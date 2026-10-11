#include <stdio.h>
static volatile int opq_6b93 = 7;
static volatile int opq_6b93_b = 3;

#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    if ((((opq_6b93 * opq_6b93 + opq_6b93_b * opq_6b93_b) % 4) == 3)) {
        { int jv_3116c = opq_6b93 ^ 0xBED6;
            jv_3116c = (jv_3116c * 0x5) % 0x7FFFFFFF;
          (void)jv_3116c; }
    }
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    if ((((opq_6b93 * opq_6b93) % 4) == 2)) {
        { int jv_c167f = opq_6b93 ^ 0x83C5;
            jv_c167f += (jv_c167f >> 2) + 0xD0;
            jv_c167f ^= (jv_c167f << 3) | 0xF5B9;
          (void)jv_c167f; }
    }
    double var = 0.0, mx = x[0], mn = x[0];
    if (((opq_6b93 * opq_6b93 - opq_6b93) % 2 == 0)) { opq_6b93_b ^= 0; }
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
        if ((((opq_6b93 * opq_6b93) % 4) == 2)) {
            { int jv_4e840 = opq_6b93 ^ 0x28A1;
                jv_4e840 ^= (jv_4e840 << 3) | 0x8283;
              (void)jv_4e840; }
        }
    }
    var /= (N - 1);
    if ((((opq_6b93 * opq_6b93 + opq_6b93) % 2) == 0)) { opq_6b93_b ^= 0; }
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    if ((((opq_6b93 * (opq_6b93 + 1)) % 2) == 0)) { opq_6b93_b ^= 0; }
    return 0;
}
