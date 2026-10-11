#include <stdio.h>
static volatile int opq_e08d = 7;
static volatile int opq_e08d_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    if ((((opq_e08d * opq_e08d + opq_e08d) % 2) == 0)) { opq_e08d_b ^= 0; }
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            if ((((opq_e08d * (opq_e08d + 1)) % 2) == 0)) { opq_e08d_b ^= 0; }
            int d = (*p >= '0' && *p <= '9');
            if ((((opq_e08d * opq_e08d + opq_e08d_b * opq_e08d_b) % 4) == 3)) {
                { int jv_89f44 = opq_e08d ^ 0x4EA8;
                    jv_89f44 ^= (jv_89f44 << 3) | 0xD4C2;
                  (void)jv_89f44; }
            }
            switch (s) {
                case ST_START: s = d ? ST_INT : ST_BAD; break;
                case ST_INT:   s = d ? ST_INT : (*p == '.' ? ST_FRAC : ST_BAD); break;
                case ST_FRAC:  s = d ? ST_FRAC : ST_BAD; break;
                default:       s = ST_BAD; break;
            }
        }
        if (s == ST_INT || s == ST_FRAC) good++; else bad++;
        if ((((opq_e08d * opq_e08d + opq_e08d_b * opq_e08d_b) % 4) == 3)) {
            { int jv_1955f = opq_e08d ^ 0x97F;
                jv_1955f ^= (jv_1955f << 3) | 0xC4BA;
                jv_1955f += (jv_1955f >> 2) + 0x54;
                jv_1955f = (jv_1955f * 0x2E) % 0x7FFFFFFF;
              (void)jv_1955f; }
        }
    }
    printf("%d %d\n", good, bad);
    return 0;
}
