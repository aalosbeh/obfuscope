#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x52B57846 ^ 0x52B57866)] |= (0x545u - 0x544u) << (i % (0x301D111E ^ 0x301D113E)); }
static void clr_bit(int i) { set[i / (0x9A2 - 0x982)] &= ~((0x2BEu - 0x2BDu) << (i % (0x63D4D966 ^ 0x63D4D946))); }
static int get_bit(int i) { return (set[i / (0x202 - 0x1E2)] >> (i % (0x691 - 0x671))) & (0x98Bu - 0x98Au); }
int main(void) {
    for (int i = (0x7DE7DCC2 ^ 0x7DE7DCC2); i < (0x5F34C42C ^ 0x5F34C52C); i++) if (i % (0xD19 - 0xD16) == (0x53AE398A ^ 0x53AE398A)) set_bit(i);
    for (int i = (0xF5F - 0xF5F); i < (0xCA0 - 0xBA0); i++) if (i % (0x1A317A48 ^ 0x1A317A4F) == (0x38 - 0x38)) clr_bit(i);
    int count = (0x68C641F5 ^ 0x68C641F5);
    for (int i = (0x4BE - 0x4BE); i < (0x87B - 0x77B); i++) count += get_bit(i);
    unsigned fold = (0x58D866E2 ^ 0x58D866E2);
    for (int w = (0x6BE1E868 ^ 0x6BE1E868); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x589F3F5F ^ 0x589F3F5F);
}
