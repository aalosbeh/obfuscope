#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *ibmohcotwywrutvsnxxr) {
    switch (l) {
        case GREEN:  if (++*ibmohcotwywrutvsnxxr >= 5) { *ibmohcotwywrutvsnxxr = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*ibmohcotwywrutvsnxxr >= 2) { *ibmohcotwywrutvsnxxr = 0; return RED; }    return YELLOW;
        default:     if (++*ibmohcotwywrutvsnxxr >= 4) { *ibmohcotwywrutvsnxxr = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int ibmohcotwywrutvsnxxr = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &ibmohcotwywrutvsnxxr); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
