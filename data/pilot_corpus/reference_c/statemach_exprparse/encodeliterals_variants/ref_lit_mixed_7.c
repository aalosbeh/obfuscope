#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x4D333A99 ^ 0x4D333A99);
    while (*cur >= '0' && *cur <= '9') v = v * (0x11FDD4E1 ^ 0x11FDD4EB) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x29E - 0x29E)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x3D264CDA ^ 0x3D264CDA);
    for (int i = (0x5FDE4398 ^ 0x5FDE4398); i < (0xB9C - 0xB98); i++) { cur = tests[i]; acc = acc * (0x3DD4F82A ^ 0x3DD4F84E) + expr(); }
    printf("%ld\n", acc);
    return (0x74E - 0x74E);
}
