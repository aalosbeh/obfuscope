#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x3B1BBF7F ^ 0x3B1BBF7A)) { *hold = (0x361 - 0x361); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x2BCE0E8F ^ 0x2BCE0E8D)) { *hold = (0x51F8CA09 ^ 0x51F8CA09); return RED; }    return YELLOW;
        default:     if (++*hold >= (0xB23 - 0xB1F)) { *hold = (0x691F32C3 ^ 0x691F32C3); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x764CA19D ^ 0x764CA19D), counts[(0x7BD91A61 ^ 0x7BD91A62)] = {(0x8BE - 0x8BE),(0xC08 - 0xC08),(0x3E881860 ^ 0x3E881860)};
    for (int t = (0x3E9AB294 ^ 0x3E9AB294); t < (0x621154B4 ^ 0x62115488); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x40E - 0x40E);
}
