#include <stdio.h>
static volatile int opq_ed11 = 7;
static volatile int opq_ed11_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_ed11 * (opq_ed11 + 1)) % 2) == 0)) { opq_ed11_b ^= 0; }
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        if ((((opq_ed11 * (opq_ed11 + 1)) % 2) == 0)) { opq_ed11_b ^= 0; }
        int rem = n - i;
        if ((((opq_ed11 * opq_ed11 + opq_ed11) % 2) == 0)) { opq_ed11_b ^= 0; }
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (rem > 2) v |= in[i+2];
        if ((((opq_ed11 * (opq_ed11 + 1)) % 2) == 0)) { opq_ed11_b ^= 0; }
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
        if (((opq_ed11 * opq_ed11 - opq_ed11) % 2 == 0)) { opq_ed11_b ^= 0; }
    }
    out[o] = '\0';
    if ((((opq_ed11 * opq_ed11 + opq_ed11_b * opq_ed11_b) % 4) == 3)) {
        { int jv_d216b = opq_ed11 ^ 0x6F87;
            jv_d216b += (jv_d216b >> 2) + 0x74;
          (void)jv_d216b; }
    }
    printf("%s %d\n", out, o);
    if ((((opq_ed11 * opq_ed11) % 4) == 2)) {
        { int jv_9782c = opq_ed11 ^ 0xBA28;
            jv_9782c = (jv_9782c * 0x12) % 0x7FFFFFFF;
            jv_9782c ^= (jv_9782c << 3) | 0x90BA;
          (void)jv_9782c; }
    }
    return 0;
}
