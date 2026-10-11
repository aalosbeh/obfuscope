#include <stdio.h>
#define WORDS 8
static unsigned v_8585de[WORDS];
static void set_bit(int i) { v_8585de[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { v_8585de[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (v_8585de[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int v_57622d = 0;
    for (int i = 0; i < 256; i++) v_57622d += get_bit(i);
    unsigned v_2a5e41 = 0;
    for (int w = 0; w < WORDS; w++) v_2a5e41 ^= v_8585de[w];
    printf("%d %08x\n", v_57622d, v_2a5e41);
    return 0;
}
