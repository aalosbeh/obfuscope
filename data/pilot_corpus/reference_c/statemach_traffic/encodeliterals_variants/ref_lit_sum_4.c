#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0xA26 - 0xA21)) { *hold = (0xD7B - 0xD7B); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x4A8 - 0x4A6)) { *hold = (0x3AB - 0x3AB); return RED; }    return YELLOW;
        default:     if (++*hold >= (0xC47 - 0xC43)) { *hold = (0xB0A - 0xB0A); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x39E - 0x39E), counts[(0x6F4 - 0x6F1)] = {(0x442 - 0x442),(0xE21 - 0xE21),(0xD8C - 0xD8C)};
    for (int t = (0x2EE - 0x2EE); t < (0x29A - 0x25E); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x97E - 0x97E);
}
