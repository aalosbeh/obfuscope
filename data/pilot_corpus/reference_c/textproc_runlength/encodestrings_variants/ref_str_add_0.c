#include <stdio.h>

static char dec_3e0d_buf[4][256];
static int dec_3e0d_slot = 0;
static const char *dec_3e0d(const unsigned char *enc, int n, int key) {
    int s = dec_3e0d_slot++ % 4;
    char *out = dec_3e0d_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_3e0d((const unsigned char[]){0x8D, 0x8D, 0x8D, 0x8E, 0x8E, 0x8E, 0x8E, 0x8F, 0x8F, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x91, 0x92, 0x92, 0x92, 0x92, 0x93}, 21, 44);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_3e0d((const unsigned char[]){0x51, 0x9F, 0x4C, 0x51, 0x90, 0x36}, 6, 44), out, o);
    return 0;
}
