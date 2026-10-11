#include <stdio.h>

static char dec_161b_buf[4][256];
static int dec_161b_slot = 0;
static const char *dec_161b(const unsigned char *enc, int n, int key) {
    int s = dec_161b_slot++ % 4;
    char *out = dec_161b_buf[s];
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
    const char *src = dec_161b((const unsigned char[]){0x7E, 0x37, 0x26, 0x43, 0x26, 0x3A, 0x38, 0x26, 0x31, 0x26, 0x7F, 0x65, 0x38, 0x26, 0x30, 0x26, 0x2E, 0x80, 0x26, 0x33, 0x26, 0x3D, 0x2F}, 23, 6);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_161b((const unsigned char[]){0x2B, 0x6A, 0x26, 0x2B, 0x6A, 0x26, 0x2B, 0x6A, 0x10}, 9, 6), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
