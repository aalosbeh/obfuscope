#include <stdio.h>
static volatile int opq_1a7a = 7;
static volatile int opq_1a7a_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    if ((((opq_1a7a * opq_1a7a + opq_1a7a_b * opq_1a7a_b) % 4) == 3)) {
        { int jv_6804d = opq_1a7a ^ 0xC491;
            jv_6804d = (jv_6804d * 0x39) % 0x7FFFFFFF;
            jv_6804d ^= (jv_6804d << 3) | 0x34B9;
          (void)jv_6804d; }
    }
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_1a7a * opq_1a7a + opq_1a7a) % 2) == 0)) { opq_1a7a_b ^= 0; }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    if ((((opq_1a7a * opq_1a7a + opq_1a7a_b * opq_1a7a_b) % 4) == 3)) {
        { int jv_5f8d6 = opq_1a7a ^ 0x86BE;
            jv_5f8d6 ^= (jv_5f8d6 << 3) | 0x501D;
            jv_5f8d6 += (jv_5f8d6 >> 2) + 0x20;
          (void)jv_5f8d6; }
    }
    return 0;
}
