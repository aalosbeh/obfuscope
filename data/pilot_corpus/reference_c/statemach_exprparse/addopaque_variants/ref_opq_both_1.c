#include <stdio.h>
static volatile int opq_4a6d = 7;
static volatile int opq_4a6d_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    if ((((opq_4a6d * opq_4a6d + opq_4a6d_b * opq_4a6d_b) % 4) == 3)) {
        { int jv_cb64f = opq_4a6d ^ 0xAD95;
            jv_cb64f += (jv_cb64f >> 2) + 0x36;
            jv_cb64f = (jv_cb64f * 0x3C) % 0x7FFFFFFF;
          (void)jv_cb64f; }
    }
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : 0); }
    return v;
}
static int expr(void) {
    if ((((opq_4a6d * (opq_4a6d + 1)) % 2) == 0)) { opq_4a6d_b ^= 0; }
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    if ((((opq_4a6d * opq_4a6d + opq_4a6d) % 2) == 0)) { opq_4a6d_b ^= 0; }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    if ((((opq_4a6d * opq_4a6d) % 4) == 2)) {
        { int jv_c347f = opq_4a6d ^ 0xE379;
            jv_c347f += (jv_c347f >> 2) + 0xC6;
            jv_c347f ^= (jv_c347f << 3) | 0x1F2D;
            jv_c347f = (jv_c347f * 0x19) % 0x7FFFFFFF;
          (void)jv_c347f; }
    }
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    return 0;
}
