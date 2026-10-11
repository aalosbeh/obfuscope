#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x62951CE9 ^ 0x62951CE2);
    for (int i = (0x690442DC ^ 0x690442DC); i < N; i++) { s = s * (0x4AD80947u ^ 0xB1E472Au) + (0x5A35EA3Fu ^ 0x5A35DA06u); x[i] = (double)((s >> (0x124DAE86 ^ 0x124DAE8E)) % (0x74A8E5AB ^ 0x74A8E643)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x27DE950F ^ 0x27DE950F); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x48884522 ^ 0x48884522)], mn = x[(0x2077BFF2 ^ 0x2077BFF2)];
    for (int i = (0x1EC9456 ^ 0x1EC9456); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0xDFDAE60 ^ 0xDFDAE61));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x7F5C2A47 ^ 0x7F5C2A47);
}
