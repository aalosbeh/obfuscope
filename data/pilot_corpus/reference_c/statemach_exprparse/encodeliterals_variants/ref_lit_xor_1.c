#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x3BCA945B ^ 0x3BCA945B);
    while (*cur >= '0' && *cur <= '9') v = v * (0x7B9DFF0E ^ 0x7B9DFF04) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x6922575F ^ 0x6922575F)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x5E566ED8 ^ 0x5E566ED8);
    for (int i = (0x7C791659 ^ 0x7C791659); i < (0x372A5559 ^ 0x372A555D); i++) { cur = tests[i]; acc = acc * (0x65A087D2 ^ 0x65A087B6) + expr(); }
    printf("%ld\n", acc);
    return (0x46BF3AB7 ^ 0x46BF3AB7);
}
