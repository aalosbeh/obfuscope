#include <stdio.h>
static volatile int opq_3815 = 7;
static volatile int opq_3815_b = 3;

int main(void) {
    if ((((opq_3815 * opq_3815 + opq_3815) % 2) == 0)) { opq_3815_b ^= 0; }
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if (((opq_3815 * opq_3815 - opq_3815) % 2 == 0)) { opq_3815_b ^= 0; }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (((opq_3815 * opq_3815 - opq_3815) % 2 == 0)) { opq_3815_b ^= 0; }
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
