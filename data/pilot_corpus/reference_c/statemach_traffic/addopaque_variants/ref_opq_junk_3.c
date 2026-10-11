#include <stdio.h>
static volatile int opq_9cc2 = 7;
static volatile int opq_9cc2_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    switch (l) {
        if ((((opq_9cc2 * opq_9cc2 + opq_9cc2_b * opq_9cc2_b) % 4) == 3)) {
            { int jv_d09d9 = opq_9cc2 ^ 0xFFCC;
                jv_d09d9 ^= (jv_d09d9 << 3) | 0xE036;
                jv_d09d9 += (jv_d09d9 >> 2) + 0x47;
              (void)jv_d09d9; }
        }
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    if ((((opq_9cc2 * opq_9cc2 + opq_9cc2_b * opq_9cc2_b) % 4) == 3)) {
        { int jv_15db5 = opq_9cc2 ^ 0x11FB;
            jv_15db5 = (jv_15db5 * 0x32) % 0x7FFFFFFF;
            jv_15db5 += (jv_15db5 >> 2) + 0xF1;
          (void)jv_15db5; }
    }
    enum light l = GREEN;
    int hold = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    if ((((opq_9cc2 * opq_9cc2) % 4) == 2)) {
        { int jv_c4469 = opq_9cc2 ^ 0x80C;
            jv_c4469 = (jv_c4469 * 0x26) % 0x7FFFFFFF;
            jv_c4469 ^= (jv_c4469 << 3) | 0x8C17;
          (void)jv_c4469; }
    }
    return 0;
}
