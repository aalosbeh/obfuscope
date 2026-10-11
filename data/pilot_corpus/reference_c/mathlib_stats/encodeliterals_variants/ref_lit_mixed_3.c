#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0xAC6 - 0xABB);
    for (int i = (0xD3E - 0xD3E); i < N; i++) { s = s * (0x41C659E2u - 0xB75u) + (0xAE067A5u ^ 0xAE0579Cu); x[i] = (double)((s >> (0x8EE - 0x8E6)) % (0x32132300 ^ 0x321320E8)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x297 - 0x297); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0xFB2 - 0xFB2)], mn = x[(0x2AD10644 ^ 0x2AD10644)];
    for (int i = (0x379FC916 ^ 0x379FC916); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0xF95 - 0xF94));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x3E3D1875 ^ 0x3E3D1875);
}
