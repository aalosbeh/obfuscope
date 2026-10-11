#include <stdio.h>

static char dec_5091_buf[4][256];
static int dec_5091_slot = 0;
static const char *dec_5091(const unsigned char *enc, int n, int key) {
    int s = dec_5091_slot++ % 4;
    char *out = dec_5091_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_5091((const unsigned char[]){0x09, 0x09, 0x09, 0x0A, 0x0A, 0x0A, 0x0A, 0x0B, 0x0B, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0D, 0x0E, 0x0E, 0x0E, 0x0E, 0x0F}, 21, 104);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_5091((const unsigned char[]){0x4D, 0x1B, 0x48, 0x4D, 0x0C, 0x62}, 6, 104), out, o);
    return 0;
}
