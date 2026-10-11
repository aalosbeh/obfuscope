#include <stdio.h>

static char dec_4408_buf[4][256];
static int dec_4408_slot = 0;
static const char *dec_4408(const unsigned char *enc, int n, int key) {
    int s = dec_4408_slot++ % 4;
    char *out = dec_4408_buf[s];
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
    const char *src = dec_4408((const unsigned char[]){0x19, 0xD2, 0xC1, 0xDE, 0xC1, 0xD5, 0xD3, 0xC1, 0xCC, 0xC1, 0x1A, 0x00, 0xD3, 0xC1, 0xCB, 0xC1, 0xC9, 0x1B, 0xC1, 0xCE, 0xC1, 0xD8, 0xCA}, 23, 161);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_4408((const unsigned char[]){0xC6, 0x05, 0xC1, 0xC6, 0x05, 0xC1, 0xC6, 0x05, 0xAB}, 9, 161), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
