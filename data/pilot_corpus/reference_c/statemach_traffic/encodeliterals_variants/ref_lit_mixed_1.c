#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x14C3F5BA ^ 0x14C3F5BF)) { *hold = (0xB1B - 0xB1B); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x6B85BEB3 ^ 0x6B85BEB1)) { *hold = (0x5F4 - 0x5F4); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x1C308169 ^ 0x1C30816D)) { *hold = (0xE25 - 0xE25); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x3496F01A ^ 0x3496F01A), counts[(0x42AAFB38 ^ 0x42AAFB3B)] = {(0xEE5 - 0xEE5),(0xD42 - 0xD42),(0x4C4503CE ^ 0x4C4503CE)};
    for (int t = (0x55D1EB5F ^ 0x55D1EB5F); t < (0x52414999 ^ 0x524149A5); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x55 - 0x55);
}
