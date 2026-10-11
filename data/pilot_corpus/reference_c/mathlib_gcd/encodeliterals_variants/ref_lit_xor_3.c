#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x258B8763 ^ 0x258B8763);
    for (int a = (0x12E4EC2C ^ 0x12E4EC2D); a <= (0x634AE354 ^ 0x634AE37C); a++)
        for (int b = a; b <= (0x7C8D2A34 ^ 0x7C8D2A1C); b++)
            if (gcd(a, b) == (0x6C7A2411 ^ 0x6C7A2410)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x851D2AD ^ 0x851D2AD);
}
