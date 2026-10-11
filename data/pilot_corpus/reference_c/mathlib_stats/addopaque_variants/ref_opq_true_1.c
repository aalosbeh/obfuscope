#include <stdio.h>
static volatile int opq_8a91 = 7;
static volatile int opq_8a91_b = 3;

#define N 40
int main(void) {
    double x[N];
    if (((opq_8a91 * opq_8a91 - opq_8a91) % 2 == 0)) { opq_8a91_b ^= 0; }
    unsigned s = 11;
    if (((opq_8a91 * opq_8a91 - opq_8a91) % 2 == 0)) { opq_8a91_b ^= 0; }
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    if (((opq_8a91 * opq_8a91 - opq_8a91) % 2 == 0)) { opq_8a91_b ^= 0; }
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    if ((((opq_8a91 * opq_8a91 + opq_8a91) % 2) == 0)) { opq_8a91_b ^= 0; }
    double var = 0.0, mx = x[0], mn = x[0];
    if (((opq_8a91 * opq_8a91 - opq_8a91) % 2 == 0)) { opq_8a91_b ^= 0; }
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    printf("%.3f %.3f %.3f %.3f\n", mean, var, mn, mx);
    if ((((opq_8a91 * (opq_8a91 + 1)) % 2) == 0)) { opq_8a91_b ^= 0; }
    return 0;
}
