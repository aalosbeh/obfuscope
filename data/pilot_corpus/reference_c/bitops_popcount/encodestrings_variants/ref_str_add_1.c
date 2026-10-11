#include <stdio.h>

static char dec_775b_buf[4][256];
static int dec_775b_slot = 0;
static const char *dec_775b(const unsigned char *enc, int n, int key) {
    int s = dec_775b_slot++ % 4;
    char *out = dec_775b_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    long a = 0, b = 0;
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf(dec_775b((const unsigned char[]){0x1B, 0x62, 0x5A, 0x16, 0x1B, 0x62, 0x5A, 0x00}, 8, 246), a, b);
    return 0;
}
