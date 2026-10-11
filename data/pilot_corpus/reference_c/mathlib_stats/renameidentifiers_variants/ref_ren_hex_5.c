#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double v_3dda5f = 0.0;
    for (int i = 0; i < N; i++) v_3dda5f += x[i];
    v_3dda5f /= N;
    double v_677017 = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - v_3dda5f;
        v_677017 += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    v_677017 /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", v_3dda5f, v_677017, mn, mx);
    return 0;
}
