#include <stdio.h>
static volatile int opq_1cb9 = 7;
static volatile int opq_1cb9_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    if ((((opq_1cb9 * opq_1cb9) % 4) == 2)) {
        { int jv_f1508 = opq_1cb9 ^ 0x6D4D;
            jv_f1508 = (jv_f1508 * 0xC) % 0x7FFFFFFF;
            jv_f1508 += (jv_f1508 >> 2) + 0xD;
          (void)jv_f1508; }
    }
    unsigned seed = 29;
    if ((((opq_1cb9 * opq_1cb9) % 4) == 2)) {
        { int jv_1cbb5 = opq_1cb9 ^ 0x6606;
            jv_1cbb5 ^= (jv_1cbb5 << 3) | 0x93A5;
            jv_1cbb5 += (jv_1cbb5 >> 2) + 0xF1;
          (void)jv_1cbb5; }
    }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        if ((((opq_1cb9 * opq_1cb9 + opq_1cb9_b * opq_1cb9_b) % 4) == 3)) {
            { int jv_896e0 = opq_1cb9 ^ 0xC3E;
                jv_896e0 = (jv_896e0 * 0x33) % 0x7FFFFFFF;
              (void)jv_896e0; }
        }
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            seed = seed * 1103515245u + 12345u;
            if ((((opq_1cb9 * opq_1cb9 + opq_1cb9_b * opq_1cb9_b) % 4) == 3)) {
                { int jv_bce2d = opq_1cb9 ^ 0xC645;
                    jv_bce2d ^= (jv_bce2d << 3) | 0x3F7D;
                    jv_bce2d += (jv_bce2d >> 2) + 0x70;
                    jv_bce2d = (jv_bce2d * 0x2D) % 0x7FFFFFFF;
                  (void)jv_bce2d; }
            }
            switch (p) {
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
    }
    printf("%d %d\n", successes, failures);
    if ((((opq_1cb9 * opq_1cb9 + opq_1cb9_b * opq_1cb9_b) % 4) == 3)) {
        { int jv_d091f = opq_1cb9 ^ 0xDD3C;
            jv_d091f += (jv_d091f >> 2) + 0xBD;
            jv_d091f ^= (jv_d091f << 3) | 0xDD28;
          (void)jv_d091f; }
    }
    return 0;
}
