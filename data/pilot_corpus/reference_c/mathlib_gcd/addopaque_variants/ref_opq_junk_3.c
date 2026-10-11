#include <stdio.h>
static volatile int opq_53e3 = 7;
static volatile int opq_53e3_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    if ((((opq_53e3 * opq_53e3) % 4) == 2)) {
        { int jv_fcfc0 = opq_53e3 ^ 0xB218;
            jv_fcfc0 = (jv_fcfc0 * 0x9) % 0x7FFFFFFF;
          (void)jv_fcfc0; }
    }
    long acc = 0;
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    if ((((opq_53e3 * opq_53e3) % 4) == 2)) {
        { int jv_d791e = opq_53e3 ^ 0xF41;
            jv_d791e = (jv_d791e * 0x3C) % 0x7FFFFFFF;
          (void)jv_d791e; }
    }
    printf("%ld\n", acc);
    return 0;
}
