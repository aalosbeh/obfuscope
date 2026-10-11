#include <stdio.h>
static volatile int opq_cdae = 7;
static volatile int opq_cdae_b = 3;

#define N 40
int main(void) {
    if ((((opq_cdae * opq_cdae + opq_cdae_b * opq_cdae_b) % 4) == 3)) {
        { int jv_8475c = opq_cdae ^ 0xCBD9;
            jv_8475c = (jv_8475c * 0x18) % 0x7FFFFFFF;
          (void)jv_8475c; }
    }
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    if ((((opq_cdae * opq_cdae + opq_cdae_b * opq_cdae_b) % 4) == 3)) {
        { int jv_1ac32 = opq_cdae ^ 0xDAAF;
            jv_1ac32 += (jv_1ac32 >> 2) + 0x8A;
          (void)jv_1ac32; }
    }
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    if ((((opq_cdae * opq_cdae + opq_cdae_b * opq_cdae_b) % 4) == 3)) {
        { int jv_3d022 = opq_cdae ^ 0xDB12;
            jv_3d022 = (jv_3d022 * 0x18) % 0x7FFFFFFF;
            jv_3d022 ^= (jv_3d022 << 3) | 0x61ED;
          (void)jv_3d022; }
    }
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        if ((((opq_cdae * opq_cdae) % 4) == 2)) {
            { int jv_368d1 = opq_cdae ^ 0x9E52;
                jv_368d1 ^= (jv_368d1 << 3) | 0xE9CD;
                jv_368d1 = (jv_368d1 * 0x17) % 0x7FFFFFFF;
              (void)jv_368d1; }
        }
        var += d * d;
        if ((((opq_cdae * opq_cdae + opq_cdae_b * opq_cdae_b) % 4) == 3)) {
            { int jv_24df5 = opq_cdae ^ 0x3B00;
                jv_24df5 ^= (jv_24df5 << 3) | 0x8ECD;
              (void)jv_24df5; }
        }
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    if ((((opq_cdae * opq_cdae) % 4) == 2)) {
        { int jv_c6d78 = opq_cdae ^ 0x83CE;
            jv_c6d78 ^= (jv_c6d78 << 3) | 0xC553;
            jv_c6d78 += (jv_c6d78 >> 2) + 0x9C;
          (void)jv_c6d78; }
    }
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
