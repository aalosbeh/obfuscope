#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x1C3A114E ^ 0x1C3A116E)] |= (0xA72D7EFu ^ 0xA72D7EEu) << (i % (0x5BD7CE36 ^ 0x5BD7CE16)); }
static void clr_bit(int i) { set[i / (0x4B6 - 0x496)] &= ~((0xEDBu - 0xEDAu) << (i % (0x1AA66737 ^ 0x1AA66717))); }
static int get_bit(int i) { return (set[i / (0x5EB212F0 ^ 0x5EB212D0)] >> (i % (0xBB0 - 0xB90))) & (0x18Bu - 0x18Au); }
int main(void) {
    for (int i = (0x90A - 0x90A); i < (0x22A - 0x12A); i++) if (i % (0x1FB - 0x1F8) == (0x628 - 0x628)) set_bit(i);
    for (int i = (0x3300731E ^ 0x3300731E); i < (0x40CE0CEE ^ 0x40CE0DEE); i++) if (i % (0x1967E609 ^ 0x1967E60E) == (0x919 - 0x919)) clr_bit(i);
    int count = (0x710 - 0x710);
    for (int i = (0x1AFAC98A ^ 0x1AFAC98A); i < (0x3A9A12EB ^ 0x3A9A13EB); i++) count += get_bit(i);
    unsigned fold = (0x26EB5EE1 ^ 0x26EB5EE1);
    for (int w = (0x6C7FB500 ^ 0x6C7FB500); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x36B - 0x36B);
}
