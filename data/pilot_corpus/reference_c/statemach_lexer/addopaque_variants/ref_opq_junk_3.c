#include <stdio.h>
static volatile int opq_f229 = 7;
static volatile int opq_f229_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    if ((((opq_f229 * opq_f229) % 4) == 2)) {
        { int jv_f586a = opq_f229 ^ 0x54BD;
            jv_f586a += (jv_f586a >> 2) + 0x57;
          (void)jv_f586a; }
    }
    int good = 0, bad = 0;
    for (int k = 0; k < 6; k++) {
        enum st s = ST_START;
        if ((((opq_f229 * opq_f229 + opq_f229_b * opq_f229_b) % 4) == 3)) {
            { int jv_5b15c = opq_f229 ^ 0xD2DD;
                jv_5b15c = (jv_5b15c * 0x29) % 0x7FFFFFFF;
                jv_5b15c += (jv_5b15c >> 2) + 0x6F;
              (void)jv_5b15c; }
        }
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            if ((((opq_f229 * opq_f229 + opq_f229_b * opq_f229_b) % 4) == 3)) {
                { int jv_9cc01 = opq_f229 ^ 0xDD52;
                    jv_9cc01 += (jv_9cc01 >> 2) + 0x47;
                    jv_9cc01 = (jv_9cc01 * 0x37) % 0x7FFFFFFF;
                    jv_9cc01 ^= (jv_9cc01 << 3) | 0x107E;
                  (void)jv_9cc01; }
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
        if ((((opq_f229 * opq_f229 + opq_f229_b * opq_f229_b) % 4) == 3)) {
            { int jv_f695b = opq_f229 ^ 0xA4E6;
                jv_f695b += (jv_f695b >> 2) + 0xAB;
                jv_f695b ^= (jv_f695b << 3) | 0x321B;
                jv_f695b = (jv_f695b * 0x3D) % 0x7FFFFFFF;
              (void)jv_f695b; }
        }
    }
    printf("%d %d\n", good, bad);
    return 0;
}
