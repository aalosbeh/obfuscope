#include <stdio.h>

static char dec_fd3b_buf[4][256];
static int dec_fd3b_slot = 0;
static const char *dec_fd3b(const unsigned char *enc, int n, int key) {
    int s = dec_fd3b_slot++ % 4;
    char *out = dec_fd3b_buf[s];
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
    const char *src = dec_fd3b((const unsigned char[]){0x5E, 0x17, 0x06, 0x1B, 0x06, 0x12, 0x14, 0x06, 0x0D, 0x06, 0x5F, 0x79, 0x14, 0x06, 0x0C, 0x06, 0x0E, 0x5C, 0x06, 0x0B, 0x06, 0x11, 0x0F}, 23, 38);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_fd3b((const unsigned char[]){0x03, 0x42, 0x06, 0x03, 0x42, 0x06, 0x03, 0x42, 0x2C}, 9, 38), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
