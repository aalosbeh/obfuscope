#include <stdio.h>
static volatile int opq_7399 = 7;
static volatile int opq_7399_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    if ((((opq_7399 * opq_7399 + opq_7399_b * opq_7399_b) % 4) == 3)) {
        { int jv_bbe76 = opq_7399 ^ 0xE301;
            jv_bbe76 ^= (jv_bbe76 << 3) | 0x3EFA;
          (void)jv_bbe76; }
    }
    switch (l) {
        if ((((opq_7399 * opq_7399 + opq_7399_b * opq_7399_b) % 4) == 3)) {
            { int jv_1f075 = opq_7399 ^ 0x9E20;
                jv_1f075 += (jv_1f075 >> 2) + 0x17;
                jv_1f075 ^= (jv_1f075 << 3) | 0xA91D;
              (void)jv_1f075; }
        }
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_7399 * opq_7399) % 4) == 2)) {
        { int jv_593cc = opq_7399 ^ 0x11A3;
            jv_593cc = (jv_593cc * 0x1A) % 0x7FFFFFFF;
            jv_593cc += (jv_593cc >> 2) + 0x55;
            jv_593cc ^= (jv_593cc << 3) | 0x96EA;
          (void)jv_593cc; }
    }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
