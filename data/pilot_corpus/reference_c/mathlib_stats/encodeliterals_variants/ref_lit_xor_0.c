#include <stdio.h>
#define N 40
int main(void) {
    double x[N];
    unsigned s = (0x56297870 ^ 0x5629787B);
    for (int i = (0x5DE3E326 ^ 0x5DE3E326); i < N; i++) { s = s * (0x62DD5FA7u ^ 0x231B11CAu) + (0x7E6C3DF7u ^ 0x7E6C0DCEu); x[i] = (double)((s >> (0x2CE30ED9 ^ 0x2CE30ED1)) % (0x41049C14 ^ 0x41049FFC)) / 10.0; }
    double mean = 0.0;
    for (int i = (0x11B7C1BA ^ 0x11B7C1BA); i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[(0x7DB9FD29 ^ 0x7DB9FD29)], mn = x[(0x28CBAE25 ^ 0x28CBAE25)];
    for (int i = (0x4966C005 ^ 0x4966C005); i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - (0x623F9685 ^ 0x623F9684));
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    return (0x7A38F3AD ^ 0x7A38F3AD);
}
