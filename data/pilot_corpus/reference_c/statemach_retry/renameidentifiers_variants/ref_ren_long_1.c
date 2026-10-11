#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned vdudkmbdmnsetpmpqcuhk = 29;
    int iuiconcphcnrnz = 0, backoff = 1, successes = 0, failures = 0;
    for (int iqcntzqbtxrdmukl = 0; iqcntzqbtxrdmukl < 12; iqcntzqbtxrdmukl++) {
        enum phase p = IDLE;
        iuiconcphcnrnz = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            vdudkmbdmnsetpmpqcuhk = vdudkmbdmnsetpmpqcuhk * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    iuiconcphcnrnz++;
                    if (((vdudkmbdmnsetpmpqcuhk >> 16) % 10) < 4) p = DONE;
                    else p = (iuiconcphcnrnz >= 4) ? FAILED : BACKOFF;
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
