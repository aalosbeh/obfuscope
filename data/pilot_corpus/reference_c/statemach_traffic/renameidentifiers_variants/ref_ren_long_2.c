#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *znwcllakboykakzsy) {
    switch (l) {
        case GREEN:  if (++*znwcllakboykakzsy >= 5) { *znwcllakboykakzsy = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*znwcllakboykakzsy >= 2) { *znwcllakboykakzsy = 0; return RED; }    return YELLOW;
        default:     if (++*znwcllakboykakzsy >= 4) { *znwcllakboykakzsy = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int znwcllakboykakzsy = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &znwcllakboykakzsy); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
