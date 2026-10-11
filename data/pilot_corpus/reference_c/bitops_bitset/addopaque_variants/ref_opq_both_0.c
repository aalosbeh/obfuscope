#include <stdio.h>
static volatile int opq_4ddc = 7;
static volatile int opq_4ddc_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    if ((((opq_4ddc * (opq_4ddc + 1)) % 2) == 0)) { opq_4ddc_b ^= 0; }
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int count = 0;
    for (int i = 0; i < 256; i++) count += get_bit(i);
    if ((((opq_4ddc * opq_4ddc) % 4) == 2)) {
        { int jv_c1486 = opq_4ddc ^ 0x5941;
            jv_c1486 = (jv_c1486 * 0x24) % 0x7FFFFFFF;
          (void)jv_c1486; }
    }
    unsigned fold = 0;
    if (((opq_4ddc * opq_4ddc - opq_4ddc) % 2 == 0)) { opq_4ddc_b ^= 0; }
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    if ((((opq_4ddc * opq_4ddc + opq_4ddc_b * opq_4ddc_b) % 4) == 3)) {
        { int jv_4785d = opq_4ddc ^ 0x1EA4;
            jv_4785d = (jv_4785d * 0x33) % 0x7FFFFFFF;
          (void)jv_4785d; }
    }
    return 0;
}
