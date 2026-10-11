#include <stdio.h>
static volatile int opq_8835 = 7;
static volatile int opq_8835_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    if ((((opq_8835 * opq_8835 + opq_8835_b * opq_8835_b) % 4) == 3)) {
        { int jv_d9299 = opq_8835 ^ 0x15FC;
            jv_d9299 = (jv_d9299 * 0x2A) % 0x7FFFFFFF;
          (void)jv_d9299; }
    }
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        if ((((opq_8835 * opq_8835 + opq_8835_b * opq_8835_b) % 4) == 3)) {
            { int jv_8cf05 = opq_8835 ^ 0xA1B9;
                jv_8cf05 ^= (jv_8cf05 << 3) | 0x3673;
              (void)jv_8cf05; }
        }
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            seed = seed * 1103515245u + 12345u;
            if ((((opq_8835 * opq_8835) % 4) == 2)) {
                { int jv_ab9cc = opq_8835 ^ 0x5FE;
                    jv_ab9cc = (jv_ab9cc * 0x1B) % 0x7FFFFFFF;
                    jv_ab9cc += (jv_ab9cc >> 2) + 0x27;
                  (void)jv_ab9cc; }
            }
            switch (p) {
                if ((((opq_8835 * opq_8835 + opq_8835_b * opq_8835_b) % 4) == 3)) {
                    { int jv_1fc51 = opq_8835 ^ 0x2AA6;
                        jv_1fc51 = (jv_1fc51 * 0x17) % 0x7FFFFFFF;
                      (void)jv_1fc51; }
                }
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if ((((opq_8835 * opq_8835) % 4) == 2)) {
                    { int jv_d8b49 = opq_8835 ^ 0x62FB;
                        jv_d8b49 = (jv_d8b49 * 0x1B) % 0x7FFFFFFF;
                      (void)jv_d8b49; }
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
