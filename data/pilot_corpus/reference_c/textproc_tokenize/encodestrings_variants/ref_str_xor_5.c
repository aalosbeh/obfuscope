#include <stdio.h>

static char dec_f87e_buf[4][256];
static int dec_f87e_slot = 0;
static const char *dec_f87e(const unsigned char *enc, int n, int key) {
    int s = dec_f87e_slot++ % 4;
    char *out = dec_f87e_buf[s];
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
    const char *src = dec_f87e((const unsigned char[]){0xB1, 0xF8, 0xE9, 0xF4, 0xE9, 0xFD, 0xFB, 0xE9, 0xE2, 0xE9, 0xB0, 0x96, 0xFB, 0xE9, 0xE3, 0xE9, 0xE1, 0xB3, 0xE9, 0xE4, 0xE9, 0xFE, 0xE0}, 23, 201);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_f87e((const unsigned char[]){0xEC, 0xAD, 0xE9, 0xEC, 0xAD, 0xE9, 0xEC, 0xAD, 0xC3}, 9, 201), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
