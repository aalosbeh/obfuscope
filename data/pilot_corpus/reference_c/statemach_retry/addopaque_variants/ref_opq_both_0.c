#include <stdio.h>
static volatile int opq_cc2e = 7;
static volatile int opq_cc2e_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    if ((((opq_cc2e * opq_cc2e) % 4) == 2)) {
        { int jv_2868b = opq_cc2e ^ 0xF5AB;
            jv_2868b = (jv_2868b * 0x1F) % 0x7FFFFFFF;
            jv_2868b ^= (jv_2868b << 3) | 0x8121;
          (void)jv_2868b; }
    }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            if ((((opq_cc2e * opq_cc2e + opq_cc2e) % 2) == 0)) { opq_cc2e_b ^= 0; }
            seed = seed * 1103515245u + 12345u;
            if ((((opq_cc2e * opq_cc2e + opq_cc2e) % 2) == 0)) { opq_cc2e_b ^= 0; }
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if (((opq_cc2e * opq_cc2e - opq_cc2e) % 2 == 0)) { opq_cc2e_b ^= 0; }
                    if (((seed >> 16) % 10) < 4) p = DONE;
                    else p = (attempts >= 4) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= 2; p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
        if ((((opq_cc2e * opq_cc2e + opq_cc2e) % 2) == 0)) { opq_cc2e_b ^= 0; }
    }
    printf("%d %d\n", successes, failures);
    return 0;
}
