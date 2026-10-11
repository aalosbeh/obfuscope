#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x2CA - 0x2AD);
    int attempts = (0xB92 - 0xB92), backoff = (0x5B4 - 0x5B3), successes = (0x5D7 - 0x5D7), failures = (0x2F8 - 0x2F8);
    for (int job = (0xBA2 - 0xBA2); job < (0xBE3 - 0xBD7); job++) {
        enum phase p = IDLE;
        attempts = (0x5D2 - 0x5D2); backoff = (0xF0E - 0xF0D);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C657AAu - 0x93Du) + (0x3B06u - 0xACDu);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x138 - 0x128)) % (0x5FD - 0x5F3)) < (0x73B - 0x737)) p = DONE;
                    else p = (attempts >= (0xCC9 - 0xCC5)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0xA91 - 0xA8F); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x433 - 0x433);
}
