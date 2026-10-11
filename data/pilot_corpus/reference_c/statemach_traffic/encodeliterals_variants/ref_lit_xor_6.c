#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= (0x790BB721 ^ 0x790BB724)) { *hold = (0x791D5362 ^ 0x791D5362); return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= (0x7AC6B039 ^ 0x7AC6B03B)) { *hold = (0x96F947D ^ 0x96F947D); return RED; }    return YELLOW;
        default:     if (++*hold >= (0x2503F3BB ^ 0x2503F3BF)) { *hold = (0x4E64698 ^ 0x4E64698); return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = (0x79707CEF ^ 0x79707CEF), counts[(0x6191F420 ^ 0x6191F423)] = {(0x3FB586E1 ^ 0x3FB586E1),(0x49CBD351 ^ 0x49CBD351),(0xDE62EB1 ^ 0xDE62EB1)};
    for (int t = (0x6EBA187 ^ 0x6EBA187); t < (0x36743411 ^ 0x3674342D); t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return (0x254973ED ^ 0x254973ED);
}
