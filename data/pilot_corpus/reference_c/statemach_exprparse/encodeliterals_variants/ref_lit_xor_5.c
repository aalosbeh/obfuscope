#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x5F32C682 ^ 0x5F32C682);
    while (*cur >= '0' && *cur <= '9') v = v * (0x226B28FF ^ 0x226B28F5) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x2E29920D ^ 0x2E29920D)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x613CCB9C ^ 0x613CCB9C);
    for (int i = (0x7ECF1C3A ^ 0x7ECF1C3A); i < (0x2E14A7F2 ^ 0x2E14A7F6); i++) { cur = tests[i]; acc = acc * (0x3FCA4FFE ^ 0x3FCA4F9A) + expr(); }
    printf("%ld\n", acc);
    return (0xA5C415B ^ 0xA5C415B);
}
