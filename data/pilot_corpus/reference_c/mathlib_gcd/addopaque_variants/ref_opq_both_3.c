#include <stdio.h>
static volatile int opq_8b74 = 7;
static volatile int opq_8b74_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = 0;
    if ((((opq_8b74 * opq_8b74 + opq_8b74_b * opq_8b74_b) % 4) == 3)) {
        { int jv_ec6e1 = opq_8b74 ^ 0xB32B;
            jv_ec6e1 = (jv_ec6e1 * 0x1A) % 0x7FFFFFFF;
          (void)jv_ec6e1; }
    }
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    printf("%ld\n", acc);
    if ((((opq_8b74 * (opq_8b74 + 1)) % 2) == 0)) { opq_8b74_b ^= 0; }
    return 0;
}
