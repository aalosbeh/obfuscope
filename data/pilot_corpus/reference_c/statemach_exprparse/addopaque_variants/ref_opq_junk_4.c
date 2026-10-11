#include <stdio.h>
static volatile int opq_9234 = 7;
static volatile int opq_9234_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if ((((opq_9234 * opq_9234 + opq_9234_b * opq_9234_b) % 4) == 3)) {
        { int jv_91dd3 = opq_9234 ^ 0xFAF8;
            jv_91dd3 += (jv_91dd3 >> 2) + 0x9B;
            jv_91dd3 = (jv_91dd3 * 0xE) % 0x7FFFFFFF;
            jv_91dd3 ^= (jv_91dd3 << 3) | 0x6A49;
          (void)jv_91dd3; }
    }
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    return v;
}
static int term(void) {
    if ((((opq_9234 * opq_9234) % 4) == 2)) {
        { int jv_1ab8e = opq_9234 ^ 0x505D;
            jv_1ab8e ^= (jv_1ab8e << 3) | 0x1054;
            jv_1ab8e += (jv_1ab8e >> 2) + 0x1C;
            jv_1ab8e = (jv_1ab8e * 0xF) % 0x7FFFFFFF;
          (void)jv_1ab8e; }
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
    if ((((opq_9234 * opq_9234) % 4) == 2)) {
        { int jv_350f1 = opq_9234 ^ 0x9961;
            jv_350f1 += (jv_350f1 >> 2) + 0xF6;
            jv_350f1 = (jv_350f1 * 0x25) % 0x7FFFFFFF;
            jv_350f1 ^= (jv_350f1 << 3) | 0x2847;
          (void)jv_350f1; }
    }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    if ((((opq_9234 * opq_9234 + opq_9234_b * opq_9234_b) % 4) == 3)) {
        { int jv_5fbbb = opq_9234 ^ 0xCDDF;
            jv_5fbbb ^= (jv_5fbbb << 3) | 0x8AAC;
            jv_5fbbb = (jv_5fbbb * 0x1B) % 0x7FFFFFFF;
          (void)jv_5fbbb; }
    }
    return 0;
}
