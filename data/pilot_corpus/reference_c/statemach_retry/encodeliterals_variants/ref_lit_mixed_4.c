#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x4A3 - 0x486);
    int attempts = (0x568 - 0x568), backoff = (0x45E8476 ^ 0x45E8477), successes = (0x40C - 0x40C), failures = (0x5C2B7E6B ^ 0x5C2B7E6B);
    for (int job = (0xC74 - 0xC74); job < (0x5399B2FD ^ 0x5399B2F1); job++) {
        enum phase p = IDLE;
        attempts = (0x6F8 - 0x6F8); backoff = (0x8E6 - 0x8E5);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x1EDB2CA9u ^ 0x5F1D62C4u) + (0x3610u - 0x5D7u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x19065FC2 ^ 0x19065FD2)) % (0xB1B - 0xB11)) < (0x31FF2AE2 ^ 0x31FF2AE6)) p = DONE;
                    else p = (attempts >= (0xBDE - 0xBDA)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x8F3 - 0x8F1); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x450 - 0x450);
}
