#include <stdio.h>

static char dec_330b_buf[4][256];
static int dec_330b_slot = 0;
static const char *dec_330b(const unsigned char *enc, int n, int key) {
    int s = dec_330b_slot++ % 4;
    char *out = dec_330b_buf[s];
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
    const char *src = dec_330b((const unsigned char[]){0x2C, 0x65, 0x74, 0x69, 0x74, 0x60, 0x66, 0x74, 0x7F, 0x74, 0x2D, 0x0B, 0x66, 0x74, 0x7E, 0x74, 0x7C, 0x2E, 0x74, 0x79, 0x74, 0x63, 0x7D}, 23, 84);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_330b((const unsigned char[]){0x71, 0x30, 0x74, 0x71, 0x30, 0x74, 0x71, 0x30, 0x5E}, 9, 84), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
