#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x4A8 - 0x49D);
    for (int i = (0xFD3 - 0xFD3); i < N; i++) { s = s * (0x41C65BADu - 0xD40u) + (0x3FEFu - 0xFB6u); x[i] = (double)((s >> (0xE5B - 0xE53)) % (0xE66 - 0xA7E)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x649 - 0x649); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x361 - 0x361)], mn = x[(0x1F3 - 0x1F3)];
    for (int i = (0xD5 - 0xD5); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x1F4 - 0x1F3));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0xF5E - 0xF5E);
}
