#include <stdio.h>

static char dec_792c_buf[4][256];
static int dec_792c_slot = 0;
static const char *dec_792c(const unsigned char *enc, int n, int key) {
    int s = dec_792c_slot++ % 4;
    char *out = dec_792c_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    long a = 0, b = 0;
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf(dec_792c((const unsigned char[]){0x51, 0x98, 0x90, 0x4C, 0x51, 0x98, 0x90, 0x36}, 8, 44), a, b);
    return 0;
}
