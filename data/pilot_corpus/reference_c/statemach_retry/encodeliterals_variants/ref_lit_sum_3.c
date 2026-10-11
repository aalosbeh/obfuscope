#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0xC2F - 0xC12);
    int attempts = (0xE3E - 0xE3E), backoff = (0x368 - 0x367), successes = (0xF44 - 0xF44), failures = (0x38F - 0x38F);
    for (int job = (0x2BD - 0x2BD); job < (0x4FB - 0x4EF); job++) {
        enum phase p = IDLE;
        attempts = (0x33F - 0x33F); backoff = (0x94F - 0x94E);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C65800u - 0x993u) + (0x3657u - 0x61Eu);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0xD51 - 0xD41)) % (0x97B - 0x971)) < (0x692 - 0x68E)) p = DONE;
                    else p = (attempts >= (0x728 - 0x724)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x7F3 - 0x7F1); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x49 - 0x49);
}
