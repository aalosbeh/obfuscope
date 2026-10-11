#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0xBFE - 0xBFE);
    for (int a = (0xE20 - 0xE1F); a <= (0xA8D - 0xA65); a++)
        for (int b = a; b <= (0xBBB - 0xB93); b++)
            if (gcd(a, b) == (0x7B6 - 0x7B5)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0xF7D - 0xF7D);
}
