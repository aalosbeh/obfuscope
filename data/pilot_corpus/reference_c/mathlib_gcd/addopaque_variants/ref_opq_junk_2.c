#include <stdio.h>
static volatile int opq_a79f = 7;
static volatile int opq_a79f_b = 3;

static int gcd(int a, int b) { while (b) { int t = a % b; a = b; b = t; } return a; }
static int lcm(int a, int b) { return a / gcd(a, b) * b; }
int main(void) {
    if ((((opq_a79f * opq_a79f) % 4) == 2)) {
        { int jv_28924 = opq_a79f ^ 0xD685;
            jv_28924 += (jv_28924 >> 2) + 0x2;
            jv_28924 ^= (jv_28924 << 3) | 0x2272;
          (void)jv_28924; }
    }
    long acc = 0;
    for (int a = 1; a <= 40; a++)
        for (int b = a; b <= 40; b++)
            if (gcd(a, b) == 1) acc += lcm(a, b);
    printf("%ld\n", acc);
    if ((((opq_a79f * opq_a79f) % 4) == 2)) {
        { int jv_e7eea = opq_a79f ^ 0x835C;
            jv_e7eea ^= (jv_e7eea << 3) | 0x3CEA;
            jv_e7eea = (jv_e7eea * 0x15) % 0x7FFFFFFF;
            jv_e7eea += (jv_e7eea >> 2) + 0x83;
          (void)jv_e7eea; }
    }
    return 0;
}
