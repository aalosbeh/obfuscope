#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x36C - 0x36C);
    while (*cur >= '0' && *cur <= '9') v = v * (0xE0 - 0xD6) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x8E8 - 0x8E8)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x330 - 0x330);
    for (int i = (0x17A - 0x17A); i < (0x94F - 0x94B); i++) { cur = tests[i]; acc = acc * (0xEB1 - 0xE4D) + expr(); }
    printf("%ld\n", acc);
    return (0x276 - 0x276);
}
