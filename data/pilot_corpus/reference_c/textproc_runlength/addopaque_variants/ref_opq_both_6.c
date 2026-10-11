#include <stdio.h>
static volatile int opq_3795 = 7;
static volatile int opq_3795_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    if ((((opq_3795 * (opq_3795 + 1)) % 2) == 0)) { opq_3795_b ^= 0; }
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        if ((((opq_3795 * opq_3795 + opq_3795_b * opq_3795_b) % 4) == 3)) {
            { int jv_8e3b1 = opq_3795 ^ 0xACB;
                jv_8e3b1 += (jv_8e3b1 >> 2) + 0xE1;
                jv_8e3b1 = (jv_8e3b1 * 0x2E) % 0x7FFFFFFF;
                jv_8e3b1 ^= (jv_8e3b1 << 3) | 0x2E55;
              (void)jv_8e3b1; }
        }
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if (((opq_3795 * opq_3795 - opq_3795) % 2 == 0)) { opq_3795_b ^= 0; }
    printf("%s %d\n", out, o);
    return 0;
}
