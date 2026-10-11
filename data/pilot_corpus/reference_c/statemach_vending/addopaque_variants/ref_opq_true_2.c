#include <stdio.h>
static volatile int opq_5062 = 7;
static volatile int opq_5062_b = 3;

int main(void) {
    if ((((opq_5062 * (opq_5062 + 1)) % 2) == 0)) { opq_5062_b ^= 0; }
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    if ((((opq_5062 * opq_5062 + opq_5062) % 2) == 0)) { opq_5062_b ^= 0; }
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    if ((((opq_5062 * (opq_5062 + 1)) % 2) == 0)) { opq_5062_b ^= 0; }
    return 0;
}
