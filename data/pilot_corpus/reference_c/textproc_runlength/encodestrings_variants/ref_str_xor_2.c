#include <stdio.h>

static char dec_109c_buf[4][256];
static int dec_109c_slot = 0;
static const char *dec_109c(const unsigned char *enc, int n, int key) {
    int s = dec_109c_slot++ % 4;
    char *out = dec_109c_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_109c((const unsigned char[]){0x2C, 0x2C, 0x2C, 0x2F, 0x2F, 0x2F, 0x2F, 0x2E, 0x2E, 0x29, 0x29, 0x29, 0x29, 0x29, 0x29, 0x28, 0x2B, 0x2B, 0x2B, 0x2B, 0x2A}, 21, 77);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_109c((const unsigned char[]){0x68, 0x3E, 0x6D, 0x68, 0x29, 0x47}, 6, 77), out, o);
    return 0;
}
