#include <stdio.h>
static volatile int opq_c7f1 = 7;
static volatile int opq_c7f1_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((((opq_c7f1 * opq_c7f1) % 4) == 2)) {
        { int jv_ba3ec = opq_c7f1 ^ 0x17F4;
            jv_ba3ec = (jv_ba3ec * 0x2F) % 0x7FFFFFFF;
            jv_ba3ec ^= (jv_ba3ec << 3) | 0x7BEE;
          (void)jv_ba3ec; }
    }
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    if ((((opq_c7f1 * opq_c7f1) % 4) == 2)) {
        { int jv_16c10 = opq_c7f1 ^ 0x2763;
            jv_16c10 += (jv_16c10 >> 2) + 0x21;
            jv_16c10 ^= (jv_16c10 << 3) | 0xCBA0;
          (void)jv_16c10; }
    }
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if ((((opq_c7f1 * opq_c7f1) % 4) == 2)) {
        { int jv_ddcae = opq_c7f1 ^ 0xF3CE;
            jv_ddcae += (jv_ddcae >> 2) + 0xE5;
            jv_ddcae ^= (jv_ddcae << 3) | 0xAF57;
            jv_ddcae = (jv_ddcae * 0x12) % 0x7FFFFFFF;
          (void)jv_ddcae; }
    }
    int counts[4] = {0,0,0,0};
    if ((((opq_c7f1 * opq_c7f1) % 4) == 2)) {
        { int jv_f1d5a = opq_c7f1 ^ 0x551A;
            jv_f1d5a += (jv_f1d5a >> 2) + 0xD7;
          (void)jv_f1d5a; }
    }
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        if ((((opq_c7f1 * opq_c7f1) % 4) == 2)) {
            { int jv_557da = opq_c7f1 ^ 0x93AE;
                jv_557da = (jv_557da * 0x1F) % 0x7FFFFFFF;
                jv_557da += (jv_557da >> 2) + 0xBF;
              (void)jv_557da; }
        }
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        if ((((opq_c7f1 * opq_c7f1 + opq_c7f1_b * opq_c7f1_b) % 4) == 3)) {
            { int jv_c5cb3 = opq_c7f1 ^ 0xB05D;
                jv_c5cb3 += (jv_c5cb3 >> 2) + 0x7D;
              (void)jv_c5cb3; }
        }
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
