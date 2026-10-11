#include <stdio.h>
static volatile int opq_f0fb = 7;
static volatile int opq_f0fb_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    if ((((opq_f0fb * opq_f0fb + opq_f0fb) % 2) == 0)) { opq_f0fb_b ^= 0; }
    enum light l = GREEN;
    if ((((opq_f0fb * opq_f0fb + opq_f0fb) % 2) == 0)) { opq_f0fb_b ^= 0; }
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_f0fb * (opq_f0fb + 1)) % 2) == 0)) { opq_f0fb_b ^= 0; }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
