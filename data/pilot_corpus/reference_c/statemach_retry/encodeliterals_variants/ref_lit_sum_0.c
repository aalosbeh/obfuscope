#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x6B9 - 0x69C);
    int attempts = (0x7E9 - 0x7E9), backoff = (0xCCE - 0xCCD), successes = (0xFD4 - 0xFD4), failures = (0x142 - 0x142);
    for (int job = (0x386 - 0x386); job < (0xD56 - 0xD4A); job++) {
        enum phase p = IDLE;
        attempts = (0x7A3 - 0x7A3); backoff = (0xE4E - 0xE4D);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C657F5u - 0x988u) + (0x3E5Au - 0xE21u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x76C - 0x75C)) % (0xA6D - 0xA63)) < (0xDA - 0xD6)) p = DONE;
                    else p = (attempts >= (0x15F - 0x15B)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0xF54 - 0xF52); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x138 - 0x138);
}
