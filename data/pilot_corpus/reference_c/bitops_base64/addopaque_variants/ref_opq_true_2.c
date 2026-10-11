#include <stdio.h>
static volatile int opq_cff4 = 7;
static volatile int opq_cff4_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    if (((opq_cff4 * opq_cff4 - opq_cff4) % 2 == 0)) { opq_cff4_b ^= 0; }
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    if ((((opq_cff4 * (opq_cff4 + 1)) % 2) == 0)) { opq_cff4_b ^= 0; }
    int n = (int)sizeof(in) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        if ((((opq_cff4 * opq_cff4 + opq_cff4) % 2) == 0)) { opq_cff4_b ^= 0; }
        int rem = n - i;
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (((opq_cff4 * opq_cff4 - opq_cff4) % 2 == 0)) { opq_cff4_b ^= 0; }
        if (rem > 2) v |= in[i+2];
        if ((((opq_cff4 * opq_cff4 + opq_cff4) % 2) == 0)) { opq_cff4_b ^= 0; }
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    if ((((opq_cff4 * (opq_cff4 + 1)) % 2) == 0)) { opq_cff4_b ^= 0; }
    printf("%s %d\n", out, o);
    if (((opq_cff4 * opq_cff4 - opq_cff4) % 2 == 0)) { opq_cff4_b ^= 0; }
    return 0;
}
