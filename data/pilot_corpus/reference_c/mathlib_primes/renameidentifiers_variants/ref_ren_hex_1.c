#include <stdio.h>
#define LIM 500
int main(void) {
    char v_60e4b8[LIM];
    for (int i = 0; i < LIM; i++) v_60e4b8[i] = 1;
    v_60e4b8[0] = v_60e4b8[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (v_60e4b8[i])
            for (int j = i * i; j < LIM; j += i) v_60e4b8[j] = 0;
    int v_b6cc2d = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (v_60e4b8[i]) { v_b6cc2d++; last = i; }
    printf("%d %d\n", v_b6cc2d, last);
    return 0;
}
