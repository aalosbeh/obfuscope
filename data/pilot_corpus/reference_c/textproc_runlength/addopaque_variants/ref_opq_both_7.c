#include <stdio.h>
static volatile int opq_8479 = 7;
static volatile int opq_8479_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    if ((((opq_8479 * opq_8479) % 4) == 2)) {
        { int jv_c82c2 = opq_8479 ^ 0x9C57;
            jv_c82c2 ^= (jv_c82c2 << 3) | 0x9FDF;
            jv_c82c2 += (jv_c82c2 >> 2) + 0x17;
            jv_c82c2 = (jv_c82c2 * 0x31) % 0x7FFFFFFF;
          (void)jv_c82c2; }
    }
    char out[64];
    if ((((opq_8479 * opq_8479 + opq_8479) % 2) == 0)) { opq_8479_b ^= 0; }
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        if ((((opq_8479 * opq_8479) % 4) == 2)) {
            { int jv_2ce1d = opq_8479 ^ 0xC42A;
                jv_2ce1d = (jv_2ce1d * 0x16) % 0x7FFFFFFF;
                jv_2ce1d ^= (jv_2ce1d << 3) | 0x2A2B;
                jv_2ce1d += (jv_2ce1d >> 2) + 0x6C;
              (void)jv_2ce1d; }
        }
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return 0;
}
