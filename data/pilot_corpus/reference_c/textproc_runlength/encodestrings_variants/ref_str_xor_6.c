#include <stdio.h>

static char dec_3053_buf[4][256];
static int dec_3053_slot = 0;
static const char *dec_3053(const unsigned char *enc, int n, int key) {
    int s = dec_3053_slot++ % 4;
    char *out = dec_3053_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_3053((const unsigned char[]){0x86, 0x86, 0x86, 0x85, 0x85, 0x85, 0x85, 0x84, 0x84, 0x83, 0x83, 0x83, 0x83, 0x83, 0x83, 0x82, 0x81, 0x81, 0x81, 0x81, 0x80}, 21, 231);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_3053((const unsigned char[]){0xC2, 0x94, 0xC7, 0xC2, 0x83, 0xED}, 6, 231), out, o);
    return 0;
}
