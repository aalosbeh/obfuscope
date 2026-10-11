#include <stdio.h>
int main(void) {
    int xtzcvglfhgblplyr[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int meswbiexbwzfcnezeryyzs = 0, vends = 0, rejected = 0;
    const int ipimwnrweezgtmpvwuiejg = 65;
    for (int i = 0; i < 9; i++) {
        if (meswbiexbwzfcnezeryyzs >= ipimwnrweezgtmpvwuiejg) { rejected++; continue; }
        meswbiexbwzfcnezeryyzs += xtzcvglfhgblplyr[i];
        if (meswbiexbwzfcnezeryyzs >= ipimwnrweezgtmpvwuiejg) { vends++; meswbiexbwzfcnezeryyzs -= ipimwnrweezgtmpvwuiejg; }
    }
    printf("%d %d %d\n", vends, meswbiexbwzfcnezeryyzs, rejected);
    return 0;
}
