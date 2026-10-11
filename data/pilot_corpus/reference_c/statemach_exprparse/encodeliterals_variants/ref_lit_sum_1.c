#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0xC7 - 0xC7);
    while (*cur >= '0' && *cur <= '9') v = v * (0xB21 - 0xB17) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x2F8 - 0x2F8)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x454 - 0x454);
    for (int i = (0xD44 - 0xD44); i < (0x8C6 - 0x8C2); i++) { cur = tests[i]; acc = acc * (0x52C - 0x4C8) + expr(); }
    printf("%ld\n", acc);
    return (0x455 - 0x455);
}
