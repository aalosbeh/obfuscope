#include <stdio.h>
static volatile int opq_ad43 = 7;
static volatile int opq_ad43_b = 3;

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    if (((opq_ad43 * opq_ad43 - opq_ad43) % 2 == 0)) { opq_ad43_b ^= 0; }
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if ((((opq_ad43 * opq_ad43 + opq_ad43_b * opq_ad43_b) % 4) == 3)) {
            { int jv_ab74a = opq_ad43 ^ 0x1302;
                jv_ab74a += (jv_ab74a >> 2) + 0x25;
              (void)jv_ab74a; }
        }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    if ((((opq_ad43 * opq_ad43 + opq_ad43) % 2) == 0)) { opq_ad43_b ^= 0; }
    return 0;
}
