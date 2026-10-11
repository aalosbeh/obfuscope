#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x207 - 0x207);
    for (int a = (0xF5FA521 ^ 0xF5FA520); a <= (0x5E0F943F ^ 0x5E0F9417); a++)
        for (int b = a; b <= (0x6AF - 0x687); b++)
            if (gcd(a, b) == (0x6ACCAB6E ^ 0x6ACCAB6F)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x6B0 - 0x6B0);
}
