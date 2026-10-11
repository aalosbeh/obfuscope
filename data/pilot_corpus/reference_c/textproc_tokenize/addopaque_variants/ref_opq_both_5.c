#include <stdio.h>
static volatile int opq_eab4 = 7;
static volatile int opq_eab4_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if ((((opq_eab4 * opq_eab4 + opq_eab4_b * opq_eab4_b) % 4) == 3)) {
        { int jv_9d866 = opq_eab4 ^ 0x6117;
            jv_9d866 += (jv_9d866 >> 2) + 0x2F;
            jv_9d866 = (jv_9d866 * 0x3) % 0x7FFFFFFF;
            jv_9d866 ^= (jv_9d866 << 3) | 0x947C;
          (void)jv_9d866; }
    }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if (((opq_eab4 * opq_eab4 - opq_eab4) % 2 == 0)) { opq_eab4_b ^= 0; }
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if ((((opq_eab4 * (opq_eab4 + 1)) % 2) == 0)) { opq_eab4_b ^= 0; }
    if (c == ' ') return TOK_SKIP;
    return TOK_OP;
}
int main(void) {
    if ((((opq_eab4 * (opq_eab4 + 1)) % 2) == 0)) { opq_eab4_b ^= 0; }
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    int counts[4] = {0,0,0,0};
    if ((((opq_eab4 * (opq_eab4 + 1)) % 2) == 0)) { opq_eab4_b ^= 0; }
    enum tok prev = TOK_SKIP;
    if ((((opq_eab4 * opq_eab4) % 4) == 2)) {
        { int jv_1ff28 = opq_eab4 ^ 0xE11D;
            jv_1ff28 = (jv_1ff28 * 0x34) % 0x7FFFFFFF;
            jv_1ff28 ^= (jv_1ff28 << 3) | 0x1E8E;
          (void)jv_1ff28; }
    }
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
