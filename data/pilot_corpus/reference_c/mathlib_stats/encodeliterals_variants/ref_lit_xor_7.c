#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x27B52D32 ^ 0x27B52D39);
    for (int i = (0x6833BF3F ^ 0x6833BF3F); i < N; i++) { s = s * (0x377AB007u ^ 0x76BCFE6Au) + (0x647A5EC8u ^ 0x647A6EF1u); x[i] = (double)((s >> (0x1B782E99 ^ 0x1B782E91)) % (0x6F1E2A57 ^ 0x6F1E29BF)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x766E8ECC ^ 0x766E8ECC); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x579EF63F ^ 0x579EF63F)], mn = x[(0x139CCBFD ^ 0x139CCBFD)];
    for (int i = (0xD4A0668 ^ 0xD4A0668); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x1352018D ^ 0x1352018C));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x2A438E5F ^ 0x2A438E5F);
}
