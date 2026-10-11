#include <stdio.h>
static volatile int opq_9930 = 7;
static volatile int opq_9930_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (((opq_9930 * opq_9930 - opq_9930) % 2 == 0)) { opq_9930_b ^= 0; }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((((opq_9930 * opq_9930 + opq_9930_b * opq_9930_b) % 4) == 3)) {
        { int jv_762c0 = opq_9930 ^ 0xA741;
            jv_762c0 ^= (jv_762c0 << 3) | 0x95C0;
          (void)jv_762c0; }
    }
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    int counts[4] = {0,0,0,0};
    if (((opq_9930 * opq_9930 - opq_9930) % 2 == 0)) { opq_9930_b ^= 0; }
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        if ((((opq_9930 * (opq_9930 + 1)) % 2) == 0)) { opq_9930_b ^= 0; }
        enum tok t = classify(*p);
        if ((((opq_9930 * opq_9930) % 4) == 2)) {
            { int jv_e7f83 = opq_9930 ^ 0xDAC0;
                jv_e7f83 = (jv_e7f83 * 0xB) % 0x7FFFFFFF;
                jv_e7f83 ^= (jv_e7f83 << 3) | 0x90DE;
                jv_e7f83 += (jv_e7f83 >> 2) + 0xF6;
              (void)jv_e7f83; }
        }
        if (t != TOK_SKIP && t != prev) counts[t]++;
        if ((((opq_9930 * opq_9930 + opq_9930_b * opq_9930_b) % 4) == 3)) {
            { int jv_b17d4 = opq_9930 ^ 0x9AE3;
                jv_b17d4 ^= (jv_b17d4 << 3) | 0xBA6B;
              (void)jv_b17d4; }
        }
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
