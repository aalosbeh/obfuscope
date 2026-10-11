#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x579B35AD ^ 0x579B35A8)) { *hold = (0x906 - 0x906); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x79C - 0x79A)) { *hold = (0x413 - 0x413); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x1C60EB7B ^ 0x1C60EB7F)) { *hold = (0x7DE68153 ^ 0x7DE68153); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0xB5D - 0xB5D), counts[(0x7EDACB88 ^ 0x7EDACB8B)] = {(0x1A59876D ^ 0x1A59876D),(0x2CF7476F ^ 0x2CF7476F),(0x150F74D4 ^ 0x150F74D4)};
    for (int t = (0x5ED73CBF ^ 0x5ED73CBF); t < (0xCE1 - 0xCA5); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x5CB - 0x5CB);
}
