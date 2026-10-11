#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x6D52E9D6 ^ 0x6D52E9F6)] |= (0x2C0585Au ^ 0x2C0585Bu) << (i % (0x3A29A2A5 ^ 0x3A29A285)); }
static void clr_bit(int i) { set[i / (0x47914EF6 ^ 0x47914ED6)] &= ~((0x59FF41FDu ^ 0x59FF41FCu) << (i % (0x708138EE ^ 0x708138CE))); }
static int get_bit(int i) { return (set[i / (0x196EC5F7 ^ 0x196EC5D7)] >> (i % (0x3CED76AC ^ 0x3CED768C))) & (0x4D052055u ^ 0x4D052054u); }
int main(void) {
    for (int i = (0x3ADDD9B5 ^ 0x3ADDD9B5); i < (0x721B3E6C ^ 0x721B3F6C); i++) if (i % (0x15A18F22 ^ 0x15A18F21) == (0x4341C575 ^ 0x4341C575)) set_bit(i);
    for (int i = (0x62C8136D ^ 0x62C8136D); i < (0x3FC79CD5 ^ 0x3FC79DD5); i++) if (i % (0x7FBD284E ^ 0x7FBD2849) == (0x131E2021 ^ 0x131E2021)) clr_bit(i);
    int count = (0x1F286CA ^ 0x1F286CA);
    for (int i = (0x3D3393D ^ 0x3D3393D); i < (0x3F535F03 ^ 0x3F535E03); i++) count += get_bit(i);
    unsigned fold = (0x6590F469 ^ 0x6590F469);
    for (int w = (0x2C04D33B ^ 0x2C04D33B); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x2A1CD8E2 ^ 0x2A1CD8E2);
}
