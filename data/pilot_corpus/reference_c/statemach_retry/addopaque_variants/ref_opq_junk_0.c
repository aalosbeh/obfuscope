#include <stdio.h>
static volatile int opq_d5a9 = 7;
static volatile int opq_d5a9_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    if ((((opq_d5a9 * opq_d5a9) % 4) == 2)) {
        { int jv_3801b = opq_d5a9 ^ 0x5FA8;
            jv_3801b += (jv_3801b >> 2) + 0xE1;
            jv_3801b ^= (jv_3801b << 3) | 0x68BD;
          (void)jv_3801b; }
    }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        if ((((opq_d5a9 * opq_d5a9 + opq_d5a9_b * opq_d5a9_b) % 4) == 3)) {
            { int jv_956ff = opq_d5a9 ^ 0xD6F0;
                jv_956ff += (jv_956ff >> 2) + 0xC1;
              (void)jv_956ff; }
        }
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            seed = seed * 1103515245u + 12345u;
            switch (p) {
                if ((((opq_d5a9 * opq_d5a9) % 4) == 2)) {
                    { int jv_13e0e = opq_d5a9 ^ 0x30CC;
                        jv_13e0e = (jv_13e0e * 0x3) % 0x7FFFFFFF;
                      (void)jv_13e0e; }
                }
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
        if ((((opq_d5a9 * opq_d5a9 + opq_d5a9_b * opq_d5a9_b) % 4) == 3)) {
            { int jv_70d07 = opq_d5a9 ^ 0x38AB;
                jv_70d07 ^= (jv_70d07 << 3) | 0x27D6;
              (void)jv_70d07; }
        }
    }
    printf("%d %d\n", successes, failures);
    if ((((opq_d5a9 * opq_d5a9) % 4) == 2)) {
        { int jv_9b0a3 = opq_d5a9 ^ 0x1542;
            jv_9b0a3 ^= (jv_9b0a3 << 3) | 0x2FF0;
            jv_9b0a3 += (jv_9b0a3 >> 2) + 0xCE;
          (void)jv_9b0a3; }
    }
    return 0;
}
