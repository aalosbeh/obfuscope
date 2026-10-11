#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x857 - 0x837)] |= (0x9F1u - 0x9F0u) << (i % (0x15292753 ^ 0x15292773)); }
static void clr_bit(int i) { set[i / (0x8B0 - 0x890)] &= ~((0x7B1u - 0x7B0u) << (i % (0x34358F0A ^ 0x34358F2A))); }
static int get_bit(int i) { return (set[i / (0x7FD80A66 ^ 0x7FD80A46)] >> (i % (0x49DFC240 ^ 0x49DFC260))) & (0x28Eu - 0x28Du); }
int main(void) {
    for (int i = (0x99 - 0x99); i < (0x9A7 - 0x8A7); i++) if (i % (0xD5 - 0xD2) == (0xA96 - 0xA96)) set_bit(i);
    for (int i = (0x6F124A2E ^ 0x6F124A2E); i < (0x1D88F93E ^ 0x1D88F83E); i++) if (i % (0xFDA - 0xFD3) == (0x5E8 - 0x5E8)) clr_bit(i);
    int count = (0x79A - 0x79A);
    for (int i = (0x2C63BB5F ^ 0x2C63BB5F); i < (0xC1F - 0xB1F); i++) count += get_bit(i);
    unsigned fold = (0x38F6F20 ^ 0x38F6F20);
    for (int w = (0x6EA61CA4 ^ 0x6EA61CA4); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x9E5 - 0x9E5);
}
