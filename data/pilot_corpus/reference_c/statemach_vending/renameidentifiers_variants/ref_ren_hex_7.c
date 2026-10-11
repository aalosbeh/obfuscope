#include <stdio.h>
int main(void) {
    int v_832ffb[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int v_784c97 = 0, vends = 0, rejected = 0;
    const int v_580a9e = 65;
    for (int i = 0; i < 9; i++) {
        if (v_784c97 >= v_580a9e) { rejected++; continue; }
        v_784c97 += v_832ffb[i];
        if (v_784c97 >= v_580a9e) { vends++; v_784c97 -= v_580a9e; }
    }
    printf("%d %d %d\n", vends, v_784c97, rejected);
    return 0;
}
