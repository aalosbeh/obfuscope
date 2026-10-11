#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x94A - 0x94A);
    for (int a = (0x2D5 - 0x2D4); a <= (0xCE0 - 0xCB8); a++)
        for (int b = a; b <= (0x451DBA83 ^ 0x451DBAAB); b++)
            if (gcd(a, b) == (0x3D15D305 ^ 0x3D15D304)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x578 - 0x578);
}
