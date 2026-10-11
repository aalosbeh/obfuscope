#include <stdio.h>
static volatile int opq_1f82 = 7;
static volatile int opq_1f82_b = 3;

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    if ((((opq_1f82 * (opq_1f82 + 1)) % 2) == 0)) { opq_1f82_b ^= 0; }
    for (int i = 0; i < 9; i++) {
        if (((opq_1f82 * opq_1f82 - opq_1f82) % 2 == 0)) { opq_1f82_b ^= 0; }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    if (((opq_1f82 * opq_1f82 - opq_1f82) % 2 == 0)) { opq_1f82_b ^= 0; }
    return 0;
}
