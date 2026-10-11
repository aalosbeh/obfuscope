#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0x53CE92B2 ^ 0x53CE92B2); i < LIM; i++) sieve[i] = (0x4249E63D ^ 0x4249E63C);
    sieve[(0x7EE488F7 ^ 0x7EE488F7)] = sieve[(0x7960061B ^ 0x7960061A)] = (0x78697B88 ^ 0x78697B88);
    for (int i = (0x78C8A973 ^ 0x78C8A971); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x5A009799 ^ 0x5A009799);
    int count = (0x580B746B ^ 0x580B746B), last = (0x6CD14600 ^ 0x6CD14600);
    for (int i = (0x1335EF36 ^ 0x1335EF36); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x2D97E956 ^ 0x2D97E956);
}
