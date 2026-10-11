#include <stdio.h>
static volatile int opq_9a4d = 7;
static volatile int opq_9a4d_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    if ((((opq_9a4d * opq_9a4d + opq_9a4d_b * opq_9a4d_b) % 4) == 3)) {
        { int jv_c9ec8 = opq_9a4d ^ 0xB32D;
            jv_c9ec8 ^= (jv_c9ec8 << 3) | 0x7AC6;
            jv_c9ec8 += (jv_c9ec8 >> 2) + 0xBB;
            jv_c9ec8 = (jv_c9ec8 * 0x3B) % 0x7FFFFFFF;
          (void)jv_c9ec8; }
    }
    const unsigned char in[] = "Obfuscation provenance";
    char out[64];
    if ((((opq_9a4d * opq_9a4d + opq_9a4d_b * opq_9a4d_b) % 4) == 3)) {
        { int jv_5d646 = opq_9a4d ^ 0x40A9;
            jv_5d646 += (jv_5d646 >> 2) + 0xAB;
          (void)jv_5d646; }
    }
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_9a4d * opq_9a4d) % 4) == 2)) {
        { int jv_e8015 = opq_9a4d ^ 0xF8FC;
            jv_e8015 += (jv_e8015 >> 2) + 0xEE;
            jv_e8015 = (jv_e8015 * 0x1E) % 0x7FFFFFFF;
            jv_e8015 ^= (jv_e8015 << 3) | 0xD6D2;
          (void)jv_e8015; }
    }
    for (int i = 0; i < n; i += 3) {
        unsigned v = (unsigned)in[i] << 16;
        if ((((opq_9a4d * opq_9a4d + opq_9a4d_b * opq_9a4d_b) % 4) == 3)) {
            { int jv_23a90 = opq_9a4d ^ 0x18CC;
                jv_23a90 ^= (jv_23a90 << 3) | 0x50C5;
                jv_23a90 = (jv_23a90 * 0x3B) % 0x7FFFFFFF;
                jv_23a90 += (jv_23a90 >> 2) + 0x30;
              (void)jv_23a90; }
        }
        int rem = n - i;
        if ((((opq_9a4d * opq_9a4d) % 4) == 2)) {
            { int jv_46361 = opq_9a4d ^ 0x4B59;
                jv_46361 = (jv_46361 * 0x29) % 0x7FFFFFFF;
                jv_46361 ^= (jv_46361 << 3) | 0x9F8D;
              (void)jv_46361; }
        }
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (rem > 2) v |= in[i+2];
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        if ((((opq_9a4d * opq_9a4d + opq_9a4d_b * opq_9a4d_b) % 4) == 3)) {
            { int jv_c6a2d = opq_9a4d ^ 0x9B85;
                jv_c6a2d = (jv_c6a2d * 0x29) % 0x7FFFFFFF;
              (void)jv_c6a2d; }
        }
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        if ((((opq_9a4d * opq_9a4d + opq_9a4d_b * opq_9a4d_b) % 4) == 3)) {
            { int jv_7d13d = opq_9a4d ^ 0xF89E;
                jv_7d13d ^= (jv_7d13d << 3) | 0xDFD4;
              (void)jv_7d13d; }
        }
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    return 0;
}
