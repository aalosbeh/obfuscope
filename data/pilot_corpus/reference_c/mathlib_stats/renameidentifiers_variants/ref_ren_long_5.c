#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double ieixttbjtgsydyreias = 0.0;
    for (int i = 0; i < N; i++) ieixttbjtgsydyreias += x[i];
    ieixttbjtgsydyreias /= N;
    double vviskeuoqtzahto = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - ieixttbjtgsydyreias;
        vviskeuoqtzahto += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    vviskeuoqtzahto /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", ieixttbjtgsydyreias, vviskeuoqtzahto, mn, mx);
    return 0;
}
