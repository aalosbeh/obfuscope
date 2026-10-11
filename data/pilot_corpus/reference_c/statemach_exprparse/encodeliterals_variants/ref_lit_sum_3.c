#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x5B - 0x5B);
    while (*cur >= '0' && *cur <= '9') v = v * (0x351 - 0x347) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x42E - 0x42E)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0xE70 - 0xE70);
    for (int i = (0x7EB - 0x7EB); i < (0xE94 - 0xE90); i++) { cur = tests[i]; acc = acc * (0x2B4 - 0x250) + expr(); }
    printf("%ld\n", acc);
    return (0x47D - 0x47D);
}
