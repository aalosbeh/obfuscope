#include <stdio.h>

static char dec_e0f6_buf[4][256];
static int dec_e0f6_slot = 0;
static const char *dec_e0f6(const unsigned char *enc, int n, int key) {
    int s = dec_e0f6_slot++ % 4;
    char *out = dec_e0f6_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : 0); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf(dec_e0f6((const unsigned char[]){0x9E, 0xD7, 0xDF, 0xB1}, 4, 187), acc);
    return 0;
}
