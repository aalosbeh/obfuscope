#include <stdio.h>
static volatile int opq_4b14 = 7;
static volatile int opq_4b14_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    if (((opq_4b14 * opq_4b14 - opq_4b14) % 2 == 0)) { opq_4b14_b ^= 0; }
    int o = 0, i = 0;
    while (in[i]) {
        if ((((opq_4b14 * (opq_4b14 + 1)) % 2) == 0)) { opq_4b14_b ^= 0; }
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if ((((opq_4b14 * opq_4b14 + opq_4b14) % 2) == 0)) { opq_4b14_b ^= 0; }
    printf("%s %d\n", out, o);
    return 0;
}
