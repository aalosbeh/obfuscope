#include <stdio.h>
static volatile int opq_4e82 = 7;
static volatile int opq_4e82_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if ((((opq_4e82 * opq_4e82) % 4) == 2)) {
        { int jv_839fd = opq_4e82 ^ 0x4CBD;
            jv_839fd ^= (jv_839fd << 3) | 0x1C43;
            jv_839fd = (jv_839fd * 0x1E) % 0x7FFFFFFF;
          (void)jv_839fd; }
    }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    if ((((opq_4e82 * opq_4e82) % 4) == 2)) {
        { int jv_9a59e = opq_4e82 ^ 0xE40B;
            jv_9a59e ^= (jv_9a59e << 3) | 0xC1C6;
            jv_9a59e = (jv_9a59e * 0x3C) % 0x7FFFFFFF;
            jv_9a59e += (jv_9a59e >> 2) + 0x8C;
          (void)jv_9a59e; }
    }
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if ((((opq_4e82 * opq_4e82 + opq_4e82_b * opq_4e82_b) % 4) == 3)) {
        { int jv_1d12b = opq_4e82 ^ 0x1C73;
            jv_1d12b = (jv_1d12b * 0x1D) % 0x7FFFFFFF;
            jv_1d12b ^= (jv_1d12b << 3) | 0x6BFF;
            jv_1d12b += (jv_1d12b >> 2) + 0xF5;
          (void)jv_1d12b; }
    }
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    if ((((opq_4e82 * opq_4e82) % 4) == 2)) {
        { int jv_dd97e = opq_4e82 ^ 0x1EE8;
            jv_dd97e += (jv_dd97e >> 2) + 0x1E;
            jv_dd97e ^= (jv_dd97e << 3) | 0xC5EC;
            jv_dd97e = (jv_dd97e * 0x3B) % 0x7FFFFFFF;
          (void)jv_dd97e; }
    }
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if ((((opq_4e82 * opq_4e82) % 4) == 2)) {
            { int jv_6c3d8 = opq_4e82 ^ 0x5020;
                jv_6c3d8 = (jv_6c3d8 * 0x2A) % 0x7FFFFFFF;
              (void)jv_6c3d8; }
        }
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    if ((((opq_4e82 * opq_4e82) % 4) == 2)) {
        { int jv_e632f = opq_4e82 ^ 0xCB;
            jv_e632f += (jv_e632f >> 2) + 0x85;
            jv_e632f = (jv_e632f * 0x15) % 0x7FFFFFFF;
            jv_e632f ^= (jv_e632f << 3) | 0x1B17;
          (void)jv_e632f; }
    }
    return 0;
}
