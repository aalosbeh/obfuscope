#include <stdio.h>
static volatile int opq_b79e = 7;
static volatile int opq_b79e_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    if ((((opq_b79e * opq_b79e + opq_b79e) % 2) == 0)) { opq_b79e_b ^= 0; }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    if ((((opq_b79e * (opq_b79e + 1)) % 2) == 0)) { opq_b79e_b ^= 0; }
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            if (((opq_b79e * opq_b79e - opq_b79e) % 2 == 0)) { opq_b79e_b ^= 0; }
            seed = seed * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if ((((opq_b79e * opq_b79e) % 4) == 2)) {
                    { int jv_bf376 = opq_b79e ^ 0xA078;
                        jv_bf376 = (jv_bf376 * 0x36) % 0x7FFFFFFF;
                      (void)jv_bf376; }
                }
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
    if ((((opq_b79e * opq_b79e + opq_b79e) % 2) == 0)) { opq_b79e_b ^= 0; }
    return 0;
}
