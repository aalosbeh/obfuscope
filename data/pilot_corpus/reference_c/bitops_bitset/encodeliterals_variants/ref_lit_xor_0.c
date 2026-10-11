#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x6485110F ^ 0x6485112F)] |= (0x498A218Au ^ 0x498A218Bu) << (i % (0x47D00D9E ^ 0x47D00DBE)); }
static void clr_bit(int i) { set[i / (0x362E25E5 ^ 0x362E25C5)] &= ~((0x39D198B6u ^ 0x39D198B7u) << (i % (0x2EFEDA72 ^ 0x2EFEDA52))); }
static int get_bit(int i) { return (set[i / (0x48889373 ^ 0x48889353)] >> (i % (0x878B1B2 ^ 0x878B192))) & (0x28E887A6u ^ 0x28E887A7u); }
int main(void) {
    for (int i = (0x6881378 ^ 0x6881378); i < (0x54AE52C9 ^ 0x54AE53C9); i++) if (i % (0x770B2678 ^ 0x770B267B) == (0x79C09596 ^ 0x79C09596)) set_bit(i);
    for (int i = (0x4CFA29AC ^ 0x4CFA29AC); i < (0x1945DAD7 ^ 0x1945DBD7); i++) if (i % (0x2366524 ^ 0x2366523) == (0x45A56F7 ^ 0x45A56F7)) clr_bit(i);
    int count = (0x423661F7 ^ 0x423661F7);
    for (int i = (0x618A4DC7 ^ 0x618A4DC7); i < (0xD197AAE ^ 0xD197BAE); i++) count += get_bit(i);
    unsigned fold = (0x1050169B ^ 0x1050169B);
    for (int w = (0x57168F08 ^ 0x57168F08); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x32BD814A ^ 0x32BD814A);
}
