#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x85A - 0x85A); i < LIM; i++) sieve[i] = (0x16C - 0x16B);
    sieve[(0x2FD - 0x2FD)] = sieve[(0x23B - 0x23A)] = (0xEB9 - 0xEB9);
    for (int i = (0xA23 - 0xA21); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0xD9B - 0xD9B);
    int count = (0xC77 - 0xC77), last = (0x91A - 0x91A);
    for (int i = (0xAEE - 0xAEE); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x4D0 - 0x4D0);
}
