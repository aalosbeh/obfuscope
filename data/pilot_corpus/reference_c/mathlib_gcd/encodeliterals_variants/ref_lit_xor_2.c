#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x42E641A0 ^ 0x42E641A0);
    for (int a = (0x79AEAE43 ^ 0x79AEAE42); a <= (0x294090F2 ^ 0x294090DA); a++)
        for (int b = a; b <= (0x33D2F473 ^ 0x33D2F45B); b++)
            if (gcd(a, b) == (0x3CA6165F ^ 0x3CA6165E)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x4C6B9BAE ^ 0x4C6B9BAE);
}
