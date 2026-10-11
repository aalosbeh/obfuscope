#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x68B - 0x68B);
    for (int a = (0x79D - 0x79C); a <= (0xB1C890F ^ 0xB1C8927); a++)
        for (int b = a; b <= (0x60F - 0x5E7); b++)
            if (gcd(a, b) == (0x1DE9BF15 ^ 0x1DE9BF14)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x140 - 0x140);
}
