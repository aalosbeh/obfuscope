#include <stdio.h>
static volatile int opq_fb2b = 7;
static volatile int opq_fb2b_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        if ((((opq_fb2b * opq_fb2b + opq_fb2b_b * opq_fb2b_b) % 4) == 3)) {
            { int jv_db812 = opq_fb2b ^ 0xA707;
                jv_db812 ^= (jv_db812 << 3) | 0x1909;
              (void)jv_db812; }
        }
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            if ((((opq_fb2b * opq_fb2b) % 4) == 2)) {
                { int jv_3602c = opq_fb2b ^ 0xEF26;
                    jv_3602c ^= (jv_3602c << 3) | 0xA93A;
                  (void)jv_3602c; }
            }
            seed = seed * 1103515245u + 12345u;
            if (((opq_fb2b * opq_fb2b - opq_fb2b) % 2 == 0)) { opq_fb2b_b ^= 0; }
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if ((((opq_fb2b * opq_fb2b + opq_fb2b_b * opq_fb2b_b) % 4) == 3)) {
                    { int jv_c013e = opq_fb2b ^ 0xDF5;
                        jv_c013e = (jv_c013e * 0x9) % 0x7FFFFFFF;
                        jv_c013e ^= (jv_c013e << 3) | 0x17CF;
                      (void)jv_c013e; }
                }
                    if (((seed >> 16) % 10) < 4) p = DONE;
                    else p = (attempts >= 4) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= 2; p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
        if ((((opq_fb2b * (opq_fb2b + 1)) % 2) == 0)) { opq_fb2b_b ^= 0; }
    }
    printf("%d %d\n", successes, failures);
    return 0;
}
