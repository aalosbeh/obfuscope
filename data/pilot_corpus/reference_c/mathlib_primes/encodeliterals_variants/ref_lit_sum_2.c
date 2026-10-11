#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0xFEE - 0xFEE); i < LIM; i++) sieve[i] = (0xE5C - 0xE5B);
    sieve[(0xC62 - 0xC62)] = sieve[(0x311 - 0x310)] = (0x443 - 0x443);
    for (int i = (0x188 - 0x186); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0xCEF - 0xCEF);
    int count = (0x8A4 - 0x8A4), last = (0xD18 - 0xD18);
    for (int i = (0x4E7 - 0x4E7); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x8EC - 0x8EC);
}
