#include <stdio.h>

static char dec_2d10_buf[4][256];
static int dec_2d10_slot = 0;
static const char *dec_2d10(const unsigned char *enc, int n, int key) {
    int s = dec_2d10_slot++ % 4;
    char *out = dec_2d10_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

#define N 40
int main(void) {
    double x[N];
    unsigned s = 11;
    for (int i = 0; i < N; i++) { s = s * 1103515245u + 12345u; x[i] = (double)((s >> 8) % 1000) / 10.0; }
    double mean = 0.0;
    for (int i = 0; i < N; i++) mean += x[i];
    mean /= N;
    double var = 0.0, mx = x[0], mn = x[0];
    for (int i = 0; i < N; i++) {
        double d = x[i] - mean;
        var += d * d;
        if (x[i] > mx) mx = x[i];
        if (x[i] < mn) mn = x[i];
    }
    var /= (N - 1);
    printf(dec_2d10((const unsigned char[]){0x18, 0x13, 0x0E, 0x5B, 0x1D, 0x18, 0x13, 0x0E, 0x5B, 0x1D, 0x18, 0x13, 0x0E, 0x5B, 0x1D, 0x18, 0x13, 0x0E, 0x5B, 0x37}, 20, 61), mean, var, mn, mx);
    return 0;
}
