#include <stdio.h>

static char dec_68c2_buf[4][256];
static int dec_68c2_slot = 0;
static const char *dec_68c2(const unsigned char *enc, int n, int key) {
    int s = dec_68c2_slot++ % 4;
    char *out = dec_68c2_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_68c2((const unsigned char[]){0x7B, 0x7B, 0x7B, 0x7C, 0x7C, 0x7C, 0x7C, 0x7D, 0x7D, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7E, 0x7F, 0x80, 0x80, 0x80, 0x80, 0x81}, 21, 26);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_68c2((const unsigned char[]){0x3F, 0x8D, 0x3A, 0x3F, 0x7E, 0x24}, 6, 26), out, o);
    return 0;
}
