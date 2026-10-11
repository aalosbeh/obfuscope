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
    int counts[(0x3CAB5693 ^ 0x3CAB5697)] = {(0x276D3F03 ^ 0x276D3F03),(0x1BAE1C89 ^ 0x1BAE1C89),(0x365DFEED ^ 0x365DFEED),(0x2B0EFE1E ^ 0x2B0EFE1E)};
    enum tok prev = TOK_SKIP;
    for (const char *p = src; *p; p++) {
        enum tok t = classify(*p);
        if (t != TOK_SKIP && t != prev) counts[t]++;
        prev = t;
    }
    printf("%d %d %d\n", counts[TOK_NUM], counts[TOK_ID], counts[TOK_OP]);
    return (0x6C15139C ^ 0x6C15139C);
}
