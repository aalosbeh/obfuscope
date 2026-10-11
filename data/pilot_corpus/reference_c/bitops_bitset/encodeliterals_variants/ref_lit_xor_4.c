#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x6DCA8C4C ^ 0x6DCA8C6C)] |= (0x1AF3829Eu ^ 0x1AF3829Fu) << (i % (0x77151A77 ^ 0x77151A57)); }
static void clr_bit(int i) { set[i / (0x7AA4C70D ^ 0x7AA4C72D)] &= ~((0x45CFE830u ^ 0x45CFE831u) << (i % (0x7FB06822 ^ 0x7FB06802))); }
static int get_bit(int i) { return (set[i / (0x603647CA ^ 0x603647EA)] >> (i % (0x52BFBB16 ^ 0x52BFBB36))) & (0x2B6B6216u ^ 0x2B6B6217u); }
int main(void) {
    for (int i = (0x20EB495 ^ 0x20EB495); i < (0x22155D88 ^ 0x22155C88); i++) if (i % (0x25CC6BC3 ^ 0x25CC6BC0) == (0x4AE96883 ^ 0x4AE96883)) set_bit(i);
    for (int i = (0x5059C022 ^ 0x5059C022); i < (0x607A89E5 ^ 0x607A88E5); i++) if (i % (0x1E5CB69B ^ 0x1E5CB69C) == (0x7FB5E70B ^ 0x7FB5E70B)) clr_bit(i);
    int count = (0x2A4584B0 ^ 0x2A4584B0);
    for (int i = (0x2376247F ^ 0x2376247F); i < (0x6D60B77A ^ 0x6D60B67A); i++) count += get_bit(i);
    unsigned fold = (0x7C1CF0BC ^ 0x7C1CF0BC);
    for (int w = (0x5960DCF2 ^ 0x5960DCF2); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x1A83A70C ^ 0x1A83A70C);
}
