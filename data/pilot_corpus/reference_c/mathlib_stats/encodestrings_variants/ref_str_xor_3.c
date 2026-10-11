#include <stdio.h>

static char dec_5be0_buf[4][256];
static int dec_5be0_slot = 0;
static const char *dec_5be0(const unsigned char *enc, int n, int key) {
    int s = dec_5be0_slot++ % 4;
    char *out = dec_5be0_buf[s];
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
    printf(dec_5be0((const unsigned char[]){0x83, 0x88, 0x95, 0xC0, 0x86, 0x83, 0x88, 0x95, 0xC0, 0x86, 0x83, 0x88, 0x95, 0xC0, 0x86, 0x83, 0x88, 0x95, 0xC0, 0xAC}, 20, 166), mean, var, mn, mx);
    return 0;
}
