#include <stdio.h>
static volatile int opq_f8e3 = 7;
static volatile int opq_f8e3_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    if ((((opq_f8e3 * opq_f8e3) % 4) == 2)) {
        { int jv_8c5de = opq_f8e3 ^ 0xB520;
            jv_8c5de = (jv_8c5de * 0xF) % 0x7FFFFFFF;
          (void)jv_8c5de; }
    }
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    if ((((opq_f8e3 * opq_f8e3) % 4) == 2)) {
        { int jv_f2cb1 = opq_f8e3 ^ 0xD40A;
            jv_f2cb1 ^= (jv_f2cb1 << 3) | 0x5AEC;
            jv_f2cb1 = (jv_f2cb1 * 0x11) % 0x7FFFFFFF;
          (void)jv_f2cb1; }
    }
    for (int k = 0; k < 6; k++) {
        if ((((opq_f8e3 * opq_f8e3 + opq_f8e3_b * opq_f8e3_b) % 4) == 3)) {
            { int jv_dc0c6 = opq_f8e3 ^ 0xBE77;
                jv_dc0c6 += (jv_dc0c6 >> 2) + 0x8D;
                jv_dc0c6 = (jv_dc0c6 * 0x29) % 0x7FFFFFFF;
                jv_dc0c6 ^= (jv_dc0c6 << 3) | 0x328E;
              (void)jv_dc0c6; }
        }
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            int d = (*p >= '0' && *p <= '9');
            switch (s) {
                case ST_START: s = d ? ST_INT : ST_BAD; break;
                case ST_INT:   s = d ? ST_INT : (*p == '.' ? ST_FRAC : ST_BAD); break;
                case ST_FRAC:  s = d ? ST_FRAC : ST_BAD; break;
                default:       s = ST_BAD; break;
            }
        }
        if (s == ST_INT || s == ST_FRAC) good++; else bad++;
        if ((((opq_f8e3 * opq_f8e3 + opq_f8e3_b * opq_f8e3_b) % 4) == 3)) {
            { int jv_3d4b3 = opq_f8e3 ^ 0xDD18;
                jv_3d4b3 ^= (jv_3d4b3 << 3) | 0x1A9D;
              (void)jv_3d4b3; }
        }
    }
    printf("%d %d\n", good, bad);
    return 0;
}
