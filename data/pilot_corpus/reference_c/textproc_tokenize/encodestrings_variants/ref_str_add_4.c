#include <stdio.h>

static char dec_f142_buf[4][256];
static int dec_f142_slot = 0;
static const char *dec_f142(const unsigned char *enc, int n, int key) {
    int s = dec_f142_slot++ % 4;
    char *out = dec_f142_buf[s];
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
    const char *src = dec_f142((const unsigned char[]){0x8E, 0x47, 0x36, 0x53, 0x36, 0x4A, 0x48, 0x36, 0x41, 0x36, 0x8F, 0x75, 0x48, 0x36, 0x40, 0x36, 0x3E, 0x90, 0x36, 0x43, 0x36, 0x4D, 0x3F}, 23, 22);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_f142((const unsigned char[]){0x3B, 0x7A, 0x36, 0x3B, 0x7A, 0x36, 0x3B, 0x7A, 0x20}, 9, 22), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
