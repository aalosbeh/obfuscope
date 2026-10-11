#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x9DB - 0x9D0);
    for (int i = (0xD70 - 0xD70); i < N; i++) { s = s * (0x41C65BF3u - 0xD86u) + (0x3523u - 0x4EAu); x[i] = (double)((s >> (0x79F - 0x797)) % (0x465 - 0x7D)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x4FF - 0x4FF); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x9C4 - 0x9C4)], mn = x[(0xC37 - 0xC37)];
    for (int i = (0xB42 - 0xB42); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x9BA - 0x9B9));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x12C - 0x12C);
}
