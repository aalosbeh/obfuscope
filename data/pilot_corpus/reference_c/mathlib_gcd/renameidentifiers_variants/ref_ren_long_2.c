#include <stdio.h>
static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long rxvkfzqtguwfaozb = 0;
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) rxvkfzqtguwfaozb += lcm(a, b);
    printf("%ld\n", rxvkfzqtguwfaozb);
    return 0;
}
