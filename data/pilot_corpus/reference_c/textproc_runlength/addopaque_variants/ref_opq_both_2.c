#include <stdio.h>
static volatile int opq_f4aa = 7;
static volatile int opq_f4aa_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    if (((opq_f4aa * opq_f4aa - opq_f4aa) % 2 == 0)) { opq_f4aa_b ^= 0; }
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        if ((((opq_f4aa * (opq_f4aa + 1)) % 2) == 0)) { opq_f4aa_b ^= 0; }
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    if ((((opq_f4aa * opq_f4aa) % 4) == 2)) {
        { int jv_3948f = opq_f4aa ^ 0x8D11;
            jv_3948f ^= (jv_3948f << 3) | 0xE07A;
            jv_3948f += (jv_3948f >> 2) + 0xCF;
            jv_3948f = (jv_3948f * 0x17) % 0x7FFFFFFF;
          (void)jv_3948f; }
    }
    return 0;
}
