#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x8EA - 0x8DF);
    for (int i = (0x1BF - 0x1BF); i < N; i++) { s = s * (0x41C65142u - 0x2D5u) + (0x3FF4u - 0xFBBu); x[i] = (double)((s >> (0x22E - 0x226)) % (0xF15 - 0xB2D)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x1E7EBD40 ^ 0x1E7EBD40); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x561BC246 ^ 0x561BC246)], mn = x[(0x47F - 0x47F)];
    for (int i = (0xE2D - 0xE2D); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x34869D13 ^ 0x34869D12));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x2FA - 0x2FA);
}
