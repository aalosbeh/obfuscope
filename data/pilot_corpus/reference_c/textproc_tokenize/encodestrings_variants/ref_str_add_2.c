#include <stdio.h>

static char dec_5a7c_buf[4][256];
static int dec_5a7c_slot = 0;
static const char *dec_5a7c(const unsigned char *enc, int n, int key) {
    int s = dec_5a7c_slot++ % 4;
    char *out = dec_5a7c_buf[s];
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
    const char *src = dec_5a7c((const unsigned char[]){0x3B, 0xF4, 0xE3, 0x00, 0xE3, 0xF7, 0xF5, 0xE3, 0xEE, 0xE3, 0x3C, 0x22, 0xF5, 0xE3, 0xED, 0xE3, 0xEB, 0x3D, 0xE3, 0xF0, 0xE3, 0xFA, 0xEC}, 23, 195);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_5a7c((const unsigned char[]){0xE8, 0x27, 0xE3, 0xE8, 0x27, 0xE3, 0xE8, 0x27, 0xCD}, 9, 195), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
