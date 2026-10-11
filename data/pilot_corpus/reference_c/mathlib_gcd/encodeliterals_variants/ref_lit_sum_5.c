#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x8D0 - 0x8D0);
    for (int a = (0x412 - 0x411); a <= (0x3FF - 0x3D7); a++)
        for (int b = a; b <= (0x863 - 0x83B); b++)
            if (gcd(a, b) == (0x9D7 - 0x9D6)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x945 - 0x945);
}
