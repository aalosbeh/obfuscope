#include <stdio.h>
static volatile int opq_7863 = 7;
static volatile int opq_7863_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_7863 * opq_7863 + opq_7863_b * opq_7863_b) % 4) == 3)) {
        { int jv_4897d = opq_7863 ^ 0x67C4;
            jv_4897d += (jv_4897d >> 2) + 0x45;
            jv_4897d ^= (jv_4897d << 3) | 0x2E1B;
            jv_4897d = (jv_4897d * 0x3C) % 0x7FFFFFFF;
          (void)jv_4897d; }
    }
    for (int i = 0; i < n; i += 3) {
        if ((((opq_7863 * opq_7863 + opq_7863_b * opq_7863_b) % 4) == 3)) {
            { int jv_70aea = opq_7863 ^ 0xE043;
                jv_70aea += (jv_70aea >> 2) + 0xE4;
                jv_70aea ^= (jv_70aea << 3) | 0x61AE;
              (void)jv_70aea; }
        }
        unsigned v = (unsigned)in[i] << 16;
        int rem = n - i;
        if ((((opq_7863 * opq_7863 + opq_7863_b * opq_7863_b) % 4) == 3)) {
            { int jv_bf0df = opq_7863 ^ 0xC15F;
                jv_bf0df += (jv_bf0df >> 2) + 0x83;
                jv_bf0df ^= (jv_bf0df << 3) | 0x3E31;
              (void)jv_bf0df; }
        }
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if ((((opq_7863 * opq_7863 + opq_7863_b * opq_7863_b) % 4) == 3)) {
            { int jv_d2c0e = opq_7863 ^ 0x7357;
                jv_d2c0e ^= (jv_d2c0e << 3) | 0xC4DB;
                jv_d2c0e = (jv_d2c0e * 0x3E) % 0x7FFFFFFF;
              (void)jv_d2c0e; }
        }
        if (rem > 2) v |= in[i+2];
        if ((((opq_7863 * opq_7863) % 4) == 2)) {
            { int jv_b7c4a = opq_7863 ^ 0x6B14;
                jv_b7c4a = (jv_b7c4a * 0x1C) % 0x7FFFFFFF;
              (void)jv_b7c4a; }
        }
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    if ((((opq_7863 * opq_7863 + opq_7863_b * opq_7863_b) % 4) == 3)) {
        { int jv_c08c8 = opq_7863 ^ 0xB000;
            jv_c08c8 = (jv_c08c8 * 0x1E) % 0x7FFFFFFF;
            jv_c08c8 ^= (jv_c08c8 << 3) | 0xD186;
          (void)jv_c08c8; }
    }
    printf("%s %d\n", out, o);
    if (((opq_7863 * opq_7863 - opq_7863) % 2 == 0)) { opq_7863_b ^= 0; }
    return 0;
}
