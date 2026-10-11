#include <stdio.h>
#define WORDS 8
static unsigned v_2f0bbf[WORDS];
static void set_bit(int i) { v_2f0bbf[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { v_2f0bbf[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (v_2f0bbf[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int v_e2aa76 = 0;
    for (int i = 0; i < 256; i++) v_e2aa76 += get_bit(i);
    unsigned v_c89547 = 0;
    for (int w = 0; w < WORDS; w++) v_c89547 ^= v_2f0bbf[w];
    printf("%d %08x\n", v_e2aa76, v_c89547);
    return 0;
}
