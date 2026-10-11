#include <stdio.h>
static volatile int opq_e2c1 = 7;
static volatile int opq_e2c1_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    if ((((opq_e2c1 * opq_e2c1) % 4) == 2)) {
        { int jv_4c5a7 = opq_e2c1 ^ 0x6519;
            jv_4c5a7 = (jv_4c5a7 * 0x14) % 0x7FFFFFFF;
            jv_4c5a7 += (jv_4c5a7 >> 2) + 0x33;
          (void)jv_4c5a7; }
    }
    const unsigned char in[] = "Obfuscation provenance";
    if ((((opq_e2c1 * opq_e2c1 + opq_e2c1_b * opq_e2c1_b) % 4) == 3)) {
        { int jv_ebb91 = opq_e2c1 ^ 0x7259;
            jv_ebb91 = (jv_ebb91 * 0x2C) % 0x7FFFFFFF;
            jv_ebb91 += (jv_ebb91 >> 2) + 0xB8;
            jv_ebb91 ^= (jv_ebb91 << 3) | 0x69CB;
          (void)jv_ebb91; }
    }
    char out[64];
    if ((((opq_e2c1 * opq_e2c1 + opq_e2c1_b * opq_e2c1_b) % 4) == 3)) {
        { int jv_bb950 = opq_e2c1 ^ 0xE2C1;
            jv_bb950 += (jv_bb950 >> 2) + 0xDF;
          (void)jv_bb950; }
    }
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_e2c1 * opq_e2c1) % 4) == 2)) {
        { int jv_76174 = opq_e2c1 ^ 0x8333;
            jv_76174 += (jv_76174 >> 2) + 0x40;
            jv_76174 ^= (jv_76174 << 3) | 0xAD82;
            jv_76174 = (jv_76174 * 0x38) % 0x7FFFFFFF;
          (void)jv_76174; }
    }
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        int rem = n - i;
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (rem > 2) v |= in[i+2];
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        if ((((opq_e2c1 * (opq_e2c1 + 1)) % 2) == 0)) { opq_e2c1_b ^= 0; }
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    if ((((opq_e2c1 * opq_e2c1) % 4) == 2)) {
        { int jv_10374 = opq_e2c1 ^ 0xE8B1;
            jv_10374 = (jv_10374 * 0x1F) % 0x7FFFFFFF;
            jv_10374 ^= (jv_10374 << 3) | 0x5850;
            jv_10374 += (jv_10374 >> 2) + 0xEC;
          (void)jv_10374; }
    }
    printf("%s %d\n", out, o);
    if ((((opq_e2c1 * opq_e2c1 + opq_e2c1) % 2) == 0)) { opq_e2c1_b ^= 0; }
    return 0;
}
