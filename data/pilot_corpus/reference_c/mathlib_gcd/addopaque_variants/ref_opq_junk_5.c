#include <stdio.h>
static volatile int opq_ab24 = 7;
static volatile int opq_ab24_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    if ((((opq_ab24 * opq_ab24 + opq_ab24_b * opq_ab24_b) % 4) == 3)) {
        { int jv_bc99d = opq_ab24 ^ 0xC679;
            jv_bc99d = (jv_bc99d * 0x11) % 0x7FFFFFFF;
          (void)jv_bc99d; }
    }
    long acc = 0;
    if ((((opq_ab24 * opq_ab24 + opq_ab24_b * opq_ab24_b) % 4) == 3)) {
        { int jv_41945 = opq_ab24 ^ 0x1156;
            jv_41945 += (jv_41945 >> 2) + 0x1A;
          (void)jv_41945; }
    }
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    printf("%ld\n", acc);
    return 0;
}
