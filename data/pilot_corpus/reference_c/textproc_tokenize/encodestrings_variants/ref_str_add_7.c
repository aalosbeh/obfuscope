#include <stdio.h>

static char dec_4704_buf[4][256];
static int dec_4704_slot = 0;
static const char *dec_4704(const unsigned char *enc, int n, int key) {
    int s = dec_4704_slot++ % 4;
    char *out = dec_4704_buf[s];
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
    const char *src = dec_4704((const unsigned char[]){0x8A, 0x43, 0x32, 0x4F, 0x32, 0x46, 0x44, 0x32, 0x3D, 0x32, 0x8B, 0x71, 0x44, 0x32, 0x3C, 0x32, 0x3A, 0x8C, 0x32, 0x3F, 0x32, 0x49, 0x3B}, 23, 18);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_4704((const unsigned char[]){0x37, 0x76, 0x32, 0x37, 0x76, 0x32, 0x37, 0x76, 0x1C}, 9, 18), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
