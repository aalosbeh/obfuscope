#include <stdio.h>
static volatile int opq_12cd = 7;
static volatile int opq_12cd_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        if ((((opq_12cd * opq_12cd) % 4) == 2)) {
            { int jv_af657 = opq_12cd ^ 0x95B9;
                jv_af657 += (jv_af657 >> 2) + 0x2E;
              (void)jv_af657; }
        }
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if ((((opq_12cd * opq_12cd + opq_12cd_b * opq_12cd_b) % 4) == 3)) {
        { int jv_b819a = opq_12cd ^ 0xA009;
            jv_b819a = (jv_b819a * 0x23) % 0x7FFFFFFF;
            jv_b819a ^= (jv_b819a << 3) | 0x67A3;
          (void)jv_b819a; }
    }
    printf("%s %d\n", out, o);
    if ((((opq_12cd * opq_12cd) % 4) == 2)) {
        { int jv_46b61 = opq_12cd ^ 0x60BE;
            jv_46b61 ^= (jv_46b61 << 3) | 0x16B0;
            jv_46b61 = (jv_46b61 * 0x38) % 0x7FFFFFFF;
          (void)jv_46b61; }
    }
    return 0;
}
