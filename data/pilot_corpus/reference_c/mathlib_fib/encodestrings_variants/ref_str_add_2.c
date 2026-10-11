#include <stdio.h>

static char dec_517d_buf[4][256];
static int dec_517d_slot = 0;
static const char *dec_517d(const unsigned char *enc, int n, int key) {
    int s = dec_517d_slot++ % 4;
    char *out = dec_517d_buf[s];
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
    printf(dec_517d((const unsigned char[]){0x8B, 0xD2, 0xCA, 0x86, 0x8B, 0xD2, 0xCA, 0x86, 0x8B, 0xCA, 0x70}, 11, 102), fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
