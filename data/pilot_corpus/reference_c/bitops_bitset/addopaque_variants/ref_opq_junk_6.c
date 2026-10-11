#include <stdio.h>
static volatile int opq_6129 = 7;
static volatile int opq_6129_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    if ((((opq_6129 * opq_6129 + opq_6129_b * opq_6129_b) % 4) == 3)) {
        { int jv_1c2c0 = opq_6129 ^ 0xCB27;
            jv_1c2c0 ^= (jv_1c2c0 << 3) | 0x56F3;
            jv_1c2c0 = (jv_1c2c0 * 0x15) % 0x7FFFFFFF;
            jv_1c2c0 += (jv_1c2c0 >> 2) + 0x94;
          (void)jv_1c2c0; }
    }
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    if ((((opq_6129 * opq_6129) % 4) == 2)) {
        { int jv_b1dd2 = opq_6129 ^ 0x3D0C;
            jv_b1dd2 += (jv_b1dd2 >> 2) + 0x73;
          (void)jv_b1dd2; }
    }
    int count = 0;
    if ((((opq_6129 * opq_6129 + opq_6129_b * opq_6129_b) % 4) == 3)) {
        { int jv_63826 = opq_6129 ^ 0xDE7F;
            jv_63826 += (jv_63826 >> 2) + 0x52;
            jv_63826 = (jv_63826 * 0x8) % 0x7FFFFFFF;
          (void)jv_63826; }
    }
    for (int i = 0; i < 256; i++) count += get_bit(i);
    unsigned fold = 0;
    if ((((opq_6129 * opq_6129 + opq_6129_b * opq_6129_b) % 4) == 3)) {
        { int jv_797b1 = opq_6129 ^ 0x8B7E;
            jv_797b1 += (jv_797b1 >> 2) + 0x30;
            jv_797b1 ^= (jv_797b1 << 3) | 0xB028;
            jv_797b1 = (jv_797b1 * 0x34) % 0x7FFFFFFF;
          (void)jv_797b1; }
    }
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return 0;
}
