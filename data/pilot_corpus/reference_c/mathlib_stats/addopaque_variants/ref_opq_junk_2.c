#include <stdio.h>
static volatile int opq_815b = 7;
static volatile int opq_815b_b = 3;

#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    if ((((opq_815b * opq_815b) % 4) == 2)) {
        { int jv_2e1c7 = opq_815b ^ 0xF42;
            jv_2e1c7 ^= (jv_2e1c7 << 3) | 0x901;
            jv_2e1c7 = (jv_2e1c7 * 0x36) % 0x7FFFFFFF;
            jv_2e1c7 += (jv_2e1c7 >> 2) + 0xE8;
          (void)jv_2e1c7; }
    }
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        if ((((opq_815b * opq_815b + opq_815b_b * opq_815b_b) % 4) == 3)) {
            { int jv_554d5 = opq_815b ^ 0x3581;
                jv_554d5 ^= (jv_554d5 << 3) | 0xF65D;
              (void)jv_554d5; }
        }
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if ((((opq_815b * opq_815b) % 4) == 2)) {
            { int jv_abb4b = opq_815b ^ 0x9259;
                jv_abb4b += (jv_abb4b >> 2) + 0x27;
                jv_abb4b = (jv_abb4b * 0x7) % 0x7FFFFFFF;
              (void)jv_abb4b; }
        }
        if (x[i] < mn) mn = x[i];
        if ((((opq_815b * opq_815b + opq_815b_b * opq_815b_b) % 4) == 3)) {
            { int jv_1f778 = opq_815b ^ 0xAE9A;
                jv_1f778 = (jv_1f778 * 0x1C) % 0x7FFFFFFF;
              (void)jv_1f778; }
        }
    }
    var /= (N - 1);
    if ((((opq_815b * opq_815b + opq_815b_b * opq_815b_b) % 4) == 3)) {
        { int jv_4664f = opq_815b ^ 0x54AE;
            jv_4664f ^= (jv_4664f << 3) | 0x888E;
            jv_4664f += (jv_4664f >> 2) + 0x62;
          (void)jv_4664f; }
    }
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    if ((((opq_815b * opq_815b) % 4) == 2)) {
        { int jv_22da7 = opq_815b ^ 0x7ADE;
            jv_22da7 = (jv_22da7 * 0x29) % 0x7FFFFFFF;
          (void)jv_22da7; }
    }
    return 0;
}
