#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0xA62 - 0xA57);
    for (int i = (0xE57 - 0xE57); i < N; i++) { s = s * (0x41C6552Bu - 0x6BEu) + (0x3A6Bu - 0xA32u); x[i] = (double)((s >> (0x1B4 - 0x1AC)) % (0x662 - 0x27A)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x7B1 - 0x7B1); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0xADC - 0xADC)], mn = x[(0xAD5 - 0xAD5)];
    for (int i = (0x411 - 0x411); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x88F - 0x88E));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0xAEE - 0xAEE);
}
