#include <stdio.h>
static volatile int opq_638a = 7;
static volatile int opq_638a_b = 3;

int main(void) {
    if (((opq_638a * opq_638a - opq_638a) % 2 == 0)) { opq_638a_b ^= 0; }
    const char *in = "aaabbbbccddddddeffffg";
    if ((((opq_638a * (opq_638a + 1)) % 2) == 0)) { opq_638a_b ^= 0; }
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        if ((((opq_638a * (opq_638a + 1)) % 2) == 0)) { opq_638a_b ^= 0; }
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return 0;
}
