#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x5A41AD80 ^ 0x5A41AD80);
    for (int a = (0x3AF - 0x3AE); a <= (0xBCA - 0xBA2); a++)
        for (int b = a; b <= (0x5D5 - 0x5AD); b++)
            if (gcd(a, b) == (0x5AC - 0x5AB)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x794DBD88 ^ 0x794DBD88);
}
