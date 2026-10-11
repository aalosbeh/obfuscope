#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double zrkxpxstvuamtej = 0.0;
    for (int i = 0; i < N; i++) zrkxpxstvuamtej += x[i];
    zrkxpxstvuamtej /= N;
    double ejlldvcxmxmfkhsad = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - zrkxpxstvuamtej;
        ejlldvcxmxmfkhsad += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    ejlldvcxmxmfkhsad /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", zrkxpxstvuamtej, ejlldvcxmxmfkhsad, mn, mx);
    return 0;
}
