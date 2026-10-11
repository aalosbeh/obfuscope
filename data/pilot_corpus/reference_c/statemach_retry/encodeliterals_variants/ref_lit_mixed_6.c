#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x7C2FE5E5 ^ 0x7C2FE5F8);
    int attempts = (0x41C71721 ^ 0x41C71721), backoff = (0xD4E - 0xD4D), successes = (0x39C2BA56 ^ 0x39C2BA56), failures = (0x656 - 0x656);
    for (int job = (0x49BA2692 ^ 0x49BA2692); job < (0x7C6 - 0x7BA); job++) {
        enum phase p = IDLE;
        attempts = (0x2D5 - 0x2D5); backoff = (0x4AF - 0x4AE);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C65593u - 0x726u) + (0x5525BE29u ^ 0x55258E10u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0xF6A - 0xF5A)) % (0xB84 - 0xB7A)) < (0x1796502 ^ 0x1796506)) p = DONE;
                    else p = (attempts >= (0x20EF4DE9 ^ 0x20EF4DED)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x892 - 0x890); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0xC03 - 0xC03);
}
