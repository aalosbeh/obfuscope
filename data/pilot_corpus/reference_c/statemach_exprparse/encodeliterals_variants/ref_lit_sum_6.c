#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0xCA4 - 0xCA4);
    while (*cur >= '0' && *cur <= '9') v = v * (0xBCD - 0xBC3) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0xBF - 0xBF)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0xB16 - 0xB16);
    for (int i = (0xD74 - 0xD74); i < (0xAF5 - 0xAF1); i++) { cur = tests[i]; acc = acc * (0xFDA - 0xF76) + expr(); }
    printf("%ld\n", acc);
    return (0x78 - 0x78);
}
