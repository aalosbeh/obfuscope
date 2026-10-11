#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x13D6D886 ^ 0x13D6D88D);
    for (int i = (0x3F52D92B ^ 0x3F52D92B); i < N; i++) { s = s * (0x7409AD98u ^ 0x35CFE3F5u) + (0x26D91F9Fu ^ 0x26D92FA6u); x[i] = (double)((s >> (0x3385096D ^ 0x33850965)) % (0x19B2AD53 ^ 0x19B2AEBB)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x24D7E263 ^ 0x24D7E263); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x41D97B5C ^ 0x41D97B5C)], mn = x[(0x27938ACB ^ 0x27938ACB)];
    for (int i = (0x51A23FC5 ^ 0x51A23FC5); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x288CEA71 ^ 0x288CEA70));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x2567D9AF ^ 0x2567D9AF);
}
