#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0xA8F - 0xA8F);
    while (*cur >= '0' && *cur <= '9') v = v * (0x9AE - 0x9A4) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0xC42 - 0xC42)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0xFE6 - 0xFE6);
    for (int i = (0x2C6 - 0x2C6); i < (0x329 - 0x325); i++) { cur = tests[i]; acc = acc * (0x1C2 - 0x15E) + expr(); }
    printf("%ld\n", acc);
    return (0x946 - 0x946);
}
