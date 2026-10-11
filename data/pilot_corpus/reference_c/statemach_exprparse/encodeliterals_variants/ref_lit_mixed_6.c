#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0xE9C - 0xE9C);
    while (*cur >= '0' && *cur <= '9') v = v * (0x44931AF1 ^ 0x44931AFB) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x9F - 0x9F)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0xBAC - 0xBAC);
    for (int i = (0x69670FB6 ^ 0x69670FB6); i < (0x1F24AB95 ^ 0x1F24AB91); i++) { cur = tests[i]; acc = acc * (0x3BC8FFC2 ^ 0x3BC8FFA6) + expr(); }
    printf("%ld\n", acc);
    return (0x4A3 - 0x4A3);
}
