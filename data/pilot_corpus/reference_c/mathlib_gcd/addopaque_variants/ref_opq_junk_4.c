#include <stdio.h>
static volatile int opq_8f16 = 7;
static volatile int opq_8f16_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    if ((((opq_8f16 * opq_8f16 + opq_8f16_b * opq_8f16_b) % 4) == 3)) {
        { int jv_55e88 = opq_8f16 ^ 0x9E9B;
            jv_55e88 += (jv_55e88 >> 2) + 0x77;
          (void)jv_55e88; }
    }
    long acc = 0;
    if ((((opq_8f16 * opq_8f16) % 4) == 2)) {
        { int jv_f5aac = opq_8f16 ^ 0xAD7F;
            jv_f5aac = (jv_f5aac * 0x35) % 0x7FFFFFFF;
            jv_f5aac += (jv_f5aac >> 2) + 0x5F;
            jv_f5aac ^= (jv_f5aac << 3) | 0x1A4A;
          (void)jv_f5aac; }
    }
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    printf("%ld\n", acc);
    return 0;
}
