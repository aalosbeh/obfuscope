#include <stdio.h>
static volatile int opq_f4ea = 7;
static volatile int opq_f4ea_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    if ((((opq_f4ea * opq_f4ea + opq_f4ea_b * opq_f4ea_b) % 4) == 3)) {
        { int jv_275b4 = opq_f4ea ^ 0x2992;
            jv_275b4 = (jv_275b4 * 0x35) % 0x7FFFFFFF;
            jv_275b4 += (jv_275b4 >> 2) + 0xB2;
          (void)jv_275b4; }
    }
    const unsigned char in[] = "Obfuscation provenance";
    if ((((opq_f4ea * opq_f4ea) % 4) == 2)) {
        { int jv_8a87f = opq_f4ea ^ 0x4A74;
            jv_8a87f += (jv_8a87f >> 2) + 0x46;
          (void)jv_8a87f; }
    }
    char out[64];
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_f4ea * (opq_f4ea + 1)) % 2) == 0)) { opq_f4ea_b ^= 0; }
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        int rem = n - i;
        if (((opq_f4ea * opq_f4ea - opq_f4ea) % 2 == 0)) { opq_f4ea_b ^= 0; }
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (((opq_f4ea * opq_f4ea - opq_f4ea) % 2 == 0)) { opq_f4ea_b ^= 0; }
        if (rem > 2) v |= in[i+2];
        if ((((opq_f4ea * (opq_f4ea + 1)) % 2) == 0)) { opq_f4ea_b ^= 0; }
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    if ((((opq_f4ea * (opq_f4ea + 1)) % 2) == 0)) { opq_f4ea_b ^= 0; }
    return 0;
}
