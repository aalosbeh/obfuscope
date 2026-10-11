#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x7E4E2F88 ^ 0x7E4E2F95);
    int attempts = (0x7BE1D4AB ^ 0x7BE1D4AB), backoff = (0x16FA60A6 ^ 0x16FA60A7), successes = (0x3432A814 ^ 0x3432A814), failures = (0x4B00AE80 ^ 0x4B00AE80);
    for (int job = (0x275474B5 ^ 0x275474B5); job < (0x299888EB ^ 0x299888E7); job++) {
        enum phase p = IDLE;
        attempts = (0x9D5970B ^ 0x9D5970B); backoff = (0x70D18A61 ^ 0x70D18A60);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x3AE691DDu ^ 0x7B20DFB0u) + (0x7F95F3BFu ^ 0x7F95C386u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x211665E5 ^ 0x211665F5)) % (0x6703C925 ^ 0x6703C92F)) < (0x3049F188 ^ 0x3049F18C)) p = DONE;
                    else p = (attempts >= (0x146A853A ^ 0x146A853E)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x7E4E2095 ^ 0x7E4E2097); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x3312BF72 ^ 0x3312BF72);
}
