#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x54F4C399 ^ 0x54F4C384);
    int attempts = (0x29F7E919 ^ 0x29F7E919), backoff = (0x2A2CDA79 ^ 0x2A2CDA78), successes = (0x6F6F03A2 ^ 0x6F6F03A2), failures = (0x6883AD12 ^ 0x6883AD12);
    for (int job = (0x347F2CD7 ^ 0x347F2CD7); job < (0x222FE5E2 ^ 0x222FE5EE); job++) {
        enum phase p = IDLE;
        attempts = (0x4D459FF8 ^ 0x4D459FF8); backoff = (0x77B0DBD3 ^ 0x77B0DBD2);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x30176CBCu ^ 0x71D122D1u) + (0x60E78802u ^ 0x60E7B83Bu);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x5C5C26F8 ^ 0x5C5C26E8)) % (0x5676384A ^ 0x56763840)) < (0x66E7EC44 ^ 0x66E7EC40)) p = DONE;
                    else p = (attempts >= (0x5A8E742E ^ 0x5A8E742A)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x2F7C2D41 ^ 0x2F7C2D43); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x50361B2C ^ 0x50361B2C);
}
