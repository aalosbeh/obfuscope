#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *yjaltxdwmmnminbvcoo) {
    switch (l) {
        case GREEN:  if (++*yjaltxdwmmnminbvcoo >= 5) { *yjaltxdwmmnminbvcoo = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*yjaltxdwmmnminbvcoo >= 2) { *yjaltxdwmmnminbvcoo = 0; return RED; }    return YELLOW;
        default:     if (++*yjaltxdwmmnminbvcoo >= 4) { *yjaltxdwmmnminbvcoo = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int yjaltxdwmmnminbvcoo = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &yjaltxdwmmnminbvcoo); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
