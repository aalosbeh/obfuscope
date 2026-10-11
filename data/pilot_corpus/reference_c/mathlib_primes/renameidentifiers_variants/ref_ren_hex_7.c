#include <stdio.h>
#define LIM 500
int main(void) {
    char v_c0a967[LIM];
    for (int i = 0; i < LIM; i++) v_c0a967[i] = 1;
    v_c0a967[0] = v_c0a967[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (v_c0a967[i])
            for (int j = i * i; j < LIM; j += i) v_c0a967[j] = 0;
    int v_9b0463 = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (v_c0a967[i]) { v_9b0463++; last = i; }
    printf("%d %d\n", v_9b0463, last);
    return 0;
}
