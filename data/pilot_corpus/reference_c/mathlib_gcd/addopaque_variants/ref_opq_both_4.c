#include <stdio.h>
static volatile int opq_1e82 = 7;
static volatile int opq_1e82_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    if ((((opq_1e82 * opq_1e82 + opq_1e82_b * opq_1e82_b) % 4) == 3)) {
        { int jv_bf488 = opq_1e82 ^ 0x6E85;
            jv_bf488 ^= (jv_bf488 << 3) | 0x38F5;
          (void)jv_bf488; }
    }
    long acc = 0;
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    if ((((opq_1e82 * opq_1e82 + opq_1e82_b * opq_1e82_b) % 4) == 3)) {
        { int jv_8fee9 = opq_1e82 ^ 0x400F;
            jv_8fee9 = (jv_8fee9 * 0x22) % 0x7FFFFFFF;
            jv_8fee9 ^= (jv_8fee9 << 3) | 0xB6E5;
            jv_8fee9 += (jv_8fee9 >> 2) + 0x95;
          (void)jv_8fee9; }
    }
    printf("%ld\n", acc);
    return 0;
}
