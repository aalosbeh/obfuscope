#include <stdio.h>
#define LIM 500
int main(void) {
    char praiyxrkwztpyk[LIM];
    for (int i = 0; i < LIM; i++) praiyxrkwztpyk[i] = 1;
    praiyxrkwztpyk[0] = praiyxrkwztpyk[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (praiyxrkwztpyk[i])
            for (int j = i * i; j < LIM; j += i) praiyxrkwztpyk[j] = 0;
    int mxsoedgzcuxxsrqoxx = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (praiyxrkwztpyk[i]) { mxsoedgzcuxxsrqoxx++; last = i; }
    printf("%d %d\n", mxsoedgzcuxxsrqoxx, last);
    return 0;
}
