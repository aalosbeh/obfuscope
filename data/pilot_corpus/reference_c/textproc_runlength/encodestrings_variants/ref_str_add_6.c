#include <stdio.h>

static char dec_202c_buf[4][256];
static int dec_202c_slot = 0;
static const char *dec_202c(const unsigned char *enc, int n, int key) {
    int s = dec_202c_slot++ % 4;
    char *out = dec_202c_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

int main(void) {
    const char *in = dec_202c((const unsigned char[]){0x45, 0x45, 0x45, 0x46, 0x46, 0x46, 0x46, 0x47, 0x47, 0x48, 0x48, 0x48, 0x48, 0x48, 0x48, 0x49, 0x4A, 0x4A, 0x4A, 0x4A, 0x4B}, 21, 228);
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf(dec_202c((const unsigned char[]){0x09, 0x57, 0x04, 0x09, 0x48, 0xEE}, 6, 228), out, o);
    return 0;
}
