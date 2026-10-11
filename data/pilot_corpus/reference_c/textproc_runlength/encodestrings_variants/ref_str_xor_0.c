#include <stdio.h>

static char dec_1bdf_buf[4][256];
static int dec_1bdf_slot = 0;
static const char *dec_1bdf(const unsigned char *enc, int n, int key) {
    int s = dec_1bdf_slot++ % 4;
    char *out = dec_1bdf_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_1bdf((const unsigned char[]){0xDE, 0xDE, 0xDE, 0xDD, 0xDD, 0xDD, 0xDD, 0xDC, 0xDC, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDB, 0xDA, 0xD9, 0xD9, 0xD9, 0xD9, 0xD8}, 21, 191);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_1bdf((const unsigned char[]){0x9A, 0xCC, 0x9F, 0x9A, 0xDB, 0xB5}, 6, 191), out, o);
    return 0;
}
