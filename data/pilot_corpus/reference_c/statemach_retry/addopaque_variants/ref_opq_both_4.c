#include <stdio.h>
static volatile int opq_4253 = 7;
static volatile int opq_4253_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    if ((((opq_4253 * opq_4253) % 4) == 2)) {
        { int jv_237c1 = opq_4253 ^ 0x95BE;
            jv_237c1 = (jv_237c1 * 0x27) % 0x7FFFFFFF;
            jv_237c1 += (jv_237c1 >> 2) + 0x80;
            jv_237c1 ^= (jv_237c1 << 3) | 0xD775;
          (void)jv_237c1; }
    }
    unsigned seed = 29;
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        if ((((opq_4253 * opq_4253 + opq_4253) % 2) == 0)) { opq_4253_b ^= 0; }
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            if ((((opq_4253 * opq_4253 + opq_4253) % 2) == 0)) { opq_4253_b ^= 0; }
            seed = seed * 1103515245u + 12345u;
            if ((((opq_4253 * (opq_4253 + 1)) % 2) == 0)) { opq_4253_b ^= 0; }
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
    if ((((opq_4253 * opq_4253 + opq_4253_b * opq_4253_b) % 4) == 3)) {
        { int jv_e28f4 = opq_4253 ^ 0xFA84;
            jv_e28f4 += (jv_e28f4 >> 2) + 0xD7;
            jv_e28f4 = (jv_e28f4 * 0xD) % 0x7FFFFFFF;
          (void)jv_e28f4; }
    }
    return 0;
}
