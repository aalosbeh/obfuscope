#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double v_654bf7 = 0.0;
    for (int i = 0; i < N; i++) v_654bf7 += x[i];
    v_654bf7 /= N;
    double v_bb49ce = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - v_654bf7;
        v_bb49ce += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    v_bb49ce /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", v_654bf7, v_bb49ce, mn, mx);
    return 0;
}
