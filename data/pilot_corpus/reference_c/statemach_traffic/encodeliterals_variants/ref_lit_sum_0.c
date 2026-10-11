#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x286 - 0x281)) { *hold = (0xD17 - 0xD17); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x8F8 - 0x8F6)) { *hold = (0xC13 - 0xC13); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x3A - 0x36)) { *hold = (0x80A - 0x80A); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x8BE - 0x8BE), counts[(0xE78 - 0xE75)] = {(0xA47 - 0xA47),(0xB7C - 0xB7C),(0x5E7 - 0x5E7)};
    for (int t = (0x5EE - 0x5EE); t < (0x8C5 - 0x889); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x20F - 0x20F);
}
