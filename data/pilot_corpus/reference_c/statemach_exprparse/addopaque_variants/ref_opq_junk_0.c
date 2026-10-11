#include <stdio.h>
static volatile int opq_fba7 = 7;
static volatile int opq_fba7_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    if ((((opq_fba7 * opq_fba7 + opq_fba7_b * opq_fba7_b) % 4) == 3)) {
        { int jv_34acd = opq_fba7 ^ 0x272E;
            jv_34acd += (jv_34acd >> 2) + 0x1A;
            jv_34acd = (jv_34acd * 0x31) % 0x7FFFFFFF;
          (void)jv_34acd; }
    }
    return v;
}
static int term(void) {
    if ((((opq_fba7 * opq_fba7) % 4) == 2)) {
        { int jv_830e9 = opq_fba7 ^ 0x5E09;
            jv_830e9 += (jv_830e9 >> 2) + 0xBD;
            jv_830e9 ^= (jv_830e9 << 3) | 0x474F;
            jv_830e9 = (jv_830e9 * 0xF) % 0x7FFFFFFF;
          (void)jv_830e9; }
    }
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
    if ((((opq_fba7 * opq_fba7) % 4) == 2)) {
        { int jv_b845b = opq_fba7 ^ 0xA0FE;
            jv_b845b ^= (jv_b845b << 3) | 0x12;
            jv_b845b += (jv_b845b >> 2) + 0x24;
            jv_b845b = (jv_b845b * 0x35) % 0x7FFFFFFF;
          (void)jv_b845b; }
    }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    if ((((opq_fba7 * opq_fba7) % 4) == 2)) {
        { int jv_6992c = opq_fba7 ^ 0xBE06;
            jv_6992c += (jv_6992c >> 2) + 0x11;
          (void)jv_6992c; }
    }
    return 0;
}
