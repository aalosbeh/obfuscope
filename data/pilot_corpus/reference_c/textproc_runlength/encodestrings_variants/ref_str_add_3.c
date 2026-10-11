#include <stdio.h>

static char dec_bfbf_buf[4][256];
static int dec_bfbf_slot = 0;
static const char *dec_bfbf(const unsigned char *enc, int n, int key) {
    int s = dec_bfbf_slot++ % 4;
    char *out = dec_bfbf_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_bfbf((const unsigned char[]){0x46, 0x46, 0x46, 0x47, 0x47, 0x47, 0x47, 0x48, 0x48, 0x49, 0x49, 0x49, 0x49, 0x49, 0x49, 0x4A, 0x4B, 0x4B, 0x4B, 0x4B, 0x4C}, 21, 229);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_bfbf((const unsigned char[]){0x0A, 0x58, 0x05, 0x0A, 0x49, 0xEF}, 6, 229), out, o);
    return 0;
}
