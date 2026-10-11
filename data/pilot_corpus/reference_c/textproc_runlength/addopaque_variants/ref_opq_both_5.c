#include <stdio.h>
static volatile int opq_c169 = 7;
static volatile int opq_c169_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    if ((((opq_c169 * opq_c169 + opq_c169) % 2) == 0)) { opq_c169_b ^= 0; }
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if (((opq_c169 * opq_c169 - opq_c169) % 2 == 0)) { opq_c169_b ^= 0; }
    printf("%s %d\n", out, o);
    if ((((opq_c169 * opq_c169) % 4) == 2)) {
        { int jv_fe436 = opq_c169 ^ 0x9B8A;
            jv_fe436 = (jv_fe436 * 0x28) % 0x7FFFFFFF;
            jv_fe436 += (jv_fe436 >> 2) + 0x14;
          (void)jv_fe436; }
    }
    return 0;
}
