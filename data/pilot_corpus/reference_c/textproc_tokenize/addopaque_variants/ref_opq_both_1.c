#include <stdio.h>
static volatile int opq_9683 = 7;
static volatile int opq_9683_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((((opq_9683 * opq_9683) % 4) == 2)) {
        { int jv_87f77 = opq_9683 ^ 0xF151;
            jv_87f77 = (jv_87f77 * 0x30) % 0x7FFFFFFF;
            jv_87f77 += (jv_87f77 >> 2) + 0x80;
          (void)jv_87f77; }
    }
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    return TOK_OP;
}
int main(void) {
    if (((opq_9683 * opq_9683 - opq_9683) % 2 == 0)) { opq_9683_b ^= 0; }
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    int counts[4] = {0,0,0,0};
    if (((opq_9683 * opq_9683 - opq_9683) % 2 == 0)) { opq_9683_b ^= 0; }
    enum tok prev = TOK_SKIP;
    if ((((opq_9683 * opq_9683 + opq_9683) % 2) == 0)) { opq_9683_b ^= 0; }
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        if ((((opq_9683 * opq_9683 + opq_9683_b * opq_9683_b) % 4) == 3)) {
            { int jv_4211b = opq_9683 ^ 0xDAB9;
                jv_4211b += (jv_4211b >> 2) + 0xC3;
                jv_4211b ^= (jv_4211b << 3) | 0x448C;
              (void)jv_4211b; }
        }
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    if ((((opq_9683 * opq_9683 + opq_9683_b * opq_9683_b) % 4) == 3)) {
        { int jv_f178d = opq_9683 ^ 0x44C0;
            jv_f178d ^= (jv_f178d << 3) | 0x348A;
            jv_f178d += (jv_f178d >> 2) + 0xF6;
            jv_f178d = (jv_f178d * 0x3E) % 0x7FFFFFFF;
          (void)jv_f178d; }
    }
    return 0;
}
