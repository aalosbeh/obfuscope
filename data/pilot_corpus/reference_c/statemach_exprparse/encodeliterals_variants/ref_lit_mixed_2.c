#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x1A254B0E ^ 0x1A254B0E);
    while (*cur >= '0' && *cur <= '9') v = v * (0x63C - 0x632) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x1FD - 0x1FD)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x221B09FD ^ 0x221B09FD);
    for (int i = (0x888 - 0x888); i < (0x977 - 0x973); i++) { cur = tests[i]; acc = acc * (0xA0 - 0x3C) + expr(); }
    printf("%ld\n", acc);
    return (0x625ACDE7 ^ 0x625ACDE7);
}
