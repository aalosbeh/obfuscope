#include <stdio.h>
#define LIM 500
int main(void) {
    char v_d52a55[LIM];
    for (int i = 0; i < LIM; i++) v_d52a55[i] = 1;
    v_d52a55[0] = v_d52a55[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (v_d52a55[i])
            for (int j = i * i; j < LIM; j += i) v_d52a55[j] = 0;
    int v_691b39 = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (v_d52a55[i]) { v_691b39++; last = i; }
    printf("%d %d\n", v_691b39, last);
    return 0;
}
