#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x770 - 0x770);
    for (int a = (0xB04 - 0xB03); a <= (0xDBA - 0xD92); a++)
        for (int b = a; b <= (0x7E8 - 0x7C0); b++)
            if (gcd(a, b) == (0x331 - 0x330)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x113 - 0x113);
}
