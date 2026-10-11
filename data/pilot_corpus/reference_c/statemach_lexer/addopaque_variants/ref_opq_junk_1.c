#include <stdio.h>
static volatile int opq_44a1 = 7;
static volatile int opq_44a1_b = 3;

enum st { ST_START, ST_INT, ST_FRAC, ST_BAD };
int main(void) {
    if ((((opq_44a1 * opq_44a1) % 4) == 2)) {
        { int jv_efa9a = opq_44a1 ^ 0xE268;
            jv_efa9a ^= (jv_efa9a << 3) | 0xB7F5;
            jv_efa9a = (jv_efa9a * 0x1B) % 0x7FFFFFFF;
            jv_efa9a += (jv_efa9a >> 2) + 0xBC;
          (void)jv_efa9a; }
    }
    const char *inputs[] = {"12.5", "7", "3.1.4", "x9", ".5", "100.001"};
    int good = 0, bad = 0;
    for (int k = 0; k < 6; k++) {
        if ((((opq_44a1 * opq_44a1) % 4) == 2)) {
            { int jv_b4f29 = opq_44a1 ^ 0x4665;
                jv_b4f29 += (jv_b4f29 >> 2) + 0x27;
                jv_b4f29 ^= (jv_b4f29 << 3) | 0x5276;
              (void)jv_b4f29; }
        }
        enum st s = ST_START;
        for (const char *p = inputs[k]; *p && s != ST_BAD; p++) {
            if ((((opq_44a1 * opq_44a1) % 4) == 2)) {
                { int jv_694e9 = opq_44a1 ^ 0xC474;
                    jv_694e9 = (jv_694e9 * 0x25) % 0x7FFFFFFF;
                  (void)jv_694e9; }
            }
            int d = (*p >= '0' && *p <= '9');
            if ((((opq_44a1 * opq_44a1 + opq_44a1_b * opq_44a1_b) % 4) == 3)) {
                { int jv_46f2e = opq_44a1 ^ 0xE8EB;
                    jv_46f2e ^= (jv_46f2e << 3) | 0x126E;
                    jv_46f2e += (jv_46f2e >> 2) + 0x6A;
                    jv_46f2e = (jv_46f2e * 0x16) % 0x7FFFFFFF;
                  (void)jv_46f2e; }
            }
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
    return 0;
}
