#include <stdio.h>
static volatile int opq_845d = 7;
static volatile int opq_845d_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    if ((((opq_845d * opq_845d + opq_845d) % 2) == 0)) { opq_845d_b ^= 0; }
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        if ((((opq_845d * opq_845d + opq_845d) % 2) == 0)) { opq_845d_b ^= 0; }
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            int d = (*p >= '0' && *p <= '9');
            if (((opq_845d * opq_845d - opq_845d) % 2 == 0)) { opq_845d_b ^= 0; }
            switch (s) {
                if ((((opq_845d * opq_845d + opq_845d) % 2) == 0)) { opq_845d_b ^= 0; }
                case ST_START: s = d ? ST_INT : ST_BAD; break;
                case ST_INT:   s = d ? ST_INT : (*p == '.' ? ST_FRAC : ST_BAD); break;
                case ST_FRAC:  s = d ? ST_FRAC : ST_BAD; break;
                default:       s = ST_BAD; break;
            }
        }
        if (s == ST_INT || s == ST_FRAC) good++; else bad++;
    }
    printf("%d %d\n", good, bad);
    return 0;
}
