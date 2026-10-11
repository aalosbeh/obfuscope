#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double sdxtcwdclnioxximjvltlb = 0.0;
    for (int i = 0; i < N; i++) sdxtcwdclnioxximjvltlb += x[i];
    sdxtcwdclnioxximjvltlb /= N;
    double yoonunrnvhjrgpurb = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - sdxtcwdclnioxximjvltlb;
        yoonunrnvhjrgpurb += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    yoonunrnvhjrgpurb /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", sdxtcwdclnioxximjvltlb, yoonunrnvhjrgpurb, mn, mx);
    return 0;
}
