#include <stdio.h>
static volatile int opq_7a55 = 7;
static volatile int opq_7a55_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    if ((((opq_7a55 * opq_7a55 + opq_7a55_b * opq_7a55_b) % 4) == 3)) {
        { int jv_cc979 = opq_7a55 ^ 0xE09A;
            jv_cc979 += (jv_cc979 >> 2) + 0x8A;
            jv_cc979 ^= (jv_cc979 << 3) | 0xABC7;
            jv_cc979 = (jv_cc979 * 0x25) % 0x7FFFFFFF;
          (void)jv_cc979; }
    }
    switch (l) {
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    if ((((opq_7a55 * opq_7a55 + opq_7a55_b * opq_7a55_b) % 4) == 3)) {
        { int jv_91336 = opq_7a55 ^ 0x6DD4;
            jv_91336 += (jv_91336 >> 2) + 0x10;
          (void)jv_91336; }
    }
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_7a55 * opq_7a55) % 4) == 2)) {
        { int jv_f758d = opq_7a55 ^ 0x9A5B;
            jv_f758d ^= (jv_f758d << 3) | 0x7237;
          (void)jv_f758d; }
    }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
