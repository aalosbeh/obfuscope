#include <stdio.h>
static volatile int opq_565a = 7;
static volatile int opq_565a_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    if ((((opq_565a * opq_565a + opq_565a_b * opq_565a_b) % 4) == 3)) {
        { int jv_c4455 = opq_565a ^ 0xFC4C;
            jv_c4455 += (jv_c4455 >> 2) + 0x8D;
          (void)jv_c4455; }
    }
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    if ((((opq_565a * opq_565a) % 4) == 2)) {
        { int jv_6f115 = opq_565a ^ 0xED72;
            jv_6f115 ^= (jv_6f115 << 3) | 0xF7E;
          (void)jv_6f115; }
    }
    int count = 0;
    for (int i = 0; i < 256; i++) count += get_bit(i);
    unsigned fold = 0;
    if ((((opq_565a * opq_565a) % 4) == 2)) {
        { int jv_83548 = opq_565a ^ 0xB222;
            jv_83548 ^= (jv_83548 << 3) | 0x61AA;
            jv_83548 = (jv_83548 * 0x14) % 0x7FFFFFFF;
            jv_83548 += (jv_83548 >> 2) + 0x12;
          (void)jv_83548; }
    }
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    if ((((opq_565a * opq_565a + opq_565a_b * opq_565a_b) % 4) == 3)) {
        { int jv_58a7b = opq_565a ^ 0x34AE;
            jv_58a7b = (jv_58a7b * 0x2B) % 0x7FFFFFFF;
            jv_58a7b ^= (jv_58a7b << 3) | 0x24C1;
          (void)jv_58a7b; }
    }
    return 0;
}
