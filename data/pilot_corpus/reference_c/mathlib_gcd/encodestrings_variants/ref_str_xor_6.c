#include <stdio.h>

static char dec_e792_buf[4][256];
static int dec_e792_slot = 0;
static const char *dec_e792(const unsigned char *enc, int n, int key) {
    int s = dec_e792_slot++ % 4;
    char *out = dec_e792_buf[s];
    for (int i = 0; i < n && i < 255; i++) out[i] = (char)(enc[i] ^ key);
    out[n < 255 ? n : 255] = '\0';
    return out;
}

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = 0;
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    printf(dec_e792((const unsigned char[]){0xC8, 0x81, 0x89, 0xE7}, 4, 237), acc);
    return 0;
}
