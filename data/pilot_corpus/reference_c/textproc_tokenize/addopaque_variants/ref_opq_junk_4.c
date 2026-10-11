#include <stdio.h>
static volatile int opq_8bee = 7;
static volatile int opq_8bee_b = 3;

enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if ((((opq_8bee * opq_8bee + opq_8bee_b * opq_8bee_b) % 4) == 3)) {
        { int jv_43c6a = opq_8bee ^ 0x3BF6;
            jv_43c6a = (jv_43c6a * 0xE) % 0x7FFFFFFF;
            jv_43c6a += (jv_43c6a >> 2) + 0xB9;
            jv_43c6a ^= (jv_43c6a << 3) | 0x3D6D;
          (void)jv_43c6a; }
    }
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if ((((opq_8bee * opq_8bee + opq_8bee_b * opq_8bee_b) % 4) == 3)) {
        { int jv_c98b2 = opq_8bee ^ 0x9460;
            jv_c98b2 ^= (jv_c98b2 << 3) | 0x7A49;
          (void)jv_c98b2; }
    }
    if (c == ' ') return TOK_SKIP;
    if ((((opq_8bee * opq_8bee) % 4) == 2)) {
        { int jv_380f3 = opq_8bee ^ 0x8E15;
            jv_380f3 += (jv_380f3 >> 2) + 0x71;
            jv_380f3 = (jv_380f3 * 0x23) % 0x7FFFFFFF;
            jv_380f3 ^= (jv_380f3 << 3) | 0x56F9;
          (void)jv_380f3; }
    }
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    if ((((opq_8bee * opq_8bee + opq_8bee_b * opq_8bee_b) % 4) == 3)) {
        { int jv_9bdce = opq_8bee ^ 0xFB7;
            jv_9bdce ^= (jv_9bdce << 3) | 0xC826;
            jv_9bdce = (jv_9bdce * 0x25) % 0x7FFFFFFF;
            jv_9bdce += (jv_9bdce >> 2) + 0xA2;
          (void)jv_9bdce; }
    }
    int counts[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        if ((((opq_8bee * opq_8bee) % 4) == 2)) {
            { int jv_363f7 = opq_8bee ^ 0x909C;
                jv_363f7 += (jv_363f7 >> 2) + 0xA0;
                jv_363f7 ^= (jv_363f7 << 3) | 0xB877;
              (void)jv_363f7; }
        }
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        if ((((opq_8bee * opq_8bee + opq_8bee_b * opq_8bee_b) % 4) == 3)) {
            { int jv_36de5 = opq_8bee ^ 0x1E81;
                jv_36de5 ^= (jv_36de5 << 3) | 0x1268;
                jv_36de5 = (jv_36de5 * 0xE) % 0x7FFFFFFF;
                jv_36de5 += (jv_36de5 >> 2) + 0x80;
              (void)jv_36de5; }
        }
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return 0;
}
