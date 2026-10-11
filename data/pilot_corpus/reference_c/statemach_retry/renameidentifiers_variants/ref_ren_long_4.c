#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned ahscfsolhnblvoaxs = 29;
    int eqqqwonlukfmcmgsxnwwc = 0, backoff = 1, successes = 0, failures = 0;
    for (int nbawqjydlqwvwjfgg = 0; nbawqjydlqwvwjfgg < 12; nbawqjydlqwvwjfgg++) {
        enum phase p = IDLE;
        eqqqwonlukfmcmgsxnwwc = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            ahscfsolhnblvoaxs = ahscfsolhnblvoaxs * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    eqqqwonlukfmcmgsxnwwc++;
                    if (((ahscfsolhnblvoaxs >> 16) % 10) < 4) p = DONE;
                    else p = (eqqqwonlukfmcmgsxnwwc >= 4) ? FAILED : BACKOFF;
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
