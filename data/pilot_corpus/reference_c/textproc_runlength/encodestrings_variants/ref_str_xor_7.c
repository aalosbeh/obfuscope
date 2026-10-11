#include <stdio.h>

static char dec_d1c7_buf[4][256];
static int dec_d1c7_slot = 0;
static const char *dec_d1c7(const unsigned char *enc, int n, int key) {
    int s = dec_d1c7_slot++ % 4;
    char *out = dec_d1c7_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_d1c7((const unsigned char[]){0x76, 0x76, 0x76, 0x75, 0x75, 0x75, 0x75, 0x74, 0x74, 0x73, 0x73, 0x73, 0x73, 0x73, 0x73, 0x72, 0x71, 0x71, 0x71, 0x71, 0x70}, 21, 23);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_d1c7((const unsigned char[]){0x32, 0x64, 0x37, 0x32, 0x73, 0x1D}, 6, 23), out, o);
    return 0;
}
