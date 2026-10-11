#include <stdio.h>
static volatile int opq_ba55 = 7;
static volatile int opq_ba55_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if ((((opq_ba55 * opq_ba55) % 4) == 2)) {
        { int jv_a1884 = opq_ba55 ^ 0x2C16;
            jv_a1884 += (jv_a1884 >> 2) + 0x7;
          (void)jv_a1884; }
    }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((((opq_ba55 * opq_ba55 + opq_ba55_b * opq_ba55_b) % 4) == 3)) {
        { int jv_69c10 = opq_ba55 ^ 0x5DDA;
            jv_69c10 = (jv_69c10 * 0x16) % 0x7FFFFFFF;
          (void)jv_69c10; }
    }
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    return TOK_OP;
}
int main(void) {
    if ((((opq_ba55 * (opq_ba55 + 1)) % 2) == 0)) { opq_ba55_b ^= 0; }
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        if (((opq_ba55 * opq_ba55 - opq_ba55) % 2 == 0)) { opq_ba55_b ^= 0; }
        enum tok t = classify(*p);
        if ((((opq_ba55 * (opq_ba55 + 1)) % 2) == 0)) { opq_ba55_b ^= 0; }
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    if (((opq_ba55 * opq_ba55 - opq_ba55) % 2 == 0)) { opq_ba55_b ^= 0; }
    return 0;
}
