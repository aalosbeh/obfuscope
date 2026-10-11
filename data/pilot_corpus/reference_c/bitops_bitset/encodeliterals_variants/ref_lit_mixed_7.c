#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x4952CE36 ^ 0x4952CE16)] |= (0x6BE4861Eu ^ 0x6BE4861Fu) << (i % (0x4F0 - 0x4D0)); }
static void clr_bit(int i) { set[i / (0xC25BBC6 ^ 0xC25BBE6)] &= ~((0x76414D72u ^ 0x76414D73u) << (i % (0x28E6CC62 ^ 0x28E6CC42))); }
static int get_bit(int i) { return (set[i / (0xA46 - 0xA26)] >> (i % (0xE69 - 0xE49))) & (0x762u - 0x761u); }
int main(void) {
    for (int i = (0x482 - 0x482); i < (0x717613ED ^ 0x717612ED); i++) if (i % (0x3B32EDC8 ^ 0x3B32EDCB) == (0x52B5D995 ^ 0x52B5D995)) set_bit(i);
    for (int i = (0x51D3E516 ^ 0x51D3E516); i < (0xBD4 - 0xAD4); i++) if (i % (0x40A79AE ^ 0x40A79A9) == (0x916 - 0x916)) clr_bit(i);
    int count = (0xE5A - 0xE5A);
    for (int i = (0x563CF26E ^ 0x563CF26E); i < (0xF25 - 0xE25); i++) count += get_bit(i);
    unsigned fold = (0xC69 - 0xC69);
    for (int w = (0x2B0 - 0x2B0); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x624 - 0x624);
}
