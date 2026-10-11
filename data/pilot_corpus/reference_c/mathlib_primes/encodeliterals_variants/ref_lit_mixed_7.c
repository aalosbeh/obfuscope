#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x79A650DE ^ 0x79A650DE); i < LIM; i++) sieve[i] = (0x3CA - 0x3C9);
    sieve[(0x1CE5C17A ^ 0x1CE5C17A)] = sieve[(0xBC3 - 0xBC2)] = (0x7DF9B725 ^ 0x7DF9B725);
    for (int i = (0xD64F2FD ^ 0xD64F2FF); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x2C30A69F ^ 0x2C30A69F);
    int count = (0xD9F - 0xD9F), last = (0xC3A5125 ^ 0xC3A5125);
    for (int i = (0x5F810B0 ^ 0x5F810B0); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0xD8E - 0xD8E);
}
