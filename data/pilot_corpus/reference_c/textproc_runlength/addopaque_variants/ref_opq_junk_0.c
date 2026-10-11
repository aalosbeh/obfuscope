#include <stdio.h>
static volatile int opq_201b = 7;
static volatile int opq_201b_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    if ((((opq_201b * opq_201b) % 4) == 2)) {
        { int jv_bc85f = opq_201b ^ 0x76D4;
            jv_bc85f += (jv_bc85f >> 2) + 0xFC;
            jv_bc85f = (jv_bc85f * 0x3) % 0x7FFFFFFF;
            jv_bc85f ^= (jv_bc85f << 3) | 0x8C40;
          (void)jv_bc85f; }
    }
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        if ((((opq_201b * opq_201b) % 4) == 2)) {
            { int jv_97444 = opq_201b ^ 0x1C6F;
                jv_97444 += (jv_97444 >> 2) + 0xB8;
                jv_97444 = (jv_97444 * 0xF) % 0x7FFFFFFF;
              (void)jv_97444; }
        }
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    if ((((opq_201b * opq_201b + opq_201b_b * opq_201b_b) % 4) == 3)) {
        { int jv_d086c = opq_201b ^ 0xDDA3;
            jv_d086c = (jv_d086c * 0x38) % 0x7FFFFFFF;
          (void)jv_d086c; }
    }
    return 0;
}
