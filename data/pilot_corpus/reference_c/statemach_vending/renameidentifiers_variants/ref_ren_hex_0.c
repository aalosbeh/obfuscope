#include <stdio.h>
int main(void) {
    int v_f1ce40[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int v_e5b61b = 0, vends = 0, rejected = 0;
    const int v_f18c1c = 65;
    for (int i = 0; i < 9; i++) {
        if (v_e5b61b >= v_f18c1c) { rejected++; continue; }
        v_e5b61b += v_f1ce40[i];
        if (v_e5b61b >= v_f18c1c) { vends++; v_e5b61b -= v_f18c1c; }
    }
    printf("%d %d %d\n", vends, v_e5b61b, rejected);
    return 0;
}
