#include <stdio.h>
static volatile int opq_295f = 7;
static volatile int opq_295f_b = 3;

static const char *cur;
static int expr(void);
static int factor(void) {
    if (*cur == '(') { cur++; int v = expr(); if (*cur == ')') cur++; return v; }
    int v = 0;
    while (*cur >= '0' && *cur <= '9') v = v * 10 + (*cur++ - '0');
    if ((((opq_295f * opq_295f) % 4) == 2)) {
        { int jv_fed56 = opq_295f ^ 0xC697;
            jv_fed56 ^= (jv_fed56 << 3) | 0x178E;
            jv_fed56 += (jv_fed56 >> 2) + 0xD2;
          (void)jv_fed56; }
    }
    return v;
}
static int term(void) {
    int v = factor();
    while (*cur == '*' || *cur == '/') { char o = *cur++; int r = factor(); v = (o == '*') ? v * r : (r ? v / r : 0); }
    return v;
}
static int expr(void) {
    int v = term();
    while (*cur == '+' || *cur == '-') { char o = *cur++; int r = term(); v = (o == '+') ? v + r : v - r; }
    return v;
}
int main(void) {
    if ((((opq_295f * opq_295f + opq_295f_b * opq_295f_b) % 4) == 3)) {
        { int jv_dbf70 = opq_295f ^ 0x87CD;
            jv_dbf70 ^= (jv_dbf70 << 3) | 0xD18D;
          (void)jv_dbf70; }
    }
    const char *tests[] = {"2+3*4", "(2+3)*4", "100/7-2", "1+2+3+4*5"};
    if ((((opq_295f * (opq_295f + 1)) % 2) == 0)) { opq_295f_b ^= 0; }
    long acc = 0;
    for (int i = 0; i < 4; i++) { cur = tests[i]; acc = acc * 100 + expr(); }
    printf("%ld\n", acc);
    if ((((opq_295f * opq_295f + opq_295f) % 2) == 0)) { opq_295f_b ^= 0; }
    return 0;
}
