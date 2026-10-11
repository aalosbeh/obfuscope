#include <stdio.h>
static volatile int opq_9d1b = 7;
static volatile int opq_9d1b_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    if ((((opq_9d1b * opq_9d1b) % 4) == 2)) {
        { int jv_f5151 = opq_9d1b ^ 0xCF80;
            jv_f5151 = (jv_f5151 * 0x1E) % 0x7FFFFFFF;
          (void)jv_f5151; }
    }
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    if ((((opq_9d1b * opq_9d1b) % 4) == 2)) {
        { int jv_67676 = opq_9d1b ^ 0x109;
            jv_67676 += (jv_67676 >> 2) + 0x6E;
            jv_67676 ^= (jv_67676 << 3) | 0x78B7;
          (void)jv_67676; }
    }
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int count = 0;
    for (int i = 0; i < 256; i++) count += get_bit(i);
    if ((((opq_9d1b * opq_9d1b) % 4) == 2)) {
        { int jv_ec268 = opq_9d1b ^ 0xC2B8;
            jv_ec268 += (jv_ec268 >> 2) + 0x75;
            jv_ec268 ^= (jv_ec268 << 3) | 0xBE23;
          (void)jv_ec268; }
    }
    unsigned fold = 0;
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    if ((((opq_9d1b * opq_9d1b + opq_9d1b_b * opq_9d1b_b) % 4) == 3)) {
        { int jv_5dd74 = opq_9d1b ^ 0xEC4C;
            jv_5dd74 = (jv_5dd74 * 0x3B) % 0x7FFFFFFF;
            jv_5dd74 += (jv_5dd74 >> 2) + 0xA7;
          (void)jv_5dd74; }
    }
    printf("%d %08x\n", count, fold);
    return 0;
}
