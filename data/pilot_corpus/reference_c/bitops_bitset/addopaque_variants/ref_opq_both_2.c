#include <stdio.h>
static volatile int opq_ab52 = 7;
static volatile int opq_ab52_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    if ((((opq_ab52 * (opq_ab52 + 1)) % 2) == 0)) { opq_ab52_b ^= 0; }
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    if ((((opq_ab52 * (opq_ab52 + 1)) % 2) == 0)) { opq_ab52_b ^= 0; }
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int count = 0;
    if ((((opq_ab52 * (opq_ab52 + 1)) % 2) == 0)) { opq_ab52_b ^= 0; }
    for (int i = 0; i < 256; i++) count += get_bit(i);
    unsigned fold = 0;
    if ((((opq_ab52 * opq_ab52 + opq_ab52_b * opq_ab52_b) % 4) == 3)) {
        { int jv_280aa = opq_ab52 ^ 0x7BC2;
            jv_280aa = (jv_280aa * 0x34) % 0x7FFFFFFF;
          (void)jv_280aa; }
    }
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return 0;
}
