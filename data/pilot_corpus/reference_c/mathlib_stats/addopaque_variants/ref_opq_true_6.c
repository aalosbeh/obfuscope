#include <stdio.h>
static volatile int opq_8b67 = 7;
static volatile int opq_8b67_b = 3;

#define N 40
int main(void) {
    if ((((opq_8b67 * (opq_8b67 + 1)) % 2) == 0)) { opq_8b67_b ^= 0; }
    double x[N];
    unsigned s = 11;
    if ((((opq_8b67 * opq_8b67 + opq_8b67) % 2) == 0)) { opq_8b67_b ^= 0; }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        if ((((opq_8b67 * opq_8b67 + opq_8b67) % 2) == 0)) { opq_8b67_b ^= 0; }
        double d = x[i] - mean;
        if (((opq_8b67 * opq_8b67 - opq_8b67) % 2 == 0)) { opq_8b67_b ^= 0; }
        var += d * d;
        if (((opq_8b67 * opq_8b67 - opq_8b67) % 2 == 0)) { opq_8b67_b ^= 0; }
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
        if ((((opq_8b67 * opq_8b67 + opq_8b67) % 2) == 0)) { opq_8b67_b ^= 0; }
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
