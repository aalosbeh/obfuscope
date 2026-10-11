#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double lnhnjzhtrnkvemf = 0.0;
    for (int i = 0; i < N; i++) lnhnjzhtrnkvemf += x[i];
    lnhnjzhtrnkvemf /= N;
    double xuijqgrxjgbzhiuelylu = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - lnhnjzhtrnkvemf;
        xuijqgrxjgbzhiuelylu += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    xuijqgrxjgbzhiuelylu /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", lnhnjzhtrnkvemf, xuijqgrxjgbzhiuelylu, mn, mx);
    return 0;
}
