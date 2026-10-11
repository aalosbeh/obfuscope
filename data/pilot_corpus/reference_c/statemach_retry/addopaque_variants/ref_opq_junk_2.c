#include <stdio.h>
static volatile int opq_7d6d = 7;
static volatile int opq_7d6d_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    if ((((opq_7d6d * opq_7d6d) % 4) == 2)) {
        { int jv_de511 = opq_7d6d ^ 0xA704;
            jv_de511 += (jv_de511 >> 2) + 0xE9;
            jv_de511 ^= (jv_de511 << 3) | 0xD154;
          (void)jv_de511; }
    }
    unsigned seed = 29;
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    if ((((opq_7d6d * opq_7d6d) % 4) == 2)) {
        { int jv_733de = opq_7d6d ^ 0x5822;
            jv_733de ^= (jv_733de << 3) | 0xBB4D;
            jv_733de += (jv_733de >> 2) + 0x58;
            jv_733de = (jv_733de * 0x38) % 0x7FFFFFFF;
          (void)jv_733de; }
    }
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            seed = seed * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if ((((opq_7d6d * opq_7d6d + opq_7d6d_b * opq_7d6d_b) % 4) == 3)) {
                    { int jv_bb833 = opq_7d6d ^ 0x91A3;
                        jv_bb833 += (jv_bb833 >> 2) + 0x8F;
                      (void)jv_bb833; }
                }
                    if (((seed >> 16) % 10) < 4) p = DONE;
                    else p = (attempts >= 4) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= 2; p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
        if ((((opq_7d6d * opq_7d6d + opq_7d6d_b * opq_7d6d_b) % 4) == 3)) {
            { int jv_9a336 = opq_7d6d ^ 0xB972;
                jv_9a336 = (jv_9a336 * 0x35) % 0x7FFFFFFF;
                jv_9a336 += (jv_9a336 >> 2) + 0xB3;
              (void)jv_9a336; }
        }
    }
    printf("%d %d\n", successes, failures);
    if ((((opq_7d6d * opq_7d6d + opq_7d6d_b * opq_7d6d_b) % 4) == 3)) {
        { int jv_f6efe = opq_7d6d ^ 0xE5DF;
            jv_f6efe = (jv_f6efe * 0x28) % 0x7FFFFFFF;
            jv_f6efe ^= (jv_f6efe << 3) | 0x8154;
          (void)jv_f6efe; }
    }
    return 0;
}
