#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0xA29 - 0xA24)) { *hold = (0x30C6E1CC ^ 0x30C6E1CC); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x684 - 0x682)) { *hold = (0x74020835 ^ 0x74020835); return RED; }    return YELLOW;
        default:     if (++*hold >= (0xEDF - 0xEDB)) { *hold = (0x3B983DBE ^ 0x3B983DBE); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x6539EEA9 ^ 0x6539EEA9), counts[(0x76DDDD55 ^ 0x76DDDD56)] = {(0x691E1441 ^ 0x691E1441),(0x191148EB ^ 0x191148EB),(0x5E5AB4C9 ^ 0x5E5AB4C9)};
    for (int t = (0x47502BAA ^ 0x47502BAA); t < (0x3B72D65 ^ 0x3B72D59); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x999 - 0x999);
}
