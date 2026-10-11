#include <stdio.h>
int main(void) {
    int v_aa8dbe[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int v_c7f12c = 0, vends = 0, rejected = 0;
    const int v_6e05e0 = 65;
    for (int i = 0; i < 9; i++) {
        if (v_c7f12c >= v_6e05e0) { rejected++; continue; }
        v_c7f12c += v_aa8dbe[i];
        if (v_c7f12c >= v_6e05e0) { vends++; v_c7f12c -= v_6e05e0; }
    }
    printf("%d %d %d\n", vends, v_c7f12c, rejected);
    return 0;
}
