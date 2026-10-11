#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x293 - 0x293);
    for (int a = (0x8E4 - 0x8E3); a <= (0x8FE - 0x8D6); a++)
        for (int b = a; b <= (0xD83 - 0xD5B); b++)
            if (gcd(a, b) == (0x3C7 - 0x3C6)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0xAD9 - 0xAD9);
}
