#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x6B9 - 0x6B9);
    for (int a = (0xFD3 - 0xFD2); a <= (0xCAA - 0xC82); a++)
        for (int b = a; b <= (0x473 - 0x44B); b++)
            if (gcd(a, b) == (0x624 - 0x623)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0xF42 - 0xF42);
}
