#include <stdio.h>
static volatile int opq_cee4 = 7;
static volatile int opq_cee4_b = 3;

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    if (((opq_cee4 * opq_cee4 - opq_cee4) % 2 == 0)) { opq_cee4_b ^= 0; }
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    if ((((opq_cee4 * (opq_cee4 + 1)) % 2) == 0)) { opq_cee4_b ^= 0; }
    for (int i = 0; i < 9; i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    if ((((opq_cee4 * (opq_cee4 + 1)) % 2) == 0)) { opq_cee4_b ^= 0; }
    return 0;
}
