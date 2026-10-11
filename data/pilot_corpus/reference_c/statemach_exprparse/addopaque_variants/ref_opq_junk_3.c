#include <stdio.h>
static volatile int opq_b736 = 7;
static volatile int opq_b736_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    if ((((opq_b736 * opq_b736) % 4) == 2)) {
        { int jv_4735c = opq_b736 ^ 0x949;
            jv_4735c = (jv_4735c * 0x16) % 0x7FFFFFFF;
          (void)jv_4735c; }
    }
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : 0); }
    return v;
}
static int expr(void) {
    if ((((opq_b736 * opq_b736 + opq_b736_b * opq_b736_b) % 4) == 3)) {
        { int jv_ff9f5 = opq_b736 ^ 0xCECC;
            jv_ff9f5 = (jv_ff9f5 * 0x16) % 0x7FFFFFFF;
            jv_ff9f5 += (jv_ff9f5 >> 2) + 0xF7;
          (void)jv_ff9f5; }
    }
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    if ((((opq_b736 * opq_b736) % 4) == 2)) {
        { int jv_f6224 = opq_b736 ^ 0xDC5D;
            jv_f6224 ^= (jv_f6224 << 3) | 0x3616;
            jv_f6224 = (jv_f6224 * 0x23) % 0x7FFFFFFF;
          (void)jv_f6224; }
    }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    if ((((opq_b736 * opq_b736) % 4) == 2)) {
        { int jv_3bf65 = opq_b736 ^ 0x4F76;
            jv_3bf65 += (jv_3bf65 >> 2) + 0x73;
            jv_3bf65 ^= (jv_3bf65 << 3) | 0xA0C7;
            jv_3bf65 = (jv_3bf65 * 0x1B) % 0x7FFFFFFF;
          (void)jv_3bf65; }
    }
    return 0;
}
