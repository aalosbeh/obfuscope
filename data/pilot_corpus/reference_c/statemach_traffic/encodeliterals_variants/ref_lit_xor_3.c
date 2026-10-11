#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x2EC91769 ^ 0x2EC9176C)) { *hold = (0x5B7D7722 ^ 0x5B7D7722); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x4EEA31 ^ 0x4EEA33)) { *hold = (0x71A2DB44 ^ 0x71A2DB44); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x40C34DD4 ^ 0x40C34DD0)) { *hold = (0x3B7197B3 ^ 0x3B7197B3); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x2CF345DC ^ 0x2CF345DC), counts[(0x598AE3B9 ^ 0x598AE3BA)] = {(0x761B6B34 ^ 0x761B6B34),(0x3A650226 ^ 0x3A650226),(0xC73F047 ^ 0xC73F047)};
    for (int t = (0x656B65F6 ^ 0x656B65F6); t < (0xADF1BB8 ^ 0xADF1B84); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x525E8C7 ^ 0x525E8C7);
}
