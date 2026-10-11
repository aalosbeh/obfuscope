#include <stdio.h>
static volatile int opq_b913 = 7;
static volatile int opq_b913_b = 3;

#define N 40
int main(void) {
    double x[N];
    if (((opq_b913 * opq_b913 - opq_b913) % 2 == 0)) { opq_b913_b ^= 0; }
    unsigned s = 11;
    if ((((opq_b913 * opq_b913 + opq_b913) % 2) == 0)) { opq_b913_b ^= 0; }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    if ((((opq_b913 * opq_b913 + opq_b913) % 2) == 0)) { opq_b913_b ^= 0; }
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    if ((((opq_b913 * opq_b913 + opq_b913) % 2) == 0)) { opq_b913_b ^= 0; }
    for (int i = 0; i < N; i++) {
        if (((opq_b913 * opq_b913 - opq_b913) % 2 == 0)) { opq_b913_b ^= 0; }
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    if (((opq_b913 * opq_b913 - opq_b913) % 2 == 0)) { opq_b913_b ^= 0; }
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return 0;
}
