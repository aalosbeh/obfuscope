#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x87E - 0x873);
    for (int i = (0xCD7 - 0xCD7); i < N; i++) { s = s * (0x41C65029u - 0x1BCu) + (0x323Au - 0x201u); x[i] = (double)((s >> (0x477 - 0x46F)) % (0x870 - 0x488)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x4EF - 0x4EF); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x7A0 - 0x7A0)], mn = x[(0xF4E - 0xF4E)];
    for (int i = (0xFD - 0xFD); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x71A - 0x719));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x6B1 - 0x6B1);
}
