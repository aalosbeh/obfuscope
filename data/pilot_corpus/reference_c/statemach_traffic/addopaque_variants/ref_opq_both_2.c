#include <stdio.h>
static volatile int opq_e511 = 7;
static volatile int opq_e511_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        if ((((opq_e511 * opq_e511 + opq_e511_b * opq_e511_b) % 4) == 3)) {
            { int jv_d6f8c = opq_e511 ^ 0xC9F8;
                jv_d6f8c = (jv_d6f8c * 0x35) % 0x7FFFFFFF;
                jv_d6f8c ^= (jv_d6f8c << 3) | 0xE4F4;
              (void)jv_d6f8c; }
        }
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_e511 * (opq_e511 + 1)) % 2) == 0)) { opq_e511_b ^= 0; }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    if ((((opq_e511 * (opq_e511 + 1)) % 2) == 0)) { opq_e511_b ^= 0; }
    return 0;
}
