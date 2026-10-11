#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x9B64DCA ^ 0x9B64DCF)) { *hold = (0x54ABBB6A ^ 0x54ABBB6A); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x3CE32B0 ^ 0x3CE32B2)) { *hold = (0x51A4BFB6 ^ 0x51A4BFB6); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x6040A4A8 ^ 0x6040A4AC)) { *hold = (0x1EF31F4E ^ 0x1EF31F4E); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0xF32D680 ^ 0xF32D680), counts[(0x1E4355B6 ^ 0x1E4355B5)] = {(0x68CA89B9 ^ 0x68CA89B9),(0x7997BE44 ^ 0x7997BE44),(0x52CD232E ^ 0x52CD232E)};
    for (int t = (0x47477CAA ^ 0x47477CAA); t < (0x1C3D08DA ^ 0x1C3D08E6); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x3A1BB09 ^ 0x3A1BB09);
}
