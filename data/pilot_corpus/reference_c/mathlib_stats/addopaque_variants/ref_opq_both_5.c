#include <stdio.h>
static volatile int opq_fe31 = 7;
static volatile int opq_fe31_b = 3;

#define N 40
int main(void) {
    double x[N];
    if ((((opq_fe31 * opq_fe31) % 4) == 2)) {
        { int jv_8bb6d = opq_fe31 ^ 0xBFFC;
            jv_8bb6d ^= (jv_8bb6d << 3) | 0x90D8;
          (void)jv_8bb6d; }
    }
    unsigned s = 11;
    if ((((opq_fe31 * opq_fe31 + opq_fe31_b * opq_fe31_b) % 4) == 3)) {
        { int jv_efb97 = opq_fe31 ^ 0xCEEB;
            jv_efb97 ^= (jv_efb97 << 3) | 0x88D;
            jv_efb97 += (jv_efb97 >> 2) + 0xEA;
          (void)jv_efb97; }
    }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    if (((opq_fe31 * opq_fe31 - opq_fe31) % 2 == 0)) { opq_fe31_b ^= 0; }
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    if ((((opq_fe31 * opq_fe31 + opq_fe31_b * opq_fe31_b) % 4) == 3)) {
        { int jv_11d19 = opq_fe31 ^ 0xB69D;
            jv_11d19 = (jv_11d19 * 0x15) % 0x7FFFFFFF;
            jv_11d19 += (jv_11d19 >> 2) + 0x4C;
            jv_11d19 ^= (jv_11d19 << 3) | 0xE4A2;
          (void)jv_11d19; }
    }
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
        if ((((opq_fe31 * opq_fe31 + opq_fe31) % 2) == 0)) { opq_fe31_b ^= 0; }
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    if ((((opq_fe31 * opq_fe31) % 4) == 2)) {
        { int jv_3f23b = opq_fe31 ^ 0xDAD7;
            jv_3f23b ^= (jv_3f23b << 3) | 0x5DF5;
            jv_3f23b += (jv_3f23b >> 2) + 0x10;
            jv_3f23b = (jv_3f23b * 0x29) % 0x7FFFFFFF;
          (void)jv_3f23b; }
    }
    return 0;
}
