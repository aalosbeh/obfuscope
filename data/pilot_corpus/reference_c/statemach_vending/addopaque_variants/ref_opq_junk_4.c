#include <stdio.h>
static volatile int opq_d3e2 = 7;
static volatile int opq_d3e2_b = 3;

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    if ((((opq_d3e2 * opq_d3e2 + opq_d3e2_b * opq_d3e2_b) % 4) == 3)) {
        { int jv_22228 = opq_d3e2 ^ 0x7765;
            jv_22228 = (jv_22228 * 0x7) % 0x7FFFFFFF;
            jv_22228 ^= (jv_22228 << 3) | 0x6DF8;
            jv_22228 += (jv_22228 >> 2) + 0xBE;
          (void)jv_22228; }
    }
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if ((((opq_d3e2 * opq_d3e2 + opq_d3e2_b * opq_d3e2_b) % 4) == 3)) {
            { int jv_ac349 = opq_d3e2 ^ 0xA4B8;
                jv_ac349 = (jv_ac349 * 0x29) % 0x7FFFFFFF;
              (void)jv_ac349; }
        }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    if ((((opq_d3e2 * opq_d3e2 + opq_d3e2_b * opq_d3e2_b) % 4) == 3)) {
        { int jv_b3666 = opq_d3e2 ^ 0x4FD8;
            jv_b3666 += (jv_b3666 >> 2) + 0x28;
            jv_b3666 = (jv_b3666 * 0x39) % 0x7FFFFFFF;
            jv_b3666 ^= (jv_b3666 << 3) | 0x20DE;
          (void)jv_b3666; }
    }
    return 0;
}
