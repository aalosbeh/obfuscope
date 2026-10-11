#include <stdio.h>
static volatile int opq_a8db = 7;
static volatile int opq_a8db_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    if ((((opq_a8db * opq_a8db) % 4) == 2)) {
        { int jv_818fa = opq_a8db ^ 0xD22A;
            jv_818fa ^= (jv_818fa << 3) | 0x4CFC;
            jv_818fa = (jv_818fa * 0x16) % 0x7FFFFFFF;
            jv_818fa += (jv_818fa >> 2) + 0x6F;
          (void)jv_818fa; }
    }
    switch (l) {
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_a8db * opq_a8db) % 4) == 2)) {
        { int jv_93566 = opq_a8db ^ 0x7DBD;
            jv_93566 = (jv_93566 * 0x25) % 0x7FFFFFFF;
            jv_93566 += (jv_93566 >> 2) + 0xE2;
            jv_93566 ^= (jv_93566 << 3) | 0x9F8C;
          (void)jv_93566; }
    }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    if ((((opq_a8db * opq_a8db + opq_a8db_b * opq_a8db_b) % 4) == 3)) {
        { int jv_7db93 = opq_a8db ^ 0x24E0;
            jv_7db93 = (jv_7db93 * 0x1F) % 0x7FFFFFFF;
            jv_7db93 += (jv_7db93 >> 2) + 0xA7;
          (void)jv_7db93; }
    }
    return 0;
}
