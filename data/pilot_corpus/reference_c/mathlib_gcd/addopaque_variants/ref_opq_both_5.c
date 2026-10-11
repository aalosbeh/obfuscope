#include <stdio.h>
static volatile int opq_584f = 7;
static volatile int opq_584f_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    long acc = 0;
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    if (((opq_584f * opq_584f - opq_584f) % 2 == 0)) { opq_584f_b ^= 0; }
    printf("%ld\n", acc);
    if ((((opq_584f * opq_584f + opq_584f_b * opq_584f_b) % 4) == 3)) {
        { int jv_51f1f = opq_584f ^ 0xA413;
            jv_51f1f = (jv_51f1f * 0x20) % 0x7FFFFFFF;
            jv_51f1f += (jv_51f1f >> 2) + 0xDE;
          (void)jv_51f1f; }
    }
    return 0;
}
