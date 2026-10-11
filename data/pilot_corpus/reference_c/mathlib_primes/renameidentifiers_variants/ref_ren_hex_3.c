#include <stdio.h>
#define LIM 500
int main(void) {
    char v_3bc831[LIM];
    for (int i = 0; i < LIM; i++) v_3bc831[i] = 1;
    v_3bc831[0] = v_3bc831[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (v_3bc831[i])
            for (int j = i * i; j < LIM; j += i) v_3bc831[j] = 0;
    int v_14a59f = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (v_3bc831[i]) { v_14a59f++; last = i; }
    printf("%d %d\n", v_14a59f, last);
    return 0;
}
