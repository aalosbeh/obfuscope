#include <stdio.h>

static char dec_85a0_buf[4][256];
static int dec_85a0_slot = 0;
static const char *dec_85a0(const unsigned char *enc, int n, int key) {
    int s = dec_85a0_slot++ % 4;
    char *out = dec_85a0_buf[s];
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
    const char *src = dec_85a0((const unsigned char[]){0x08, 0xC1, 0xB0, 0xCD, 0xB0, 0xC4, 0xC2, 0xB0, 0xBB, 0xB0, 0x09, 0xEF, 0xC2, 0xB0, 0xBA, 0xB0, 0xB8, 0x0A, 0xB0, 0xBD, 0xB0, 0xC7, 0xB9}, 23, 144);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_85a0((const unsigned char[]){0xB5, 0xF4, 0xB0, 0xB5, 0xF4, 0xB0, 0xB5, 0xF4, 0x9A}, 9, 144), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
