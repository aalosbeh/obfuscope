#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0x52C9A4E8 ^ 0x52C9A4F5);
    int attempts = (0x6B931D04 ^ 0x6B931D04), backoff = (0x425739CE ^ 0x425739CF), successes = (0x299E7FB6 ^ 0x299E7FB6), failures = (0x5A42C6EB ^ 0x5A42C6EB);
    for (int job = (0x3FDAC64C ^ 0x3FDAC64C); job < (0x1B101058 ^ 0x1B101054); job++) {
        enum phase p = IDLE;
        attempts = (0x4E809199 ^ 0x4E809199); backoff = (0x7E3B608A ^ 0x7E3B608B);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x7A706C25u ^ 0x3BB62248u) + (0x38CF6F5Fu ^ 0x38CF5F66u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0x5538ECF6 ^ 0x5538ECE6)) % (0x644F76D4 ^ 0x644F76DE)) < (0x79CCF9DC ^ 0x79CCF9D8)) p = DONE;
                    else p = (attempts >= (0x2445EAB6 ^ 0x2445EAB2)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x550219FB ^ 0x550219F9); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x38E600B7 ^ 0x38E600B7);
}
