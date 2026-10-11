#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x894 - 0x877);
    int attempts = (0x7A5 - 0x7A5), backoff = (0xAA4 - 0xAA3), successes = (0x3A - 0x3A), failures = (0x11B - 0x11B);
    for (int job = (0x1DC - 0x1DC); job < (0x9C - 0x90); job++) {
        enum phase p = IDLE;
        attempts = (0xFD0 - 0xFD0); backoff = (0x3DD - 0x3DC);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C65D2Du - 0xEC0u) + (0x3FB6u - 0xF7Du);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0xA3D - 0xA2D)) % (0x83C - 0x832)) < (0x4CB - 0x4C7)) p = DONE;
                    else p = (attempts >= (0x5E0 - 0x5DC)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0xB3 - 0xB1); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x12C - 0x12C);
}
