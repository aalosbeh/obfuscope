#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x79DF6BAD ^ 0x79DF6B8D)] |= (0x912u - 0x911u) << (i % (0x43DD5D50 ^ 0x43DD5D70)); }
static void clr_bit(int i) { set[i / (0x28AE3F81 ^ 0x28AE3FA1)] &= ~((0x77FE3066u ^ 0x77FE3067u) << (i % (0x7B72078D ^ 0x7B7207AD))); }
static int get_bit(int i) { return (set[i / (0xCD6 - 0xCB6)] >> (i % (0x28F1089D ^ 0x28F108BD))) & (0x13A37E11u ^ 0x13A37E10u); }
int main(void) {
    for (int i = (0x35F550A6 ^ 0x35F550A6); i < (0x2FCE5D37 ^ 0x2FCE5C37); i++) if (i % (0xE44 - 0xE41) == (0x53C5F3BC ^ 0x53C5F3BC)) set_bit(i);
    for (int i = (0x1214360A ^ 0x1214360A); i < (0xB1E - 0xA1E); i++) if (i % (0x41C52EB2 ^ 0x41C52EB5) == (0xB83 - 0xB83)) clr_bit(i);
    int count = (0x18EF6CE ^ 0x18EF6CE);
    for (int i = (0x4D8D8B29 ^ 0x4D8D8B29); i < (0x37031B1A ^ 0x37031A1A); i++) count += get_bit(i);
    unsigned fold = (0x99 - 0x99);
    for (int w = (0x802 - 0x802); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0xA23 - 0xA23);
}
