#include <stdio.h>

static char dec_ff6b_buf[4][256];
static int dec_ff6b_slot = 0;
static const char *dec_ff6b(const unsigned char *enc, int n, int key) {
    int s = dec_ff6b_slot++ % 4;
    char *out = dec_ff6b_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_ff6b((const unsigned char[]){0xC1, 0xC1, 0xC1, 0xC2, 0xC2, 0xC2, 0xC2, 0xC3, 0xC3, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC5, 0xC6, 0xC6, 0xC6, 0xC6, 0xC7}, 21, 96);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_ff6b((const unsigned char[]){0x85, 0xD3, 0x80, 0x85, 0xC4, 0x6A}, 6, 96), out, o);
    return 0;
}
