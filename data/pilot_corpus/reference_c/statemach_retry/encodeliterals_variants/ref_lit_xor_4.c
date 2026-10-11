#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x33CB8F27 ^ 0x33CB8F3A);
    int attempts = (0x2AEA9D4 ^ 0x2AEA9D4), backoff = (0x6EA1A256 ^ 0x6EA1A257), successes = (0x296BEB86 ^ 0x296BEB86), failures = (0x6CB58813 ^ 0x6CB58813);
    for (int job = (0x4356F2AB ^ 0x4356F2AB); job < (0x68394246 ^ 0x6839424A); job++) {
        enum phase p = IDLE;
        attempts = (0x6214F461 ^ 0x6214F461); backoff = (0x1FB1D1B6 ^ 0x1FB1D1B7);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x62106D29u ^ 0x23D62344u) + (0x130280EDu ^ 0x1302B0D4u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x3B6131F6 ^ 0x3B6131E6)) % (0x1FCB952E ^ 0x1FCB9524)) < (0x5143F37 ^ 0x5143F33)) p = DONE;
                    else p = (attempts >= (0x57EFBF59 ^ 0x57EFBF5D)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x5DF6161 ^ 0x5DF6163); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x56714932 ^ 0x56714932);
}
