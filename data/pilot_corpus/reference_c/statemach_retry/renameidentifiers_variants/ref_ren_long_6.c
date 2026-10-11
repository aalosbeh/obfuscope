#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned iubyphtbbagpyxxjiawjvp = 29;
    int frfnmidjrxcnyv = 0, backoff = 1, successes = 0, failures = 0;
    for (int nwgcgmntfknpoaqlbuca = 0; nwgcgmntfknpoaqlbuca < 12; nwgcgmntfknpoaqlbuca++) {
        enum phase p = IDLE;
        frfnmidjrxcnyv = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            iubyphtbbagpyxxjiawjvp = iubyphtbbagpyxxjiawjvp * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    frfnmidjrxcnyv++;
                    if (((iubyphtbbagpyxxjiawjvp >> 16) % 10) < 4) p = DONE;
                    else p = (frfnmidjrxcnyv >= 4) ? FAILED : BACKOFF;
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
