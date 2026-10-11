#include <stdio.h>
static volatile int opq_8121 = 7;
static volatile int opq_8121_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    if ((((opq_8121 * opq_8121 + opq_8121_b * opq_8121_b) % 4) == 3)) {
        { int jv_221dc = opq_8121 ^ 0x3958;
            jv_221dc += (jv_221dc >> 2) + 0x9;
            jv_221dc = (jv_221dc * 0x26) % 0x7FFFFFFF;
            jv_221dc ^= (jv_221dc << 3) | 0xC454;
          (void)jv_221dc; }
    }
    long acc = 0;
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    printf("%ld\n", acc);
    if (((opq_8121 * opq_8121 - opq_8121) % 2 == 0)) { opq_8121_b ^= 0; }
    return 0;
}
