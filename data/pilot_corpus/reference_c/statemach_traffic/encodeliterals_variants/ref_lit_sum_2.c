#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0xD3B - 0xD36)) { *hold = (0x640 - 0x640); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x4B5 - 0x4B3)) { *hold = (0x8F4 - 0x8F4); return RED; }    return YELLOW;
        default:     if (++*hold >= (0xB29 - 0xB25)) { *hold = (0x16A - 0x16A); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x30E - 0x30E), counts[(0x196 - 0x193)] = {(0x278 - 0x278),(0x5C4 - 0x5C4),(0x4B8 - 0x4B8)};
    for (int t = (0x4CB - 0x4CB); t < (0x612 - 0x5D6); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x667 - 0x667);
}
