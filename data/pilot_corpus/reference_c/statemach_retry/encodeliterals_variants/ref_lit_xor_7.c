#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x22D3152E ^ 0x22D31533);
    int attempts = (0x588D4D61 ^ 0x588D4D61), backoff = (0x231E3CFA ^ 0x231E3CFB), successes = (0x54461268 ^ 0x54461268), failures = (0x618E8B24 ^ 0x618E8B24);
    for (int job = (0x17BDE270 ^ 0x17BDE270); job < (0xD46617A ^ 0xD466176); job++) {
        enum phase p = IDLE;
        attempts = (0x641552E1 ^ 0x641552E1); backoff = (0x7ADBCF6F ^ 0x7ADBCF6E);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41ADAF4Eu ^ 0x6BE123u) + (0x5071DDB9u ^ 0x5071ED80u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x1F779E7E ^ 0x1F779E6E)) % (0x1B533ABE ^ 0x1B533AB4)) < (0x2680883D ^ 0x26808839)) p = DONE;
                    else p = (attempts >= (0x6A2A836E ^ 0x6A2A836A)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x4A312DD4 ^ 0x4A312DD6); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0xC2D96F3 ^ 0xC2D96F3);
}
