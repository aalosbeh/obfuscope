#include <stdio.h>
static volatile int opq_ab32 = 7;
static volatile int opq_ab32_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    if ((((opq_ab32 * opq_ab32 + opq_ab32) % 2) == 0)) { opq_ab32_b ^= 0; }
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int count = 0;
    if ((((opq_ab32 * opq_ab32) % 4) == 2)) {
        { int jv_32476 = opq_ab32 ^ 0x3D18;
            jv_32476 += (jv_32476 >> 2) + 0x30;
            jv_32476 = (jv_32476 * 0x3A) % 0x7FFFFFFF;
          (void)jv_32476; }
    }
    for (int i = 0; i < 256; i++) count += get_bit(i);
    if ((((opq_ab32 * opq_ab32 + opq_ab32_b * opq_ab32_b) % 4) == 3)) {
        { int jv_e2fad = opq_ab32 ^ 0x911D;
            jv_e2fad = (jv_e2fad * 0x35) % 0x7FFFFFFF;
            jv_e2fad += (jv_e2fad >> 2) + 0x77;
            jv_e2fad ^= (jv_e2fad << 3) | 0xB73D;
          (void)jv_e2fad; }
    }
    unsigned fold = 0;
    if ((((opq_ab32 * (opq_ab32 + 1)) % 2) == 0)) { opq_ab32_b ^= 0; }
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return 0;
}
