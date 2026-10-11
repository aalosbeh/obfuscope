#include <stdio.h>
static volatile int opq_69bc = 7;
static volatile int opq_69bc_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    if (((opq_69bc * opq_69bc - opq_69bc) % 2 == 0)) { opq_69bc_b ^= 0; }
    switch (l) {
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    if ((((opq_69bc * opq_69bc + opq_69bc_b * opq_69bc_b) % 4) == 3)) {
        { int jv_1e155 = opq_69bc ^ 0x3503;
            jv_1e155 ^= (jv_1e155 << 3) | 0xA62C;
          (void)jv_1e155; }
    }
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_69bc * opq_69bc + opq_69bc) % 2) == 0)) { opq_69bc_b ^= 0; }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
