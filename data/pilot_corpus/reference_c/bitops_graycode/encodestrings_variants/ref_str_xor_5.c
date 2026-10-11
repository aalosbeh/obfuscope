#include <stdio.h>

static char dec_4fd6_buf[4][256];
static int dec_4fd6_slot = 0;
static const char *dec_4fd6(const unsigned char *enc, int n, int key) {
    int s = dec_4fd6_slot++ % 4;
    char *out = dec_4fd6_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static unsigned to_gray(unsigned n) { return n ^ (n >> 1); }
static unsigned from_gray(unsigned g) { unsigned n = g; while (g >>= 1) n ^= g; return n; }
int main(void) {
    int roundtrip = 0, transitions = 0;
    unsigned prev = to_gray(0);
    for (unsigned i = 0; i < 1024; i++) {
        unsigned g = to_gray(i);
        if (from_gray(g) == i) roundtrip++;
        unsigned d = g ^ prev;
        while (d) { transitions += d & 1u; d >>= 1; }
        prev = g;
    }
    printf(dec_4fd6((const unsigned char[]){0x12, 0x53, 0x17, 0x12, 0x53, 0x3D}, 6, 55), roundtrip, transitions);
    return 0;
}
