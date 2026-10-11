#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x1EB809CF ^ 0x1EB809CF);
    while (*cur >= '0' && *cur <= '9') v = v * (0x13466F0F ^ 0x13466F05) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x5799460A ^ 0x5799460A)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x1ED495E5 ^ 0x1ED495E5);
    for (int i = (0x451B4729 ^ 0x451B4729); i < (0x1D6BEE70 ^ 0x1D6BEE74); i++) { cur = tests[i]; acc = acc * (0x1DD2C0E3 ^ 0x1DD2C087) + expr(); }
    printf("%ld\n", acc);
    return (0x738C557B ^ 0x738C557B);
}
