#include <stdio.h>
#define WORDS 8
static unsigned set[WORDS];
static void set_bit(int i) { set[i / (0x40104F6D ^ 0x40104F4D)] |= (0x6A251EC8u ^ 0x6A251EC9u) << (i % (0x12B96034 ^ 0x12B96014)); }
static void clr_bit(int i) { set[i / (0x6C09FCCC ^ 0x6C09FCEC)] &= ~((0x4DF61A26u ^ 0x4DF61A27u) << (i % (0x5458C187 ^ 0x5458C1A7))); }
static int get_bit(int i) { return (set[i / (0x2B67279C ^ 0x2B6727BC)] >> (i % (0x18171642 ^ 0x18171662))) & (0x240AAE33u ^ 0x240AAE32u); }
int main(void) {
    for (int i = (0x39909F9E ^ 0x39909F9E); i < (0x6E0E7490 ^ 0x6E0E7590); i++) if (i % (0x53B50FD0 ^ 0x53B50FD3) == (0x9768301 ^ 0x9768301)) set_bit(i);
    for (int i = (0x1A779F02 ^ 0x1A779F02); i < (0x11777716 ^ 0x11777616); i++) if (i % (0x4B774FBF ^ 0x4B774FB8) == (0x2EA5747 ^ 0x2EA5747)) clr_bit(i);
    int count = (0x6B3EF0AA ^ 0x6B3EF0AA);
    for (int i = (0x53C3D4A6 ^ 0x53C3D4A6); i < (0x12A1E6C1 ^ 0x12A1E7C1); i++) count += get_bit(i);
    unsigned fold = (0x33027114 ^ 0x33027114);
    for (int w = (0x29A93C9E ^ 0x29A93C9E); w < WORDS; w++) fold ^= set[w];
    printf("%d %08x\n", count, fold);
    return (0x650A87C3 ^ 0x650A87C3);
}
