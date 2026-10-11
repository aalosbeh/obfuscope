#include <stdio.h>
static volatile int opq_ab7d = 7;
static volatile int opq_ab7d_b = 3;

#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    if (((opq_ab7d * opq_ab7d - opq_ab7d) % 2 == 0)) { opq_ab7d_b ^= 0; }
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    if ((((opq_ab7d * (opq_ab7d + 1)) % 2) == 0)) { opq_ab7d_b ^= 0; }
    int count = 0, last = 0;
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    if (((opq_ab7d * opq_ab7d - opq_ab7d) % 2 == 0)) { opq_ab7d_b ^= 0; }
    return 0;
}
