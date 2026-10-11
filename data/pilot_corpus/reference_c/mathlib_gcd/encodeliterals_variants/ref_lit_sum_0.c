#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x48C - 0x48C);
    for (int a = (0xFCA - 0xFC9); a <= (0x361 - 0x339); a++)
        for (int b = a; b <= (0xBD8 - 0xBB0); b++)
            if (gcd(a, b) == (0x577 - 0x576)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x512 - 0x512);
}
