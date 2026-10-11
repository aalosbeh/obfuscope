#include <stdio.h>
static volatile int opq_711d = 7;
static volatile int opq_711d_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    if ((((opq_711d * opq_711d + opq_711d) % 2) == 0)) { opq_711d_b ^= 0; }
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            if ((((opq_711d * opq_711d) % 4) == 2)) {
                { int jv_e5d39 = opq_711d ^ 0x5F20;
                    jv_e5d39 = (jv_e5d39 * 0x14) % 0x7FFFFFFF;
                  (void)jv_e5d39; }
            }
            int d = (*p >= '0' && *p <= '9');
            if ((((opq_711d * opq_711d + opq_711d) % 2) == 0)) { opq_711d_b ^= 0; }
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
    if ((((opq_711d * opq_711d + opq_711d_b * opq_711d_b) % 4) == 3)) {
        { int jv_9c8f0 = opq_711d ^ 0x9BF8;
            jv_9c8f0 += (jv_9c8f0 >> 2) + 0x2C;
            jv_9c8f0 = (jv_9c8f0 * 0x3B) % 0x7FFFFFFF;
            jv_9c8f0 ^= (jv_9c8f0 << 3) | 0xB985;
          (void)jv_9c8f0; }
    }
    return 0;
}
