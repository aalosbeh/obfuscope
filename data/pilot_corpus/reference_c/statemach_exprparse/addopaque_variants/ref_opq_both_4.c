#include <stdio.h>
static volatile int opq_154d = 7;
static volatile int opq_154d_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    if ((((opq_154d * (opq_154d + 1)) % 2) == 0)) { opq_154d_b ^= 0; }
    return v;
}
static int term(void) {
    if ((((opq_154d * opq_154d) % 4) == 2)) {
        { int jv_3369d = opq_154d ^ 0x3A83;
            jv_3369d = (jv_3369d * 0xC) % 0x7FFFFFFF;
            jv_3369d ^= (jv_3369d << 3) | 0x3BFA;
          (void)jv_3369d; }
    }
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : 0); }
    return v;
}
static int expr(void) {
    if (((opq_154d * opq_154d - opq_154d) % 2 == 0)) { opq_154d_b ^= 0; }
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = 0;
    if ((((opq_154d * opq_154d + opq_154d_b * opq_154d_b) % 4) == 3)) {
        { int jv_c76af = opq_154d ^ 0xB6E;
            jv_c76af = (jv_c76af * 0x12) % 0x7FFFFFFF;
            jv_c76af += (jv_c76af >> 2) + 0x81;
          (void)jv_c76af; }
    }
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    return 0;
}
