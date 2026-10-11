#include <stdio.h>

static char dec_807c_buf[4][256];
static int dec_807c_slot = 0;
static const char *dec_807c(const unsigned char *enc, int n, int key) {
    int s = dec_807c_slot++ % 4;
    char *out = dec_807c_buf[s];
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
    printf(dec_807c((const unsigned char[]){0x09, 0x50, 0x48, 0x04, 0x09, 0x50, 0x48, 0x04, 0x09, 0x48, 0xEE}, 11, 228), fib(40), iter_a, fib(40) == iter_a);
    return 0;
}
