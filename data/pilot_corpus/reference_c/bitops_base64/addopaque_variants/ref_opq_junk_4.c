#include <stdio.h>
static volatile int opq_fab1 = 7;
static volatile int opq_fab1_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    if ((((opq_fab1 * opq_fab1) % 4) == 2)) {
        { int jv_f08ba = opq_fab1 ^ 0x63D4;
            jv_f08ba += (jv_f08ba >> 2) + 0x34;
          (void)jv_f08ba; }
    }
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    if ((((opq_fab1 * opq_fab1 + opq_fab1_b * opq_fab1_b) % 4) == 3)) {
        { int jv_f7b4b = opq_fab1 ^ 0x8191;
            jv_f7b4b ^= (jv_f7b4b << 3) | 0xDE6C;
          (void)jv_f7b4b; }
    }
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_fab1 * opq_fab1) % 4) == 2)) {
        { int jv_c7a8a = opq_fab1 ^ 0xD8CF;
            jv_c7a8a = (jv_c7a8a * 0x26) % 0x7FFFFFFF;
            jv_c7a8a += (jv_c7a8a >> 2) + 0xD2;
          (void)jv_c7a8a; }
    }
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        int rem = n - i;
        if ((((opq_fab1 * opq_fab1) % 4) == 2)) {
            { int jv_fbe6d = opq_fab1 ^ 0x46B9;
                jv_fbe6d = (jv_fbe6d * 0x3C) % 0x7FFFFFFF;
              (void)jv_fbe6d; }
        }
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if ((((opq_fab1 * opq_fab1) % 4) == 2)) {
            { int jv_3a1bf = opq_fab1 ^ 0x4235;
                jv_3a1bf += (jv_3a1bf >> 2) + 0xDF;
                jv_3a1bf = (jv_3a1bf * 0x38) % 0x7FFFFFFF;
              (void)jv_3a1bf; }
        }
        if (rem > 2) v |= in[i+2];
        if ((((opq_fab1 * opq_fab1 + opq_fab1_b * opq_fab1_b) % 4) == 3)) {
            { int jv_a5813 = opq_fab1 ^ 0x6975;
                jv_a5813 ^= (jv_a5813 << 3) | 0x4D21;
                jv_a5813 += (jv_a5813 >> 2) + 0xC;
              (void)jv_a5813; }
        }
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        if ((((opq_fab1 * opq_fab1 + opq_fab1_b * opq_fab1_b) % 4) == 3)) {
            { int jv_93c45 = opq_fab1 ^ 0xB465;
                jv_93c45 ^= (jv_93c45 << 3) | 0x12FF;
                jv_93c45 += (jv_93c45 >> 2) + 0x67;
              (void)jv_93c45; }
        }
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return 0;
}
