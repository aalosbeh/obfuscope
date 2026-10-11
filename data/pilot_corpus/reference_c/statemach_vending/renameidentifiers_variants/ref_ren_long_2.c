#include <stdio.h>
int main(void) {
    int xgnbxrmloykfuymf[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int yiowtklddohozaq = 0, vends = 0, rejected = 0;
    const int drumhzwzfojzacltfi = 65;
    for (int i = 0; i < 9; i++) {
        if (yiowtklddohozaq >= drumhzwzfojzacltfi) { rejected++; continue; }
        yiowtklddohozaq += xgnbxrmloykfuymf[i];
        if (yiowtklddohozaq >= drumhzwzfojzacltfi) { vends++; yiowtklddohozaq -= drumhzwzfojzacltfi; }
    }
    printf("%d %d %d\n", vends, yiowtklddohozaq, rejected);
    return 0;
}
