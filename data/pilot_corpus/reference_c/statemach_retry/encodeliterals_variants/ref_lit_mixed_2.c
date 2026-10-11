#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0xA05 - 0x9E8);
    int attempts = (0x547B171E ^ 0x547B171E), backoff = (0xE1C - 0xE1B), successes = (0xF5C - 0xF5C), failures = (0x3FA2ED0C ^ 0x3FA2ED0C);
    for (int job = (0x7F2441CD ^ 0x7F2441CD); job < (0x99E - 0x992); job++) {
        enum phase p = IDLE;
        attempts = (0x7C0E4885 ^ 0x7C0E4885); backoff = (0x2AC - 0x2AB);
        while (p != DONE && p != FAILED) {
            seed = seed * (0xC625D5Eu ^ 0x4DA41333u) + (0x6C6CB7E0u ^ 0x6C6C87D9u);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0xEE7 - 0xED7)) % (0x6CFA92C9 ^ 0x6CFA92C3)) < (0x6DB38DD5 ^ 0x6DB38DD1)) p = DONE;
                    else p = (attempts >= (0x10F - 0x10B)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x76A1A55B ^ 0x76A1A559); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x56E - 0x56E);
}
