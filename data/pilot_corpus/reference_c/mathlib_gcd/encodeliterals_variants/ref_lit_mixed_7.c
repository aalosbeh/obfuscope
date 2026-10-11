#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x11968A25 ^ 0x11968A25);
    for (int a = (0x565E3E6F ^ 0x565E3E6E); a <= (0x6DB49FE7 ^ 0x6DB49FCF); a++)
        for (int b = a; b <= (0x4AB1BBA9 ^ 0x4AB1BB81); b++)
            if (gcd(a, b) == (0xD5C - 0xD5B)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x1EBC9A90 ^ 0x1EBC9A90);
}
