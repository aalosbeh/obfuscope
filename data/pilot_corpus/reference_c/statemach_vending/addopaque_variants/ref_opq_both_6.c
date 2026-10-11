#include <stdio.h>
static volatile int opq_95c8 = 7;
static volatile int opq_95c8_b = 3;

int main(void) {
    if (((opq_95c8 * opq_95c8 - opq_95c8) % 2 == 0)) { opq_95c8_b ^= 0; }
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    if ((((opq_95c8 * (opq_95c8 + 1)) % 2) == 0)) { opq_95c8_b ^= 0; }
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if ((((opq_95c8 * opq_95c8 + opq_95c8_b * opq_95c8_b) % 4) == 3)) {
            { int jv_4f804 = opq_95c8 ^ 0x1936;
                jv_4f804 += (jv_4f804 >> 2) + 0x6A;
                jv_4f804 = (jv_4f804 * 0x33) % 0x7FFFFFFF;
              (void)jv_4f804; }
        }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
