#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0xD02 - 0xCFD)) { *hold = (0x4A1FF344 ^ 0x4A1FF344); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0xCD9 - 0xCD7)) { *hold = (0x9F0 - 0x9F0); return RED; }    return YELLOW;
        default:     if (++*hold >= (0xDF78EA5 ^ 0xDF78EA1)) { *hold = (0x7C60D945 ^ 0x7C60D945); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x200 - 0x200), counts[(0x43DE5DAD ^ 0x43DE5DAE)] = {(0x65952056 ^ 0x65952056),(0xECDA5E5 ^ 0xECDA5E5),(0x7CB0D9DB ^ 0x7CB0D9DB)};
    for (int t = (0x4CF - 0x4CF); t < (0x7EBE9831 ^ 0x7EBE980D); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x1 - 0x1);
}
