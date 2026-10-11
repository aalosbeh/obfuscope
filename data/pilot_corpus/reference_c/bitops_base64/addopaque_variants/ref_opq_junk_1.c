#include <stdio.h>
static volatile int opq_e08b = 7;
static volatile int opq_e08b_b = 3;

static const char tbl[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int main(void) {
    if ((((opq_e08b * opq_e08b) % 4) == 2)) {
        { int jv_e8101 = opq_e08b ^ 0xBCDC;
            jv_e8101 = (jv_e8101 * 0x37) % 0x7FFFFFFF;
            jv_e8101 ^= (jv_e8101 << 3) | 0x5F1D;
            jv_e8101 += (jv_e8101 >> 2) + 0x46;
          (void)jv_e8101; }
    }
    const unsigned char in[] = "Obfuscation provenance";
    if ((((opq_e08b * opq_e08b) % 4) == 2)) {
        { int jv_4d088 = opq_e08b ^ 0xB5CC;
            jv_4d088 ^= (jv_4d088 << 3) | 0x92A;
            jv_4d088 = (jv_4d088 * 0x2D) % 0x7FFFFFFF;
          (void)jv_4d088; }
    }
    char out[64];
    int n = (int)sizeof(in) - 1, o = 0;
    if ((((opq_e08b * opq_e08b) % 4) == 2)) {
        { int jv_15152 = opq_e08b ^ 0xCBEE;
            jv_15152 = (jv_15152 * 0x32) % 0x7FFFFFFF;
            jv_15152 ^= (jv_15152 << 3) | 0x4A66;
          (void)jv_15152; }
    }
    for (int i = 0; i < n; i += 3) {
        if ((((opq_e08b * opq_e08b + opq_e08b_b * opq_e08b_b) % 4) == 3)) {
            { int jv_cdc4a = opq_e08b ^ 0x7514;
                jv_cdc4a = (jv_cdc4a * 0x14) % 0x7FFFFFFF;
              (void)jv_cdc4a; }
        }
        unsigned v = (unsigned)in[i] << 16;
        int rem = n - i;
        if (rem > 1) v |= (unsigned)in[i+1] << 8;
        if (rem > 2) v |= in[i+2];
        out[o++] = tbl[(v >> 18) & 63];
        out[o++] = tbl[(v >> 12) & 63];
        if ((((opq_e08b * opq_e08b) % 4) == 2)) {
            { int jv_eb2d3 = opq_e08b ^ 0x17B3;
                jv_eb2d3 ^= (jv_eb2d3 << 3) | 0xF1E4;
                jv_eb2d3 = (jv_eb2d3 * 0x16) % 0x7FFFFFFF;
                jv_eb2d3 += (jv_eb2d3 >> 2) + 0x1E;
              (void)jv_eb2d3; }
        }
        out[o++] = (rem > 1) ? tbl[(v >> 6) & 63] : '=';
        out[o++] = (rem > 2) ? tbl[v & 63] : '=';
        if ((((opq_e08b * opq_e08b) % 4) == 2)) {
            { int jv_110f6 = opq_e08b ^ 0xBF00;
                jv_110f6 ^= (jv_110f6 << 3) | 0x3F35;
                jv_110f6 = (jv_110f6 * 0xC) % 0x7FFFFFFF;
              (void)jv_110f6; }
        }
    }
    out[o] = '\0';
    printf("%s %d\n", out, o);
    if ((((opq_e08b * opq_e08b) % 4) == 2)) {
        { int jv_f36c8 = opq_e08b ^ 0x3CEB;
            jv_f36c8 = (jv_f36c8 * 0x15) % 0x7FFFFFFF;
          (void)jv_f36c8; }
    }
    return 0;
}
