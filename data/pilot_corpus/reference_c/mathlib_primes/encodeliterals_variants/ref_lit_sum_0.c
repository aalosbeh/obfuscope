#include <stdio.h>
#define LIM 500
int main(void) {
    char sieve[LIM];
    for (int i = (0xC95 - 0xC95); i < LIM; i++) sieve[i] = (0x3E4 - 0x3E3);
    sieve[(0x75 - 0x75)] = sieve[(0xD20 - 0xD1F)] = (0xE82 - 0xE82);
    for (int i = (0xC70 - 0xC6E); i * i < LIM; i++)
        if (sieve[i])
            for (int j = i * i; j < LIM; j += i) sieve[j] = (0xC23 - 0xC23);
    int count = (0xDD4 - 0xDD4), last = (0xE9F - 0xE9F);
    for (int i = (0x6F2 - 0x6F2); i < LIM; i++) if (sieve[i]) { count++; last = i; }
    printf("%d %d\n", count, last);
    return (0x4C4 - 0x4C4);
}
