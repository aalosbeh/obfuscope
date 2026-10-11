#include <stdio.h>
static volatile int opq_1eed = 7;
static volatile int opq_1eed_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    if ((((opq_1eed * opq_1eed) % 4) == 2)) {
        { int jv_fe620 = opq_1eed ^ 0x24;
            jv_fe620 = (jv_fe620 * 0x1D) % 0x7FFFFFFF;
          (void)jv_fe620; }
    }
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    if ((((opq_1eed * opq_1eed) % 4) == 2)) {
        { int jv_1b919 = opq_1eed ^ 0x4A25;
            jv_1b919 = (jv_1b919 * 0x1A) % 0x7FFFFFFF;
          (void)jv_1b919; }
    }
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int count = 0;
    for (int i = 0; i < 256; i++) count += get_bit(i);
    if ((((opq_1eed * opq_1eed) % 4) == 2)) {
        { int jv_15cc3 = opq_1eed ^ 0xDAF6;
            jv_15cc3 = (jv_15cc3 * 0x36) % 0x7FFFFFFF;
            jv_15cc3 ^= (jv_15cc3 << 3) | 0xCCB7;
            jv_15cc3 += (jv_15cc3 >> 2) + 0xCF;
          (void)jv_15cc3; }
    }
    unsigned fold = 0;
    if ((((opq_1eed * opq_1eed) % 4) == 2)) {
        { int jv_34efb = opq_1eed ^ 0x70D6;
            jv_34efb = (jv_34efb * 0x14) % 0x7FFFFFFF;
            jv_34efb += (jv_34efb >> 2) + 0x53;
            jv_34efb ^= (jv_34efb << 3) | 0xE7DA;
          (void)jv_34efb; }
    }
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return 0;
}
