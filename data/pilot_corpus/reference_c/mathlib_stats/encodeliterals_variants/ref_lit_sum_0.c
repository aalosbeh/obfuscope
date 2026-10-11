#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0xEED - 0xEE2);
    for (int i = (0xA9B - 0xA9B); i < N; i++) { s = s * (0x41C651F2u - 0x385u) + (0x3B1Fu - 0xAE6u); x[i] = (double)((s >> (0xADD - 0xAD5)) % (0x4A1 - 0xB9)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x4E3 - 0x4E3); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0xA3A - 0xA3A)], mn = x[(0xF7B - 0xF7B)];
    for (int i = (0xA66 - 0xA66); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x47 - 0x46));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x1F0 - 0x1F0);
}
