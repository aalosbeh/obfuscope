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
    int fjmldahaknksbijgsebwh[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) fjmldahaknksbijgsebwh[t]++;
        prev = t;
    }
    printf("%d %d %d\n", fjmldahaknksbijgsebwh[TOK_NUM], fjmldahaknksbijgsebwh[TOK_ID], fjmldahaknksbijgsebwh[TOK_OP]);
    return 0;
}
