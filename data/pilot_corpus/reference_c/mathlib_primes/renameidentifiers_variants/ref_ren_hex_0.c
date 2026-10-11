#include <stdio.h>
#define LIM 500
int main(void) {
    char v_b2e063[LIM];
    for (int i = 0; i < LIM; i++) v_b2e063[i] = 1;
    v_b2e063[0] = v_b2e063[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (v_b2e063[i])
            for (int j = i * i; j < LIM; j += i) v_b2e063[j] = 0;
    int v_4b23b8 = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (v_b2e063[i]) { v_4b23b8++; last = i; }
    printf("%d %d\n", v_4b23b8, last);
    return 0;
}
