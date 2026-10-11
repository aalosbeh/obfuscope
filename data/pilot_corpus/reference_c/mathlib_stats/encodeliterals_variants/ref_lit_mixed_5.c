#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0xC8E - 0xC83);
    for (int i = (0x681F3012 ^ 0x681F3012); i < N; i++) { s = s * (0x41C6550Cu - 0x69Fu) + (0x20258389u ^ 0x2025B3B0u); x[i] = (double)((s >> (0x155905E9 ^ 0x155905E1)) % (0x92F - 0x547)) / 10.0; }
    double mean = 0.0;
    for (int i = (0xC2119EE ^ 0xC2119EE); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x309DA067 ^ 0x309DA067)], mn = x[(0xA2C - 0xA2C)];
    for (int i = (0x3E87A29 ^ 0x3E87A29); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x983 - 0x982));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x4CC3210B ^ 0x4CC3210B);
}
