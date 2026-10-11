#include <stdio.h>
static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = (0x1CAFF3CA ^ 0x1CAFF3CA);
    while (*cur >= '0' && *cur <= '9') v = v * (0x62BD237 ^ 0x62BD23D) + (*cur++ - '0');
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : (0x562A83B9 ^ 0x562A83B9)); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    long acc = (0x59B4742D ^ 0x59B4742D);
    for (int i = (0x61BE03A2 ^ 0x61BE03A2); i < (0xB61F8D0 ^ 0xB61F8D4); i++) { cur = tests[i]; acc = acc * (0x1F4A149F ^ 0x1F4A14FB) + expr(); }
    printf("%ld\n", acc);
    return (0x1A761F98 ^ 0x1A761F98);
}
