#include <stdio.h>
static volatile int opq_e74b = 7;
static volatile int opq_e74b_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    if ((((opq_e74b * opq_e74b) % 4) == 2)) {
        { int jv_170e2 = opq_e74b ^ 0x3EC8;
            jv_170e2 ^= (jv_170e2 << 3) | 0x3998;
            jv_170e2 += (jv_170e2 >> 2) + 0xA;
          (void)jv_170e2; }
    }
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    if ((((opq_e74b * opq_e74b) % 4) == 2)) {
        { int jv_ab7b3 = opq_e74b ^ 0xE7A9;
            jv_ab7b3 += (jv_ab7b3 >> 2) + 0xFC;
          (void)jv_ab7b3; }
    }
    int count = 0;
    if ((((opq_e74b * opq_e74b) % 4) == 2)) {
        { int jv_e4a5d = opq_e74b ^ 0x50EE;
            jv_e4a5d ^= (jv_e4a5d << 3) | 0x264D;
            jv_e4a5d += (jv_e4a5d >> 2) + 0xAF;
            jv_e4a5d = (jv_e4a5d * 0x12) % 0x7FFFFFFF;
          (void)jv_e4a5d; }
    }
    for (int i = 0; i < 256; i++) count += get_bit(i);
    unsigned fold = 0;
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    if (((opq_e74b * opq_e74b - opq_e74b) % 2 == 0)) { opq_e74b_b ^= 0; }
    return 0;
}
