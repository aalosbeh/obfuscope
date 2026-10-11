#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0xD8E - 0xD83);
    for (int i = (0x260 - 0x260); i < N; i++) { s = s * (0x41C6583Fu - 0x9D2u) + (0x3133u - 0xFAu); x[i] = (double)((s >> (0xF1B - 0xF13)) % (0x455C5B6B ^ 0x455C5883)) / 10.0; }
    double mean = 0.0;
    for (int i = (0xD0B - 0xD0B); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x1B7 - 0x1B7)], mn = x[(0x5E2410EA ^ 0x5E2410EA)];
    for (int i = (0x41B006AA ^ 0x41B006AA); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x402E9301 ^ 0x402E9300));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0xD81 - 0xD81);
}
