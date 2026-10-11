#include <stdio.h>
static volatile int opq_5c5d = 7;
static volatile int opq_5c5d_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        if ((((opq_5c5d * opq_5c5d) % 4) == 2)) {
            { int jv_950ca = opq_5c5d ^ 0xDD47;
                jv_950ca += (jv_950ca >> 2) + 0x61;
                jv_950ca ^= (jv_950ca << 3) | 0x895D;
                jv_950ca = (jv_950ca * 0x8) % 0x7FFFFFFF;
              (void)jv_950ca; }
        }
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_5c5d * opq_5c5d + opq_5c5d_b * opq_5c5d_b) % 4) == 3)) {
        { int jv_7ad28 = opq_5c5d ^ 0xF44F;
            jv_7ad28 += (jv_7ad28 >> 2) + 0x6F;
            jv_7ad28 = (jv_7ad28 * 0x6) % 0x7FFFFFFF;
          (void)jv_7ad28; }
    }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    if ((((opq_5c5d * opq_5c5d) % 4) == 2)) {
        { int jv_fa04c = opq_5c5d ^ 0x8E33;
            jv_fa04c ^= (jv_fa04c << 3) | 0x92CD;
            jv_fa04c += (jv_fa04c >> 2) + 0x78;
          (void)jv_fa04c; }
    }
    return 0;
}
