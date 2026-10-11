#include <stdio.h>
static volatile int opq_c58b = 7;
static volatile int opq_c58b_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if ((((opq_c58b * opq_c58b + opq_c58b_b * opq_c58b_b) % 4) == 3)) {
        { int jv_4767e = opq_c58b ^ 0x129F;
            jv_4767e += (jv_4767e >> 2) + 0xEE;
            jv_4767e = (jv_4767e * 0x10) % 0x7FFFFFFF;
            jv_4767e ^= (jv_4767e << 3) | 0x9E94;
          (void)jv_4767e; }
    }
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
    if ((((opq_c58b * opq_c58b + opq_c58b_b * opq_c58b_b) % 4) == 3)) {
        { int jv_b74c8 = opq_c58b ^ 0xBB5;
            jv_b74c8 += (jv_b74c8 >> 2) + 0xEC;
            jv_b74c8 = (jv_b74c8 * 0x27) % 0x7FFFFFFF;
            jv_b74c8 ^= (jv_b74c8 << 3) | 0x8619;
          (void)jv_b74c8; }
    }
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    if ((((opq_c58b * opq_c58b) % 4) == 2)) {
        { int jv_fa3ea = opq_c58b ^ 0x4ECA;
            jv_fa3ea = (jv_fa3ea * 0x35) % 0x7FFFFFFF;
            jv_fa3ea += (jv_fa3ea >> 2) + 0xA1;
          (void)jv_fa3ea; }
    }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    if ((((opq_c58b * opq_c58b + opq_c58b_b * opq_c58b_b) % 4) == 3)) {
        { int jv_590d2 = opq_c58b ^ 0xA78A;
            jv_590d2 ^= (jv_590d2 << 3) | 0xEAC5;
            jv_590d2 += (jv_590d2 >> 2) + 0x68;
            jv_590d2 = (jv_590d2 * 0x18) % 0x7FFFFFFF;
          (void)jv_590d2; }
    }
    return 0;
}
