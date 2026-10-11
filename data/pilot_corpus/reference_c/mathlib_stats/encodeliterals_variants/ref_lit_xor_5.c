#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x288B21E5 ^ 0x288B21EE);
    for (int i = (0x5F471025 ^ 0x5F471025); i < N; i++) { s = s * (0x1176C99Cu ^ 0x50B087F1u) + (0x52CEF41u ^ 0x52CDF78u); x[i] = (double)((s >> (0x734B0B57 ^ 0x734B0B5F)) % (0x632BA9B3 ^ 0x632BAA5B)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x7ED0FE9B ^ 0x7ED0FE9B); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x54CF4E78 ^ 0x54CF4E78)], mn = x[(0x5E269FAC ^ 0x5E269FAC)];
    for (int i = (0x5166E367 ^ 0x5166E367); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x37013A44 ^ 0x37013A45));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x3399BDAB ^ 0x3399BDAB);
}
