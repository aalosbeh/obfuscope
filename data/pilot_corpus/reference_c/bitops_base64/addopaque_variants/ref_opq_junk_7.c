#include <stdio.h>
static volatile int opq_75ff = 7;
static volatile int opq_75ff_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    if ((((opq_75ff * opq_75ff) % 4) == 2)) {
        { int jv_c34ed = opq_75ff ^ 0x74C5;
            jv_c34ed += (jv_c34ed >> 2) + 0x8E;
            jv_c34ed ^= (jv_c34ed << 3) | 0xC45;
          (void)jv_c34ed; }
    }
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    if ((((opq_75ff * opq_75ff + opq_75ff_b * opq_75ff_b) % 4) == 3)) {
        { int jv_f502a = opq_75ff ^ 0x1E4E;
            jv_f502a ^= (jv_f502a << 3) | 0x3B2D;
            jv_f502a = (jv_f502a * 0x17) % 0x7FFFFFFF;
          (void)jv_f502a; }
    }
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_75ff * opq_75ff) % 4) == 2)) {
        { int jv_d6591 = opq_75ff ^ 0xB705;
            jv_d6591 += (jv_d6591 >> 2) + 0x7E;
            jv_d6591 = (jv_d6591 * 0x13) % 0x7FFFFFFF;
            jv_d6591 ^= (jv_d6591 << 3) | 0xA1AA;
          (void)jv_d6591; }
    }
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        if ((((opq_75ff * opq_75ff) % 4) == 2)) {
            { int jv_d56dc = opq_75ff ^ 0xEABF;
                jv_d56dc += (jv_d56dc >> 2) + 0x8C;
              (void)jv_d56dc; }
        }
        int rem = n - i;
        if ((((opq_75ff * opq_75ff) % 4) == 2)) {
            { int jv_1bddb = opq_75ff ^ 0x5761;
                jv_1bddb += (jv_1bddb >> 2) + 0xD4;
                jv_1bddb = (jv_1bddb * 0x17) % 0x7FFFFFFF;
                jv_1bddb ^= (jv_1bddb << 3) | 0xF35A;
              (void)jv_1bddb; }
        }
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if ((((opq_75ff * opq_75ff + opq_75ff_b * opq_75ff_b) % 4) == 3)) {
            { int jv_7bd63 = opq_75ff ^ 0x42B1;
                jv_7bd63 ^= (jv_7bd63 << 3) | 0xE471;
                jv_7bd63 += (jv_7bd63 >> 2) + 0x78;
                jv_7bd63 = (jv_7bd63 * 0x32) % 0x7FFFFFFF;
              (void)jv_7bd63; }
        }
        if (rem > 2) v |= in[i+2];
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        if ((((opq_75ff * opq_75ff) % 4) == 2)) {
            { int jv_62ad8 = opq_75ff ^ 0xC855;
                jv_62ad8 ^= (jv_62ad8 << 3) | 0xB368;
                jv_62ad8 = (jv_62ad8 * 0x1B) % 0x7FFFFFFF;
                jv_62ad8 += (jv_62ad8 >> 2) + 0x19;
              (void)jv_62ad8; }
        }
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return 0;
}
