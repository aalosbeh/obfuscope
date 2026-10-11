#include <stdio.h>
static volatile int opq_9f58 = 7;
static volatile int opq_9f58_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    if ((((opq_9f58 * opq_9f58) % 4) == 2)) {
        { int jv_9918e = opq_9f58 ^ 0xABA7;
            jv_9918e ^= (jv_9918e << 3) | 0x37C;
          (void)jv_9918e; }
    }
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : 0); }
    return v;
}
static int expr(void) {
    if ((((opq_9f58 * opq_9f58 + opq_9f58_b * opq_9f58_b) % 4) == 3)) {
        { int jv_383ac = opq_9f58 ^ 0x604F;
            jv_383ac += (jv_383ac >> 2) + 0x4B;
            jv_383ac = (jv_383ac * 0x26) % 0x7FFFFFFF;
          (void)jv_383ac; }
    }
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    if ((((opq_9f58 * opq_9f58 + opq_9f58_b * opq_9f58_b) % 4) == 3)) {
        { int jv_6aa6d = opq_9f58 ^ 0x20F0;
            jv_6aa6d += (jv_6aa6d >> 2) + 0x5;
          (void)jv_6aa6d; }
    }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    if ((((opq_9f58 * opq_9f58) % 4) == 2)) {
        { int jv_ffbe6 = opq_9f58 ^ 0x4F69;
            jv_ffbe6 += (jv_ffbe6 >> 2) + 0xBE;
            jv_ffbe6 ^= (jv_ffbe6 << 3) | 0xEF9B;
            jv_ffbe6 = (jv_ffbe6 * 0x18) % 0x7FFFFFFF;
          (void)jv_ffbe6; }
    }
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    return 0;
}
