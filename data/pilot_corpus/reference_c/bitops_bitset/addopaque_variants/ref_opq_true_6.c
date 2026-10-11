#include <stdio.h>
static volatile int opq_b60f = 7;
static volatile int opq_b60f_b = 3;

#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { set[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (set[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    if ((((opq_b60f * (opq_b60f + 1)) % 2) == 0)) { opq_b60f_b ^= 0; }
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    if (((opq_b60f * opq_b60f - opq_b60f) % 2 == 0)) { opq_b60f_b ^= 0; }
    int count = 0;
    for (int i = 0; i < 256; i++) count += get_bit(i);
    unsigned fold = 0;
    if ((((opq_b60f * (opq_b60f + 1)) % 2) == 0)) { opq_b60f_b ^= 0; }
    for (int w = 0; w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    if (((opq_b60f * opq_b60f - opq_b60f) % 2 == 0)) { opq_b60f_b ^= 0; }
    return 0;
}
