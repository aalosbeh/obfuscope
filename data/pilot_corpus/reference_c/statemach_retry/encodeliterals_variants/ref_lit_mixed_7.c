#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x4B1E8D29 ^ 0x4B1E8D34);
    int attempts = (0x23AE2AE7 ^ 0x23AE2AE7), backoff = (0x3F1DB12D ^ 0x3F1DB12C), successes = (0x87B - 0x87B), failures = (0x1A469BFB ^ 0x1A469BFB);
    for (int job = (0x2DA19717 ^ 0x2DA19717); job < (0x5C6E66A8 ^ 0x5C6E66A4); job++) {
        enum phase p = IDLE;
        attempts = (0x882 - 0x882); backoff = (0x548EA33A ^ 0x548EA33B);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x134CA59Bu ^ 0x528AEBF6u) + (0x21E8397Eu ^ 0x21E80947u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x3C7C1503 ^ 0x3C7C1513)) % (0x23A - 0x230)) < (0x7749337E ^ 0x7749337A)) p = DONE;
                    else p = (attempts >= (0xE70 - 0xE6C)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x28B - 0x289); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x2A1 - 0x2A1);
}
