#include <stdio.h>

static char dec_853e_buf[4][256];
static int dec_853e_slot = 0;
static const char *dec_853e(const unsigned char *enc, int n, int key) {
    int s = dec_853e_slot++ % 4;
    char *out = dec_853e_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_853e((const unsigned char[]){0x6E, 0x6E, 0x6E, 0x6F, 0x6F, 0x6F, 0x6F, 0x70, 0x70, 0x71, 0x71, 0x71, 0x71, 0x71, 0x71, 0x72, 0x73, 0x73, 0x73, 0x73, 0x74}, 21, 13);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_853e((const unsigned char[]){0x32, 0x80, 0x2D, 0x32, 0x71, 0x17}, 6, 13), out, o);
    return 0;
}
