#include <stdio.h>
static volatile int opq_d8c8 = 7;
static volatile int opq_d8c8_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((((opq_d8c8 * opq_d8c8) % 4) == 2)) {
        { int jv_b28cb = opq_d8c8 ^ 0x8A2;
            jv_b28cb = (jv_b28cb * 0xB) % 0x7FFFFFFF;
            jv_b28cb ^= (jv_b28cb << 3) | 0x751C;
            jv_b28cb += (jv_b28cb >> 2) + 0xA1;
          (void)jv_b28cb; }
    }
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    if ((((opq_d8c8 * opq_d8c8 + opq_d8c8_b * opq_d8c8_b) % 4) == 3)) {
        { int jv_76445 = opq_d8c8 ^ 0x3D2D;
            jv_76445 = (jv_76445 * 0x3B) % 0x7FFFFFFF;
            jv_76445 += (jv_76445 >> 2) + 0x60;
          (void)jv_76445; }
    }
    return TOK_OP;
}
int main(void) {
    if ((((opq_d8c8 * opq_d8c8) % 4) == 2)) {
        { int jv_e9852 = opq_d8c8 ^ 0xCE20;
            jv_e9852 += (jv_e9852 >> 2) + 0x3;
            jv_e9852 = (jv_e9852 * 0x1A) % 0x7FFFFFFF;
            jv_e9852 ^= (jv_e9852 << 3) | 0x59A;
          (void)jv_e9852; }
    }
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    int counts[4] = {0,0,0,0};
    if ((((opq_d8c8 * opq_d8c8 + opq_d8c8_b * opq_d8c8_b) % 4) == 3)) {
        { int jv_ca88d = opq_d8c8 ^ 0xAB43;
            jv_ca88d += (jv_ca88d >> 2) + 0x4A;
            jv_ca88d ^= (jv_ca88d << 3) | 0x3113;
            jv_ca88d = (jv_ca88d * 0x3B) % 0x7FFFFFFF;
          (void)jv_ca88d; }
    }
    enum tok prev = TOK_SKIP;
    if ((((opq_d8c8 * opq_d8c8 + opq_d8c8_b * opq_d8c8_b) % 4) == 3)) {
        { int jv_867b4 = opq_d8c8 ^ 0x6025;
            jv_867b4 ^= (jv_867b4 << 3) | 0x7274;
          (void)jv_867b4; }
    }
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
        if ((((opq_d8c8 * opq_d8c8) % 4) == 2)) {
            { int jv_f482f = opq_d8c8 ^ 0xED6C;
                jv_f482f = (jv_f482f * 0x21) % 0x7FFFFFFF;
                jv_f482f ^= (jv_f482f << 3) | 0xF4C7;
                jv_f482f += (jv_f482f >> 2) + 0xEB;
              (void)jv_f482f; }
        }
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
