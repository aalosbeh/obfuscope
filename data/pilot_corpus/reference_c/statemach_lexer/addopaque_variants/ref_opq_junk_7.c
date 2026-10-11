#include <stdio.h>
static volatile int opq_7659 = 7;
static volatile int opq_7659_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    if ((((opq_7659 * opq_7659) % 4) == 2)) {
        { int jv_3be80 = opq_7659 ^ 0x6675;
            jv_3be80 += (jv_3be80 >> 2) + 0xD9;
          (void)jv_3be80; }
    }
    for (int k = 0; k < 6; k++) {
        if ((((opq_7659 * opq_7659) % 4) == 2)) {
            { int jv_1a11e = opq_7659 ^ 0xC5D5;
                jv_1a11e = (jv_1a11e * 0x13) % 0x7FFFFFFF;
              (void)jv_1a11e; }
        }
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            if ((((opq_7659 * opq_7659) % 4) == 2)) {
                { int jv_3fd23 = opq_7659 ^ 0x5E55;
                    jv_3fd23 = (jv_3fd23 * 0x9) % 0x7FFFFFFF;
                    jv_3fd23 ^= (jv_3fd23 << 3) | 0xCB7E;
                  (void)jv_3fd23; }
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
    if ((((opq_7659 * opq_7659 + opq_7659_b * opq_7659_b) % 4) == 3)) {
        { int jv_1331b = opq_7659 ^ 0xFA1C;
            jv_1331b = (jv_1331b * 0x1F) % 0x7FFFFFFF;
            jv_1331b += (jv_1331b >> 2) + 0x23;
            jv_1331b ^= (jv_1331b << 3) | 0xBBBA;
          (void)jv_1331b; }
    }
    return 0;
}
