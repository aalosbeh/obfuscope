#include <stdio.h>
static volatile int opq_4600 = 7;
static volatile int opq_4600_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    if (((opq_4600 * opq_4600 - opq_4600) % 2 == 0)) { opq_4600_b ^= 0; }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            seed = seed * 1103515245u + 12345u;
            if ((((opq_4600 * opq_4600 + opq_4600) % 2) == 0)) { opq_4600_b ^= 0; }
            switch (p) {
                if ((((opq_4600 * (opq_4600 + 1)) % 2) == 0)) { opq_4600_b ^= 0; }
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if ((((opq_4600 * (opq_4600 + 1)) % 2) == 0)) { opq_4600_b ^= 0; }
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
    if (((opq_4600 * opq_4600 - opq_4600) % 2 == 0)) { opq_4600_b ^= 0; }
    return 0;
}
