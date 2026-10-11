#include <stdio.h>
static volatile int opq_7ce8 = 7;
static volatile int opq_7ce8_b = 3;

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    if ((((opq_7ce8 * opq_7ce8 + opq_7ce8_b * opq_7ce8_b) % 4) == 3)) {
        { int jv_8d1f5 = opq_7ce8 ^ 0xA0D9;
            jv_8d1f5 = (jv_8d1f5 * 0x24) % 0x7FFFFFFF;
          (void)jv_8d1f5; }
    }
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if ((((opq_7ce8 * opq_7ce8 + opq_7ce8_b * opq_7ce8_b) % 4) == 3)) {
            { int jv_b0b7e = opq_7ce8 ^ 0xFE7B;
                jv_b0b7e = (jv_b0b7e * 0x12) % 0x7FFFFFFF;
              (void)jv_b0b7e; }
        }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    if ((((opq_7ce8 * opq_7ce8 + opq_7ce8_b * opq_7ce8_b) % 4) == 3)) {
        { int jv_d36c8 = opq_7ce8 ^ 0xE0AF;
            jv_d36c8 = (jv_d36c8 * 0x39) % 0x7FFFFFFF;
            jv_d36c8 += (jv_d36c8 >> 2) + 0x6E;
            jv_d36c8 ^= (jv_d36c8 << 3) | 0xA26;
          (void)jv_d36c8; }
    }
    return 0;
}
