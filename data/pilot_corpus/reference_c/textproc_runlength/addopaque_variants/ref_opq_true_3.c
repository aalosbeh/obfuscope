#include <stdio.h>
static volatile int opq_36ce = 7;
static volatile int opq_36ce_b = 3;

int main(void) {
    if (((opq_36ce * opq_36ce - opq_36ce) % 2 == 0)) { opq_36ce_b ^= 0; }
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        if ((((opq_36ce * opq_36ce + opq_36ce) % 2) == 0)) { opq_36ce_b ^= 0; }
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if (((opq_36ce * opq_36ce - opq_36ce) % 2 == 0)) { opq_36ce_b ^= 0; }
    printf("%s %d\n", out, o);
    return 0;
}
