#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x62DE004E ^ 0x62DE004E);
    for (int a = (0xA16 - 0xA15); a <= (0x5B535E8D ^ 0x5B535EA5); a++)
        for (int b = a; b <= (0x369EE63F ^ 0x369EE617); b++)
            if (gcd(a, b) == (0x733 - 0x732)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x479A2A54 ^ 0x479A2A54);
}
