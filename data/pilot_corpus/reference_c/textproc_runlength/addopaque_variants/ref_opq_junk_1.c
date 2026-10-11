#include <stdio.h>
static volatile int opq_990a = 7;
static volatile int opq_990a_b = 3;

int main(void) {
    if ((((opq_990a * opq_990a) % 4) == 2)) {
        { int jv_2b90a = opq_990a ^ 0x86E8;
            jv_2b90a = (jv_2b90a * 0x21) % 0x7FFFFFFF;
            jv_2b90a += (jv_2b90a >> 2) + 0x30;
            jv_2b90a ^= (jv_2b90a << 3) | 0x7E4A;
          (void)jv_2b90a; }
    }
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    if ((((opq_990a * opq_990a) % 4) == 2)) {
        { int jv_3f1d4 = opq_990a ^ 0xBA3;
            jv_3f1d4 ^= (jv_3f1d4 << 3) | 0x6F66;
            jv_3f1d4 += (jv_3f1d4 >> 2) + 0xCE;
          (void)jv_3f1d4; }
    }
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if ((((opq_990a * opq_990a) % 4) == 2)) {
        { int jv_3e00c = opq_990a ^ 0xB9EB;
            jv_3e00c += (jv_3e00c >> 2) + 0x99;
            jv_3e00c ^= (jv_3e00c << 3) | 0xFAB3;
            jv_3e00c = (jv_3e00c * 0x1C) % 0x7FFFFFFF;
          (void)jv_3e00c; }
    }
    printf("%s %d\n", out, o);
    return 0;
}
