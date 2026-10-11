#include <stdio.h>
static volatile int opq_20db = 7;
static volatile int opq_20db_b = 3;

int main(void) {
    const char *in = "aaabbbbccddddddeffffg";
    char out[64];
    if ((((opq_20db * opq_20db + opq_20db_b * opq_20db_b) % 4) == 3)) {
        { int jv_e077c = opq_20db ^ 0x126A;
            jv_e077c += (jv_e077c >> 2) + 0x93;
            jv_e077c ^= (jv_e077c << 3) | 0xB498;
            jv_e077c = (jv_e077c * 0x24) % 0x7FFFFFFF;
          (void)jv_e077c; }
    }
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if ((((opq_20db * opq_20db + opq_20db_b * opq_20db_b) % 4) == 3)) {
        { int jv_15c8c = opq_20db ^ 0x4E4D;
            jv_15c8c += (jv_15c8c >> 2) + 0xC7;
            jv_15c8c = (jv_15c8c * 0x9) % 0x7FFFFFFF;
            jv_15c8c ^= (jv_15c8c << 3) | 0xA36F;
          (void)jv_15c8c; }
    }
    printf("%s %d\n", out, o);
    if ((((opq_20db * opq_20db) % 4) == 2)) {
        { int jv_1e53f = opq_20db ^ 0x497C;
            jv_1e53f ^= (jv_1e53f << 3) | 0x8608;
            jv_1e53f = (jv_1e53f * 0x11) % 0x7FFFFFFF;
            jv_1e53f += (jv_1e53f >> 2) + 0xD1;
          (void)jv_1e53f; }
    }
    return 0;
}
