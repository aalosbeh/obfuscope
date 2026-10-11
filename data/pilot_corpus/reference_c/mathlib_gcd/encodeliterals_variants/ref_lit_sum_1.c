#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x724 - 0x724);
    for (int a = (0xB93 - 0xB92); a <= (0x711 - 0x6E9); a++)
        for (int b = a; b <= (0x9A6 - 0x97E); b++)
            if (gcd(a, b) == (0x449 - 0x448)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x2EF - 0x2EF);
}
