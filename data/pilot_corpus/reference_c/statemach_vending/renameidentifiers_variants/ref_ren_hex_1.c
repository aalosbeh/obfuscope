#include <stdio.h>
int main(void) {
    int v_172796[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int v_9f32a7 = 0, vends = 0, rejected = 0;
    const int v_8125cd = 65;
    for (int i = 0; i < 9; i++) {
        if (v_9f32a7 >= v_8125cd) { rejected++; continue; }
        v_9f32a7 += v_172796[i];
        if (v_9f32a7 >= v_8125cd) { vends++; v_9f32a7 -= v_8125cd; }
    }
    printf("%d %d %d\n", vends, v_9f32a7, rejected);
    return 0;
}
