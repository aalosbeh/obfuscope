#include <stdio.h>

static char dec_66f0_buf[4][256];
static int dec_66f0_slot = 0;
static const char *dec_66f0(const unsigned char *enc, int n, int key) {
    int s = dec_66f0_slot++ % 4;
    char *out = dec_66f0_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    int n = (int)sizeof(in) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        int rem = n - i;
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (rem > 2) v |= in[i+2];
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    printf(dec_66f0((const unsigned char[]){0x2E, 0x7C, 0x29, 0x2E, 0x6D, 0x13}, 6, 9), out, o);
    return 0;
}
