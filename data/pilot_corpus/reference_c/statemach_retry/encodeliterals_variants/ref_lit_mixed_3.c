#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0xD24 - 0xD07);
    int attempts = (0x421 - 0x421), backoff = (0x1E2 - 0x1E1), successes = (0x1047AC54 ^ 0x1047AC54), failures = (0xA5F - 0xA5F);
    for (int job = (0xB8D - 0xB8D); job < (0x7038E42C ^ 0x7038E420); job++) {
        enum phase p = IDLE;
        attempts = (0x263B9602 ^ 0x263B9602); backoff = (0x6A2 - 0x6A1);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C65186u - 0x319u) + (0x4D354DA9u ^ 0x4D357D90u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x2F1896A4 ^ 0x2F1896B4)) % (0x579 - 0x56F)) < (0x4320951F ^ 0x4320951B)) p = DONE;
                    else p = (attempts >= (0x5F - 0x5B)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x16AE8BB7 ^ 0x16AE8BB5); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x9D8 - 0x9D8);
}
