#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x989 - 0x97E);
    for (int i = (0xEF6 - 0xEF6); i < N; i++) { s = s * (0x41C65040u - 0x1D3u) + (0x3BBBu - 0xB82u); x[i] = (double)((s >> (0x608 - 0x600)) % (0x893 - 0x4AB)) / 10.0; }
    double mean = 0.0;
    for (int i = (0xC2 - 0xC2); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x56 - 0x56)], mn = x[(0xE0C - 0xE0C)];
    for (int i = (0x961 - 0x961); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0xE65 - 0xE64));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0xCAC - 0xCAC);
}
