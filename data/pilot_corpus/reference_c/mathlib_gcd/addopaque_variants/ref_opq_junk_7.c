#include <stdio.h>
static volatile int opq_723b = 7;
static volatile int opq_723b_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = 0;
    if ((((opq_723b * opq_723b + opq_723b_b * opq_723b_b) % 4) == 3)) {
        { int jv_1035c = opq_723b ^ 0x1DB3;
            jv_1035c ^= (jv_1035c << 3) | 0xA6CA;
            jv_1035c += (jv_1035c >> 2) + 0xD6;
          (void)jv_1035c; }
    }
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    printf("%ld\n", acc);
    if ((((opq_723b * opq_723b + opq_723b_b * opq_723b_b) % 4) == 3)) {
        { int jv_39306 = opq_723b ^ 0xD448;
            jv_39306 = (jv_39306 * 0x36) % 0x7FFFFFFF;
            jv_39306 += (jv_39306 >> 2) + 0x9E;
            jv_39306 ^= (jv_39306 << 3) | 0x6E1E;
          (void)jv_39306; }
    }
    return 0;
}
