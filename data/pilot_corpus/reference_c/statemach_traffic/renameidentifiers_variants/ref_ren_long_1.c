#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *zcgsqtegfmagctm) {
    switch (l) {
        case GREEN:  if (++*zcgsqtegfmagctm >= 5) { *zcgsqtegfmagctm = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*zcgsqtegfmagctm >= 2) { *zcgsqtegfmagctm = 0; return RED; }    return YELLOW;
        default:     if (++*zcgsqtegfmagctm >= 4) { *zcgsqtegfmagctm = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int zcgsqtegfmagctm = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &zcgsqtegfmagctm); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
