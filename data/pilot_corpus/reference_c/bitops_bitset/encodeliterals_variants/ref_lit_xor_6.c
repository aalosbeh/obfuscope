#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x4D3E5AF4 ^ 0x4D3E5AD4)] |= (0x2C1F2F00u ^ 0x2C1F2F01u) << (i % (0x76D434F9 ^ 0x76D434D9)); }
static void clr_bit(int i) { set[i / (0x61642784 ^ 0x616427A4)] &= ~((0x3BB709Eu ^ 0x3BB709Fu) << (i % (0x637F13A8 ^ 0x637F1388))); }
static int get_bit(int i) { return (set[i / (0x13BED444 ^ 0x13BED464)] >> (i % (0xF6601C4 ^ 0xF6601E4))) & (0x4D4E3F4Cu ^ 0x4D4E3F4Du); }
int main(void) {
    for (int i = (0x37D722F2 ^ 0x37D722F2); i < (0x750812D6 ^ 0x750813D6); i++) if (i % (0x62272F1B ^ 0x62272F18) == (0x2F8356B0 ^ 0x2F8356B0)) set_bit(i);
    for (int i = (0x5D490501 ^ 0x5D490501); i < (0x5B6BD9A5 ^ 0x5B6BD8A5); i++) if (i % (0x250D4A9C ^ 0x250D4A9B) == (0x70E34DA1 ^ 0x70E34DA1)) clr_bit(i);
    int count = (0x6FF7CDFF ^ 0x6FF7CDFF);
    for (int i = (0x72E3B0BD ^ 0x72E3B0BD); i < (0x27656639 ^ 0x27656739); i++) count += get_bit(i);
    unsigned fold = (0x215AB3BD ^ 0x215AB3BD);
    for (int w = (0x3B5AE63E ^ 0x3B5AE63E); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x1735657C ^ 0x1735657C);
}
