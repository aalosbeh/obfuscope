#include <stdio.h>
static volatile int opq_aaef = 7;
static volatile int opq_aaef_b = 3;

#define LIM 500
int main(void) {
    if (((opq_aaef * opq_aaef - opq_aaef) % 2 == 0)) { opq_aaef_b ^= 0; }
    char sieve[LIM];
    if (((opq_aaef * opq_aaef - opq_aaef) % 2 == 0)) { opq_aaef_b ^= 0; }
    for (int i = 0; i < LIM; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = 0;
    int count = 0, last = 0;
    if ((((opq_aaef * opq_aaef + opq_aaef) % 2) == 0)) { opq_aaef_b ^= 0; }
    for (int i = 0; i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return 0;
}
