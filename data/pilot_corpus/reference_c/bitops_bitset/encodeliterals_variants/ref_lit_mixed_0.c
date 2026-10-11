#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x4B3 - 0x493)] |= (0x760DB96Du ^ 0x760DB96Cu) << (i % (0x20D03BCD ^ 0x20D03BED)); }
static void clr_bit(int i) { set[i / (0x1A900538 ^ 0x1A900518)] &= ~((0x79Cu - 0x79Bu) << (i % (0x1F55B204 ^ 0x1F55B224))); }
static int get_bit(int i) { return (set[i / (0x405 - 0x3E5)] >> (i % (0x67B - 0x65B))) & (0x625u - 0x624u); }
int main(void) {
    for (int i = (0x17FEFAE1 ^ 0x17FEFAE1); i < (0x37A - 0x27A); i++) if (i % (0x6EDE14E3 ^ 0x6EDE14E0) == (0x6DE13E68 ^ 0x6DE13E68)) set_bit(i);
    for (int i = (0x647 - 0x647); i < (0x2EB13C02 ^ 0x2EB13D02); i++) if (i % (0x1CD7C9E ^ 0x1CD7C99) == (0x196D38F0 ^ 0x196D38F0)) clr_bit(i);
    int count = (0x3B8 - 0x3B8);
    for (int i = (0x193 - 0x193); i < (0x6F500544 ^ 0x6F500444); i++) count += get_bit(i);
    unsigned fold = (0x6A7 - 0x6A7);
    for (int w = (0x5B401B21 ^ 0x5B401B21); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0xBFB - 0xBFB);
}
