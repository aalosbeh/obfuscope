#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x59CBACA3 ^ 0x59CBACA3);
    for (int a = (0x64F4B068 ^ 0x64F4B069); a <= (0xB66F80F ^ 0xB66F827); a++)
        for (int b = a; b <= (0x2663D8AD ^ 0x2663D885); b++)
            if (gcd(a, b) == (0x1B745A6F ^ 0x1B745A6E)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x5B27D876 ^ 0x5B27D876);
}
