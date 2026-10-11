#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x26FC2B0E ^ 0x26FC2B0E);
    for (int a = (0x13F3DDB9 ^ 0x13F3DDB8); a <= (0x7A2B7A97 ^ 0x7A2B7ABF); a++)
        for (int b = a; b <= (0x56266F24 ^ 0x56266F0C); b++)
            if (gcd(a, b) == (0x299440BB ^ 0x299440BA)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x6A05C1E6 ^ 0x6A05C1E6);
}
