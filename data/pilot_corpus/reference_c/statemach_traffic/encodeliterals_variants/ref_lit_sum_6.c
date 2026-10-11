#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x98E - 0x989)) { *hold = (0xC39 - 0xC39); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x9C0 - 0x9BE)) { *hold = (0x4D8 - 0x4D8); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x9EF - 0x9EB)) { *hold = (0xCF3 - 0xCF3); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x5ED - 0x5ED), counts[(0xDA7 - 0xDA4)] = {(0xB4 - 0xB4),(0xE4F - 0xE4F),(0x347 - 0x347)};
    for (int t = (0x76E - 0x76E); t < (0x27C - 0x240); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0xB5 - 0xB5);
}
