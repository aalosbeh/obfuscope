#include <stdio.h>
static volatile int opq_bda2 = 7;
static volatile int opq_bda2_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    if ((((opq_bda2 * (opq_bda2 + 1)) % 2) == 0)) { opq_bda2_b ^= 0; }
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        if (((opq_bda2 * opq_bda2 - opq_bda2) % 2 == 0)) { opq_bda2_b ^= 0; }
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if (((opq_bda2 * opq_bda2 - opq_bda2) % 2 == 0)) { opq_bda2_b ^= 0; }
    printf("%s %d\n", out, o);
    return 0;
}
