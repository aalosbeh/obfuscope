#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x7EE31FA3 ^ 0x7EE31FA3);
    while (*cur >= '0' && *cur <= '9') v = v * (0x6DEE366A ^ 0x6DEE3660) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x38003238 ^ 0x38003238)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x1687AB42 ^ 0x1687AB42);
    for (int i = (0x327A9EF8 ^ 0x327A9EF8); i < (0x41F00771 ^ 0x41F00775); i++) { cur = tests[i]; acc = acc * (0x25570117 ^ 0x25570173) + expr(); }
    printf("%ld\n", acc);
    return (0x2CCF4C9 ^ 0x2CCF4C9);
}
