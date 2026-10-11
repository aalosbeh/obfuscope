#include <stdio.h>
static volatile int opq_b31a = 7;
static volatile int opq_b31a_b = 3;

#define LIM 500
int main(void) {
    if ((((opq_b31a * opq_b31a + opq_b31a_b * opq_b31a_b) % 4) == 3)) {
        { int jv_b2407 = opq_b31a ^ 0x2855;
            jv_b2407 ^= (jv_b2407 << 3) | 0xCCD5;
          (void)jv_b2407; }
    }
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    if ((((opq_b31a * opq_b31a + opq_b31a_b * opq_b31a_b) % 4) == 3)) {
        { int jv_68067 = opq_b31a ^ 0x987B;
            jv_68067 ^= (jv_68067 << 3) | 0xB90B;
          (void)jv_68067; }
    }
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_b31a * opq_b31a) % 4) == 2)) {
        { int jv_cd6aa = opq_b31a ^ 0xB17A;
            jv_cd6aa += (jv_cd6aa >> 2) + 0x5D;
            jv_cd6aa ^= (jv_cd6aa << 3) | 0x4886;
            jv_cd6aa = (jv_cd6aa * 0x3D) % 0x7FFFFFFF;
          (void)jv_cd6aa; }
    }
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return 0;
}
