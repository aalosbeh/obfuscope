#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x6FD - 0x6F2);
    for (int i = (0x76C - 0x76C); i < N; i++) { s = s * (0x41C65AA0u - 0xC33u) + (0x341Du - 0x3E4u); x[i] = (double)((s >> (0xEDB - 0xED3)) % (0x1261 - 0xE79)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x716 - 0x716); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x6B1 - 0x6B1)], mn = x[(0x8E9 - 0x8E9)];
    for (int i = (0xB16 - 0xB16); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x294 - 0x293));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x5F5 - 0x5F5);
}
