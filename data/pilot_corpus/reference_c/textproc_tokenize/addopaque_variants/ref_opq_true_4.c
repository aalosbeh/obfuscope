#include <stdio.h>
static volatile int opq_932f = 7;
static volatile int opq_932f_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (((opq_932f * opq_932f - opq_932f) % 2 == 0)) { opq_932f_b ^= 0; }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    if ((((opq_932f * (opq_932f + 1)) % 2) == 0)) { opq_932f_b ^= 0; }
    return TOK_OP;
}
int main(void) {
    if (((opq_932f * opq_932f - opq_932f) % 2 == 0)) { opq_932f_b ^= 0; }
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    int counts[4] = {0,0,0,0};
    if ((((opq_932f * (opq_932f + 1)) % 2) == 0)) { opq_932f_b ^= 0; }
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        if ((((opq_932f * (opq_932f + 1)) % 2) == 0)) { opq_932f_b ^= 0; }
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        if ((((opq_932f * opq_932f + opq_932f) % 2) == 0)) { opq_932f_b ^= 0; }
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
