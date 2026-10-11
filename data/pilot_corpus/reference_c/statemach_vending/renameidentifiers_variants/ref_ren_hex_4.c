#include <stdio.h>
int main(void) {
    int v_aeebc9[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int v_7f3a88 = 0, vends = 0, rejected = 0;
    const int v_d1ad81 = 65;
    for (int i = 0; i < 9; i++) {
        if (v_7f3a88 >= v_d1ad81) { rejected++; continue; }
        v_7f3a88 += v_aeebc9[i];
        if (v_7f3a88 >= v_d1ad81) { vends++; v_7f3a88 -= v_d1ad81; }
    }
    printf("%d %d %d\n", vends, v_7f3a88, rejected);
    return 0;
}
