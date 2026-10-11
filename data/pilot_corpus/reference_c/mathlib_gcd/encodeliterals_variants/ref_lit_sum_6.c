#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x71E - 0x71E);
    for (int a = (0x2B2 - 0x2B1); a <= (0x5AF - 0x587); a++)
        for (int b = a; b <= (0xC6A - 0xC42); b++)
            if (gcd(a, b) == (0xE69 - 0xE68)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0xD09 - 0xD09);
}
