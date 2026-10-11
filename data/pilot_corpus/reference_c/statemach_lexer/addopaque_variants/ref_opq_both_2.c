#include <stdio.h>
static volatile int opq_e1cf = 7;
static volatile int opq_e1cf_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        if ((((opq_e1cf * opq_e1cf + opq_e1cf) % 2) == 0)) { opq_e1cf_b ^= 0; }
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            int d = (*p >= '0' && *p <= '9');
            if ((((opq_e1cf * opq_e1cf) % 4) == 2)) {
                { int jv_ad109 = opq_e1cf ^ 0x4DB3;
                    jv_ad109 = (jv_ad109 * 0x11) % 0x7FFFFFFF;
                    jv_ad109 ^= (jv_ad109 << 3) | 0xBD75;
                  (void)jv_ad109; }
            }
            switch (s) {
                if ((((opq_e1cf * opq_e1cf + opq_e1cf_b * opq_e1cf_b) % 4) == 3)) {
                    { int jv_11291 = opq_e1cf ^ 0xB30F;
                        jv_11291 ^= (jv_11291 << 3) | 0x5408;
                      (void)jv_11291; }
                }
                case ST_START: s = d ? ST_INT : ST_BAD; break;
                case ST_INT:   s = d ? ST_INT : (*p == '.' ? ST_FRAC : ST_BAD); break;
                case ST_FRAC:  s = d ? ST_FRAC : ST_BAD; break;
                default:       s = ST_BAD; break;
            }
        }
        if (s == ST_INT || s == ST_FRAC) good++; else bad++;
    }
    printf("%d %d\n", good, bad);
    if ((((opq_e1cf * opq_e1cf + opq_e1cf) % 2) == 0)) { opq_e1cf_b ^= 0; }
    return 0;
}
