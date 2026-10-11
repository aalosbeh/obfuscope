#include <stdio.h>

static char dec_54e8_buf[4][256];
static int dec_54e8_slot = 0;
static const char *dec_54e8(const unsigned char *enc, int n, int key) {
    int s = dec_54e8_slot++ % 4;
    char *out = dec_54e8_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            int d = (*p >= '0' && *p <= '9');
            switch (s) {
                case ST_START: s = d ? ST_INT : ST_BAD; break;
                case ST_INT:   s = d ? ST_INT : (*p == '.' ? ST_FRAC : ST_BAD); break;
                case ST_FRAC:  s = d ? ST_FRAC : ST_BAD; break;
                default:       s = ST_BAD; break;
            }
        }
        if (s == ST_INT || s == ST_FRAC) good++; else bad++;
    }
    printf(dec_54e8((const unsigned char[]){0x0B, 0x4A, 0x0E, 0x0B, 0x4A, 0x24}, 6, 46), good, bad);
    return 0;
}
