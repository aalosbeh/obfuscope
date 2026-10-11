#include <stdio.h>
static volatile int opq_429b = 7;
static volatile int opq_429b_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    if ((((opq_429b * opq_429b) % 4) == 2)) {
        { int jv_1453d = opq_429b ^ 0x1583;
            jv_1453d += (jv_1453d >> 2) + 0x5;
            jv_1453d ^= (jv_1453d << 3) | 0x1F60;
            jv_1453d = (jv_1453d * 0x14) % 0x7FFFFFFF;
          (void)jv_1453d; }
    }
    return v;
}
static int term(void) {
    if ((((opq_429b * opq_429b + opq_429b_b * opq_429b_b) % 4) == 3)) {
        { int jv_453df = opq_429b ^ 0x3A31;
            jv_453df ^= (jv_453df << 3) | 0x9FFD;
            jv_453df = (jv_453df * 0x3A) % 0x7FFFFFFF;
            jv_453df += (jv_453df >> 2) + 0xC9;
          (void)jv_453df; }
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
    if ((((opq_429b * opq_429b) % 4) == 2)) {
        { int jv_a1dfb = opq_429b ^ 0x89EC;
            jv_a1dfb ^= (jv_a1dfb << 3) | 0xC5A8;
            jv_a1dfb = (jv_a1dfb * 0x17) % 0x7FFFFFFF;
          (void)jv_a1dfb; }
    }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = 0;
    if ((((opq_429b * opq_429b + opq_429b_b * opq_429b_b) % 4) == 3)) {
        { int jv_292ee = opq_429b ^ 0xC0DA;
            jv_292ee += (jv_292ee >> 2) + 0x1D;
          (void)jv_292ee; }
    }
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    return 0;
}
