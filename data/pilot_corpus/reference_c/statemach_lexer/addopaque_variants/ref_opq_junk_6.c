#include <stdio.h>
static volatile int opq_1051 = 7;
static volatile int opq_1051_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    if ((((opq_1051 * opq_1051) % 4) == 2)) {
        { int jv_dfeb7 = opq_1051 ^ 0x1613;
            jv_dfeb7 = (jv_dfeb7 * 0x17) % 0x7FFFFFFF;
          (void)jv_dfeb7; }
    }
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    if ((((opq_1051 * opq_1051 + opq_1051_b * opq_1051_b) % 4) == 3)) {
        { int jv_1a11b = opq_1051 ^ 0xF469;
            jv_1a11b += (jv_1a11b >> 2) + 0xB6;
            jv_1a11b = (jv_1a11b * 0x2C) % 0x7FFFFFFF;
          (void)jv_1a11b; }
    }
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            int d = (*p >= '0' && *p <= '9');
            if ((((opq_1051 * opq_1051 + opq_1051_b * opq_1051_b) % 4) == 3)) {
                { int jv_387fa = opq_1051 ^ 0x2408;
                    jv_387fa += (jv_387fa >> 2) + 0xCA;
                  (void)jv_387fa; }
            }
            switch (s) {
                if ((((opq_1051 * opq_1051 + opq_1051_b * opq_1051_b) % 4) == 3)) {
                    { int jv_982ec = opq_1051 ^ 0x7CDF;
                        jv_982ec = (jv_982ec * 0x2E) % 0x7FFFFFFF;
                        jv_982ec += (jv_982ec >> 2) + 0x46;
                      (void)jv_982ec; }
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
    return 0;
}
