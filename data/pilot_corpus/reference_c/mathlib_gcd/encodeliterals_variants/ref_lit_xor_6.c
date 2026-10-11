#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x13D280C8 ^ 0x13D280C8);
    for (int a = (0x3A5691B9 ^ 0x3A5691B8); a <= (0x12362071 ^ 0x12362059); a++)
        for (int b = a; b <= (0x12F3FA02 ^ 0x12F3FA2A); b++)
            if (gcd(a, b) == (0x3EEE37DB ^ 0x3EEE37DA)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0xAA644D ^ 0xAA644D);
}
