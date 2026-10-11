#include <stdio.h>
enum light { GREEN, YELLOW, RED };
static enum light next(enum light l, int *umggexggofzebcmjbwxjmx) {
    switch (l) {
        case GREEN:  if (++*umggexggofzebcmjbwxjmx >= 5) { *umggexggofzebcmjbwxjmx = 0; return YELLOW; } return GREEN;
        case YELLOW: if (++*umggexggofzebcmjbwxjmx >= 2) { *umggexggofzebcmjbwxjmx = 0; return RED; }    return YELLOW;
        default:     if (++*umggexggofzebcmjbwxjmx >= 4) { *umggexggofzebcmjbwxjmx = 0; return GREEN; }  return RED;
    }
}
int main(void) {
    enum light l = GREEN;
    int umggexggofzebcmjbwxjmx = 0, counts[3] = {0,0,0};
    for (int t = 0; t < 60; t++) { counts[l]++; l = next(l, &umggexggofzebcmjbwxjmx); }
    printf("%d %d %d\n", counts[GREEN], counts[YELLOW], counts[RED]);
    return 0;
}
