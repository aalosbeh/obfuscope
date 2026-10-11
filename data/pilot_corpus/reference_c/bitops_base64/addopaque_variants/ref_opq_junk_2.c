#include <stdio.h>
static volatile int opq_2cd7 = 7;
static volatile int opq_2cd7_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    if ((((opq_2cd7 * opq_2cd7 + opq_2cd7_b * opq_2cd7_b) % 4) == 3)) {
        { int jv_63be7 = opq_2cd7 ^ 0x34C9;
            jv_63be7 = (jv_63be7 * 0x38) % 0x7FFFFFFF;
          (void)jv_63be7; }
    }
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    if ((((opq_2cd7 * opq_2cd7 + opq_2cd7_b * opq_2cd7_b) % 4) == 3)) {
        { int jv_2505b = opq_2cd7 ^ 0x7434;
            jv_2505b = (jv_2505b * 0x3) % 0x7FFFFFFF;
            jv_2505b ^= (jv_2505b << 3) | 0xD537;
          (void)jv_2505b; }
    }
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_2cd7 * opq_2cd7 + opq_2cd7_b * opq_2cd7_b) % 4) == 3)) {
        { int jv_2bf3e = opq_2cd7 ^ 0x3A72;
            jv_2bf3e ^= (jv_2bf3e << 3) | 0xFEA0;
            jv_2bf3e += (jv_2bf3e >> 2) + 0x26;
            jv_2bf3e = (jv_2bf3e * 0x39) % 0x7FFFFFFF;
          (void)jv_2bf3e; }
    }
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        if ((((opq_2cd7 * opq_2cd7 + opq_2cd7_b * opq_2cd7_b) % 4) == 3)) {
            { int jv_1c1df = opq_2cd7 ^ 0x5127;
                jv_1c1df += (jv_1c1df >> 2) + 0x78;
                jv_1c1df = (jv_1c1df * 0x14) % 0x7FFFFFFF;
                jv_1c1df ^= (jv_1c1df << 3) | 0x81AB;
              (void)jv_1c1df; }
        }
        int rem = n - i;
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if ((((opq_2cd7 * opq_2cd7 + opq_2cd7_b * opq_2cd7_b) % 4) == 3)) {
            { int jv_174c5 = opq_2cd7 ^ 0x1AF6;
                jv_174c5 ^= (jv_174c5 << 3) | 0xA6F1;
              (void)jv_174c5; }
        }
        if (rem > 2) v |= in[i+2];
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        if ((((opq_2cd7 * opq_2cd7 + opq_2cd7_b * opq_2cd7_b) % 4) == 3)) {
            { int jv_31974 = opq_2cd7 ^ 0x527F;
                jv_31974 ^= (jv_31974 << 3) | 0x8CC4;
                jv_31974 += (jv_31974 >> 2) + 0x91;
                jv_31974 = (jv_31974 * 0x27) % 0x7FFFFFFF;
              (void)jv_31974; }
        }
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        if ((((opq_2cd7 * opq_2cd7 + opq_2cd7_b * opq_2cd7_b) % 4) == 3)) {
            { int jv_1b2c5 = opq_2cd7 ^ 0xD4B7;
                jv_1b2c5 += (jv_1b2c5 >> 2) + 0xD;
                jv_1b2c5 ^= (jv_1b2c5 << 3) | 0x8DD;
              (void)jv_1b2c5; }
        }
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return 0;
}
