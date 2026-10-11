#include <stdio.h>
static volatile int opq_89ef = 7;
static volatile int opq_89ef_b = 3;

#define N 40
int main(void) {
    double x[N];
    if (((opq_89ef * opq_89ef - opq_89ef) % 2 == 0)) { opq_89ef_b ^= 0; }
    unsigned s = 11;
    if ((((opq_89ef * (opq_89ef + 1)) % 2) == 0)) { opq_89ef_b ^= 0; }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    if ((((opq_89ef * opq_89ef) % 4) == 2)) {
        { int jv_59953 = opq_89ef ^ 0xF9E0;
            jv_59953 ^= (jv_59953 << 3) | 0x1331;
            jv_59953 = (jv_59953 * 0x2E) % 0x7FFFFFFF;
          (void)jv_59953; }
    }
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        if ((((opq_89ef * opq_89ef) % 4) == 2)) {
            { int jv_aaa1c = opq_89ef ^ 0x361D;
                jv_aaa1c ^= (jv_aaa1c << 3) | 0x28DC;
              (void)jv_aaa1c; }
        }
        var += d * d;
        if ((((opq_89ef * opq_89ef) % 4) == 2)) {
            { int jv_da377 = opq_89ef ^ 0x359D;
                jv_da377 = (jv_da377 * 0x12) % 0x7FFFFFFF;
              (void)jv_da377; }
        }
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
        if ((((opq_89ef * opq_89ef) % 4) == 2)) {
            { int jv_d28d9 = opq_89ef ^ 0xD192;
                jv_d28d9 += (jv_d28d9 >> 2) + 0x10;
              (void)jv_d28d9; }
        }
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
