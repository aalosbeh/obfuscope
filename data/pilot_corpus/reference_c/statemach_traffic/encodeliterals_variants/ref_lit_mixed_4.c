#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0xB3E - 0xB39)) { *hold = (0x268 - 0x268); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0xFE1 - 0xFDF)) { *hold = (0xB0628A9 ^ 0xB0628A9); return RED; }    return YELLOW;
        default:     if (++*hold >= (0xCC7 - 0xCC3)) { *hold = (0x907 - 0x907); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x7C973624 ^ 0x7C973624), counts[(0x9A5 - 0x9A2)] = {(0x70716861 ^ 0x70716861),(0x3B3 - 0x3B3),(0x58CDCD7A ^ 0x58CDCD7A)};
    for (int t = (0x542 - 0x542); t < (0x4B72F0B4 ^ 0x4B72F088); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0xFE - 0xFE);
}
