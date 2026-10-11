#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x40631E70 ^ 0x40631E50)] |= (0x17115C43u ^ 0x17115C42u) << (i % (0x522B8095 ^ 0x522B80B5)); }
static void clr_bit(int i) { set[i / (0x3A923B3F ^ 0x3A923B1F)] &= ~((0x7CCA11FCu ^ 0x7CCA11FDu) << (i % (0x21623FAD ^ 0x21623F8D))); }
static int get_bit(int i) { return (set[i / (0x2769ECEA ^ 0x2769ECCA)] >> (i % (0x17B9510B ^ 0x17B9512B))) & (0xDAADA1Du ^ 0xDAADA1Cu); }
int main(void) {
    for (int i = (0x5B9D40E6 ^ 0x5B9D40E6); i < (0x6D94D3A2 ^ 0x6D94D2A2); i++) if (i % (0x1C0ADEB7 ^ 0x1C0ADEB4) == (0x74D28995 ^ 0x74D28995)) set_bit(i);
    for (int i = (0x3387EA7D ^ 0x3387EA7D); i < (0x2EC2AB25 ^ 0x2EC2AA25); i++) if (i % (0x5A73F8CD ^ 0x5A73F8CA) == (0xB2BBBDE ^ 0xB2BBBDE)) clr_bit(i);
    int count = (0x48FD2191 ^ 0x48FD2191);
    for (int i = (0x2C064443 ^ 0x2C064443); i < (0x550808F5 ^ 0x550809F5); i++) count += get_bit(i);
    unsigned fold = (0x77E847D9 ^ 0x77E847D9);
    for (int w = (0x27D0518 ^ 0x27D0518); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x6631B018 ^ 0x6631B018);
}
