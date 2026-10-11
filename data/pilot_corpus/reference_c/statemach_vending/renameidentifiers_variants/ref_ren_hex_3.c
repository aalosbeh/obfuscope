#include <stdio.h>
int main(void) {
    int v_351885[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int v_ef1f35 = 0, vends = 0, rejected = 0;
    const int v_fcc23f = 65;
    for (int i = 0; i < 9; i++) {
        if (v_ef1f35 >= v_fcc23f) { rejected++; continue; }
        v_ef1f35 += v_351885[i];
        if (v_ef1f35 >= v_fcc23f) { vends++; v_ef1f35 -= v_fcc23f; }
    }
    printf("%d %d %d\n", vends, v_ef1f35, rejected);
    return 0;
}
