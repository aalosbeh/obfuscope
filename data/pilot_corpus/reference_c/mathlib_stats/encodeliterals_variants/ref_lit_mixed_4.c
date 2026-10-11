#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x421CB857 ^ 0x421CB85C);
    for (int i = (0x5B4 - 0x5B4); i < N; i++) { s = s * (0x41C6589Au - 0xA2Du) + (0x5DC7BCA4u ^ 0x5DC78C9Du); x[i] = (double)((s >> (0x965 - 0x95D)) % (0x2AF5F9EA ^ 0x2AF5FA02)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x38CBF01F ^ 0x38CBF01F); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0xD91 - 0xD91)], mn = x[(0x4287D532 ^ 0x4287D532)];
    for (int i = (0xCF4 - 0xCF4); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0xBF48D87 ^ 0xBF48D86));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x235 - 0x235);
}
