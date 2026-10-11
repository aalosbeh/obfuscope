#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x24DBAAF3 ^ 0x24DBAAF3);
    while (*cur >= '0' && *cur <= '9') v = v * (0x16AD05B3 ^ 0x16AD05B9) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x26B132E1 ^ 0x26B132E1)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x8B2 - 0x8B2);
    for (int i = (0xBB86F39 ^ 0xBB86F39); i < (0x45B - 0x457); i++) { cur = tests[i]; acc = acc * (0x6DA - 0x676) + expr(); }
    printf("%ld\n", acc);
    return (0x3F2 - 0x3F2);
}
