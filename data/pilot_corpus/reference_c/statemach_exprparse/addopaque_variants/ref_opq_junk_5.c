#include <stdio.h>
static volatile int opq_9628 = 7;
static volatile int opq_9628_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    return v;
}
static int term(void) {
    if ((((opq_9628 * opq_9628) % 4) == 2)) {
        { int jv_914f6 = opq_9628 ^ 0xE99E;
            jv_914f6 += (jv_914f6 >> 2) + 0xFE;
            jv_914f6 = (jv_914f6 * 0xD) % 0x7FFFFFFF;
            jv_914f6 ^= (jv_914f6 << 3) | 0x3DCB;
          (void)jv_914f6; }
    }
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : 0); }
    return v;
}
static int expr(void) {
    if ((((opq_9628 * opq_9628) % 4) == 2)) {
        { int jv_1df1f = opq_9628 ^ 0x6538;
            jv_1df1f = (jv_1df1f * 0x23) % 0x7FFFFFFF;
            jv_1df1f ^= (jv_1df1f << 3) | 0x58;
          (void)jv_1df1f; }
    }
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    if ((((opq_9628 * opq_9628) % 4) == 2)) {
        { int jv_ca4ad = opq_9628 ^ 0xBB56;
            jv_ca4ad += (jv_ca4ad >> 2) + 0x77;
          (void)jv_ca4ad; }
    }
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    if ((((opq_9628 * opq_9628) % 4) == 2)) {
        { int jv_fc45a = opq_9628 ^ 0x387B;
            jv_fc45a = (jv_fc45a * 0x1E) % 0x7FFFFFFF;
            jv_fc45a ^= (jv_fc45a << 3) | 0xF445;
          (void)jv_fc45a; }
    }
    return 0;
}
