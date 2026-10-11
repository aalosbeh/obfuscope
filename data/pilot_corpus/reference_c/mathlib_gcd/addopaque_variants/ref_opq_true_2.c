#include <stdio.h>
static volatile int opq_3ef6 = 7;
static volatile int opq_3ef6_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    if ((((opq_3ef6 * (opq_3ef6 + 1)) % 2) == 0)) { opq_3ef6_b ^= 0; }
    long acc = 0;
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    if ((((opq_3ef6 * (opq_3ef6 + 1)) % 2) == 0)) { opq_3ef6_b ^= 0; }
    printf("%ld\n", acc);
    return 0;
}
