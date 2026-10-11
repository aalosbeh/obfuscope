#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x55D - 0x540);
    int attempts = (0x1FD - 0x1FD), backoff = (0x42C - 0x42B), successes = (0x6D205922 ^ 0x6D205922), failures = (0x1F1 - 0x1F1);
    for (int job = (0x429EE0C2 ^ 0x429EE0C2); job < (0x3DF - 0x3D3); job++) {
        enum phase p = IDLE;
        attempts = (0xE14 - 0xE14); backoff = (0x424D4BA0 ^ 0x424D4BA1);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x315FC1E5u ^ 0x70998F88u) + (0x35AEu - 0x575u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x13203DE0 ^ 0x13203DF0)) % (0x6359AF6D ^ 0x6359AF67)) < (0x407A97A6 ^ 0x407A97A2)) p = DONE;
                    else p = (attempts >= (0x2D64B410 ^ 0x2D64B414)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x77A56DAC ^ 0x77A56DAE); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x74ED4DB2 ^ 0x74ED4DB2);
}
