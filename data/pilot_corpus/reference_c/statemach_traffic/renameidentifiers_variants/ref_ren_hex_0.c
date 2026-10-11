#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *v_279c7a) {
    switch (l) {
        case GREEN:  if (++*v_279c7a >= 5) { *v_279c7a = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*v_279c7a >= 2) { *v_279c7a = 0; return RED; }    return YELLOW;
        default:     if (++*v_279c7a >= 4) { *v_279c7a = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int v_279c7a = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &v_279c7a); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
