#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x74F - 0x74F);
    while (*cur >= '0' && *cur <= '9') v = v * (0xDB5 - 0xDAB) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0xBE - 0xBE)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x3C7 - 0x3C7);
    for (int i = (0x79A - 0x79A); i < (0xD3C - 0xD38); i++) { cur = tests[i]; acc = acc * (0xBF0 - 0xB8C) + expr(); }
    printf("%ld\n", acc);
    return (0xFF0 - 0xFF0);
}
