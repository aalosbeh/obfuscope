#include <stdio.h>
static volatile int opq_9b67 = 7;
static volatile int opq_9b67_b = 3;

int main(void) {
    if ((((opq_9b67 * opq_9b67) % 4) == 2)) {
        { int jv_21acd = opq_9b67 ^ 0x6C5B;
            jv_21acd += (jv_21acd >> 2) + 0xFA;
            jv_21acd = (jv_21acd * 0x2A) % 0x7FFFFFFF;
          (void)jv_21acd; }
    }
    const char *in = "aaabbbbccddddddeffffg";
    if ((((opq_9b67 * opq_9b67 + opq_9b67_b * opq_9b67_b) % 4) == 3)) {
        { int jv_5568c = opq_9b67 ^ 0xB670;
            jv_5568c ^= (jv_5568c << 3) | 0x165E;
            jv_5568c = (jv_5568c * 0x26) % 0x7FFFFFFF;
            jv_5568c += (jv_5568c >> 2) + 0xED;
          (void)jv_5568c; }
    }
    char out[64];
    int o = 0, i = 0;
    while (in[i]) {
        char c = in[i];
        int run = 0;
        while (in[i] == c) { run++; i++; }
        if (o < 60) { out[o++] = c; out[o++] = (char)('0' + (run % 10)); }
    }
    out[o] = '\0';
    if ((((opq_9b67 * opq_9b67) % 4) == 2)) {
        { int jv_e578a = opq_9b67 ^ 0x78B9;
            jv_e578a += (jv_e578a >> 2) + 0x7A;
            jv_e578a ^= (jv_e578a << 3) | 0xB296;
          (void)jv_e578a; }
    }
    printf("%s %d\n", out, o);
    return 0;
}
