#include <stdio.h>
static volatile int opq_44bf = 7;
static volatile int opq_44bf_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if ((((opq_44bf * opq_44bf) % 4) == 2)) {
        { int jv_6855f = opq_44bf ^ 0x6B6C;
            jv_6855f = (jv_6855f * 0x7) % 0x7FFFFFFF;
            jv_6855f ^= (jv_6855f << 3) | 0x7DD6;
          (void)jv_6855f; }
    }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    if ((((opq_44bf * opq_44bf + opq_44bf_b * opq_44bf_b) % 4) == 3)) {
        { int jv_5c69a = opq_44bf ^ 0x8A58;
            jv_5c69a += (jv_5c69a >> 2) + 0xFC;
            jv_5c69a ^= (jv_5c69a << 3) | 0xEB43;
            jv_5c69a = (jv_5c69a * 0x9) % 0x7FFFFFFF;
          (void)jv_5c69a; }
    }
    return TOK_OP;
}
int main(void) {
    if ((((opq_44bf * opq_44bf + opq_44bf_b * opq_44bf_b) % 4) == 3)) {
        { int jv_d84c8 = opq_44bf ^ 0x4998;
            jv_d84c8 ^= (jv_d84c8 << 3) | 0xB05E;
            jv_d84c8 += (jv_d84c8 >> 2) + 0x3A;
          (void)jv_d84c8; }
    }
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    int counts[4] = {0,0,0,0};
    if ((((opq_44bf * opq_44bf) % 4) == 2)) {
        { int jv_19a1c = opq_44bf ^ 0xE89F;
            jv_19a1c = (jv_19a1c * 0x20) % 0x7FFFFFFF;
            jv_19a1c += (jv_19a1c >> 2) + 0xBE;
            jv_19a1c ^= (jv_19a1c << 3) | 0x595F;
          (void)jv_19a1c; }
    }
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        if ((((opq_44bf * opq_44bf + opq_44bf_b * opq_44bf_b) % 4) == 3)) {
            { int jv_ecc96 = opq_44bf ^ 0x921A;
                jv_ecc96 += (jv_ecc96 >> 2) + 0x79;
              (void)jv_ecc96; }
        }
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        if ((((opq_44bf * opq_44bf + opq_44bf_b * opq_44bf_b) % 4) == 3)) {
            { int jv_30cce = opq_44bf ^ 0xE67;
                jv_30cce ^= (jv_30cce << 3) | 0x913A;
              (void)jv_30cce; }
        }
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
