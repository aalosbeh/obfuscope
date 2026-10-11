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
    int qtiloythatknvutcmyitav[4] = {0,0,0,0};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) qtiloythatknvutcmyitav[t]++;
        prev = t;
    }
    printf("%d %d %d\n", qtiloythatknvutcmyitav[TOK_NUM], qtiloythatknvutcmyitav[TOK_ID], qtiloythatknvutcmyitav[TOK_OP]);
    return 0;
}
