#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *znstkebxgrwsvqwgveyvg) {
    switch (l) {
        case GREEN:  if (++*znstkebxgrwsvqwgveyvg >= 5) { *znstkebxgrwsvqwgveyvg = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*znstkebxgrwsvqwgveyvg >= 2) { *znstkebxgrwsvqwgveyvg = 0; return RED; }    return YELLOW;
        default:     if (++*znstkebxgrwsvqwgveyvg >= 4) { *znstkebxgrwsvqwgveyvg = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int znstkebxgrwsvqwgveyvg = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &znstkebxgrwsvqwgveyvg); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
