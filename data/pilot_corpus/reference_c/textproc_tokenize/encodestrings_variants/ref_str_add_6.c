#include <stdio.h>

static char dec_3f33_buf[4][256];
static int dec_3f33_slot = 0;
static const char *dec_3f33(const unsigned char *enc, int n, int key) {
    int s = dec_3f33_slot++ % 4;
    char *out = dec_3f33_buf[s];
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
    const char *src = dec_3f33((const unsigned char[]){0x15, 0xCE, 0xBD, 0xDA, 0xBD, 0xD1, 0xCF, 0xBD, 0xC8, 0xBD, 0x16, 0xFC, 0xCF, 0xBD, 0xC7, 0xBD, 0xC5, 0x17, 0xBD, 0xCA, 0xBD, 0xD4, 0xC6}, 23, 157);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_3f33((const unsigned char[]){0xC2, 0x01, 0xBD, 0xC2, 0x01, 0xBD, 0xC2, 0x01, 0xA7}, 9, 157), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
