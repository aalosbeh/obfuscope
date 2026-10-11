#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x93F1461 ^ 0x93F1464)) { *hold = (0xF04 - 0xF04); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x27438B3E ^ 0x27438B3C)) { *hold = (0xE9A - 0xE9A); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x3A8 - 0x3A4)) { *hold = (0x383FE56E ^ 0x383FE56E); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0xA54 - 0xA54), counts[(0x394FA53A ^ 0x394FA539)] = {(0x11FF5C2C ^ 0x11FF5C2C),(0xF16 - 0xF16),(0x41EC6096 ^ 0x41EC6096)};
    for (int t = (0x73DC042E ^ 0x73DC042E); t < (0x171 - 0x135); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x6FD - 0x6FD);
}
