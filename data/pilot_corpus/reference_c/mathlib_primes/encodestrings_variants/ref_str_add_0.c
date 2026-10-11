#include <stdio.h>

static char dec_cdda_buf[4][256];
static int dec_cdda_slot = 0;
static const char *dec_cdda(const unsigned char *enc, int n, int key) {
    int s = dec_cdda_slot++ % 4;
    char *out = dec_cdda_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf(dec_cdda((const unsigned char[]){0x66, 0xA5, 0x61, 0x66, 0xA5, 0x4B}, 6, 65), count, last);
    return 0;
}
