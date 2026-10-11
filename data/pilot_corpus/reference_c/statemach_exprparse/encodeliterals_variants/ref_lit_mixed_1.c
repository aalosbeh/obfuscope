#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x407 - 0x407);
    while (*cur >= '0' && *cur <= '9') v = v * (0x6AB - 0x6A1) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x5B698AD8 ^ 0x5B698AD8)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0xAC3 - 0xAC3);
    for (int i = (0x1B2F397F ^ 0x1B2F397F); i < (0x20BE538D ^ 0x20BE5389); i++) { cur = tests[i]; acc = acc * (0x572 - 0x50E) + expr(); }
    printf("%ld\n", acc);
    return (0x28E - 0x28E);
}
