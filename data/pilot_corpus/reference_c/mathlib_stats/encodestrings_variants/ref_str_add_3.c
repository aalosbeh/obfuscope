#include <stdio.h>

static char dec_76ca_buf[4][256];
static int dec_76ca_slot = 0;
static const char *dec_76ca(const unsigned char *enc, int n, int key) {
    int s = dec_76ca_slot++ % 4;
    char *out = dec_76ca_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
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
    printf(dec_76ca((const unsigned char[]){0x15, 0x1E, 0x23, 0x56, 0x10, 0x15, 0x1E, 0x23, 0x56, 0x10, 0x15, 0x1E, 0x23, 0x56, 0x10, 0x15, 0x1E, 0x23, 0x56, 0xFA}, 20, 240), mean, var, mn, mx);
    return 0;
}
