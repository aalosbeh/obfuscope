#include <stdio.h>

static char dec_e2ed_buf[4][256];
static int dec_e2ed_slot = 0;
static const char *dec_e2ed(const unsigned char *enc, int n, int key) {
    int s = dec_e2ed_slot++ % 4;
    char *out = dec_e2ed_buf[s];
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
    const char *src = dec_e2ed((const unsigned char[]){0xA1, 0xE8, 0xF9, 0xE4, 0xF9, 0xED, 0xEB, 0xF9, 0xF2, 0xF9, 0xA0, 0x86, 0xEB, 0xF9, 0xF3, 0xF9, 0xF1, 0xA3, 0xF9, 0xF4, 0xF9, 0xEE, 0xF0}, 23, 217);
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf(dec_e2ed((const unsigned char[]){0xFC, 0xBD, 0xF9, 0xFC, 0xBD, 0xF9, 0xFC, 0xBD, 0xD3}, 9, 217), counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
