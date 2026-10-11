#include <stdio.h>
static volatile int opq_5cb2 = 7;
static volatile int opq_5cb2_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    if (((opq_5cb2 * opq_5cb2 - opq_5cb2) % 2 == 0)) { opq_5cb2_b ^= 0; }
    unsigned seed = 29;
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        if ((((opq_5cb2 * (opq_5cb2 + 1)) % 2) == 0)) { opq_5cb2_b ^= 0; }
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            if ((((opq_5cb2 * (opq_5cb2 + 1)) % 2) == 0)) { opq_5cb2_b ^= 0; }
            seed = seed * 1103515245u + 12345u;
            switch (p) {
                if (((opq_5cb2 * opq_5cb2 - opq_5cb2) % 2 == 0)) { opq_5cb2_b ^= 0; }
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if ((((opq_5cb2 * opq_5cb2 + opq_5cb2_b * opq_5cb2_b) % 4) == 3)) {
                    { int jv_ed4bd = opq_5cb2 ^ 0x1F7C;
                        jv_ed4bd ^= (jv_ed4bd << 3) | 0x109;
                        jv_ed4bd += (jv_ed4bd >> 2) + 0xB;
                        jv_ed4bd = (jv_ed4bd * 0x29) % 0x7FFFFFFF;
                      (void)jv_ed4bd; }
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
    return 0;
}
