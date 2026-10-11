#include <stdio.h>

static char dec_a1ed_buf[4][256];
static int dec_a1ed_slot = 0;
static const char *dec_a1ed(const unsigned char *enc, int n, int key) {
    int s = dec_a1ed_slot++ % 4;
    char *out = dec_a1ed_buf[s];
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
    const char *src = dec_a1ed((const unsigned char[]){0x9D, 0xD4, 0xC5, 0xD8, 0xC5, 0xD1, 0xD7, 0xC5, 0xCE, 0xC5, 0x9C, 0xBA, 0xD7, 0xC5, 0xCF, 0xC5, 0xCD, 0x9F, 0xC5, 0xC8, 0xC5, 0xD2, 0xCC}, 23, 229);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_a1ed((const unsigned char[]){0xC0, 0x81, 0xC5, 0xC0, 0x81, 0xC5, 0xC0, 0x81, 0xEF}, 9, 229), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
