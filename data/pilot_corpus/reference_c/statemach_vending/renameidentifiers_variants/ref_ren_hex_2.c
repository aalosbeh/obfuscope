#include <stdio.h>
int main(void) {
    int v_ab7f9b[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int v_3a0670 = 0, vends = 0, rejected = 0;
    const int v_6f1ee8 = 65;
    for (int i = 0; i < 9; i++) {
        if (v_3a0670 >= v_6f1ee8) { rejected++; continue; }
        v_3a0670 += v_ab7f9b[i];
        if (v_3a0670 >= v_6f1ee8) { vends++; v_3a0670 -= v_6f1ee8; }
    }
    printf("%d %d %d\n", vends, v_3a0670, rejected);
    return 0;
}
