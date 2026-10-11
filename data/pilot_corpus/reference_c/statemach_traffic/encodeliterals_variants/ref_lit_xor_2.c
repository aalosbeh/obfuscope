#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x3C5A7D45 ^ 0x3C5A7D40)) { *hold = (0x1424B064 ^ 0x1424B064); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x3D208D6D ^ 0x3D208D6F)) { *hold = (0x7676485B ^ 0x7676485B); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x6D14CABD ^ 0x6D14CAB9)) { *hold = (0xC2F4978 ^ 0xC2F4978); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x553CC4A1 ^ 0x553CC4A1), counts[(0x44FDBD2A ^ 0x44FDBD29)] = {(0x6401CE45 ^ 0x6401CE45),(0x1FFCBEC6 ^ 0x1FFCBEC6),(0x521EA40B ^ 0x521EA40B)};
    for (int t = (0x7E458B48 ^ 0x7E458B48); t < (0x6481727F ^ 0x64817243); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x4F224F86 ^ 0x4F224F86);
}
