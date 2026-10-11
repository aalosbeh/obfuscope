#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x54EE5FC1 ^ 0x54EE5FCA);
    for (int i = (0x1C - 0x1C); i < N; i++) { s = s * (0x41C6529Bu - 0x42Eu) + (0x3D67u - 0xD2Eu); x[i] = (double)((s >> (0x42088D82 ^ 0x42088D8A)) % (0x592 - 0x1AA)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x64B - 0x64B); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0xE0B - 0xE0B)], mn = x[(0x6634A48C ^ 0x6634A48C)];
    for (int i = (0xE99 - 0xE99); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x5E0C57A3 ^ 0x5E0C57A2));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x9DF - 0x9DF);
}
