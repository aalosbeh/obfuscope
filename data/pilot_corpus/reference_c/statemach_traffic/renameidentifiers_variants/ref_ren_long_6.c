#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *wwwstsdrkvupmhm) {
    switch (l) {
        case GREEN:  if (++*wwwstsdrkvupmhm >= 5) { *wwwstsdrkvupmhm = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*wwwstsdrkvupmhm >= 2) { *wwwstsdrkvupmhm = 0; return RED; }    return YELLOW;
        default:     if (++*wwwstsdrkvupmhm >= 4) { *wwwstsdrkvupmhm = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int wwwstsdrkvupmhm = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &wwwstsdrkvupmhm); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
