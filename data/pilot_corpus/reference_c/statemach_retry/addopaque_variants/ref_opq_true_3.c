#include <stdio.h>
static volatile int opq_ba47 = 7;
static volatile int opq_ba47_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    if ((((opq_ba47 * opq_ba47 + opq_ba47) % 2) == 0)) { opq_ba47_b ^= 0; }
    unsigned seed = 29;
    if ((((opq_ba47 * opq_ba47 + opq_ba47) % 2) == 0)) { opq_ba47_b ^= 0; }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    if (((opq_ba47 * opq_ba47 - opq_ba47) % 2 == 0)) { opq_ba47_b ^= 0; }
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            seed = seed * 1103515245u + 12345u;
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
        if ((((opq_ba47 * (opq_ba47 + 1)) % 2) == 0)) { opq_ba47_b ^= 0; }
    }
    printf("%d %d\n", successes, failures);
    if ((((opq_ba47 * opq_ba47 + opq_ba47) % 2) == 0)) { opq_ba47_b ^= 0; }
    return 0;
}
