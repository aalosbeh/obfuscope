#include <stdio.h>

static char dec_d1fb_buf[4][256];
static int dec_d1fb_slot = 0;
static const char *dec_d1fb(const unsigned char *enc, int n, int key) {
    int s = dec_d1fb_slot++ % 4;
    char *out = dec_d1fb_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_d1fb((const unsigned char[]){0xC7, 0xC7, 0xC7, 0xC4, 0xC4, 0xC4, 0xC4, 0xC5, 0xC5, 0xC2, 0xC2, 0xC2, 0xC2, 0xC2, 0xC2, 0xC3, 0xC0, 0xC0, 0xC0, 0xC0, 0xC1}, 21, 166);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_d1fb((const unsigned char[]){0x83, 0xD5, 0x86, 0x83, 0xC2, 0xAC}, 6, 166), out, o);
    return 0;
}
