#include <stdio.h>
static volatile int opq_ace6 = 7;
static volatile int opq_ace6_b = 3;

int main(void) {
    if ((((opq_ace6 * opq_ace6) % 4) == 2)) {
        { int jv_633d1 = opq_ace6 ^ 0xDB46;
            jv_633d1 ^= (jv_633d1 << 3) | 0xE18;
            jv_633d1 += (jv_633d1 >> 2) + 0xB5;
            jv_633d1 = (jv_633d1 * 0x19) % 0x7FFFFFFF;
          (void)jv_633d1; }
    }
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    if ((((opq_ace6 * opq_ace6) % 4) == 2)) {
        { int jv_89f27 = opq_ace6 ^ 0x5CDA;
            jv_89f27 = (jv_89f27 * 0x35) % 0x7FFFFFFF;
          (void)jv_89f27; }
    }
    int credit = 0, vends = 0, rejected = 0;
    if ((((opq_ace6 * opq_ace6) % 4) == 2)) {
        { int jv_4cf43 = opq_ace6 ^ 0xC708;
            jv_4cf43 = (jv_4cf43 * 0x3A) % 0x7FFFFFFF;
            jv_4cf43 ^= (jv_4cf43 << 3) | 0x4F9;
            jv_4cf43 += (jv_4cf43 >> 2) + 0xBF;
          (void)jv_4cf43; }
    }
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
