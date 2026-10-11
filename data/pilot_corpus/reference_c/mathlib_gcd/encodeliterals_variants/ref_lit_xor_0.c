#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x1C8AA61 ^ 0x1C8AA61);
    for (int a = (0x42CD774 ^ 0x42CD775); a <= (0x12C4EEEE ^ 0x12C4EEC6); a++)
        for (int b = a; b <= (0xAFB66AA ^ 0xAFB6682); b++)
            if (gcd(a, b) == (0x7F892E39 ^ 0x7F892E38)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0xF110F5E ^ 0xF110F5E);
}
