#include <stdio.h>
static volatile int opq_2e59 = 7;
static volatile int opq_2e59_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    if ((((opq_2e59 * opq_2e59) % 4) == 2)) {
        { int jv_eb2a2 = opq_2e59 ^ 0x108F;
            jv_eb2a2 = (jv_eb2a2 * 0x2A) % 0x7FFFFFFF;
            jv_eb2a2 += (jv_eb2a2 >> 2) + 0xF7;
            jv_eb2a2 ^= (jv_eb2a2 << 3) | 0xB25F;
          (void)jv_eb2a2; }
    }
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        if ((((opq_2e59 * opq_2e59) % 4) == 2)) {
            { int jv_60f22 = opq_2e59 ^ 0xB1F;
                jv_60f22 += (jv_60f22 >> 2) + 0xCB;
                jv_60f22 ^= (jv_60f22 << 3) | 0x9281;
                jv_60f22 = (jv_60f22 * 0x3C) % 0x7FFFFFFF;
              (void)jv_60f22; }
        }
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            int d = (*p >= '0' && *p <= '9');
            switch (s) {
                if ((((opq_2e59 * opq_2e59 + opq_2e59_b * opq_2e59_b) % 4) == 3)) {
                    { int jv_2632d = opq_2e59 ^ 0x6A95;
                        jv_2632d = (jv_2632d * 0x20) % 0x7FFFFFFF;
                        jv_2632d += (jv_2632d >> 2) + 0x70;
                      (void)jv_2632d; }
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
    if ((((opq_2e59 * opq_2e59 + opq_2e59_b * opq_2e59_b) % 4) == 3)) {
        { int jv_4ca43 = opq_2e59 ^ 0x4766;
            jv_4ca43 = (jv_4ca43 * 0x20) % 0x7FFFFFFF;
          (void)jv_4ca43; }
    }
    return 0;
}
