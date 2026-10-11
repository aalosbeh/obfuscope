#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x70E3AB9 ^ 0x70E3AB9);
    while (*cur >= '0' && *cur <= '9') v = v * (0x7DAFEBED ^ 0x7DAFEBE7) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x4C998CB5 ^ 0x4C998CB5)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x658AFC88 ^ 0x658AFC88);
    for (int i = (0x64784B00 ^ 0x64784B00); i < (0x39CEF808 ^ 0x39CEF80C); i++) { cur = tests[i]; acc = acc * (0x1B6FAF58 ^ 0x1B6FAF3C) + expr(); }
    printf("%ld\n", acc);
    return (0x330CBA79 ^ 0x330CBA79);
}
