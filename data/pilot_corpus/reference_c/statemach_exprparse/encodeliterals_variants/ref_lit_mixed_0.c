#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x2E56FEB9 ^ 0x2E56FEB9);
    while (*cur >= '0' && *cur <= '9') v = v * (0x7325AB26 ^ 0x7325AB2C) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x706B40A8 ^ 0x706B40A8)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x2A334BA5 ^ 0x2A334BA5);
    for (int i = (0xF8F - 0xF8F); i < (0xE7B - 0xE77); i++) { cur = tests[i]; acc = acc * (0xB49 - 0xAE5) + expr(); }
    printf("%ld\n", acc);
    return (0x8C - 0x8C);
}
