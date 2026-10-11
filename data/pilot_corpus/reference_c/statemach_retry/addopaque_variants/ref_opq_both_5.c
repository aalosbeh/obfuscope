#include <stdio.h>
static volatile int opq_a44a = 7;
static volatile int opq_a44a_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    if (((opq_a44a * opq_a44a - opq_a44a) % 2 == 0)) { opq_a44a_b ^= 0; }
    unsigned seed = 29;
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    if ((((opq_a44a * opq_a44a + opq_a44a_b * opq_a44a_b) % 4) == 3)) {
        { int jv_2fbba = opq_a44a ^ 0x3878;
            jv_2fbba ^= (jv_2fbba << 3) | 0x9C2;
            jv_2fbba = (jv_2fbba * 0x13) % 0x7FFFFFFF;
          (void)jv_2fbba; }
    }
    for (int job = 0; job < 12; job++) {
        if ((((opq_a44a * opq_a44a) % 4) == 2)) {
            { int jv_f383e = opq_a44a ^ 0x7B29;
                jv_f383e = (jv_f383e * 0x7) % 0x7FFFFFFF;
                jv_f383e ^= (jv_f383e << 3) | 0x301;
                jv_f383e += (jv_f383e >> 2) + 0x35;
              (void)jv_f383e; }
        }
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            seed = seed * 1103515245u + 12345u;
            switch (p) {
                if ((((opq_a44a * opq_a44a + opq_a44a) % 2) == 0)) { opq_a44a_b ^= 0; }
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
    if ((((opq_a44a * (opq_a44a + 1)) % 2) == 0)) { opq_a44a_b ^= 0; }
    return 0;
}
