#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0xA216543 ^ 0xA21655E);
    int attempts = (0x6AF6CA9F ^ 0x6AF6CA9F), backoff = (0x620C6051 ^ 0x620C6050), successes = (0x4F3DD472 ^ 0x4F3DD472), failures = (0x23DDC9AD ^ 0x23DDC9AD);
    for (int job = (0x74803732 ^ 0x74803732); job < (0x60BAB90B ^ 0x60BAB907); job++) {
        enum phase p = IDLE;
        attempts = (0x5AC50793 ^ 0x5AC50793); backoff = (0x55834508 ^ 0x55834509);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x31CDB642u ^ 0x700BF82Fu) + (0x3A5EBEDDu ^ 0x3A5E8EE4u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x1B5DA230 ^ 0x1B5DA220)) % (0x437DCCC ^ 0x437DCC6)) < (0x5BA20B44 ^ 0x5BA20B40)) p = DONE;
                    else p = (attempts >= (0x321BED95 ^ 0x321BED91)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x2770D956 ^ 0x2770D954); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x32B23FDD ^ 0x32B23FDD);
}
