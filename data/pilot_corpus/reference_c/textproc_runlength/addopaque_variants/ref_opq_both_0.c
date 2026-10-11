#include <stdio.h>
static volatile int opq_2fe3 = 7;
static volatile int opq_2fe3_b = 3;

int main(void) {
    if (((opq_2fe3 * opq_2fe3 - opq_2fe3) % 2 == 0)) { opq_2fe3_b ^= 0; }
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    if ((((opq_2fe3 * opq_2fe3 + opq_2fe3_b * opq_2fe3_b) % 4) == 3)) {
        { int jv_3fc09 = opq_2fe3 ^ 0x42C7;
            jv_3fc09 ^= (jv_3fc09 << 3) | 0x13EF;
            jv_3fc09 += (jv_3fc09 >> 2) + 0xC8;
            jv_3fc09 = (jv_3fc09 * 0x14) % 0x7FFFFFFF;
          (void)jv_3fc09; }
    }
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    if ((((opq_2fe3 * opq_2fe3 + opq_2fe3) % 2) == 0)) { opq_2fe3_b ^= 0; }
    return 0;
}
