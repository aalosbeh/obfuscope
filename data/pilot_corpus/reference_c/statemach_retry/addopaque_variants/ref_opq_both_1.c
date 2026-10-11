#include <stdio.h>
static volatile int opq_d13d = 7;
static volatile int opq_d13d_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    if ((((opq_d13d * opq_d13d + opq_d13d) % 2) == 0)) { opq_d13d_b ^= 0; }
    unsigned seed = 29;
    if ((((opq_d13d * opq_d13d) % 4) == 2)) {
        { int jv_59de9 = opq_d13d ^ 0xDC76;
            jv_59de9 = (jv_59de9 * 0x12) % 0x7FFFFFFF;
            jv_59de9 ^= (jv_59de9 << 3) | 0xA9C0;
            jv_59de9 += (jv_59de9 >> 2) + 0xD3;
          (void)jv_59de9; }
    }
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    if ((((opq_d13d * opq_d13d) % 4) == 2)) {
        { int jv_99f80 = opq_d13d ^ 0xB9AE;
            jv_99f80 += (jv_99f80 >> 2) + 0xEF;
            jv_99f80 = (jv_99f80 * 0x21) % 0x7FFFFFFF;
            jv_99f80 ^= (jv_99f80 << 3) | 0xCC0D;
          (void)jv_99f80; }
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
                if (((opq_d13d * opq_d13d - opq_d13d) % 2 == 0)) { opq_d13d_b ^= 0; }
                    if (((seed >> 16) % 10) < 4) p = DONE;
                    else p = (attempts >= 4) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= 2; p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
        if ((((opq_d13d * (opq_d13d + 1)) % 2) == 0)) { opq_d13d_b ^= 0; }
    }
    printf("%d %d\n", successes, failures);
    return 0;
}
