#include <stdio.h>
static volatile int opq_25c9 = 7;
static volatile int opq_25c9_b = 3;

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
    if ((((opq_25c9 * opq_25c9 + opq_25c9_b * opq_25c9_b) % 4) == 3)) {
        { int jv_8f9b6 = opq_25c9 ^ 0xBB0E;
            jv_8f9b6 = (jv_8f9b6 * 0x3C) % 0x7FFFFFFF;
            jv_8f9b6 ^= (jv_8f9b6 << 3) | 0x399;
            jv_8f9b6 += (jv_8f9b6 >> 2) + 0x38;
          (void)jv_8f9b6; }
    }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    if ((((opq_25c9 * opq_25c9) % 4) == 2)) {
        { int jv_c4aa3 = opq_25c9 ^ 0x425E;
            jv_c4aa3 ^= (jv_c4aa3 << 3) | 0x9DB3;
            jv_c4aa3 = (jv_c4aa3 * 0xB) % 0x7FFFFFFF;
          (void)jv_c4aa3; }
    }
    long acc = 0;
    if ((((opq_25c9 * opq_25c9 + opq_25c9_b * opq_25c9_b) % 4) == 3)) {
        { int jv_a1e2a = opq_25c9 ^ 0x909;
            jv_a1e2a += (jv_a1e2a >> 2) + 0xA1;
          (void)jv_a1e2a; }
    }
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    if ((((opq_25c9 * opq_25c9) % 4) == 2)) {
        { int jv_5ecea = opq_25c9 ^ 0xE4B6;
            jv_5ecea ^= (jv_5ecea << 3) | 0x3282;
          (void)jv_5ecea; }
    }
    return 0;
}
