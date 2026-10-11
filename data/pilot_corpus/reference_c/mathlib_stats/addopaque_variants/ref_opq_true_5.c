#include <stdio.h>
static volatile int opq_a957 = 7;
static volatile int opq_a957_b = 3;

#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    if ((((opq_a957 * opq_a957 + opq_a957) % 2) == 0)) { opq_a957_b ^= 0; }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    if ((((opq_a957 * opq_a957 + opq_a957) % 2) == 0)) { opq_a957_b ^= 0; }
    for (int i = 0; i < N; i++) {
        if (((opq_a957 * opq_a957 - opq_a957) % 2 == 0)) { opq_a957_b ^= 0; }
        double d = x[i] - mean;
        if ((((opq_a957 * opq_a957 + opq_a957) % 2) == 0)) { opq_a957_b ^= 0; }
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (((opq_a957 * opq_a957 - opq_a957) % 2 == 0)) { opq_a957_b ^= 0; }
        if (x[i] < mn) mn = x[i];
        if ((((opq_a957 * (opq_a957 + 1)) % 2) == 0)) { opq_a957_b ^= 0; }
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
