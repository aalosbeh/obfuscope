#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x67BA4AC3 ^ 0x67BA4AC8);
    for (int i = (0x5C288372 ^ 0x5C288372); i < N; i++) { s = s * (0x14B470C5u ^ 0x55723EA8u) + (0x3D583F19u ^ 0x3D580F20u); x[i] = (double)((s >> (0x52E1F432 ^ 0x52E1F43A)) % (0x224764F ^ 0x22475A7)) / 10.0; }
    double mean = 0.0;
    for (int i = (0xA88 - 0xA88); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x469 - 0x469)], mn = x[(0x340066F2 ^ 0x340066F2)];
    for (int i = (0x13293459 ^ 0x13293459); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x43F02B4 ^ 0x43F02B5));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x5B8 - 0x5B8);
}
