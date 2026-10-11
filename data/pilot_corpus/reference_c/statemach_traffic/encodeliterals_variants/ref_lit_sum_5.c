#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0xF1F - 0xF1A)) { *hold = (0x722 - 0x722); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x1B9 - 0x1B7)) { *hold = (0x61E - 0x61E); return RED; }    return YELLOW;
        default:     if (++*hold >= (0xD48 - 0xD44)) { *hold = (0x622 - 0x622); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x395 - 0x395), counts[(0xD01 - 0xCFE)] = {(0xAA - 0xAA),(0x5DD - 0x5DD),(0x94B - 0x94B)};
    for (int t = (0x573 - 0x573); t < (0xF8E - 0xF52); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0xEDE - 0xEDE);
}
