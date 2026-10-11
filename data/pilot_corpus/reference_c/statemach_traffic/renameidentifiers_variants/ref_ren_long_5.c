#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *unspgggcjlpibhfgot) {
    switch (l) {
        case GREEN:  if (++*unspgggcjlpibhfgot >= 5) { *unspgggcjlpibhfgot = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*unspgggcjlpibhfgot >= 2) { *unspgggcjlpibhfgot = 0; return RED; }    return YELLOW;
        default:     if (++*unspgggcjlpibhfgot >= 4) { *unspgggcjlpibhfgot = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int unspgggcjlpibhfgot = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &unspgggcjlpibhfgot); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
