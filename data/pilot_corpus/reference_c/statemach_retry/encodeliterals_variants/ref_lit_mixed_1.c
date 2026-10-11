#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x5E98CEB4 ^ 0x5E98CEA9);
    int attempts = (0x18500E0B ^ 0x18500E0B), backoff = (0x72D7A330 ^ 0x72D7A331), successes = (0x55C32AD ^ 0x55C32AD), failures = (0x424F082D ^ 0x424F082D);
    for (int job = (0x51C0B72F ^ 0x51C0B72F); job < (0xAAB - 0xA9F); job++) {
        enum phase p = IDLE;
        attempts = (0x4B9DB1B7 ^ 0x4B9DB1B7); backoff = (0x3C0 - 0x3BF);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x245D5B27u ^ 0x659B154Au) + (0x3BC5u - 0xB8Cu);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x6B - 0x5B)) % (0x63FE831E ^ 0x63FE8314)) < (0x669C0342 ^ 0x669C0346)) p = DONE;
                    else p = (attempts >= (0x9F - 0x9B)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x5B - 0x59); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x4AEFCD07 ^ 0x4AEFCD07);
}
