#include <stdio.h>
static volatile int opq_7611 = 7;
static volatile int opq_7611_b = 3;

int main(void) {
    if ((((opq_7611 * (opq_7611 + 1)) % 2) == 0)) { opq_7611_b ^= 0; }
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        if ((((opq_7611 * (opq_7611 + 1)) % 2) == 0)) { opq_7611_b ^= 0; }
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    if (((opq_7611 * opq_7611 - opq_7611) % 2 == 0)) { opq_7611_b ^= 0; }
    return 0;
}
