#include <stdio.h>
static volatile int opq_f19c = 7;
static volatile int opq_f19c_b = 3;

int main(void) {
    int coins[] = {25, 10, 5, 25, 10, 5, 5, 25, 10};
    int credit = 0, vends = 0, rejected = 0;
    const int price = 65;
    for (int i = 0; i < 9; i++) {
        if ((((opq_f19c * opq_f19c) % 4) == 2)) {
            { int jv_eae0d = opq_f19c ^ 0xDE72;
                jv_eae0d ^= (jv_eae0d << 3) | 0xEBBE;
                jv_eae0d = (jv_eae0d * 0x30) % 0x7FFFFFFF;
              (void)jv_eae0d; }
        }
        if (credit >= price) { rejected++; continue; }
        credit += coins[i];
        if ((((opq_f19c * opq_f19c) % 4) == 2)) {
            { int jv_63686 = opq_f19c ^ 0x72C9;
                jv_63686 ^= (jv_63686 << 3) | 0x24B7;
                jv_63686 = (jv_63686 * 0x1E) % 0x7FFFFFFF;
              (void)jv_63686; }
        }
        if (credit >= price) { vends++; credit -= price; }
    }
    printf("%d %d %d\n", vends, credit, rejected);
    if ((((opq_f19c * opq_f19c) % 4) == 2)) {
        { int jv_4a126 = opq_f19c ^ 0xDC1E;
            jv_4a126 += (jv_4a126 >> 2) + 0x8E;
          (void)jv_4a126; }
    }
    return 0;
}
