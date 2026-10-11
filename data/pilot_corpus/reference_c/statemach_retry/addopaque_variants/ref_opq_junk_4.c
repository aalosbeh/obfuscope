#include <stdio.h>
static volatile int opq_66c2 = 7;
static volatile int opq_66c2_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    if ((((opq_66c2 * opq_66c2 + opq_66c2_b * opq_66c2_b) % 4) == 3)) {
        { int jv_c1407 = opq_66c2 ^ 0x2581;
            jv_c1407 = (jv_c1407 * 0x37) % 0x7FFFFFFF;
            jv_c1407 += (jv_c1407 >> 2) + 0x90;
          (void)jv_c1407; }
    }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        if ((((opq_66c2 * opq_66c2) % 4) == 2)) {
            { int jv_da47e = opq_66c2 ^ 0x7B5F;
                jv_da47e += (jv_da47e >> 2) + 0xBB;
                jv_da47e ^= (jv_da47e << 3) | 0x4014;
              (void)jv_da47e; }
        }
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            seed = seed * 1103515245u + 12345u;
            if ((((opq_66c2 * opq_66c2) % 4) == 2)) {
                { int jv_9abda = opq_66c2 ^ 0x8914;
                    jv_9abda ^= (jv_9abda << 3) | 0xB787;
                    jv_9abda = (jv_9abda * 0x1A) % 0x7FFFFFFF;
                  (void)jv_9abda; }
            }
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if ((((opq_66c2 * opq_66c2) % 4) == 2)) {
                    { int jv_d7ae0 = opq_66c2 ^ 0x9F2F;
                        jv_d7ae0 = (jv_d7ae0 * 0x2A) % 0x7FFFFFFF;
                      (void)jv_d7ae0; }
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
    if ((((opq_66c2 * opq_66c2 + opq_66c2_b * opq_66c2_b) % 4) == 3)) {
        { int jv_85de3 = opq_66c2 ^ 0xE82;
            jv_85de3 ^= (jv_85de3 << 3) | 0x5391;
          (void)jv_85de3; }
    }
    return 0;
}
