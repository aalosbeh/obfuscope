#include <stdio.h>
static volatile int opq_d1c1 = 7;
static volatile int opq_d1c1_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    if ((((opq_d1c1 * opq_d1c1 + opq_d1c1_b * opq_d1c1_b) % 4) == 3)) {
        { int jv_9b04b = opq_d1c1 ^ 0xF53C;
            jv_9b04b += (jv_9b04b >> 2) + 0xCD;
            jv_9b04b = (jv_9b04b * 0x17) % 0x7FFFFFFF;
          (void)jv_9b04b; }
    }
    const unsigned char in[] = "Obfuscation provenance";
    if ((((opq_d1c1 * opq_d1c1 + opq_d1c1_b * opq_d1c1_b) % 4) == 3)) {
        { int jv_2690c = opq_d1c1 ^ 0xFB96;
            jv_2690c = (jv_2690c * 0x17) % 0x7FFFFFFF;
            jv_2690c += (jv_2690c >> 2) + 0xDA;
            jv_2690c ^= (jv_2690c << 3) | 0x682;
          (void)jv_2690c; }
    }
    char out[64];
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_d1c1 * opq_d1c1) % 4) == 2)) {
        { int jv_2dbe1 = opq_d1c1 ^ 0xE5DB;
            jv_2dbe1 ^= (jv_2dbe1 << 3) | 0xF8BA;
          (void)jv_2dbe1; }
    }
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        int rem = n - i;
        if ((((opq_d1c1 * opq_d1c1) % 4) == 2)) {
            { int jv_25ac1 = opq_d1c1 ^ 0x5F45;
                jv_25ac1 = (jv_25ac1 * 0x2F) % 0x7FFFFFFF;
              (void)jv_25ac1; }
        }
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if ((((opq_d1c1 * opq_d1c1) % 4) == 2)) {
            { int jv_631bd = opq_d1c1 ^ 0xC700;
                jv_631bd ^= (jv_631bd << 3) | 0xD5C8;
                jv_631bd = (jv_631bd * 0x15) % 0x7FFFFFFF;
                jv_631bd += (jv_631bd >> 2) + 0xE2;
              (void)jv_631bd; }
        }
        if (rem > 2) v |= in[i+2];
        if ((((opq_d1c1 * opq_d1c1) % 4) == 2)) {
            { int jv_103bb = opq_d1c1 ^ 0x40F7;
                jv_103bb ^= (jv_103bb << 3) | 0xFE05;
                jv_103bb += (jv_103bb >> 2) + 0x8F;
              (void)jv_103bb; }
        }
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    if ((((opq_d1c1 * opq_d1c1) % 4) == 2)) {
        { int jv_a8bee = opq_d1c1 ^ 0x691C;
            jv_a8bee = (jv_a8bee * 0x2A) % 0x7FFFFFFF;
          (void)jv_a8bee; }
    }
    printf("%s %d\n", out, o);
    return 0;
}
