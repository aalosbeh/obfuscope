#include <stdio.h>
static volatile int opq_df68 = 7;
static volatile int opq_df68_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    if ((((opq_df68 * opq_df68 + opq_df68_b * opq_df68_b) % 4) == 3)) {
        { int jv_833b6 = opq_df68 ^ 0x8E11;
            jv_833b6 += (jv_833b6 >> 2) + 0x5C;
            jv_833b6 = (jv_833b6 * 0x18) % 0x7FFFFFFF;
          (void)jv_833b6; }
    }
    int n = (int)sizeof(in) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        if (((opq_df68 * opq_df68 - opq_df68) % 2 == 0)) { opq_df68_b ^= 0; }
        unsigned v = (unsigned)in[i] << 16;
        if ((((opq_df68 * (opq_df68 + 1)) % 2) == 0)) { opq_df68_b ^= 0; }
        int rem = n - i;
        if ((((opq_df68 * opq_df68) % 4) == 2)) {
            { int jv_ce289 = opq_df68 ^ 0x1AA6;
                jv_ce289 += (jv_ce289 >> 2) + 0x8A;
              (void)jv_ce289; }
        }
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (rem > 2) v |= in[i+2];
        if ((((opq_df68 * opq_df68) % 4) == 2)) {
            { int jv_a851a = opq_df68 ^ 0xB147;
                jv_a851a += (jv_a851a >> 2) + 0x3A;
                jv_a851a ^= (jv_a851a << 3) | 0xE298;
              (void)jv_a851a; }
        }
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        if ((((opq_df68 * (opq_df68 + 1)) % 2) == 0)) { opq_df68_b ^= 0; }
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
        if ((((opq_df68 * opq_df68 + opq_df68) % 2) == 0)) { opq_df68_b ^= 0; }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return 0;
}
