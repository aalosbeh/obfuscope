#include <stdio.h>
#define LIM 500
int main(void) {
    char v_ba7661[LIM];
    for (int i = 0; i < LIM; i++) v_ba7661[i] = 1;
    v_ba7661[0] = v_ba7661[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (v_ba7661[i])
            for (int j = i * i; j < LIM; j += i) v_ba7661[j] = 0;
    int v_f66e14 = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (v_ba7661[i]) { v_f66e14++; last = i; }
    printf("%d %d\n", v_f66e14, last);
    return 0;
}
