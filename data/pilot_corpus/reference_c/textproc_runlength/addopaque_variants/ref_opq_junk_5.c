#include <stdio.h>
static volatile int opq_aa49 = 7;
static volatile int opq_aa49_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    if ((((opq_aa49 * opq_aa49) % 4) == 2)) {
        { int jv_6b488 = opq_aa49 ^ 0x4C8A;
            jv_6b488 ^= (jv_6b488 << 3) | 0xD770;
            jv_6b488 = (jv_6b488 * 0x7) % 0x7FFFFFFF;
            jv_6b488 += (jv_6b488 >> 2) + 0x7B;
          (void)jv_6b488; }
    }
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if ((((opq_aa49 * opq_aa49 + opq_aa49_b * opq_aa49_b) % 4) == 3)) {
        { int jv_72567 = opq_aa49 ^ 0x207F;
            jv_72567 ^= (jv_72567 << 3) | 0xCD0C;
            jv_72567 += (jv_72567 >> 2) + 0x21;
          (void)jv_72567; }
    }
    printf("%s %d\n", out, o);
    if ((((opq_aa49 * opq_aa49) % 4) == 2)) {
        { int jv_afb23 = opq_aa49 ^ 0xAA8D;
            jv_afb23 = (jv_afb23 * 0x32) % 0x7FFFFFFF;
          (void)jv_afb23; }
    }
    return 0;
}
