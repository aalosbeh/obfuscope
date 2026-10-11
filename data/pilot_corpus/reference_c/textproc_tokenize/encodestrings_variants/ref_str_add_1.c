#include <stdio.h>

static char dec_4fe7_buf[4][256];
static int dec_4fe7_slot = 0;
static const char *dec_4fe7(const unsigned char *enc, int n, int key) {
    int s = dec_4fe7_slot++ % 4;
    char *out = dec_4fe7_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
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
    const char *src = dec_4fe7((const unsigned char[]){0xDA, 0x93, 0x82, 0x9F, 0x82, 0x96, 0x94, 0x82, 0x8D, 0x82, 0xDB, 0xC1, 0x94, 0x82, 0x8C, 0x82, 0x8A, 0xDC, 0x82, 0x8F, 0x82, 0x99, 0x8B}, 23, 98);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_4fe7((const unsigned char[]){0x87, 0xC6, 0x82, 0x87, 0xC6, 0x82, 0x87, 0xC6, 0x6C}, 9, 98), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
