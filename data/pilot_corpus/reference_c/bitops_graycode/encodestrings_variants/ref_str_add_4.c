#include <stdio.h>

static char dec_6578_buf[4][256];
static int dec_6578_slot = 0;
static const char *dec_6578(const unsigned char *enc, int n, int key) {
    int s = dec_6578_slot++ % 4;
    char *out = dec_6578_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
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
    printf(dec_6578((const unsigned char[]){0xF9, 0x38, 0xF4, 0xF9, 0x38, 0xDE}, 6, 212), roundtrip, transitions);
    return 0;
}
