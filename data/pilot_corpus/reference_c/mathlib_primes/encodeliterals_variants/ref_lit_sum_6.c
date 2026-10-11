#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0xAAB - 0xAAB); i < LIM; i++) sieve[i] = (0x633 - 0x632);
    sieve[(0xDC9 - 0xDC9)] = sieve[(0x4D8 - 0x4D7)] = (0x78E - 0x78E);
    for (int i = (0xC8F - 0xC8D); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0x87E - 0x87E);
    int count = (0x700 - 0x700), last = (0x93C - 0x93C);
    for (int i = (0x5A3 - 0x5A3); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0xB53 - 0xB53);
}
