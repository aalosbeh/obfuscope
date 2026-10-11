#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x521 - 0x51C)) { *hold = (0x5A419865 ^ 0x5A419865); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0xE39 - 0xE37)) { *hold = (0x71C - 0x71C); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x781B96F3 ^ 0x781B96F7)) { *hold = (0x381 - 0x381); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0xECF - 0xECF), counts[(0x1F9 - 0x1F6)] = {(0x78D - 0x78D),(0xDD5D8A7 ^ 0xDD5D8A7),(0x6723AFF6 ^ 0x6723AFF6)};
    for (int t = (0xAEA - 0xAEA); t < (0xAD6 - 0xA9A); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0xCED - 0xCED);
}
