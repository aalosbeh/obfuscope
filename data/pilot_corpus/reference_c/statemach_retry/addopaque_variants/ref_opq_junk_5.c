#include <stdio.h>
static volatile int opq_56dc = 7;
static volatile int opq_56dc_b = 3;

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            if ((((opq_56dc * opq_56dc + opq_56dc_b * opq_56dc_b) % 4) == 3)) {
                { int jv_d7bf1 = opq_56dc ^ 0x9E39;
                    jv_d7bf1 += (jv_d7bf1 >> 2) + 0x5B;
                  (void)jv_d7bf1; }
            }
            seed = seed * 1103515245u + 12345u;
            if ((((opq_56dc * opq_56dc) % 4) == 2)) {
                { int jv_f3cd8 = opq_56dc ^ 0x54CE;
                    jv_f3cd8 += (jv_f3cd8 >> 2) + 0x46;
                    jv_f3cd8 = (jv_f3cd8 * 0x32) % 0x7FFFFFFF;
                  (void)jv_f3cd8; }
            }
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                if ((((opq_56dc * opq_56dc + opq_56dc_b * opq_56dc_b) % 4) == 3)) {
                    { int jv_e285d = opq_56dc ^ 0xDBF4;
                        jv_e285d ^= (jv_e285d << 3) | 0x254;
                      (void)jv_e285d; }
                }
                    if (((seed >> 16) % 10) < 4) p = DONE;
                    else p = (attempts >= 4) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= 2; p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
        if ((((opq_56dc * opq_56dc + opq_56dc_b * opq_56dc_b) % 4) == 3)) {
            { int jv_d0e44 = opq_56dc ^ 0x2873;
                jv_d0e44 ^= (jv_d0e44 << 3) | 0x673B;
              (void)jv_d0e44; }
        }
    }
    printf("%d %d\n", successes, failures);
    if ((((opq_56dc * opq_56dc) % 4) == 2)) {
        { int jv_af32f = opq_56dc ^ 0x7E59;
            jv_af32f = (jv_af32f * 0x30) % 0x7FFFFFFF;
          (void)jv_af32f; }
    }
    return 0;
}
