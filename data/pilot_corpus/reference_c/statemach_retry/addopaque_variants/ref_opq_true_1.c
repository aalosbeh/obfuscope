#include <stdio.h>
static volatile int opq_c468 = 7;
static volatile int opq_c468_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    if ((((opq_c468 * opq_c468 + opq_c468) % 2) == 0)) { opq_c468_b ^= 0; }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    if ((((opq_c468 * opq_c468 + opq_c468) % 2) == 0)) { opq_c468_b ^= 0; }
    for (int job = 0; job < 12; job++) {
        if ((((opq_c468 * (opq_c468 + 1)) % 2) == 0)) { opq_c468_b ^= 0; }
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            if ((((opq_c468 * opq_c468 + opq_c468) % 2) == 0)) { opq_c468_b ^= 0; }
            seed = seed * 1103515245u + 12345u;
            if ((((opq_c468 * opq_c468 + opq_c468) % 2) == 0)) { opq_c468_b ^= 0; }
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
    return 0;
}
