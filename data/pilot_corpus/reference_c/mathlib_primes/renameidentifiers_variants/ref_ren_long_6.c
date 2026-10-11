#include <stdio.h>
#define LIM 500
int main(void) {
    char ucswhhlvgducfns[LIM];
    for (int i = 0; i < LIM; i++) ucswhhlvgducfns[i] = 1;
    ucswhhlvgducfns[0] = ucswhhlvgducfns[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (ucswhhlvgducfns[i])
            for (int j = i * i; j < LIM; j += i) ucswhhlvgducfns[j] = 0;
    int ltgtizjgamgcfzhxz = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (ucswhhlvgducfns[i]) { ltgtizjgamgcfzhxz++; last = i; }
    printf("%d %d\n", ltgtizjgamgcfzhxz, last);
    return 0;
}
