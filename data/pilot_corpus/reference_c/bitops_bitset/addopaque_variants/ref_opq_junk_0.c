#include <stdio.h>
static volatile int opq_514b = 7;
static volatile int opq_514b_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    if ((((opq_514b * opq_514b) % 4) == 2)) {
        { int jv_9e536 = opq_514b ^ 0x1042;
            jv_9e536 += (jv_9e536 >> 2) + 0xEF;
            jv_9e536 ^= (jv_9e536 << 3) | 0x2EA8;
            jv_9e536 = (jv_9e536 * 0x4) % 0x7FFFFFFF;
          (void)jv_9e536; }
    }
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int count = 0;
    for (int i = 0; i < 256; i++) count += get_bit(i);
    if ((((opq_514b * opq_514b) % 4) == 2)) {
        { int jv_552c3 = opq_514b ^ 0x25E4;
            jv_552c3 ^= (jv_552c3 << 3) | 0xA732;
          (void)jv_552c3; }
    }
    unsigned fold = 0;
    if ((((opq_514b * opq_514b + opq_514b_b * opq_514b_b) % 4) == 3)) {
        { int jv_d768e = opq_514b ^ 0x178A;
            jv_d768e = (jv_d768e * 0x13) % 0x7FFFFFFF;
          (void)jv_d768e; }
    }
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    if ((((opq_514b * opq_514b + opq_514b_b * opq_514b_b) % 4) == 3)) {
        { int jv_853a2 = opq_514b ^ 0xB06;
            jv_853a2 ^= (jv_853a2 << 3) | 0xFA5F;
            jv_853a2 += (jv_853a2 >> 2) + 0x15;
            jv_853a2 = (jv_853a2 * 0x6) % 0x7FFFFFFF;
          (void)jv_853a2; }
    }
    return 0;
}
