#include <stdio.h>
static volatile int opq_5c8d = 7;
static volatile int opq_5c8d_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if ((((opq_5c8d * opq_5c8d) % 4) == 2)) {
        { int jv_223f2 = opq_5c8d ^ 0xB19C;
            jv_223f2 ^= (jv_223f2 << 3) | 0x44FC;
            jv_223f2 = (jv_223f2 * 0x1C) % 0x7FFFFFFF;
          (void)jv_223f2; }
    }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((((opq_5c8d * opq_5c8d) % 4) == 2)) {
        { int jv_1c071 = opq_5c8d ^ 0x6E0;
            jv_1c071 += (jv_1c071 >> 2) + 0x90;
            jv_1c071 = (jv_1c071 * 0x27) % 0x7FFFFFFF;
            jv_1c071 ^= (jv_1c071 << 3) | 0xA543;
          (void)jv_1c071; }
    }
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if ((((opq_5c8d * opq_5c8d + opq_5c8d) % 2) == 0)) { opq_5c8d_b ^= 0; }
    if (c == ' ') return TOK_SKIP;
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if ((((opq_5c8d * opq_5c8d) % 4) == 2)) {
        { int jv_595be = opq_5c8d ^ 0x87BC;
            jv_595be = (jv_595be * 0xC) % 0x7FFFFFFF;
            jv_595be += (jv_595be >> 2) + 0xC7;
            jv_595be ^= (jv_595be << 3) | 0x722F;
          (void)jv_595be; }
    }
    int counts[4] = {0,0,0,0};
    if ((((opq_5c8d * opq_5c8d + opq_5c8d_b * opq_5c8d_b) % 4) == 3)) {
        { int jv_49cda = opq_5c8d ^ 0x347B;
            jv_49cda += (jv_49cda >> 2) + 0x12;
            jv_49cda = (jv_49cda * 0x3E) % 0x7FFFFFFF;
          (void)jv_49cda; }
    }
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
        if ((((opq_5c8d * opq_5c8d) % 4) == 2)) {
            { int jv_dff79 = opq_5c8d ^ 0x938A;
                jv_dff79 ^= (jv_dff79 << 3) | 0x16BE;
                jv_dff79 = (jv_dff79 * 0x35) % 0x7FFFFFFF;
              (void)jv_dff79; }
        }
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
