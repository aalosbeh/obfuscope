#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x853 - 0x853);
    for (int a = (0x21 - 0x20); a <= (0x4D203515 ^ 0x4D20353D); a++)
        for (int b = a; b <= (0x3CCD83B ^ 0x3CCD813); b++)
            if (gcd(a, b) == (0x36F43FE7 ^ 0x36F43FE6)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x368C16F6 ^ 0x368C16F6);
}
