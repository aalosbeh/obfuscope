#include <stdio.h>

static char dec_95f5_buf[4][256];
static int dec_95f5_slot = 0;
static const char *dec_95f5(const unsigned char *enc, int n, int key) {
    int s = dec_95f5_slot++ % 4;
    char *out = dec_95f5_buf[s];
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
    printf(dec_95f5((const unsigned char[]){0x80, 0xBF, 0x7B, 0x80, 0xBF, 0x65}, 6, 91), count, last);
    return 0;
}
