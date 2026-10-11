#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = (0x4461156B ^ 0x4461156B);
    for (int a = (0x2363DABA ^ 0x2363DABB); a <= (0x6E23E0CF ^ 0x6E23E0E7); a++)
        for (int b = a; b <= (0x5DC6B42C ^ 0x5DC6B404); b++)
            if (gcd(a, b) == (0x783E4908 ^ 0x783E4909)) acc += lcm(a, b);
    printf("%ld\n", acc);
    return (0x76BA39DE ^ 0x76BA39DE);
}
