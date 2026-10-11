#include <stdio.h>
static volatile int opq_d43b = 7;
static volatile int opq_d43b_b = 3;

int main(void) {
    if ((((opq_d43b * opq_d43b + opq_d43b_b * opq_d43b_b) % 4) == 3)) {
        { int jv_f8cbc = opq_d43b ^ 0xFA2E;
            jv_f8cbc += (jv_f8cbc >> 2) + 0x34;
            jv_f8cbc = (jv_f8cbc * 0xB) % 0x7FFFFFFF;
          (void)jv_f8cbc; }
    }
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    if ((((opq_d43b * opq_d43b + opq_d43b) % 2) == 0)) { opq_d43b_b ^= 0; }
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if ((((opq_d43b * opq_d43b + opq_d43b_b * opq_d43b_b) % 4) == 3)) {
            { int jv_db40a = opq_d43b ^ 0xBA5B;
                jv_db40a += (jv_db40a >> 2) + 0x59;
              (void)jv_db40a; }
        }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    return 0;
}
