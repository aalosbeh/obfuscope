#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0xFB0 - 0xF93);
    int attempts = (0xE - 0xE), backoff = (0x815 - 0x814), successes = (0x543 - 0x543), failures = (0x448 - 0x448);
    for (int job = (0xDA0 - 0xDA0); job < (0x5D8 - 0x5CC); job++) {
        enum phase p = IDLE;
        attempts = (0x465 - 0x465); backoff = (0x721 - 0x720);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C653DFu - 0x572u) + (0x3C4Au - 0xC11u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x8C2 - 0x8B2)) % (0xFF3 - 0xFE9)) < (0xCD6 - 0xCD2)) p = DONE;
                    else p = (attempts >= (0xE37 - 0xE33)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0xAB9 - 0xAB7); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x236 - 0x236);
}
