#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x3DD2E7C3 ^ 0x3DD2E7C6)) { *hold = (0x2FBB49F9 ^ 0x2FBB49F9); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x7F080215 ^ 0x7F080217)) { *hold = (0x6A7388D9 ^ 0x6A7388D9); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x240219E8 ^ 0x240219EC)) { *hold = (0x4504CD8D ^ 0x4504CD8D); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x4FA9672D ^ 0x4FA9672D), counts[(0x52A0A26A ^ 0x52A0A269)] = {(0x4B3466E ^ 0x4B3466E),(0x34D26439 ^ 0x34D26439),(0x46CDF043 ^ 0x46CDF043)};
    for (int t = (0x6888C4B9 ^ 0x6888C4B9); t < (0x73A56FDF ^ 0x73A56FE3); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x608FA7D8 ^ 0x608FA7D8);
}
