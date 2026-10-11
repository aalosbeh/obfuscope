#include <stdio.h>
static volatile int opq_5add = 7;
static volatile int opq_5add_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    if ((((opq_5add * opq_5add) % 4) == 2)) {
        { int jv_63019 = opq_5add ^ 0x16C5;
            jv_63019 ^= (jv_63019 << 3) | 0xB7E;
            jv_63019 += (jv_63019 >> 2) + 0xAF;
          (void)jv_63019; }
    }
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if ((((opq_5add * opq_5add) % 4) == 2)) {
        { int jv_ded28 = opq_5add ^ 0xEF6B;
            jv_ded28 += (jv_ded28 >> 2) + 0x29;
            jv_ded28 = (jv_ded28 * 0x7) % 0x7FFFFFFF;
            jv_ded28 ^= (jv_ded28 << 3) | 0xA2AC;
          (void)jv_ded28; }
    }
    int counts[4] = {0,0,0,0};
    if ((((opq_5add * (opq_5add + 1)) % 2) == 0)) { opq_5add_b ^= 0; }
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        if (((opq_5add * opq_5add - opq_5add) % 2 == 0)) { opq_5add_b ^= 0; }
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        if ((((opq_5add * opq_5add + opq_5add_b * opq_5add_b) % 4) == 3)) {
            { int jv_edc7c = opq_5add ^ 0x1954;
                jv_edc7c += (jv_edc7c >> 2) + 0x74;
                jv_edc7c ^= (jv_edc7c << 3) | 0x77A2;
              (void)jv_edc7c; }
        }
        prev = t;
        if (((opq_5add * opq_5add - opq_5add) % 2 == 0)) { opq_5add_b ^= 0; }
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
