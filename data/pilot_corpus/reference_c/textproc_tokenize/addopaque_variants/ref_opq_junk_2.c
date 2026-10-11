#include <stdio.h>
static volatile int opq_c08c = 7;
static volatile int opq_c08c_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if ((((opq_c08c * opq_c08c) % 4) == 2)) {
        { int jv_f676a = opq_c08c ^ 0x2C10;
            jv_f676a ^= (jv_f676a << 3) | 0x39FA;
            jv_f676a += (jv_f676a >> 2) + 0x8A;
            jv_f676a = (jv_f676a * 0x2A) % 0x7FFFFFFF;
          (void)jv_f676a; }
    }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    if ((((opq_c08c * opq_c08c) % 4) == 2)) {
        { int jv_8999d = opq_c08c ^ 0x4B36;
            jv_8999d = (jv_8999d * 0xA) % 0x7FFFFFFF;
          (void)jv_8999d; }
    }
    return TOK_OP;
}
int main(void) {
    if ((((opq_c08c * opq_c08c) % 4) == 2)) {
        { int jv_2fa30 = opq_c08c ^ 0xDBEE;
            jv_2fa30 += (jv_2fa30 >> 2) + 0xE8;
            jv_2fa30 = (jv_2fa30 * 0x38) % 0x7FFFFFFF;
            jv_2fa30 ^= (jv_2fa30 << 3) | 0x2D27;
          (void)jv_2fa30; }
    }
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if ((((opq_c08c * opq_c08c) % 4) == 2)) {
        { int jv_86f65 = opq_c08c ^ 0x3663;
            jv_86f65 = (jv_86f65 * 0x13) % 0x7FFFFFFF;
            jv_86f65 += (jv_86f65 >> 2) + 0xDD;
            jv_86f65 ^= (jv_86f65 << 3) | 0x9355;
          (void)jv_86f65; }
    }
    int counts[4] = {0,0,0,0};
    if ((((opq_c08c * opq_c08c) % 4) == 2)) {
        { int jv_5ff10 = opq_c08c ^ 0x8489;
            jv_5ff10 = (jv_5ff10 * 0x20) % 0x7FFFFFFF;
            jv_5ff10 += (jv_5ff10 >> 2) + 0x4;
          (void)jv_5ff10; }
    }
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
        if ((((opq_c08c * opq_c08c) % 4) == 2)) {
            { int jv_10e01 = opq_c08c ^ 0xC1D;
                jv_10e01 ^= (jv_10e01 << 3) | 0x4C16;
                jv_10e01 += (jv_10e01 >> 2) + 0x12;
                jv_10e01 = (jv_10e01 * 0x14) % 0x7FFFFFFF;
              (void)jv_10e01; }
        }
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
