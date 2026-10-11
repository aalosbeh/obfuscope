#include <stdio.h>
int main(void) {
    int v_23837b[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int v_29d0f1 = 0, vends = 0, rejected = 0;
    const int v_6ba19e = 65;
    for (int i = 0; i < 9; i++) {
        if (v_29d0f1 >= v_6ba19e) { rejected++; continue; }
        v_29d0f1 += v_23837b[i];
        if (v_29d0f1 >= v_6ba19e) { vends++; v_29d0f1 -= v_6ba19e; }
    }
    printf("%d %d %d\n", vends, v_29d0f1, rejected);
    return 0;
}
