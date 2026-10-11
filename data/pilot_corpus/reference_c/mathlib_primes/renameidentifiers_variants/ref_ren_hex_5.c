#include <stdio.h>
#define LIM 500
int main(void) {
    char v_d6e206[LIM];
    for (int i = 0; i < LIM; i++) v_d6e206[i] = 1;
    v_d6e206[0] = v_d6e206[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (v_d6e206[i])
            for (int j = i * i; j < LIM; j += i) v_d6e206[j] = 0;
    int v_25131a = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (v_d6e206[i]) { v_25131a++; last = i; }
    printf("%d %d\n", v_25131a, last);
    return 0;
}
