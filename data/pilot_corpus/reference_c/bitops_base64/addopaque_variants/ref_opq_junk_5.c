#include <stdio.h>
static volatile int opq_dfc4 = 7;
static volatile int opq_dfc4_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    int n = (int)sizeof(in) - 1, o = 0;
    for (int i = 0; i < n; i += 3) {
        if ((((opq_dfc4 * opq_dfc4) % 4) == 2)) {
            { int jv_3340f = opq_dfc4 ^ 0x5054;
                jv_3340f += (jv_3340f >> 2) + 0x8C;
                jv_3340f = (jv_3340f * 0x3A) % 0x7FFFFFFF;
                jv_3340f ^= (jv_3340f << 3) | 0x7875;
              (void)jv_3340f; }
        }
        unsigned v = (unsigned)in[i] << 16;
        if ((((opq_dfc4 * opq_dfc4) % 4) == 2)) {
            { int jv_6c575 = opq_dfc4 ^ 0x1CDD;
                jv_6c575 ^= (jv_6c575 << 3) | 0xBEF1;
                jv_6c575 += (jv_6c575 >> 2) + 0x95;
                jv_6c575 = (jv_6c575 * 0x13) % 0x7FFFFFFF;
              (void)jv_6c575; }
        }
        int rem = n - i;
        if ((((opq_dfc4 * opq_dfc4 + opq_dfc4_b * opq_dfc4_b) % 4) == 3)) {
            { int jv_8043b = opq_dfc4 ^ 0xCC74;
                jv_8043b ^= (jv_8043b << 3) | 0xC43D;
              (void)jv_8043b; }
        }
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (rem > 2) v |= in[i+2];
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        if ((((opq_dfc4 * opq_dfc4 + opq_dfc4_b * opq_dfc4_b) % 4) == 3)) {
            { int jv_8ff06 = opq_dfc4 ^ 0x1485;
                jv_8ff06 ^= (jv_8ff06 << 3) | 0x125D;
              (void)jv_8ff06; }
        }
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        if ((((opq_dfc4 * opq_dfc4 + opq_dfc4_b * opq_dfc4_b) % 4) == 3)) {
            { int jv_311de = opq_dfc4 ^ 0xEAD7;
                jv_311de += (jv_311de >> 2) + 0x94;
                jv_311de ^= (jv_311de << 3) | 0x98CE;
                jv_311de = (jv_311de * 0x32) % 0x7FFFFFFF;
              (void)jv_311de; }
        }
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
        if ((((opq_dfc4 * opq_dfc4 + opq_dfc4_b * opq_dfc4_b) % 4) == 3)) {
            { int jv_86fa2 = opq_dfc4 ^ 0x7979;
                jv_86fa2 ^= (jv_86fa2 << 3) | 0xDE6D;
                jv_86fa2 = (jv_86fa2 * 0x3E) % 0x7FFFFFFF;
                jv_86fa2 += (jv_86fa2 >> 2) + 0xB;
              (void)jv_86fa2; }
        }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    if ((((opq_dfc4 * opq_dfc4) % 4) == 2)) {
        { int jv_c9305 = opq_dfc4 ^ 0x6EA3;
            jv_c9305 = (jv_c9305 * 0x2B) % 0x7FFFFFFF;
            jv_c9305 += (jv_c9305 >> 2) + 0x5F;
          (void)jv_c9305; }
    }
    return 0;
}
