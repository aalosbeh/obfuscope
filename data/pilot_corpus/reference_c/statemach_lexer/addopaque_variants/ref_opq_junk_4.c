#include <stdio.h>
static volatile int opq_63e2 = 7;
static volatile int opq_63e2_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            int d = (*p >= '0' && *p <= '9');
            if ((((opq_63e2 * opq_63e2 + opq_63e2_b * opq_63e2_b) % 4) == 3)) {
                { int jv_f544d = opq_63e2 ^ 0xF21E;
                    jv_f544d ^= (jv_f544d << 3) | 0x92FD;
                    jv_f544d += (jv_f544d >> 2) + 0x14;
                    jv_f544d = (jv_f544d * 0x2A) % 0x7FFFFFFF;
                  (void)jv_f544d; }
            }
            switch (s) {
                if ((((opq_63e2 * opq_63e2) % 4) == 2)) {
                    { int jv_48fc1 = opq_63e2 ^ 0xFCCD;
                        jv_48fc1 += (jv_48fc1 >> 2) + 0x24;
                        jv_48fc1 ^= (jv_48fc1 << 3) | 0x6504;
                        jv_48fc1 = (jv_48fc1 * 0x19) % 0x7FFFFFFF;
                      (void)jv_48fc1; }
                }
                case ST_START: s = d ? ST_INT : ST_BAD; break;
                case ST_INT:   s = d ? ST_INT : (*p == '.' ? ST_FRAC : ST_BAD); break;
                case ST_FRAC:  s = d ? ST_FRAC : ST_BAD; break;
                default:       s = ST_BAD; break;
            }
        }
        if (s == ST_INT || s == ST_FRAC) good++; else bad++;
        if ((((opq_63e2 * opq_63e2) % 4) == 2)) {
            { int jv_a4d43 = opq_63e2 ^ 0xBB7C;
                jv_a4d43 += (jv_a4d43 >> 2) + 0xEF;
                jv_a4d43 = (jv_a4d43 * 0xA) % 0x7FFFFFFF;
              (void)jv_a4d43; }
        }
    }
    printf("%d %d\n", good, bad);
    if ((((opq_63e2 * opq_63e2 + opq_63e2_b * opq_63e2_b) % 4) == 3)) {
        { int jv_653c3 = opq_63e2 ^ 0x7994;
            jv_653c3 = (jv_653c3 * 0x30) % 0x7FFFFFFF;
            jv_653c3 ^= (jv_653c3 << 3) | 0x98D0;
            jv_653c3 += (jv_653c3 >> 2) + 0x11;
          (void)jv_653c3; }
    }
    return 0;
}
