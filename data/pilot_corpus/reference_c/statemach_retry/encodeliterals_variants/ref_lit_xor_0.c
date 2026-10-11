#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x65F8576F ^ 0x65F85772);
    int attempts = (0x2EA57D02 ^ 0x2EA57D02), backoff = (0x358DEECA ^ 0x358DEECB), successes = (0x12E3A594 ^ 0x12E3A594), failures = (0x18A6E266 ^ 0x18A6E266);
    for (int job = (0x6988B56B ^ 0x6988B56B); job < (0x6B924BCA ^ 0x6B924BC6); job++) {
        enum phase p = IDLE;
        attempts = (0x20C368A8 ^ 0x20C368A8); backoff = (0x4638ED68 ^ 0x4638ED69);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x1C1D34D1u ^ 0x5DDB7ABCu) + (0x3337657Bu ^ 0x33375542u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x6AB6AF99 ^ 0x6AB6AF89)) % (0x5C13DCE ^ 0x5C13DC4)) < (0x726C3A17 ^ 0x726C3A13)) p = DONE;
                    else p = (attempts >= (0x1181DA28 ^ 0x1181DA2C)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x387ADE55 ^ 0x387ADE57); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x1A4AB674 ^ 0x1A4AB674);
}
