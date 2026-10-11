#include <stdio.h>
int main(void) {
    int nfgbmihoqfhquvg[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int vbqdvwiwqovlerodc = 0, vends = 0, rejected = 0;
    const int cefuzfmsqblvxgdvlocreu = 65;
    for (int i = 0; i < 9; i++) {
        if (vbqdvwiwqovlerodc >= cefuzfmsqblvxgdvlocreu) { rejected++; continue; }
        vbqdvwiwqovlerodc += nfgbmihoqfhquvg[i];
        if (vbqdvwiwqovlerodc >= cefuzfmsqblvxgdvlocreu) { vends++; vbqdvwiwqovlerodc -= cefuzfmsqblvxgdvlocreu; }
    }
    printf("%d %d %d\n", vends, vbqdvwiwqovlerodc, rejected);
    return 0;
}
