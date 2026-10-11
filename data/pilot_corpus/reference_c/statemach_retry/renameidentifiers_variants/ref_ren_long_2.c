#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned bortpqjqyogfljej = 29;
    int fiwxndqotdyldtcox = 0, backoff = 1, successes = 0, failures = 0;
    for (int tbgpspigblvqnukvo = 0; tbgpspigblvqnukvo < 12; tbgpspigblvqnukvo++) {
        enum phase p = IDLE;
        fiwxndqotdyldtcox = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            bortpqjqyogfljej = bortpqjqyogfljej * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    fiwxndqotdyldtcox++;
                    if (((bortpqjqyogfljej >> 16) % 10) < 4) p = DONE;
                    else p = (fiwxndqotdyldtcox >= 4) ? FAILED : BACKOFF;
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
