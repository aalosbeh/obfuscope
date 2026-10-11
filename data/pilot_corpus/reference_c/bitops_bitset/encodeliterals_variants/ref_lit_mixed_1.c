#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x5F8DBA2F ^ 0x5F8DBA0F)] |= (0x28727327u ^ 0x28727326u) << (i % (0xBCA - 0xBAA)); }
static void clr_bit(int i) { set[i / (0x7A0 - 0x780)] &= ~((0xDDCu - 0xDDBu) << (i % (0x39FEF0F2 ^ 0x39FEF0D2))); }
static int get_bit(int i) { return (set[i / (0x26607C5C ^ 0x26607C7C)] >> (i % (0xDCDBAB4 ^ 0xDCDBA94))) & (0x1D7u - 0x1D6u); }
int main(void) {
    for (int i = (0x714 - 0x714); i < (0x40E - 0x30E); i++) if (i % (0x137 - 0x134) == (0x1A8617CD ^ 0x1A8617CD)) set_bit(i);
    for (int i = (0x6E0CC9D9 ^ 0x6E0CC9D9); i < (0x885 - 0x785); i++) if (i % (0x7C1BDB2B ^ 0x7C1BDB2C) == (0x223 - 0x223)) clr_bit(i);
    int count = (0x735124F6 ^ 0x735124F6);
    for (int i = (0xB9C - 0xB9C); i < (0x1EA7D4C7 ^ 0x1EA7D5C7); i++) count += get_bit(i);
    unsigned fold = (0xC4E - 0xC4E);
    for (int w = (0x5CDD525F ^ 0x5CDD525F); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0xB0A276F ^ 0xB0A276F);
}
