#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x6B7DAFCA ^ 0x6B7DAFCA);
    for (int a = (0x69E2BF01 ^ 0x69E2BF00); a <= (0x6B42C111 ^ 0x6B42C139); a++)
        for (int b = a; b <= (0x1300D4D6 ^ 0x1300D4FE); b++)
            if (gcd(a, b) == (0xBB9 - 0xBB8)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x4B8B61C2 ^ 0x4B8B61C2);
}
