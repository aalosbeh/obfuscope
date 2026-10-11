#include <stdio.h>
#define LIM 500
int main(void) {
    char v_3d2c17[LIM];
    for (int i = 0; i < LIM; i++) v_3d2c17[i] = 1;
    v_3d2c17[0] = v_3d2c17[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (v_3d2c17[i])
            for (int j = i * i; j < LIM; j += i) v_3d2c17[j] = 0;
    int v_7f21c1 = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (v_3d2c17[i]) { v_7f21c1++; last = i; }
    printf("%d %d\n", v_7f21c1, last);
    return 0;
}
