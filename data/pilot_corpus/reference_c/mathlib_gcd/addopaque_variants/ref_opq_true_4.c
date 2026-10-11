#include <stdio.h>
static volatile int opq_854e = 7;
static volatile int opq_854e_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    if ((((opq_854e * opq_854e + opq_854e) % 2) == 0)) { opq_854e_b ^= 0; }
    long acc = 0;
    if (((opq_854e * opq_854e - opq_854e) % 2 == 0)) { opq_854e_b ^= 0; }
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    printf("%ld\n", acc);
    return 0;
}
