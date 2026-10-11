#include <stdio.h>

static char dec_d3a4_buf[4][256];
static int dec_d3a4_slot = 0;
static const char *dec_d3a4(const unsigned char *enc, int n, int key) {
    int s = dec_d3a4_slot++ % 4;
    char *out = dec_d3a4_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

enum phase { IDLE, TRYING, BACKOFF, DONE, FAILED };
int main(void) {
    unsigned seed = 29;
    int attempts = 0, backoff = 1, successes = 0, failures = 0;
    for (int job = 0; job < 12; job++) {
        enum phase p = IDLE;
        attempts = 0; backoff = 1;
        while (p != DONE && p != FAILED) {
            seed = seed * 1103515245u + 12345u;
            switch (p) {
                case IDLE: p = TRYING; break;
                case TRYING:
                    attempts++;
                    if (((seed >> 16) % 10) < 4) p = DONE;
                    else p = (attempts >= 4) ? FAILED : BACKOFF;
                    break;
                case BACKOFF: backoff *= 2; p = TRYING; break;
                default: break;
            }
        }
        if (p == DONE) successes++; else failures++;
    }
    printf(dec_d3a4((const unsigned char[]){0x79, 0xB8, 0x74, 0x79, 0xB8, 0x5E}, 6, 84), successes, failures);
    return 0;
}
