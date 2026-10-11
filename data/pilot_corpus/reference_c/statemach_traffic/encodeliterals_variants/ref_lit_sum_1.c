#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x85 - 0x80)) { *hold = (0x7A6 - 0x7A6); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x4D4 - 0x4D2)) { *hold = (0xE05 - 0xE05); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x640 - 0x63C)) { *hold = (0xA4F - 0xA4F); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x645 - 0x645), counts[(0x736 - 0x733)] = {(0x50E - 0x50E),(0x850 - 0x850),(0x93D - 0x93D)};
    for (int t = (0x124 - 0x124); t < (0xFCD - 0xF91); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0xFEA - 0xFEA);
}
