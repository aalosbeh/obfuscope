#include <stdio.h>
static volatile int opq_9fc3 = 7;
static volatile int opq_9fc3_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    if ((((opq_9fc3 * (opq_9fc3 + 1)) % 2) == 0)) { opq_9fc3_b ^= 0; }
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_9fc3 * (opq_9fc3 + 1)) % 2) == 0)) { opq_9fc3_b ^= 0; }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    if ((((opq_9fc3 * opq_9fc3) % 4) == 2)) {
        { int jv_5f61d = opq_9fc3 ^ 0x3477;
            jv_5f61d += (jv_5f61d >> 2) + 0xB;
          (void)jv_5f61d; }
    }
    return 0;
}
