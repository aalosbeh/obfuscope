#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x60F38F3D ^ 0x60F38F36);
    for (int i = (0x74D3083F ^ 0x74D3083F); i < N; i++) { s = s * (0x44658858u ^ 0x5A3C635u) + (0x5AE0631Du ^ 0x5AE05324u); x[i] = (double)((s >> (0x485A3D0E ^ 0x485A3D06)) % (0x29AAC4CC ^ 0x29AAC724)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x40D8CA39 ^ 0x40D8CA39); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x776AE77D ^ 0x776AE77D)], mn = x[(0x3E2031D2 ^ 0x3E2031D2)];
    for (int i = (0x7485E193 ^ 0x7485E193); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x7E09ACA2 ^ 0x7E09ACA3));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x4D3CA7D8 ^ 0x4D3CA7D8);
}
