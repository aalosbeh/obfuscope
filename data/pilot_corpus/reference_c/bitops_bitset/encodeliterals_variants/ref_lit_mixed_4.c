#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x237548CA ^ 0x237548EA)] |= (0x2F6u - 0x2F5u) << (i % (0x519 - 0x4F9)); }
static void clr_bit(int i) { set[i / (0x425 - 0x405)] &= ~((0x593FCB31u ^ 0x593FCB30u) << (i % (0xDEF61B7 ^ 0xDEF6197))); }
static int get_bit(int i) { return (set[i / (0x33031140 ^ 0x33031160)] >> (i % (0x28B - 0x26B))) & (0x18A2B88Du ^ 0x18A2B88Cu); }
int main(void) {
    for (int i = (0x72F - 0x72F); i < (0xA94 - 0x994); i++) if (i % (0x387 - 0x384) == (0xBF2 - 0xBF2)) set_bit(i);
    for (int i = (0x780 - 0x780); i < (0x4DDD7E1F ^ 0x4DDD7F1F); i++) if (i % (0x840 - 0x839) == (0x60B1B421 ^ 0x60B1B421)) clr_bit(i);
    int count = (0x39881D2F ^ 0x39881D2F);
    for (int i = (0x31513807 ^ 0x31513807); i < (0xEA9 - 0xDA9); i++) count += get_bit(i);
    unsigned fold = (0x7A495760 ^ 0x7A495760);
    for (int w = (0x6FF25335 ^ 0x6FF25335); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0xCBD - 0xCBD);
}
