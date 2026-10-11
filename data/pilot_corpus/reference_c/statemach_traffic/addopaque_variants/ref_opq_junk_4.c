#include <stdio.h>
static volatile int opq_ae18 = 7;
static volatile int opq_ae18_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        if ((((opq_ae18 * opq_ae18 + opq_ae18_b * opq_ae18_b) % 4) == 3)) {
            { int jv_3d743 = opq_ae18 ^ 0x35AA;
                jv_3d743 += (jv_3d743 >> 2) + 0x82;
                jv_3d743 = (jv_3d743 * 0x27) % 0x7FFFFFFF;
                jv_3d743 ^= (jv_3d743 << 3) | 0xD9B4;
              (void)jv_3d743; }
        }
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    if ((((opq_ae18 * opq_ae18) % 4) == 2)) {
        { int jv_b1dcb = opq_ae18 ^ 0x64B2;
            jv_b1dcb ^= (jv_b1dcb << 3) | 0x85A6;
            jv_b1dcb += (jv_b1dcb >> 2) + 0x4B;
            jv_b1dcb = (jv_b1dcb * 0x22) % 0x7FFFFFFF;
          (void)jv_b1dcb; }
    }
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    if ((((opq_ae18 * opq_ae18) % 4) == 2)) {
        { int jv_347f4 = opq_ae18 ^ 0x24BC;
            jv_347f4 ^= (jv_347f4 << 3) | 0xF508;
          (void)jv_347f4; }
    }
    return 0;
}
