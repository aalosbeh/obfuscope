#include <stdio.h>
static volatile int opq_9ab2 = 7;
static volatile int opq_9ab2_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((((opq_9ab2 * (opq_9ab2 + 1)) % 2) == 0)) { opq_9ab2_b ^= 0; }
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if ((((opq_9ab2 * opq_9ab2 + opq_9ab2) % 2) == 0)) { opq_9ab2_b ^= 0; }
    if (c == ' ') return TOK_SKIP;
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if ((((opq_9ab2 * opq_9ab2) % 4) == 2)) {
        { int jv_4bbe7 = opq_9ab2 ^ 0x41E6;
            jv_4bbe7 += (jv_4bbe7 >> 2) + 0x83;
          (void)jv_4bbe7; }
    }
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    if (((opq_9ab2 * opq_9ab2 - opq_9ab2) % 2 == 0)) { opq_9ab2_b ^= 0; }
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
        if ((((opq_9ab2 * opq_9ab2) % 4) == 2)) {
            { int jv_13bc7 = opq_9ab2 ^ 0xA05D;
                jv_13bc7 += (jv_13bc7 >> 2) + 0x63;
                jv_13bc7 = (jv_13bc7 * 0x23) % 0x7FFFFFFF;
                jv_13bc7 ^= (jv_13bc7 << 3) | 0xB6D3;
              (void)jv_13bc7; }
        }
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    if (((opq_9ab2 * opq_9ab2 - opq_9ab2) % 2 == 0)) { opq_9ab2_b ^= 0; }
    return 0;
}
