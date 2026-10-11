#include <stdio.h>

static char dec_45e4_buf[4][256];
static int dec_45e4_slot = 0;
static const char *dec_45e4(const unsigned char *enc, int n, int key) {
    int s = dec_45e4_slot++ % 4;
    char *out = dec_45e4_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_45e4((const unsigned char[]){0x59, 0x59, 0x59, 0x5A, 0x5A, 0x5A, 0x5A, 0x5B, 0x5B, 0x5C, 0x5C, 0x5C, 0x5C, 0x5C, 0x5C, 0x5D, 0x5E, 0x5E, 0x5E, 0x5E, 0x5F}, 21, 56);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_45e4((const unsigned char[]){0x1D, 0x4B, 0x18, 0x1D, 0x5C, 0x32}, 6, 56), out, o);
    return 0;
}
