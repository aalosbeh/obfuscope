#include <stdio.h>
static volatile int opq_8329 = 7;
static volatile int opq_8329_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    if ((((opq_8329 * opq_8329) % 4) == 2)) {
        { int jv_73a66 = opq_8329 ^ 0xBCC3;
            jv_73a66 = (jv_73a66 * 0x34) % 0x7FFFFFFF;
            jv_73a66 ^= (jv_73a66 << 3) | 0xC478;
            jv_73a66 += (jv_73a66 >> 2) + 0xCE;
          (void)jv_73a66; }
    }
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    if ((((opq_8329 * opq_8329 + opq_8329_b * opq_8329_b) % 4) == 3)) {
        { int jv_bdb9e = opq_8329 ^ 0xAE14;
            jv_bdb9e += (jv_bdb9e >> 2) + 0x40;
            jv_bdb9e = (jv_bdb9e * 0x1A) % 0x7FFFFFFF;
          (void)jv_bdb9e; }
    }
    int count = 0;
    for (int i = 0; i < 256; i++) count += get_bit(i);
    if ((((opq_8329 * opq_8329 + opq_8329_b * opq_8329_b) % 4) == 3)) {
        { int jv_d5a8d = opq_8329 ^ 0x90F;
            jv_d5a8d ^= (jv_d5a8d << 3) | 0x4800;
            jv_d5a8d += (jv_d5a8d >> 2) + 0x64;
          (void)jv_d5a8d; }
    }
    unsigned fold = 0;
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    if ((((opq_8329 * opq_8329 + opq_8329_b * opq_8329_b) % 4) == 3)) {
        { int jv_5ed1c = opq_8329 ^ 0xE88D;
            jv_5ed1c = (jv_5ed1c * 0xD) % 0x7FFFFFFF;
            jv_5ed1c ^= (jv_5ed1c << 3) | 0xC647;
          (void)jv_5ed1c; }
    }
    return 0;
}
