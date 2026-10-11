#include <stdio.h>

static char dec_2ad4_buf[4][256];
static int dec_2ad4_slot = 0;
static const char *dec_2ad4(const unsigned char *enc, int n, int key) {
    int s = dec_2ad4_slot++ % 4;
    char *out = dec_2ad4_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] - key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static long memo[64];
static long fib(int n) {
    if (n < 2) return n;
    if (memo[n]) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
int main(void) {
    long iter_a = 0, iter_b = 1;
    for (int i = 0; i < 40; i++) { long t = iter_a + iter_b; iter_a = iter_b; iter_b = t; }
    printf(dec_2ad4((const unsigned char[]){0x9C, 0xE3, 0xDB, 0x97, 0x9C, 0xE3, 0xDB, 0x97, 0x9C, 0xDB, 0x81}, 11, 119), fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
