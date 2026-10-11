#include <stdio.h>

static char dec_72d0_buf[4][256];
static int dec_72d0_slot = 0;
static const char *dec_72d0(const unsigned char *enc, int n, int key) {
    int s = dec_72d0_slot++ % 4;
    char *out = dec_72d0_buf[s];
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
    const char *src = dec_72d0((const unsigned char[]){0x6C, 0x25, 0x34, 0x29, 0x34, 0x20, 0x26, 0x34, 0x3F, 0x34, 0x6D, 0x4B, 0x26, 0x34, 0x3E, 0x34, 0x3C, 0x6E, 0x34, 0x39, 0x34, 0x23, 0x3D}, 23, 20);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_72d0((const unsigned char[]){0x31, 0x70, 0x34, 0x31, 0x70, 0x34, 0x31, 0x70, 0x1E}, 9, 20), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
