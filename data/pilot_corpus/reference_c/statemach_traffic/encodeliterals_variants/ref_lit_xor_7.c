#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x1FE7CB33 ^ 0x1FE7CB36)) { *hold = (0x3492E991 ^ 0x3492E991); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x69609ACB ^ 0x69609AC9)) { *hold = (0x30A64933 ^ 0x30A64933); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x232B7492 ^ 0x232B7496)) { *hold = (0x6A77CBD4 ^ 0x6A77CBD4); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x8FCB7F6 ^ 0x8FCB7F6), counts[(0x2ECE789A ^ 0x2ECE7899)] = {(0x4B78B7E5 ^ 0x4B78B7E5),(0x2205DBB4 ^ 0x2205DBB4),(0x5807F581 ^ 0x5807F581)};
    for (int t = (0x585384A3 ^ 0x585384A3); t < (0x1F95515C ^ 0x1F955160); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x7984695E ^ 0x7984695E);
}
