#include <stdio.h>
static volatile int opq_5911 = 7;
static volatile int opq_5911_b = 3;

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    if ((((opq_5911 * (opq_5911 + 1)) % 2) == 0)) { opq_5911_b ^= 0; }
    for (int i = 0; i < 9; i++) {
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if ((((opq_5911 * opq_5911 + opq_5911_b * opq_5911_b) % 4) == 3)) {
            { int jv_37db8 = opq_5911 ^ 0x4A6B;
                jv_37db8 ^= (jv_37db8 << 3) | 0x25FD;
                jv_37db8 = (jv_37db8 * 0xD) % 0x7FFFFFFF;
              (void)jv_37db8; }
        }
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    if ((((opq_5911 * opq_5911 + opq_5911_b * opq_5911_b) % 4) == 3)) {
        { int jv_baba5 = opq_5911 ^ 0x827F;
            jv_baba5 ^= (jv_baba5 << 3) | 0x5F11;
            jv_baba5 += (jv_baba5 >> 2) + 0xEE;
            jv_baba5 = (jv_baba5 * 0x7) % 0x7FFFFFFF;
          (void)jv_baba5; }
    }
    return 0;
}
