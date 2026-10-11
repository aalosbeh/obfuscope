#include <stdio.h>
static volatile int opq_b70b = 7;
static volatile int opq_b70b_b = 3;

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    if ((((opq_b70b * opq_b70b + opq_b70b_b * opq_b70b_b) % 4) == 3)) {
        { int jv_459d9 = opq_b70b ^ 0xC6E4;
            jv_459d9 = (jv_459d9 * 0x24) % 0x7FFFFFFF;
            jv_459d9 += (jv_459d9 >> 2) + 0x8D;
          (void)jv_459d9; }
    }
    for (int i = 0; i < 9; i++) {
        if ((((opq_b70b * opq_b70b + opq_b70b_b * opq_b70b_b) % 4) == 3)) {
            { int jv_93e7f = opq_b70b ^ 0x6BD6;
                jv_93e7f = (jv_93e7f * 0xF) % 0x7FFFFFFF;
              (void)jv_93e7f; }
        }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if ((((opq_b70b * opq_b70b) % 4) == 2)) {
            { int jv_306fa = opq_b70b ^ 0x1BDF;
                jv_306fa = (jv_306fa * 0x31) % 0x7FFFFFFF;
                jv_306fa ^= (jv_306fa << 3) | 0x1DEB;
              (void)jv_306fa; }
        }
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
