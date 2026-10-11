#include <stdio.h>
static volatile int opq_d6c2 = 7;
static volatile int opq_d6c2_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    if ((((opq_d6c2 * opq_d6c2 + opq_d6c2) % 2) == 0)) { opq_d6c2_b ^= 0; }
    char out[64];
    int n = (int)sizeof(in) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        if ((((opq_d6c2 * opq_d6c2) % 4) == 2)) {
            { int jv_fcc84 = opq_d6c2 ^ 0xCF3D;
                jv_fcc84 = (jv_fcc84 * 0x2C) % 0x7FFFFFFF;
                jv_fcc84 += (jv_fcc84 >> 2) + 0x61;
                jv_fcc84 ^= (jv_fcc84 << 3) | 0x2061;
              (void)jv_fcc84; }
        }
        int rem = n - i;
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (rem > 2) v |= in[i+2];
        out[o++] = tbl[(v >> 18) & 63];
        if ((((opq_d6c2 * opq_d6c2 + opq_d6c2_b * opq_d6c2_b) % 4) == 3)) {
            { int jv_b4237 = opq_d6c2 ^ 0xDEDF;
                jv_b4237 = (jv_b4237 * 0x39) % 0x7FFFFFFF;
              (void)jv_b4237; }
        }
        out[o++] = tbl[(v >> 12) & 63];
        if ((((opq_d6c2 * opq_d6c2 + opq_d6c2) % 2) == 0)) { opq_d6c2_b ^= 0; }
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        if ((((opq_d6c2 * (opq_d6c2 + 1)) % 2) == 0)) { opq_d6c2_b ^= 0; }
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
        if (((opq_d6c2 * opq_d6c2 - opq_d6c2) % 2 == 0)) { opq_d6c2_b ^= 0; }
    }
    out[o] = '\0';
    if (((opq_d6c2 * opq_d6c2 - opq_d6c2) % 2 == 0)) { opq_d6c2_b ^= 0; }
    printf("%s %d\n", out, o);
    return 0;
}
