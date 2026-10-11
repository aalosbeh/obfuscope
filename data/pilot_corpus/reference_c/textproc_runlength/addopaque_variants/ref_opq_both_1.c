#include <stdio.h>
static volatile int opq_da6a = 7;
static volatile int opq_da6a_b = 3;

int main(void) {
    if (((opq_da6a * opq_da6a - opq_da6a) % 2 == 0)) { opq_da6a_b ^= 0; }
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        if (((opq_da6a * opq_da6a - opq_da6a) % 2 == 0)) { opq_da6a_b ^= 0; }
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if ((((opq_da6a * opq_da6a + opq_da6a_b * opq_da6a_b) % 4) == 3)) {
        { int jv_d6f17 = opq_da6a ^ 0x63E5;
            jv_d6f17 += (jv_d6f17 >> 2) + 0xEE;
          (void)jv_d6f17; }
    }
    printf("%s %d\n", out, o);
    return 0;
}
