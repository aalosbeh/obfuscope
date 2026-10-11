#include <stdio.h>

static char dec_c275_buf[4][256];
static int dec_c275_slot = 0;
static const char *dec_c275(const unsigned char *enc, int n, int key) {
    int s = dec_c275_slot++ % 4;
    char *out = dec_c275_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    return TOK_OP;
}
int main(void) {
    const char *src = dec_c275((const unsigned char[]){0x21, 0x68, 0x79, 0x64, 0x79, 0x6D, 0x6B, 0x79, 0x72, 0x79, 0x20, 0x06, 0x6B, 0x79, 0x73, 0x79, 0x71, 0x23, 0x79, 0x74, 0x79, 0x6E, 0x70}, 23, 89);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_c275((const unsigned char[]){0x7C, 0x3D, 0x79, 0x7C, 0x3D, 0x79, 0x7C, 0x3D, 0x53}, 9, 89), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
