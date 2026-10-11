#include <stdio.h>
static volatile int opq_fc8b = 7;
static volatile int opq_fc8b_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    if ((((opq_fc8b * opq_fc8b + opq_fc8b_b * opq_fc8b_b) % 4) == 3)) {
        { int jv_4e71d = opq_fc8b ^ 0x4D7C;
            jv_4e71d = (jv_4e71d * 0x21) % 0x7FFFFFFF;
            jv_4e71d += (jv_4e71d >> 2) + 0xC6;
            jv_4e71d ^= (jv_4e71d << 3) | 0x24EC;
          (void)jv_4e71d; }
    }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            if ((((opq_fc8b * opq_fc8b) % 4) == 2)) {
                { int jv_b4574 = opq_fc8b ^ 0xE6F6;
                    jv_b4574 ^= (jv_b4574 << 3) | 0xC5FA;
                  (void)jv_b4574; }
            }
            seed = seed * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if ((((opq_fc8b * opq_fc8b + opq_fc8b_b * opq_fc8b_b) % 4) == 3)) {
                    { int jv_15a60 = opq_fc8b ^ 0x31B;
                        jv_15a60 = (jv_15a60 * 0xE) % 0x7FFFFFFF;
                      (void)jv_15a60; }
                }
                    if (((seed >> 16) % 10) < 4) p = DONE;
                    else p = (attempts >= 4) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= 2; p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
        if ((((opq_fc8b * opq_fc8b + opq_fc8b_b * opq_fc8b_b) % 4) == 3)) {
            { int jv_ab284 = opq_fc8b ^ 0xAEA5;
                jv_ab284 = (jv_ab284 * 0x34) % 0x7FFFFFFF;
              (void)jv_ab284; }
        }
    }
    printf("%d %d\n", successes, failures);
    if ((((opq_fc8b * opq_fc8b) % 4) == 2)) {
        { int jv_f0410 = opq_fc8b ^ 0xD6DE;
            jv_f0410 ^= (jv_f0410 << 3) | 0xE7F2;
            jv_f0410 = (jv_f0410 * 0xB) % 0x7FFFFFFF;
          (void)jv_f0410; }
    }
    return 0;
}
