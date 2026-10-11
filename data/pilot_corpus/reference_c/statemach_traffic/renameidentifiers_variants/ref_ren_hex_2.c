#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *v_e171b7) {
    switch (l) {
        case GREEN:  if (++*v_e171b7 >= 5) { *v_e171b7 = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*v_e171b7 >= 2) { *v_e171b7 = 0; return RED; }    return YELLOW;
        default:     if (++*v_e171b7 >= 4) { *v_e171b7 = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int v_e171b7 = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &v_e171b7); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
