#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x2EE - 0x2D1);
    int attempts = (0x262 - 0x262), backoff = (0x1F8 - 0x1F7), successes = (0xA45 - 0xA45), failures = (0x94C - 0x94C);
    for (int job = (0x7C4 - 0x7C4); job < (0x17C - 0x170); job++) {
        enum phase p = IDLE;
        attempts = (0xFBE - 0xFBE); backoff = (0x209 - 0x208);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C65A90u - 0xC23u) + (0x3197u - 0x15Eu);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x7FA - 0x7EA)) % (0x753 - 0x749)) < (0x553 - 0x54F)) p = DONE;
                    else p = (attempts >= (0x372 - 0x36E)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0xBC - 0xBA); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x8C3 - 0x8C3);
}
