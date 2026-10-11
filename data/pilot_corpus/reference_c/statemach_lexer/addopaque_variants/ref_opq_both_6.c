#include <stdio.h>
static volatile int opq_f150 = 7;
static volatile int opq_f150_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    if ((((opq_f150 * opq_f150 + opq_f150) % 2) == 0)) { opq_f150_b ^= 0; }
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            int d = (*p >= '0' && *p <= '9');
            if ((((opq_f150 * opq_f150 + opq_f150) % 2) == 0)) { opq_f150_b ^= 0; }
            switch (s) {
                case ST_START: s = d ? ST_INT : ST_BAD; break;
                case ST_INT:   s = d ? ST_INT : (*p == '.' ? ST_FRAC : ST_BAD); break;
                case ST_FRAC:  s = d ? ST_FRAC : ST_BAD; break;
                default:       s = ST_BAD; break;
            }
        }
        if (s == ST_INT || s == ST_FRAC) good++; else bad++;
        if ((((opq_f150 * opq_f150 + opq_f150) % 2) == 0)) { opq_f150_b ^= 0; }
    }
    printf("%d %d\n", good, bad);
    if ((((opq_f150 * opq_f150 + opq_f150_b * opq_f150_b) % 4) == 3)) {
        { int jv_ce133 = opq_f150 ^ 0x4F7D;
            jv_ce133 = (jv_ce133 * 0x1C) % 0x7FFFFFFF;
            jv_ce133 += (jv_ce133 >> 2) + 0x9C;
            jv_ce133 ^= (jv_ce133 << 3) | 0x6061;
          (void)jv_ce133; }
    }
    return 0;
}
