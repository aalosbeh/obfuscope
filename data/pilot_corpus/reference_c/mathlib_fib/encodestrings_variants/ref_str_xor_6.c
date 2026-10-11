#include <stdio.h>

static char dec_ac70_buf[4][256];
static int dec_ac70_slot = 0;
static const char *dec_ac70(const unsigned char *enc, int n, int key) {
    int s = dec_ac70_slot++ % 4;
    char *out = dec_ac70_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
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
    printf(dec_ac70((const unsigned char[]){0xCF, 0x86, 0x8E, 0xCA, 0xCF, 0x86, 0x8E, 0xCA, 0xCF, 0x8E, 0xE0}, 11, 234), fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
