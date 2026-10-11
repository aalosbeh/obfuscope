#include <stdio.h>
static volatile int opq_99b9 = 7;
static volatile int opq_99b9_b = 3;

int main(void) {
    if ((((opq_99b9 * opq_99b9 + opq_99b9_b * opq_99b9_b) % 4) == 3)) {
        { int jv_bbddb = opq_99b9 ^ 0x2CA4;
            jv_bbddb ^= (jv_bbddb << 3) | 0x5F5F;
            jv_bbddb = (jv_bbddb * 0x14) % 0x7FFFFFFF;
          (void)jv_bbddb; }
    }
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    if ((((opq_99b9 * opq_99b9 + opq_99b9_b * opq_99b9_b) % 4) == 3)) {
        { int jv_3081f = opq_99b9 ^ 0x3C6B;
            jv_3081f = (jv_3081f * 0x16) % 0x7FFFFFFF;
          (void)jv_3081f; }
    }
    for (int i = 0; i < 9; i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if ((((opq_99b9 * opq_99b9) % 4) == 2)) {
            { int jv_3da76 = opq_99b9 ^ 0xB416;
                jv_3da76 += (jv_3da76 >> 2) + 0x6C;
                jv_3da76 ^= (jv_3da76 << 3) | 0xF30C;
              (void)jv_3da76; }
        }
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
