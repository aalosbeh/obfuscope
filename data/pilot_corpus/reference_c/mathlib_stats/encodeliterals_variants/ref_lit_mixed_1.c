#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0xFF6 - 0xFEB);
    for (int i = (0x5364E04D ^ 0x5364E04D); i < N; i++) { s = s * (0x41C65C85u - 0xE18u) + (0x635070D3u ^ 0x635040EAu); x[i] = (double)((s >> (0x39782BB1 ^ 0x39782BB9)) % (0x32D713F4 ^ 0x32D7101C)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x44 - 0x44); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x1EE - 0x1EE)], mn = x[(0x4BB2A22D ^ 0x4BB2A22D)];
    for (int i = (0x31457602 ^ 0x31457602); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x7B4 - 0x7B3));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0xE43 - 0xE43);
}
