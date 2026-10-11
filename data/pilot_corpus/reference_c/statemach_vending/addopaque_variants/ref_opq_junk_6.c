#include <stdio.h>
static volatile int opq_30ba = 7;
static volatile int opq_30ba_b = 3;

int main(void) {
    if ((((opq_30ba * opq_30ba) % 4) == 2)) {
        { int jv_7f466 = opq_30ba ^ 0x51E2;
            jv_7f466 ^= (jv_7f466 << 3) | 0xBC1E;
          (void)jv_7f466; }
    }
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    if ((((opq_30ba * opq_30ba) % 4) == 2)) {
        { int jv_b595f = opq_30ba ^ 0xDACD;
            jv_b595f ^= (jv_b595f << 3) | 0x5D97;
            jv_b595f += (jv_b595f >> 2) + 0x5;
          (void)jv_b595f; }
    }
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    if ((((opq_30ba * opq_30ba) % 4) == 2)) {
        { int jv_b771b = opq_30ba ^ 0x9EBF;
            jv_b771b = (jv_b771b * 0x3A) % 0x7FFFFFFF;
            jv_b771b += (jv_b771b >> 2) + 0x9E;
          (void)jv_b771b; }
    }
    for (int i = 0; i < 9; i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
