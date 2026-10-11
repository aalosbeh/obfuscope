#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0xCDA - 0xCDA); i < LIM; i++) sieve[i] = (0x190 - 0x18F);
    sieve[(0x391 - 0x391)] = sieve[(0x43D - 0x43C)] = (0xF38 - 0xF38);
    for (int i = (0x4CF - 0x4CD); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x486 - 0x486);
    int count = (0x47B - 0x47B), last = (0x80 - 0x80);
    for (int i = (0x765 - 0x765); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x637 - 0x637);
}
