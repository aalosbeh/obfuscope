#include <stdio.h>
static volatile int opq_b4e2 = 7;
static volatile int opq_b4e2_b = 3;

int main(void) {
    if ((((opq_b4e2 * opq_b4e2 + opq_b4e2_b * opq_b4e2_b) % 4) == 3)) {
        { int jv_c7ba3 = opq_b4e2 ^ 0x6647;
            jv_c7ba3 += (jv_c7ba3 >> 2) + 0xA0;
            jv_c7ba3 = (jv_c7ba3 * 0x3B) % 0x7FFFFFFF;
            jv_c7ba3 ^= (jv_c7ba3 << 3) | 0xFE52;
          (void)jv_c7ba3; }
    }
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    if ((((opq_b4e2 * opq_b4e2 + opq_b4e2) % 2) == 0)) { opq_b4e2_b ^= 0; }
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    if (((opq_b4e2 * opq_b4e2 - opq_b4e2) % 2 == 0)) { opq_b4e2_b ^= 0; }
    for (int i = 0; i < 9; i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
