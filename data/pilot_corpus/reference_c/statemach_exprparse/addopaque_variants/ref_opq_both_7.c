#include <stdio.h>
static volatile int opq_e497 = 7;
static volatile int opq_e497_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    if (((opq_e497 * opq_e497 - opq_e497) % 2 == 0)) { opq_e497_b ^= 0; }
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
    if ((((opq_e497 * opq_e497 + opq_e497_b * opq_e497_b) % 4) == 3)) {
        { int jv_8e426 = opq_e497 ^ 0x7A7C;
            jv_8e426 += (jv_8e426 >> 2) + 0x14;
          (void)jv_8e426; }
    }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = 0;
    if ((((opq_e497 * opq_e497 + opq_e497) % 2) == 0)) { opq_e497_b ^= 0; }
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    if ((((opq_e497 * opq_e497) % 4) == 2)) {
        { int jv_6453c = opq_e497 ^ 0x3C50;
            jv_6453c += (jv_6453c >> 2) + 0xD;
            jv_6453c ^= (jv_6453c << 3) | 0x8DAD;
            jv_6453c = (jv_6453c * 0x10) % 0x7FFFFFFF;
          (void)jv_6453c; }
    }
    return 0;
}
