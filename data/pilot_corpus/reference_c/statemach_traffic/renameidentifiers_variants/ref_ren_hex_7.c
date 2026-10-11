#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *v_bd0415) {
    switch (l) {
        case GREEN:  if (++*v_bd0415 >= 5) { *v_bd0415 = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*v_bd0415 >= 2) { *v_bd0415 = 0; return RED; }    return YELLOW;
        default:     if (++*v_bd0415 >= 4) { *v_bd0415 = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int v_bd0415 = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &v_bd0415); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
