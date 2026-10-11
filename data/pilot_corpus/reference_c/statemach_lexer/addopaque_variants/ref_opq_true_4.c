#include <stdio.h>
static volatile int opq_acfc = 7;
static volatile int opq_acfc_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    if (((opq_acfc * opq_acfc - opq_acfc) % 2 == 0)) { opq_acfc_b ^= 0; }
    int good = 0, bad = 0;
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            int d = (*p >= '0' && *p <= '9');
            switch (s) {
                if ((((opq_acfc * opq_acfc + opq_acfc) % 2) == 0)) { opq_acfc_b ^= 0; }
                case ST_START: s = d ? ST_INT : ST_BAD; break;
                case ST_INT:   s = d ? ST_INT : (*p == '.' ? ST_FRAC : ST_BAD); break;
                case ST_FRAC:  s = d ? ST_FRAC : ST_BAD; break;
                default:       s = ST_BAD; break;
            }
        }
        if (s == ST_INT || s == ST_FRAC) good++; else bad++;
        if ((((opq_acfc * opq_acfc + opq_acfc) % 2) == 0)) { opq_acfc_b ^= 0; }
    }
    printf("%d %d\n", good, bad);
    if (((opq_acfc * opq_acfc - opq_acfc) % 2 == 0)) { opq_acfc_b ^= 0; }
    return 0;
}
