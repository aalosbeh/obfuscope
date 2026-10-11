#include <stdio.h>
static volatile int opq_1f36 = 7;
static volatile int opq_1f36_b = 3;

#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    if ((((opq_1f36 * opq_1f36 + opq_1f36) % 2) == 0)) { opq_1f36_b ^= 0; }
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_1f36 * opq_1f36 + opq_1f36_b * opq_1f36_b) % 4) == 3)) {
        { int jv_f5689 = opq_1f36 ^ 0x697E;
            jv_f5689 += (jv_f5689 >> 2) + 0x84;
            jv_f5689 ^= (jv_f5689 << 3) | 0x6614;
          (void)jv_f5689; }
    }
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    if ((((opq_1f36 * (opq_1f36 + 1)) % 2) == 0)) { opq_1f36_b ^= 0; }
    return 0;
}
