#include <stdio.h>
enum tok { TOK_NUM, TOK_ID, TOK_OP, TOK_SKIP };
static enum tok classify(char c) {
    if (c >= '0' && c <= '9') return TOK_NUM;
    if ((c >= 'a' && c <= 'z') || c == '_') return TOK_ID;
    if (c == ' ') return TOK_SKIP;
    return TOK_OP;
}
int main(void) {
    const char *src = "x1 = 42 + y_2 * (z - 7)";
    int ppjbirhqhfscsvjxjbg[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) ppjbirhqhfscsvjxjbg[t]++;
        prev = t;
    }
    printf("%d %d %d\n", ppjbirhqhfscsvjxjbg[TOK_NUM], ppjbirhqhfscsvjxjbg[TOK_ID], ppjbirhqhfscsvjxjbg[TOK_OP]);
    return 0;
}
