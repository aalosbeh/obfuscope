#include <stdio.h>
static volatile int opq_c0d7 = 7;
static volatile int opq_c0d7_b = 3;

int main(void) {
    if (((opq_c0d7 * opq_c0d7 - opq_c0d7) % 2 == 0)) { opq_c0d7_b ^= 0; }
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    if ((((opq_c0d7 * opq_c0d7 + opq_c0d7) % 2) == 0)) { opq_c0d7_b ^= 0; }
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if ((((opq_c0d7 * opq_c0d7 + opq_c0d7_b * opq_c0d7_b) % 4) == 3)) {
            { int jv_82117 = opq_c0d7 ^ 0xBEE4;
                jv_82117 ^= (jv_82117 << 3) | 0x70E5;
                jv_82117 += (jv_82117 >> 2) + 0x4E;
              (void)jv_82117; }
        }
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
