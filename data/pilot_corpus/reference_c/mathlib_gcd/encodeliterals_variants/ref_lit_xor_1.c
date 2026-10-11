#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0xE7D8C42 ^ 0xE7D8C42);
    for (int a = (0x49948925 ^ 0x49948924); a <= (0xB4DB0FF ^ 0xB4DB0D7); a++)
        for (int b = a; b <= (0x7E3709FA ^ 0x7E3709D2); b++)
            if (gcd(a, b) == (0x7E9C63AF ^ 0x7E9C63AE)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x58301E15 ^ 0x58301E15);
}
