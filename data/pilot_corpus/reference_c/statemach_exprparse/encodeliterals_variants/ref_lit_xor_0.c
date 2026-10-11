#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x32868513 ^ 0x32868513);
    while (*cur >= '0' && *cur <= '9') v = v * (0x4182F8A2 ^ 0x4182F8A8) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x4F6C589F ^ 0x4F6C589F)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x2C2CF79 ^ 0x2C2CF79);
    for (int i = (0x1C902526 ^ 0x1C902526); i < (0x5F08B632 ^ 0x5F08B636); i++) { cur = tests[i]; acc = acc * (0x1B77B59A ^ 0x1B77B5FE) + expr(); }
    printf("%ld\n", acc);
    return (0x68C6210F ^ 0x68C6210F);
}
