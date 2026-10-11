#include <stdio.h>
static volatile int opq_d6b8 = 7;
static volatile int opq_d6b8_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if ((((opq_d6b8 * (opq_d6b8 + 1)) % 2) == 0)) { opq_d6b8_b ^= 0; }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if ((((opq_d6b8 * opq_d6b8 + opq_d6b8) % 2) == 0)) { opq_d6b8_b ^= 0; }
    if (c == ' ') return TOK_SKIP;
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if ((((opq_d6b8 * opq_d6b8) % 4) == 2)) {
        { int jv_fa265 = opq_d6b8 ^ 0x36A7;
            jv_fa265 += (jv_fa265 >> 2) + 0x57;
            jv_fa265 = (jv_fa265 * 0x29) % 0x7FFFFFFF;
            jv_fa265 ^= (jv_fa265 << 3) | 0x29DA;
          (void)jv_fa265; }
    }
    int counts[4] = {0,0,0,0};
    if ((((opq_d6b8 * opq_d6b8) % 4) == 2)) {
        { int jv_b738d = opq_d6b8 ^ 0x9329;
            jv_b738d = (jv_b738d * 0x10) % 0x7FFFFFFF;
            jv_b738d ^= (jv_b738d << 3) | 0x4680;
          (void)jv_b738d; }
    }
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if ((((opq_d6b8 * opq_d6b8 + opq_d6b8_b * opq_d6b8_b) % 4) == 3)) {
            { int jv_cd65d = opq_d6b8 ^ 0xDFE1;
                jv_cd65d = (jv_cd65d * 0x29) % 0x7FFFFFFF;
                jv_cd65d ^= (jv_cd65d << 3) | 0x3F34;
                jv_cd65d += (jv_cd65d >> 2) + 0x8B;
              (void)jv_cd65d; }
        }
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
        if (((opq_d6b8 * opq_d6b8 - opq_d6b8) % 2 == 0)) { opq_d6b8_b ^= 0; }
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
