#include <stdio.h>
static volatile int opq_4bc1 = 7;
static volatile int opq_4bc1_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    if ((((opq_4bc1 * opq_4bc1) % 4) == 2)) {
        { int jv_6b267 = opq_4bc1 ^ 0x80D4;
            jv_6b267 ^= (jv_6b267 << 3) | 0x7914;
            jv_6b267 += (jv_6b267 >> 2) + 0x8A;
          (void)jv_6b267; }
    }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            if ((((opq_4bc1 * opq_4bc1) % 4) == 2)) {
                { int jv_c794f = opq_4bc1 ^ 0x1D54;
                    jv_c794f ^= (jv_c794f << 3) | 0x3AB0;
                    jv_c794f += (jv_c794f >> 2) + 0x9E;
                  (void)jv_c794f; }
            }
            seed = seed * 1103515245u + 12345u;
            if ((((opq_4bc1 * (opq_4bc1 + 1)) % 2) == 0)) { opq_4bc1_b ^= 0; }
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if ((((opq_4bc1 * opq_4bc1 + opq_4bc1) % 2) == 0)) { opq_4bc1_b ^= 0; }
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
    if ((((opq_4bc1 * opq_4bc1) % 4) == 2)) {
        { int jv_f11ce = opq_4bc1 ^ 0x362D;
            jv_f11ce += (jv_f11ce >> 2) + 0xBB;
            jv_f11ce = (jv_f11ce * 0x2A) % 0x7FFFFFFF;
            jv_f11ce ^= (jv_f11ce << 3) | 0xE044;
          (void)jv_f11ce; }
    }
    return 0;
}
