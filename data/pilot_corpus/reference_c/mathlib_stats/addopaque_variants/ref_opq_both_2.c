#include <stdio.h>
static volatile int opq_599d = 7;
static volatile int opq_599d_b = 3;

#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    if (((opq_599d * opq_599d - opq_599d) % 2 == 0)) { opq_599d_b ^= 0; }
    for (int i = 0; i < N; i++) mean += x[i];
    if ((((opq_599d * opq_599d) % 4) == 2)) {
        { int jv_4a177 = opq_599d ^ 0x4A6F;
            jv_4a177 += (jv_4a177 >> 2) + 0x61;
            jv_4a177 = (jv_4a177 * 0xA) % 0x7FFFFFFF;
          (void)jv_4a177; }
    }
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        if ((((opq_599d * opq_599d) % 4) == 2)) {
            { int jv_df801 = opq_599d ^ 0x3D3;
                jv_df801 ^= (jv_df801 << 3) | 0x826;
              (void)jv_df801; }
        }
        double d = x[i] - mean;
        if ((((opq_599d * opq_599d + opq_599d) % 2) == 0)) { opq_599d_b ^= 0; }
        var += d * d;
        if ((((opq_599d * opq_599d + opq_599d) % 2) == 0)) { opq_599d_b ^= 0; }
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    if ((((opq_599d * opq_599d + opq_599d) % 2) == 0)) { opq_599d_b ^= 0; }
    return 0;
}
