#include <stdio.h>

static char dec_dd10_buf[4][256];
static int dec_dd10_slot = 0;
static const char *dec_dd10(const unsigned char *enc, int n, int key) {
    int s = dec_dd10_slot++ % 4;
    char *out = dec_dd10_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_dd10((const unsigned char[]){0x74, 0x74, 0x74, 0x75, 0x75, 0x75, 0x75, 0x76, 0x76, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x78, 0x79, 0x79, 0x79, 0x79, 0x7A}, 21, 19);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_dd10((const unsigned char[]){0x38, 0x86, 0x33, 0x38, 0x77, 0x1D}, 6, 19), out, o);
    return 0;
}
