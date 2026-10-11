#include <stdio.h>
static volatile int opq_3d66 = 7;
static volatile int opq_3d66_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    if (((opq_3d66 * opq_3d66 - opq_3d66) % 2 == 0)) { opq_3d66_b ^= 0; }
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        if ((((opq_3d66 * opq_3d66 + opq_3d66) % 2) == 0)) { opq_3d66_b ^= 0; }
        char c = in[i];
        if ((((opq_3d66 * opq_3d66 + opq_3d66) % 2) == 0)) { opq_3d66_b ^= 0; }
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return 0;
}
