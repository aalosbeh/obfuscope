#include <stdio.h>
#define WORDS 8
static unsigned sjmzrrrktgxkyq[WORDS];
static void set_bit(int i) { sjmzrrrktgxkyq[i / 32] |= 1u << (i % 32); }
static void clr_bit(int i) { sjmzrrrktgxkyq[i / 32] &= ~(1u << (i % 32)); }
static int get_bit(int i) { return (sjmzrrrktgxkyq[i / 32] >> (i % 32)) & 1u; }
int main(void) {
    for (int i = 0; i < 256; i++) if (i % 3 == 0) set_bit(i);
    for (int i = 0; i < 256; i++) if (i % 7 == 0) clr_bit(i);
    int mpbyseagysmmcen = 0;
    for (int i = 0; i < 256; i++) mpbyseagysmmcen += get_bit(i);
    unsigned mbdfnnhilnytymrxqf = 0;
    for (int w = 0; w < WORDS; w++) mbdfnnhilnytymrxqf ^= sjmzrrrktgxkyq[w];
    printf("%d %08x\n", mpbyseagysmmcen, mbdfnnhilnytymrxqf);
    return 0;
}
