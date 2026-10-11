#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double ukgofimqlmydyqrsermzz = 0.0;
    for (int i = 0; i < N; i++) ukgofimqlmydyqrsermzz += x[i];
    ukgofimqlmydyqrsermzz /= N;
    double vinsdndfybtztjkaz = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - ukgofimqlmydyqrsermzz;
        vinsdndfybtztjkaz += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    vinsdndfybtztjkaz /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", ukgofimqlmydyqrsermzz, vinsdndfybtztjkaz, mn, mx);
    return 0;
}
