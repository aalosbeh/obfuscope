#include <stdio.h>
static volatile int opq_ecd3 = 7;
static volatile int opq_ecd3_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = 0;
    if ((((opq_ecd3 * opq_ecd3) % 4) == 2)) {
        { int jv_1f259 = opq_ecd3 ^ 0x4C47;
            jv_1f259 = (jv_1f259 * 0x19) % 0x7FFFFFFF;
            jv_1f259 ^= (jv_1f259 << 3) | 0xC0D;
          (void)jv_1f259; }
    }
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    printf("%ld\n", acc);
    if ((((opq_ecd3 * opq_ecd3 + opq_ecd3_b * opq_ecd3_b) % 4) == 3)) {
        { int jv_fa150 = opq_ecd3 ^ 0x888C;
            jv_fa150 = (jv_fa150 * 0x35) % 0x7FFFFFFF;
          (void)jv_fa150; }
    }
    return 0;
}
