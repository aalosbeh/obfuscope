#include <stdio.h>
static volatile int opq_3f00 = 7;
static volatile int opq_3f00_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    if ((((opq_3f00 * opq_3f00 + opq_3f00_b * opq_3f00_b) % 4) == 3)) {
        { int jv_174ab = opq_3f00 ^ 0x11ED;
            jv_174ab += (jv_174ab >> 2) + 0x82;
          (void)jv_174ab; }
    }
    long acc = 0;
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    if ((((opq_3f00 * opq_3f00) % 4) == 2)) {
        { int jv_1f9cd = opq_3f00 ^ 0x88A0;
            jv_1f9cd = (jv_1f9cd * 0x1D) % 0x7FFFFFFF;
            jv_1f9cd ^= (jv_1f9cd << 3) | 0x6BAD;
            jv_1f9cd += (jv_1f9cd >> 2) + 0x5E;
          (void)jv_1f9cd; }
    }
    printf("%ld\n", acc);
    return 0;
}
