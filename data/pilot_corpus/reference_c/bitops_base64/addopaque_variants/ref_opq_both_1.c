#include <stdio.h>
static volatile int opq_7695 = 7;
static volatile int opq_7695_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    if ((((opq_7695 * opq_7695 + opq_7695) % 2) == 0)) { opq_7695_b ^= 0; }
    char out[64];
    if ((((opq_7695 * opq_7695) % 4) == 2)) {
        { int jv_5615d = opq_7695 ^ 0x3453;
            jv_5615d ^= (jv_5615d << 3) | 0xD321;
          (void)jv_5615d; }
    }
    int n = (int)sizeof(in) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        if ((((opq_7695 * (opq_7695 + 1)) % 2) == 0)) { opq_7695_b ^= 0; }
        unsigned v = (unsigned)in[i] << 16;
        if ((((opq_7695 * (opq_7695 + 1)) % 2) == 0)) { opq_7695_b ^= 0; }
        int rem = n - i;
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (rem > 2) v |= in[i+2];
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        if ((((opq_7695 * opq_7695) % 4) == 2)) {
            { int jv_7f709 = opq_7695 ^ 0x4E5B;
                jv_7f709 ^= (jv_7f709 << 3) | 0xA0FD;
                jv_7f709 = (jv_7f709 * 0x16) % 0x7FFFFFFF;
                jv_7f709 += (jv_7f709 >> 2) + 0x18;
              (void)jv_7f709; }
        }
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    if ((((opq_7695 * opq_7695) % 4) == 2)) {
        { int jv_57832 = opq_7695 ^ 0x3B6E;
            jv_57832 += (jv_57832 >> 2) + 0xC3;
          (void)jv_57832; }
    }
    printf("%s %d\n", out, o);
    if ((((opq_7695 * opq_7695 + opq_7695_b * opq_7695_b) % 4) == 3)) {
        { int jv_ee24b = opq_7695 ^ 0xC4E4;
            jv_ee24b += (jv_ee24b >> 2) + 0xC;
            jv_ee24b ^= (jv_ee24b << 3) | 0x890D;
            jv_ee24b = (jv_ee24b * 0xA) % 0x7FFFFFFF;
          (void)jv_ee24b; }
    }
    return 0;
}
