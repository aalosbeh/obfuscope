#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0xDDA - 0xDDA);
    while (*cur >= '0' && *cur <= '9') v = v * (0x909 - 0x8FF) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x587 - 0x587)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x879 - 0x879);
    for (int i = (0x995 - 0x995); i < (0xF3B - 0xF37); i++) { cur = tests[i]; acc = acc * (0x399 - 0x335) + expr(); }
    printf("%ld\n", acc);
    return (0x3FE - 0x3FE);
}
