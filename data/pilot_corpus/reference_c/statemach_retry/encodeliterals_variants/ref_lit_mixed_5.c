#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x606C3045 ^ 0x606C3058);
    int attempts = (0x777F09B6 ^ 0x777F09B6), backoff = (0x208 - 0x207), successes = (0x4B848A07 ^ 0x4B848A07), failures = (0x94F - 0x94F);
    for (int job = (0x6BB776AD ^ 0x6BB776AD); job < (0xEFD - 0xEF1); job++) {
        enum phase p = IDLE;
        attempts = (0xBE8 - 0xBE8); backoff = (0x6A4 - 0x6A3);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C65084u - 0x217u) + (0x3E18u - 0xDDFu);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0xA48 - 0xA38)) % (0x2973C2EC ^ 0x2973C2E6)) < (0x41EBF8B1 ^ 0x41EBF8B5)) p = DONE;
                    else p = (attempts >= (0x55D - 0x559)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x2EC - 0x2EA); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x917 - 0x917);
}
