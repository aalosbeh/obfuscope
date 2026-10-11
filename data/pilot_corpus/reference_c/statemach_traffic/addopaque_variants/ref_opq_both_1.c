#include <stdio.h>
static volatile int opq_8afc = 7;
static volatile int opq_8afc_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        if ((((opq_8afc * opq_8afc) % 4) == 2)) {
            { int jv_45834 = opq_8afc ^ 0x527B;
                jv_45834 += (jv_45834 >> 2) + 0x99;
                jv_45834 ^= (jv_45834 << 3) | 0x36F0;
                jv_45834 = (jv_45834 * 0x11) % 0x7FFFFFFF;
              (void)jv_45834; }
        }
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    if ((((opq_8afc * (opq_8afc + 1)) % 2) == 0)) { opq_8afc_b ^= 0; }
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    if ((((opq_8afc * opq_8afc) % 4) == 2)) {
        { int jv_7381f = opq_8afc ^ 0x20D7;
            jv_7381f = (jv_7381f * 0x17) % 0x7FFFFFFF;
          (void)jv_7381f; }
    }
    return 0;
}
