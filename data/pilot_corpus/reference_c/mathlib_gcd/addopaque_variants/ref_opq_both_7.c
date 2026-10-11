#include <stdio.h>
static volatile int opq_44ce = 7;
static volatile int opq_44ce_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = 0;
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    if ((((opq_44ce * (opq_44ce + 1)) % 2) == 0)) { opq_44ce_b ^= 0; }
    printf("%ld\n", acc);
    if ((((opq_44ce * opq_44ce + opq_44ce_b * opq_44ce_b) % 4) == 3)) {
        { int jv_b6801 = opq_44ce ^ 0x3784;
            jv_b6801 ^= (jv_b6801 << 3) | 0x1282;
            jv_b6801 += (jv_b6801 >> 2) + 0xDE;
          (void)jv_b6801; }
    }
    return 0;
}
