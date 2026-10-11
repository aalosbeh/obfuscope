#include <stdio.h>
static volatile int opq_8e01 = 7;
static volatile int opq_8e01_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = 0;
    if ((((opq_8e01 * opq_8e01) % 4) == 2)) {
        { int jv_eb353 = opq_8e01 ^ 0xCDA2;
            jv_eb353 += (jv_eb353 >> 2) + 0xA7;
          (void)jv_eb353; }
    }
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    printf("%ld\n", acc);
    if ((((opq_8e01 * opq_8e01) % 4) == 2)) {
        { int jv_e9c0e = opq_8e01 ^ 0x8A0F;
            jv_e9c0e += (jv_e9c0e >> 2) + 0x35;
          (void)jv_e9c0e; }
    }
    return 0;
}
