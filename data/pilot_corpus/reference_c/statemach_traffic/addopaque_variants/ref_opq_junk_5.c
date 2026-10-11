#include <stdio.h>
static volatile int opq_2c78 = 7;
static volatile int opq_2c78_b = 3;

enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *hold) {
    if ((((opq_2c78 * opq_2c78 + opq_2c78_b * opq_2c78_b) % 4) == 3)) {
        { int jv_6ba15 = opq_2c78 ^ 0x1FB0;
            jv_6ba15 ^= (jv_6ba15 << 3) | 0x2D93;
          (void)jv_6ba15; }
    }
    switch (l) {
        if ((((opq_2c78 * opq_2c78 + opq_2c78_b * opq_2c78_b) % 4) == 3)) {
            { int jv_4f1bc = opq_2c78 ^ 0x5169;
                jv_4f1bc += (jv_4f1bc >> 2) + 0xA0;
                jv_4f1bc ^= (jv_4f1bc << 3) | 0xD6B8;
              (void)jv_4f1bc; }
        }
        case GREEN:  if (++*hold >= 5) { *hold = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*hold >= 2) { *hold = 0; return RED; }    return YELLOW;
        default:     if (++*hold >= 4) { *hold = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    if ((((opq_2c78 * opq_2c78 + opq_2c78_b * opq_2c78_b) % 4) == 3)) {
        { int jv_58626 = opq_2c78 ^ 0xF22C;
            jv_58626 ^= (jv_58626 << 3) | 0xDAE9;
            jv_58626 += (jv_58626 >> 2) + 0x6C;
          (void)jv_58626; }
    }
    int hold = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &hold); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
