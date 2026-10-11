#include <stdio.h>
static volatile int opq_e474 = 7;
static volatile int opq_e474_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    if ((((opq_e474 * opq_e474) % 4) == 2)) {
        { int jv_443b0 = opq_e474 ^ 0xC51;
            jv_443b0 ^= (jv_443b0 << 3) | 0x7089;
            jv_443b0 += (jv_443b0 >> 2) + 0xE;
            jv_443b0 = (jv_443b0 * 0x1C) % 0x7FFFFFFF;
          (void)jv_443b0; }
    }
    enum light l = GREEN;
    if ((((opq_e474 * opq_e474) % 4) == 2)) {
        { int jv_669e9 = opq_e474 ^ 0x8DFE;
            jv_669e9 = (jv_669e9 * 0x36) % 0x7FFFFFFF;
            jv_669e9 += (jv_669e9 >> 2) + 0x18;
            jv_669e9 ^= (jv_669e9 << 3) | 0xDA4D;
          (void)jv_669e9; }
    }
    int hold = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    if ((((opq_e474 * opq_e474 + opq_e474_b * opq_e474_b) % 4) == 3)) {
        { int jv_4cd50 = opq_e474 ^ 0x6775;
            jv_4cd50 += (jv_4cd50 >> 2) + 0xD;
            jv_4cd50 = (jv_4cd50 * 0x2C) % 0x7FFFFFFF;
            jv_4cd50 ^= (jv_4cd50 << 3) | 0x5122;
          (void)jv_4cd50; }
    }
    return 0;
}
