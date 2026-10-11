#include <stdio.h>
static volatile int opq_88fd = 7;
static volatile int opq_88fd_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    if ((((opq_88fd * opq_88fd + opq_88fd_b * opq_88fd_b) % 4) == 3)) {
        { int jv_23ae0 = opq_88fd ^ 0x1E20;
            jv_23ae0 += (jv_23ae0 >> 2) + 0xB3;
            jv_23ae0 ^= (jv_23ae0 << 3) | 0x5CA0;
            jv_23ae0 = (jv_23ae0 * 0x12) % 0x7FFFFFFF;
          (void)jv_23ae0; }
    }
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_88fd * opq_88fd) % 4) == 2)) {
        { int jv_40c5a = opq_88fd ^ 0xB50E;
            jv_40c5a ^= (jv_40c5a << 3) | 0xFA49;
            jv_40c5a = (jv_40c5a * 0x22) % 0x7FFFFFFF;
            jv_40c5a += (jv_40c5a >> 2) + 0x97;
          (void)jv_40c5a; }
    }
    for (int i = 0; i < n; i += 3) {
        if ((((opq_88fd * opq_88fd) % 4) == 2)) {
            { int jv_81317 = opq_88fd ^ 0x3759;
                jv_81317 ^= (jv_81317 << 3) | 0xFAB4;
                jv_81317 += (jv_81317 >> 2) + 0x82;
              (void)jv_81317; }
        }
        unsigned v = (unsigned)in[i] << 16;
        int rem = n - i;
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if ((((opq_88fd * opq_88fd) % 4) == 2)) {
            { int jv_215f4 = opq_88fd ^ 0xBDDF;
                jv_215f4 += (jv_215f4 >> 2) + 0x5;
                jv_215f4 ^= (jv_215f4 << 3) | 0xB4DB;
              (void)jv_215f4; }
        }
        if (rem > 2) v |= in[i+2];
        if ((((opq_88fd * opq_88fd) % 4) == 2)) {
            { int jv_2e6d6 = opq_88fd ^ 0x20BA;
                jv_2e6d6 += (jv_2e6d6 >> 2) + 0x51;
                jv_2e6d6 = (jv_2e6d6 * 0x3C) % 0x7FFFFFFF;
                jv_2e6d6 ^= (jv_2e6d6 << 3) | 0xC0D6;
              (void)jv_2e6d6; }
        }
        out[o++] = tbl[(v >> 18) & 63];
        if ((((opq_88fd * opq_88fd) % 4) == 2)) {
            { int jv_31386 = opq_88fd ^ 0xCB3C;
                jv_31386 += (jv_31386 >> 2) + 0x36;
              (void)jv_31386; }
        }
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    if ((((opq_88fd * opq_88fd + opq_88fd_b * opq_88fd_b) % 4) == 3)) {
        { int jv_2b35a = opq_88fd ^ 0xC96F;
            jv_2b35a ^= (jv_2b35a << 3) | 0xAD2A;
            jv_2b35a = (jv_2b35a * 0x4) % 0x7FFFFFFF;
            jv_2b35a += (jv_2b35a >> 2) + 0x75;
          (void)jv_2b35a; }
    }
    printf("%s %d\n", out, o);
    return 0;
}
