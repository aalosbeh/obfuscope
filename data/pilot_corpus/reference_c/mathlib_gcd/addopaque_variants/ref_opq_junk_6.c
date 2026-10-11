#include <stdio.h>
static volatile int opq_dec0 = 7;
static volatile int opq_dec0_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = 0;
    if ((((opq_dec0 * opq_dec0 + opq_dec0_b * opq_dec0_b) % 4) == 3)) {
        { int jv_b552b = opq_dec0 ^ 0xC9FB;
            jv_b552b ^= (jv_b552b << 3) | 0x37EF;
          (void)jv_b552b; }
    }
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    if ((((opq_dec0 * opq_dec0 + opq_dec0_b * opq_dec0_b) % 4) == 3)) {
        { int jv_88672 = opq_dec0 ^ 0xF659;
            jv_88672 += (jv_88672 >> 2) + 0x8A;
          (void)jv_88672; }
    }
    printf("%ld\n", acc);
    return 0;
}
