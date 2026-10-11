#include <stdio.h>
static volatile int opq_913b = 7;
static volatile int opq_913b_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if ((((opq_913b * (opq_913b + 1)) % 2) == 0)) { opq_913b_b ^= 0; }
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    return v;
}
static int term(void) {
    if ((((opq_913b * (opq_913b + 1)) % 2) == 0)) { opq_913b_b ^= 0; }
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : 0); }
    return v;
}
static int expr(void) {
    if ((((opq_913b * opq_913b) % 4) == 2)) {
        { int jv_11fd0 = opq_913b ^ 0x2FDB;
            jv_11fd0 ^= (jv_11fd0 << 3) | 0x7133;
          (void)jv_11fd0; }
    }
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    if ((((opq_913b * opq_913b + opq_913b) % 2) == 0)) { opq_913b_b ^= 0; }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    return 0;
}
