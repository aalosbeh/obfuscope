#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0xC53 - 0xC4E)) { *hold = (0x66D - 0x66D); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x6FB - 0x6F9)) { *hold = (0x37D - 0x37D); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x3CB - 0x3C7)) { *hold = (0x42F - 0x42F); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x6A9 - 0x6A9), counts[(0x37B - 0x378)] = {(0xF14 - 0xF14),(0xC9 - 0xC9),(0x874 - 0x874)};
    for (int t = (0x748 - 0x748); t < (0x2BD - 0x281); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x63 - 0x63);
}
