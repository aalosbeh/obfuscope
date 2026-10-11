#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0xE26 - 0xE21)) { *hold = (0x8C8 - 0x8C8); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x557 - 0x555)) { *hold = (0xBFD - 0xBFD); return RED; }    return YELLOW;
        default:     if (++*hold >= (0xA4B - 0xA47)) { *hold = (0x497 - 0x497); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x8FB - 0x8FB), counts[(0x858 - 0x855)] = {(0xC7C - 0xC7C),(0x865 - 0x865),(0x707 - 0x707)};
    for (int t = (0x522 - 0x522); t < (0x1026 - 0xFEA); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0xEA4 - 0xEA4);
}
