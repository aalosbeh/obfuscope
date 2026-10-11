#include <stdio.h>
static volatile int opq_19c6 = 7;
static volatile int opq_19c6_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if ((((opq_19c6 * opq_19c6 + opq_19c6) % 2) == 0)) { opq_19c6_b ^= 0; }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((((opq_19c6 * (opq_19c6 + 1)) % 2) == 0)) { opq_19c6_b ^= 0; }
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if ((((opq_19c6 * (opq_19c6 + 1)) % 2) == 0)) { opq_19c6_b ^= 0; }
    if (c == ' ') return TOK_SKIP;
    if (((opq_19c6 * opq_19c6 - opq_19c6) % 2 == 0)) { opq_19c6_b ^= 0; }
    return TOK_OP;
}
int main(void) {
    if ((((opq_19c6 * (opq_19c6 + 1)) % 2) == 0)) { opq_19c6_b ^= 0; }
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if (((opq_19c6 * opq_19c6 - opq_19c6) % 2 == 0)) { opq_19c6_b ^= 0; }
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
