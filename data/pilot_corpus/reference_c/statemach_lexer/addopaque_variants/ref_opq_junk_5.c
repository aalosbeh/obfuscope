#include <stdio.h>
static volatile int opq_72a0 = 7;
static volatile int opq_72a0_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    if ((((opq_72a0 * opq_72a0) % 4) == 2)) {
        { int jv_dd117 = opq_72a0 ^ 0x3710;
            jv_dd117 ^= (jv_dd117 << 3) | 0xF0CE;
            jv_dd117 = (jv_dd117 * 0x2D) % 0x7FFFFFFF;
          (void)jv_dd117; }
    }
    int good = 0, bad = 0;
    for (int k = 0; k < 6; k++) {
        if ((((opq_72a0 * opq_72a0 + opq_72a0_b * opq_72a0_b) % 4) == 3)) {
            { int jv_4bd43 = opq_72a0 ^ 0x3730;
                jv_4bd43 ^= (jv_4bd43 << 3) | 0x5F7D;
              (void)jv_4bd43; }
        }
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            if ((((opq_72a0 * opq_72a0 + opq_72a0_b * opq_72a0_b) % 4) == 3)) {
                { int jv_9034c = opq_72a0 ^ 0xF300;
                    jv_9034c += (jv_9034c >> 2) + 0x3C;
                  (void)jv_9034c; }
            }
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
    if ((((opq_72a0 * opq_72a0) % 4) == 2)) {
        { int jv_b0edf = opq_72a0 ^ 0xAB67;
            jv_b0edf = (jv_b0edf * 0x23) % 0x7FFFFFFF;
            jv_b0edf += (jv_b0edf >> 2) + 0x76;
            jv_b0edf ^= (jv_b0edf << 3) | 0xB125;
          (void)jv_b0edf; }
    }
    return 0;
}
