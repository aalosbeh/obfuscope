#include <stdio.h>
static volatile int opq_fdd2 = 7;
static volatile int opq_fdd2_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    if ((((opq_fdd2 * opq_fdd2 + opq_fdd2_b * opq_fdd2_b) % 4) == 3)) {
        { int jv_67f4b = opq_fdd2 ^ 0x4A4F;
            jv_67f4b += (jv_67f4b >> 2) + 0xFB;
            jv_67f4b ^= (jv_67f4b << 3) | 0x656;
            jv_67f4b = (jv_67f4b * 0x3) % 0x7FFFFFFF;
          (void)jv_67f4b; }
    }
    int count = 0;
    if ((((opq_fdd2 * opq_fdd2) % 4) == 2)) {
        { int jv_40472 = opq_fdd2 ^ 0x23BC;
            jv_40472 = (jv_40472 * 0xC) % 0x7FFFFFFF;
            jv_40472 += (jv_40472 >> 2) + 0x26;
            jv_40472 ^= (jv_40472 << 3) | 0x215F;
          (void)jv_40472; }
    }
    for (int i = 0; i < 256; i++) count += get_bit(i);
    if ((((opq_fdd2 * opq_fdd2 + opq_fdd2_b * opq_fdd2_b) % 4) == 3)) {
        { int jv_517ce = opq_fdd2 ^ 0xD9AB;
            jv_517ce = (jv_517ce * 0x29) % 0x7FFFFFFF;
          (void)jv_517ce; }
    }
    unsigned fold = 0;
    if ((((opq_fdd2 * opq_fdd2 + opq_fdd2_b * opq_fdd2_b) % 4) == 3)) {
        { int jv_5c636 = opq_fdd2 ^ 0x4C00;
            jv_5c636 = (jv_5c636 * 0x18) % 0x7FFFFFFF;
            jv_5c636 ^= (jv_5c636 << 3) | 0x70B7;
            jv_5c636 += (jv_5c636 >> 2) + 0xE6;
          (void)jv_5c636; }
    }
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return 0;
}
