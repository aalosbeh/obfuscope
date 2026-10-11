#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x16863C9 ^ 0x16863C2);
    for (int i = (0x4C6FC985 ^ 0x4C6FC985); i < N; i++) { s = s * (0x6F68B6FDu ^ 0x2EAEF890u) + (0x2B84710Bu ^ 0x2B844132u); x[i] = (double)((s >> (0x58DAF0F0 ^ 0x58DAF0F8)) % (0x56D197C7 ^ 0x56D1942F)) / 10.0; }
    double mean = 0.0;
    for (int i = (0xCB4A1C0 ^ 0xCB4A1C0); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x4CE72493 ^ 0x4CE72493)], mn = x[(0x528F770C ^ 0x528F770C)];
    for (int i = (0x28F76E19 ^ 0x28F76E19); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x2E7C4F43 ^ 0x2E7C4F42));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x32823786 ^ 0x32823786);
}
