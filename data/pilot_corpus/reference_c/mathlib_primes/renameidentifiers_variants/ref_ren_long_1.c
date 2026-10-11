#include <stdio.h>
#define LIM 500
int main(void) {
    char onjijvvgvvghvl[LIM];
    for (int i = 0; i < LIM; i++) onjijvvgvvghvl[i] = 1;
    onjijvvgvvghvl[0] = onjijvvgvvghvl[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (onjijvvgvvghvl[i])
            for (int j = i * i; j < LIM; j += i) onjijvvgvvghvl[j] = 0;
    int lohyamczarnndkywr = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (onjijvvgvvghvl[i]) { lohyamczarnndkywr++; last = i; }
    printf("%d %d\n", lohyamczarnndkywr, last);
    return 0;
}
