#include <stdio.h>

static char dec_8ba5_buf[4][256];
static int dec_8ba5_slot = 0;
static const char *dec_8ba5(const unsigned char *enc, int n, int key) {
    int s = dec_8ba5_slot++ % 4;
    char *out = dec_8ba5_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_8ba5((const unsigned char[]){0x97, 0x97, 0x97, 0x98, 0x98, 0x98, 0x98, 0x99, 0x99, 0x9A, 0x9A, 0x9A, 0x9A, 0x9A, 0x9A, 0x9B, 0x9C, 0x9C, 0x9C, 0x9C, 0x9D}, 21, 54);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_8ba5((const unsigned char[]){0x5B, 0xA9, 0x56, 0x5B, 0x9A, 0x40}, 6, 54), out, o);
    return 0;
}
