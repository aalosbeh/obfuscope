#include <stdio.h>
static volatile int opq_50b0 = 7;
static volatile int opq_50b0_b = 3;

int main(void) {
    if ((((opq_50b0 * opq_50b0) % 4) == 2)) {
        { int jv_88f34 = opq_50b0 ^ 0xCB38;
            jv_88f34 = (jv_88f34 * 0x22) % 0x7FFFFFFF;
            jv_88f34 += (jv_88f34 >> 2) + 0xCE;
          (void)jv_88f34; }
    }
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if ((((opq_50b0 * opq_50b0) % 4) == 2)) {
            { int jv_ba929 = opq_50b0 ^ 0x3A36;
                jv_ba929 += (jv_ba929 >> 2) + 0xAC;
                jv_ba929 ^= (jv_ba929 << 3) | 0xC22A;
                jv_ba929 = (jv_ba929 * 0x7) % 0x7FFFFFFF;
              (void)jv_ba929; }
        }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if ((((opq_50b0 * opq_50b0) % 4) == 2)) {
            { int jv_58c09 = opq_50b0 ^ 0x872B;
                jv_58c09 += (jv_58c09 >> 2) + 0x6B;
                jv_58c09 ^= (jv_58c09 << 3) | 0x7BF3;
              (void)jv_58c09; }
        }
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
