#include <stdio.h>
static volatile int opq_8041 = 7;
static volatile int opq_8041_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    if ((((opq_8041 * opq_8041 + opq_8041) % 2) == 0)) { opq_8041_b ^= 0; }
    switch (l) {
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    if ((((opq_8041 * opq_8041 + opq_8041_b * opq_8041_b) % 4) == 3)) {
        { int jv_829e8 = opq_8041 ^ 0xF514;
            jv_829e8 += (jv_829e8 >> 2) + 0xF;
            jv_829e8 = (jv_829e8 * 0x17) % 0x7FFFFFFF;
            jv_829e8 ^= (jv_829e8 << 3) | 0xA033;
          (void)jv_829e8; }
    }
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_8041 * opq_8041 + opq_8041_b * opq_8041_b) % 4) == 3)) {
        { int jv_109ec = opq_8041 ^ 0x175A;
            jv_109ec += (jv_109ec >> 2) + 0xAD;
            jv_109ec = (jv_109ec * 0x19) % 0x7FFFFFFF;
            jv_109ec ^= (jv_109ec << 3) | 0x805C;
          (void)jv_109ec; }
    }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
