#include <stdio.h>
#define WORDS 8
static unsigned v_6321ea[WORDS];
static void set_bit(int i) { v_6321ea[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { v_6321ea[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (v_6321ea[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int v_2d15fa = 0;
    for (int i = 0; i < 256; i++) v_2d15fa += get_bit(i);
    unsigned v_97b5f9 = 0;
    for (int w = 0; w < WORDS; w++) v_97b5f9 ^= v_6321ea[w];
    printf("%d %08x\n", v_2d15fa, v_97b5f9);
    return 0;
}
