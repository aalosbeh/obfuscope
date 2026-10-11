#include <stdio.h>

static char dec_5fce_buf[4][256];
static int dec_5fce_slot = 0;
static const char *dec_5fce(const unsigned char *enc, int n, int key) {
    int s = dec_5fce_slot++ % 4;
    char *out = dec_5fce_buf[s];
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
    const char *src = dec_5fce((const unsigned char[]){0x53, 0x1A, 0x0B, 0x16, 0x0B, 0x1F, 0x19, 0x0B, 0x00, 0x0B, 0x52, 0x74, 0x19, 0x0B, 0x01, 0x0B, 0x03, 0x51, 0x0B, 0x06, 0x0B, 0x1C, 0x02}, 23, 43);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_5fce((const unsigned char[]){0x0E, 0x4F, 0x0B, 0x0E, 0x4F, 0x0B, 0x0E, 0x4F, 0x21}, 9, 43), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
