#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0xE6D - 0xE6D);
    while (*cur >= '0' && *cur <= '9') v = v * (0x90 - 0x86) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x92D - 0x92D)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x52 - 0x52);
    for (int i = (0x94F - 0x94F); i < (0x559 - 0x555); i++) { cur = tests[i]; acc = acc * (0xCFB - 0xC97) + expr(); }
    printf("%ld\n", acc);
    return (0xABB - 0xABB);
}
