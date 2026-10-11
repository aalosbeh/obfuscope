#include <stdio.h>
static volatile int opq_c749 = 7;
static volatile int opq_c749_b = 3;

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    if ((((opq_c749 * opq_c749) % 4) == 2)) {
        { int jv_626a1 = opq_c749 ^ 0xF78F;
            jv_626a1 = (jv_626a1 * 0x12) % 0x7FFFFFFF;
            jv_626a1 += (jv_626a1 >> 2) + 0xB6;
            jv_626a1 ^= (jv_626a1 << 3) | 0x5CCD;
          (void)jv_626a1; }
    }
    for (int i = 0; i < 9; i++) {
        if ((((opq_c749 * opq_c749) % 4) == 2)) {
            { int jv_766b7 = opq_c749 ^ 0x796D;
                jv_766b7 += (jv_766b7 >> 2) + 0x21;
              (void)jv_766b7; }
        }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if ((((opq_c749 * opq_c749) % 4) == 2)) {
            { int jv_bc91a = opq_c749 ^ 0xE7E4;
                jv_bc91a ^= (jv_bc91a << 3) | 0x142;
                jv_bc91a = (jv_bc91a * 0x3A) % 0x7FFFFFFF;
                jv_bc91a += (jv_bc91a >> 2) + 0x41;
              (void)jv_bc91a; }
        }
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
