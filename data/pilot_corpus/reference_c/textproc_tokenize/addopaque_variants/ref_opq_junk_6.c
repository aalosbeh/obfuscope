#include <stdio.h>
static volatile int opq_f2be = 7;
static volatile int opq_f2be_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if ((((opq_f2be * opq_f2be + opq_f2be_b * opq_f2be_b) % 4) == 3)) {
        { int jv_7e644 = opq_f2be ^ 0xCE31;
            jv_7e644 ^= (jv_7e644 << 3) | 0x7FFE;
            jv_7e644 += (jv_7e644 >> 2) + 0x11;
            jv_7e644 = (jv_7e644 * 0x2E) % 0x7FFFFFFF;
          (void)jv_7e644; }
    }
    if (c == ' ') return TOK_SKIP;
    if ((((opq_f2be * opq_f2be + opq_f2be_b * opq_f2be_b) % 4) == 3)) {
        { int jv_61924 = opq_f2be ^ 0xA08A;
            jv_61924 = (jv_61924 * 0xF) % 0x7FFFFFFF;
            jv_61924 ^= (jv_61924 << 3) | 0xC0AC;
            jv_61924 += (jv_61924 >> 2) + 0x20;
          (void)jv_61924; }
    }
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if ((((opq_f2be * opq_f2be + opq_f2be_b * opq_f2be_b) % 4) == 3)) {
        { int jv_fdc9e = opq_f2be ^ 0x443E;
            jv_fdc9e = (jv_fdc9e * 0x3D) % 0x7FFFFFFF;
            jv_fdc9e += (jv_fdc9e >> 2) + 0x3F;
          (void)jv_fdc9e; }
    }
    int counts[4] = {0,0,0,0};
    if ((((opq_f2be * opq_f2be) % 4) == 2)) {
        { int jv_66f51 = opq_f2be ^ 0xBD65;
            jv_66f51 ^= (jv_66f51 << 3) | 0x33F8;
          (void)jv_66f51; }
    }
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        if ((((opq_f2be * opq_f2be + opq_f2be_b * opq_f2be_b) % 4) == 3)) {
            { int jv_f0003 = opq_f2be ^ 0x96D1;
                jv_f0003 ^= (jv_f0003 << 3) | 0xF378;
                jv_f0003 += (jv_f0003 >> 2) + 0x5F;
                jv_f0003 = (jv_f0003 * 0x38) % 0x7FFFFFFF;
              (void)jv_f0003; }
        }
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
        if ((((opq_f2be * opq_f2be) % 4) == 2)) {
            { int jv_2ec0a = opq_f2be ^ 0x9FFD;
                jv_2ec0a = (jv_2ec0a * 0x3D) % 0x7FFFFFFF;
                jv_2ec0a ^= (jv_2ec0a << 3) | 0x192F;
              (void)jv_2ec0a; }
        }
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
