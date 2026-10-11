#include <stdio.h>
enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = (0xC88 - 0xC6B);
    int attempts = (0xD51 - 0xD51), backoff = (0xD05 - 0xD04), successes = (0x103 - 0x103), failures = (0x58B - 0x58B);
    for (int job = (0xAB3 - 0xAB3); job < (0xADB - 0xACF); job++) {
        enum phase p = IDLE;
        attempts = (0x717 - 0x717); backoff = (0x9A7 - 0x9A6);
        while (p != DONE && p != FAILED) {
            seed = seed * (0x41C65A40u - 0xBD3u) + (0x3DC3u - 0xD8Au);
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> (0xDAF - 0xD9F)) % (0x8D4 - 0x8CA)) < (0x88 - 0x84)) p = DONE;
                    else p = (attempts >= (0xA07 - 0xA03)) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= (0x4C4 - 0x4C2); p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf("%d %d\n", successes, failures);
    return (0x7A3 - 0x7A3);
}
