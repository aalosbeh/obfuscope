#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x308 - 0x2EB);
    int attempts = (0x872 - 0x872), backoff = (0xB61 - 0xB60), successes = (0x590 - 0x590), failures = (0x461 - 0x461);
    for (int job = (0xC8E - 0xC8E); job < (0x300 - 0x2F4); job++) {
        enum phase p = IDLE;
        attempts = (0xE6 - 0xE6); backoff = (0x923 - 0x922);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C659FFu - 0xB92u) + (0x38B7u - 0x87Eu);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0xA33 - 0xA23)) % (0xE9C - 0xE92)) < (0x64 - 0x60)) p = DONE;
                    else p = (attempts >= (0x6BE - 0x6BA)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0xEC2 - 0xEC0); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x5E6 - 0x5E6);
}
