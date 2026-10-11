#include <stdio.h>
static volatile int opq_e982 = 7;
static volatile int opq_e982_b = 3;

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    if ((((opq_e982 * opq_e982 + opq_e982) % 2) == 0)) { opq_e982_b ^= 0; }
    int credit = 0, vends = 0, rejected = 0;
    if ((((opq_e982 * opq_e982) % 4) == 2)) {
        { int jv_7f798 = opq_e982 ^ 0x2003;
            jv_7f798 = (jv_7f798 * 0x37) % 0x7FFFFFFF;
            jv_7f798 += (jv_7f798 >> 2) + 0x81;
            jv_7f798 ^= (jv_7f798 << 3) | 0xF892;
          (void)jv_7f798; }
    }
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if ((((opq_e982 * opq_e982) % 4) == 2)) {
            { int jv_3b262 = opq_e982 ^ 0x8E3A;
                jv_3b262 = (jv_3b262 * 0x1E) % 0x7FFFFFFF;
                jv_3b262 ^= (jv_3b262 << 3) | 0x8577;
                jv_3b262 += (jv_3b262 >> 2) + 0xC9;
              (void)jv_3b262; }
        }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
