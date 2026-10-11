#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x72945EA9 ^ 0x72945EA2);
    for (int i = (0x43FECE4B ^ 0x43FECE4B); i < N; i++) { s = s * (0x672244C9u ^ 0x26E40AA4u) + (0x28039B0u ^ 0x2800989u); x[i] = (double)((s >> (0x72999653 ^ 0x7299965B)) % (0x163D905B ^ 0x163D93B3)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x78C5B0CC ^ 0x78C5B0CC); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x34FD6D16 ^ 0x34FD6D16)], mn = x[(0x7B12943F ^ 0x7B12943F)];
    for (int i = (0x37534246 ^ 0x37534246); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x337DC211 ^ 0x337DC210));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x156ABD87 ^ 0x156ABD87);
}
