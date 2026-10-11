#include <stdio.h>

static char dec_d5c6_buf[4][256];
static int dec_d5c6_slot = 0;
static const char *dec_d5c6(const unsigned char *enc, int n, int key) {
    int s = dec_d5c6_slot++ % 4;
    char *out = dec_d5c6_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static int pc_naive(unsigned v) { int c = 0; while (v) { c += v & 1u; v >>= 1; } return c; }
static int pc_kernighan(unsigned v) { int c = 0; while (v) { v &= v - 1u; c++; } return c; }
int main(void) {
    long a = 0, b = 0;
    for (unsigned i = 0; i < 4096; i++) { a += pc_naive(i); b += pc_kernighan(i * 7u + 3u); }
    printf(dec_d5c6((const unsigned char[]){0xE9, 0xA0, 0xA8, 0xEC, 0xE9, 0xA0, 0xA8, 0xC6}, 8, 204), a, b);
    return 0;
}
