#include <stdio.h>
static volatile int opq_31db = 7;
static volatile int opq_31db_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    if ((((opq_31db * opq_31db + opq_31db_b * opq_31db_b) % 4) == 3)) {
        { int jv_30c5e = opq_31db ^ 0xE103;
            jv_30c5e ^= (jv_30c5e << 3) | 0x105F;
            jv_30c5e = (jv_30c5e * 0x31) % 0x7FFFFFFF;
          (void)jv_30c5e; }
    }
    unsigned seed = 29;
    if ((((opq_31db * opq_31db + opq_31db_b * opq_31db_b) % 4) == 3)) {
        { int jv_20e72 = opq_31db ^ 0x1281;
            jv_20e72 ^= (jv_20e72 << 3) | 0x9F47;
            jv_20e72 = (jv_20e72 * 0x3C) % 0x7FFFFFFF;
          (void)jv_20e72; }
    }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        if ((((opq_31db * opq_31db + opq_31db_b * opq_31db_b) % 4) == 3)) {
            { int jv_d8b4f = opq_31db ^ 0x87DD;
                jv_d8b4f ^= (jv_d8b4f << 3) | 0xC0D0;
                jv_d8b4f = (jv_d8b4f * 0xF) % 0x7FFFFFFF;
              (void)jv_d8b4f; }
        }
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            seed = seed * 1103515245u + 12345u;
            switch (p) {
                if ((((opq_31db * opq_31db) % 4) == 2)) {
                    { int jv_1fc89 = opq_31db ^ 0xFF87;
                        jv_1fc89 += (jv_1fc89 >> 2) + 0xE6;
                        jv_1fc89 = (jv_1fc89 * 0xD) % 0x7FFFFFFF;
                        jv_1fc89 ^= (jv_1fc89 << 3) | 0x5463;
                      (void)jv_1fc89; }
                }
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> 16) % 10) < 4) p = DONE;
                    else p = (attempts >= 4) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= 2; p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
        if ((((opq_31db * opq_31db) % 4) == 2)) {
            { int jv_2e2a7 = opq_31db ^ 0x80A6;
                jv_2e2a7 = (jv_2e2a7 * 0x38) % 0x7FFFFFFF;
              (void)jv_2e2a7; }
        }
    }
    printf("%d %d\n", successes, failures);
    return 0;
}
