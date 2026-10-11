#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x78C - 0x78C);
    while (*cur >= '0' && *cur <= '9') v = v * (0x50C - 0x502) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0xE8A - 0xE8A)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x3496E0AB ^ 0x3496E0AB);
    for (int i = (0xF7A9B6C ^ 0xF7A9B6C); i < (0x6ED32FDC ^ 0x6ED32FD8); i++) { cur = tests[i]; acc = acc * (0xE619039 ^ 0xE61905D) + expr(); }
    printf("%ld\n", acc);
    return (0x790A73D3 ^ 0x790A73D3);
}
