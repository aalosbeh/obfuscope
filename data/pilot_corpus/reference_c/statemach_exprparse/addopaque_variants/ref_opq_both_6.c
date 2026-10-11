#include <stdio.h>
static volatile int opq_df23 = 7;
static volatile int opq_df23_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if ((((opq_df23 * opq_df23) % 4) == 2)) {
        { int jv_180ec = opq_df23 ^ 0x9A5F;
            jv_180ec += (jv_180ec >> 2) + 0xA3;
            jv_180ec = (jv_180ec * 0x1E) % 0x7FFFFFFF;
            jv_180ec ^= (jv_180ec << 3) | 0xEE07;
          (void)jv_180ec; }
    }
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    if ((((opq_df23 * opq_df23 + opq_df23) % 2) == 0)) { opq_df23_b ^= 0; }
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
    if ((((opq_df23 * (opq_df23 + 1)) % 2) == 0)) { opq_df23_b ^= 0; }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    if ((((opq_df23 * opq_df23 + opq_df23_b * opq_df23_b) % 4) == 3)) {
        { int jv_78715 = opq_df23 ^ 0x1D09;
            jv_78715 += (jv_78715 >> 2) + 0xA3;
            jv_78715 ^= (jv_78715 << 3) | 0x19E7;
          (void)jv_78715; }
    }
    return 0;
}
