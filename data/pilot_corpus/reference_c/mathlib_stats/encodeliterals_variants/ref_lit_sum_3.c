#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0xF0 - 0xE5);
    for (int i = (0xC69 - 0xC69); i < N; i++) { s = s * (0x41C6567Bu - 0x80Eu) + (0x34A9u - 0x470u); x[i] = (double)((s >> (0x45B - 0x453)) % (0x6D9 - 0x2F1)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x4E5 - 0x4E5); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0xA56 - 0xA56)], mn = x[(0xDD7 - 0xDD7)];
    for (int i = (0x602 - 0x602); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0xD58 - 0xD57));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x9F - 0x9F);
}
