#include <stdio.h>
static volatile int opq_7ecf = 7;
static volatile int opq_7ecf_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    if ((((opq_7ecf * opq_7ecf) % 4) == 2)) {
        { int jv_6f927 = opq_7ecf ^ 0x9349;
            jv_6f927 ^= (jv_6f927 << 3) | 0xBD46;
          (void)jv_6f927; }
    }
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        if ((((opq_7ecf * opq_7ecf + opq_7ecf_b * opq_7ecf_b) % 4) == 3)) {
            { int jv_b55d2 = opq_7ecf ^ 0x7318;
                jv_b55d2 = (jv_b55d2 * 0x4) % 0x7FFFFFFF;
                jv_b55d2 += (jv_b55d2 >> 2) + 0x6A;
              (void)jv_b55d2; }
        }
        char c = in[i];
        if ((((opq_7ecf * opq_7ecf + opq_7ecf_b * opq_7ecf_b) % 4) == 3)) {
            { int jv_1a5f4 = opq_7ecf ^ 0x7180;
                jv_1a5f4 ^= (jv_1a5f4 << 3) | 0x7F71;
              (void)jv_1a5f4; }
        }
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return 0;
}
