#include <stdio.h>
static volatile int opq_fd01 = 7;
static volatile int opq_fd01_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    if (((opq_fd01 * opq_fd01 - opq_fd01) % 2 == 0)) { opq_fd01_b ^= 0; }
    char out[64];
    if ((((opq_fd01 * opq_fd01 + opq_fd01) % 2) == 0)) { opq_fd01_b ^= 0; }
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_fd01 * opq_fd01 + opq_fd01) % 2) == 0)) { opq_fd01_b ^= 0; }
    for (int i = 0; i < n; i += 3) {
        if ((((opq_fd01 * opq_fd01 + opq_fd01) % 2) == 0)) { opq_fd01_b ^= 0; }
        unsigned v = (unsigned)in[i] << 16;
        int rem = n - i;
        if ((((opq_fd01 * (opq_fd01 + 1)) % 2) == 0)) { opq_fd01_b ^= 0; }
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (rem > 2) v |= in[i+2];
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        if ((((opq_fd01 * (opq_fd01 + 1)) % 2) == 0)) { opq_fd01_b ^= 0; }
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    if (((opq_fd01 * opq_fd01 - opq_fd01) % 2 == 0)) { opq_fd01_b ^= 0; }
    printf("%s %d\n", out, o);
    return 0;
}
