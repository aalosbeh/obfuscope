#include <stdio.h>
static volatile int opq_cc45 = 7;
static volatile int opq_cc45_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((((opq_cc45 * opq_cc45) % 4) == 2)) {
        { int jv_318c2 = opq_cc45 ^ 0x65B7;
            jv_318c2 ^= (jv_318c2 << 3) | 0x387A;
            jv_318c2 = (jv_318c2 * 0x24) % 0x7FFFFFFF;
          (void)jv_318c2; }
    }
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if ((((opq_cc45 * opq_cc45 + opq_cc45_b * opq_cc45_b) % 4) == 3)) {
        { int jv_e387a = opq_cc45 ^ 0x32FE;
            jv_e387a += (jv_e387a >> 2) + 0x47;
            jv_e387a ^= (jv_e387a << 3) | 0xF61B;
            jv_e387a = (jv_e387a * 0x11) % 0x7FFFFFFF;
          (void)jv_e387a; }
    }
    if (c == ' ') return TOK_SKIP;
    if ((((opq_cc45 * opq_cc45 + opq_cc45_b * opq_cc45_b) % 4) == 3)) {
        { int jv_159f3 = opq_cc45 ^ 0xCB23;
            jv_159f3 += (jv_159f3 >> 2) + 0x1E;
            jv_159f3 ^= (jv_159f3 << 3) | 0x6EE0;
          (void)jv_159f3; }
    }
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if ((((opq_cc45 * opq_cc45 + opq_cc45_b * opq_cc45_b) % 4) == 3)) {
        { int jv_ce7da = opq_cc45 ^ 0xC947;
            jv_ce7da += (jv_ce7da >> 2) + 0xE8;
            jv_ce7da ^= (jv_ce7da << 3) | 0x4657;
            jv_ce7da = (jv_ce7da * 0xA) % 0x7FFFFFFF;
          (void)jv_ce7da; }
    }
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    if ((((opq_cc45 * opq_cc45) % 4) == 2)) {
        { int jv_798af = opq_cc45 ^ 0xFD84;
            jv_798af += (jv_798af >> 2) + 0x41;
            jv_798af ^= (jv_798af << 3) | 0xE092;
            jv_798af = (jv_798af * 0x27) % 0x7FFFFFFF;
          (void)jv_798af; }
    }
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
        if ((((opq_cc45 * opq_cc45 + opq_cc45_b * opq_cc45_b) % 4) == 3)) {
            { int jv_3f15f = opq_cc45 ^ 0x5AE6;
                jv_3f15f += (jv_3f15f >> 2) + 0x65;
              (void)jv_3f15f; }
        }
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
