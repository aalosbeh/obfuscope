#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0xDCFBB0D ^ 0xDCFBB0D);
    while (*cur >= '0' && *cur <= '9') v = v * (0x2962FD01 ^ 0x2962FD0B) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x2E5A0357 ^ 0x2E5A0357)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x8E0 - 0x8E0);
    for (int i = (0x1B19868B ^ 0x1B19868B); i < (0x619 - 0x615); i++) { cur = tests[i]; acc = acc * (0x48AB4527 ^ 0x48AB4543) + expr(); }
    printf("%ld\n", acc);
    return (0x7F5F9580 ^ 0x7F5F9580);
}
