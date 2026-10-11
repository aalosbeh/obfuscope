#include <stdio.h>
static volatile int opq_d1f3 = 7;
static volatile int opq_d1f3_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        if ((((opq_d1f3 * opq_d1f3 + opq_d1f3) % 2) == 0)) { opq_d1f3_b ^= 0; }
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if ((((opq_d1f3 * opq_d1f3 + opq_d1f3) % 2) == 0)) { opq_d1f3_b ^= 0; }
    printf("%s %d\n", out, o);
    if (((opq_d1f3 * opq_d1f3 - opq_d1f3) % 2 == 0)) { opq_d1f3_b ^= 0; }
    return 0;
}
