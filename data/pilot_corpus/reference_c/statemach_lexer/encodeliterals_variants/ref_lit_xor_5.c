#include <stdio.h>
enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = (0x645A8F56 ^ 0x645A8F56), bad = (0x6FBF6F19 ^ 0x6FBF6F19);
    for (int k = (0x3C7CE5A3 ^ 0x3C7CE5A3); k < (0x26D3A8A0 ^ 0x26D3A8A6); k++) {
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            int d = (*p >= '0' && *p <= '9');
            switch (s) {
                case ST_START: s = d ? ST_INT : ST_BAD; break;
                case ST_INT:   s = d ? ST_INT : (*p == '.' ? ST_FRAC : ST_BAD); break;
                case ST_FRAC:  s = d ? ST_FRAC : ST_BAD; break;
                default:       s = ST_BAD; break;
            }
        }
        if (s == ST_INT || s == ST_FRAC) good++; else bad++;
    }
    printf("%d %d\n", good, bad);
    return (0x7C2B8F4E ^ 0x7C2B8F4E);
}
